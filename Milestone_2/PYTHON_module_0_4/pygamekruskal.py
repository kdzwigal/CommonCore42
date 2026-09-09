import pygame
import random
import sys
from typing import List, Tuple, Generator
from enum import IntFlag


# --- DEFINICJE STRUKTUR ---

class Wall(IntFlag):
    N = 1  # 0001
    E = 2  # 0010
    S = 4  # 0100
    W = 8  # 1000


class MazeAnimationError(Exception):
    """Niestandardowy wyjątek dla błędów inicjalizacji animacji."""
    pass


class UnionFind:
    """Struktura zbiorów rozłącznych optymalizująca algorytm Kruskala."""

    def __init__(self, size: int):
        self.parent = list(range(size))
        self.rank = [0] * size

    def find(self, i: int) -> int:
        if self.parent[i] == i:
            return i
        # Kompresja ścieżki
        self.parent[i] = self.find(self.parent[i])
        return self.parent[i]

    def union(self, i: int, j: int) -> bool:
        root_i = self.find(i)
        root_j = self.find(j)
        if root_i != root_j:
            # Łączenie według rangi
            if self.rank[root_i] < self.rank[root_j]:
                self.parent[root_i] = root_j
            elif self.rank[root_i] > self.rank[root_j]:
                self.parent[root_j] = root_i
            else:
                self.parent[root_j] = root_i
                self.rank[root_i] += 1
            return True
        return False


# --- LOGIKA I ANIMACJA LABIRYNTU ---

class MazeAnimator:
    def __init__(self, cols: int, rows: int, cell_size: int = 25):
        if cols <= 0 or rows <= 0:
            raise MazeAnimationError("Wymiary siatki muszą być większe od zera.")

        self.cols = cols
        self.rows = rows
        self.cell_size = cell_size
        self.margin = 5  # <--- DODANO: Margines od krawędzi okna
        self.width = cols * cell_size
        self.height = rows * cell_size

        # Start: każda komórka ma 4 ściany (0xF)
        self.grid: List[List[int]] = [[Wall.N | Wall.E | Wall.S | Wall.W for _ in range(cols)] for _ in range(rows)]

        # Inicjalizacja okna Pygame
        pygame.init()
        # POWIĘKSZONO OKNO O MARGINES
        self.screen = pygame.display.set_mode((self.width + 2 * self.margin, self.height + 2 * self.margin))
        pygame.display.set_caption("Kruskal & Braid Maze Generator")
        self.clock = pygame.time.Clock()

    def _extract_internal_walls(self) -> List[Tuple[int, int, int, int, Wall, Wall]]:
        """Pobiera wszystkie wewnętrzne ściany do przetworzenia przez Kruskala."""
        walls = []
        for y in range(self.rows):
            for x in range(self.cols):
                if x < self.cols - 1:
                    walls.append((x, y, x + 1, y, Wall.E, Wall.W))
                if y < self.rows - 1:
                    walls.append((x, y, x, y + 1, Wall.S, Wall.N))
        return walls

    def generate_animation_steps(self) -> Generator[None, None, None]:
        """Generator sterujący poszczególnymi klatkami animacji."""

        # FAZA 1: Algorytm Kruskala (Minimum Spanning Tree)
        walls = self._extract_internal_walls()
        random.shuffle(walls)

        uf = UnionFind(self.cols * self.rows)

        for x1, y1, x2, y2, wall1, wall2 in walls:
            cell1_idx = y1 * self.cols + x1
            cell2_idx = y2 * self.cols + x2

            # Jeśli komórki są w różnych zbiorach - burzymy ścianę
            if uf.union(cell1_idx, cell2_idx):
                self.grid[y1][x1] &= ~wall1
                self.grid[y2][x2] &= ~wall2
                yield  # Przekazanie sterowania do pętli rysującej

        # FAZA 2: Braiding (Usuwanie ślepych zaułków)
        for y in range(self.rows):
            for x in range(self.cols):
                cell = self.grid[y][x]
                # Zliczanie ilości postawionych ścian za pomocą masek
                wall_count = bool(cell & Wall.N) + bool(cell & Wall.E) + bool(cell & Wall.S) + bool(cell & Wall.W)

                if wall_count == 3:
                    # Szukanie dozwolonych wewnętrznych ścian do wyburzenia
                    candidates = []
                    if (cell & Wall.N) and y > 0: candidates.append((x, y - 1, Wall.N, Wall.S))
                    if (cell & Wall.E) and x < self.cols - 1: candidates.append((x + 1, y, Wall.E, Wall.W))
                    if (cell & Wall.S) and y < self.rows - 1: candidates.append((x, y + 1, Wall.S, Wall.N))
                    if (cell & Wall.W) and x > 0: candidates.append((x - 1, y, Wall.W, Wall.E))

                    if candidates:
                        nx, ny, wall, opp_wall = random.choice(candidates)
                        self.grid[y][x] &= ~wall
                        self.grid[ny][nx] &= ~opp_wall
                        yield  # Pokaż wyburzenie kolejnej ściany

    def draw(self) -> None:
        """Rysuje obecny stan gridu w oknie."""
        self.screen.fill((20, 20, 20))  # Ciemne tło

        wall_color = (0, 255, 128)  # Neonowy zielony
        wall_thickness = 1

        for y in range(self.rows):
            for x in range(self.cols):
                cell = self.grid[y][x]

                # PRZESUNIĘCIE PUNKTÓW RYSOWANIA O MARGINES
                px = x * self.cell_size + self.margin
                py = y * self.cell_size + self.margin

                if cell & Wall.N:
                    pygame.draw.line(self.screen, wall_color, (px, py), (px + self.cell_size, py), wall_thickness)
                if cell & Wall.S:
                    pygame.draw.line(self.screen, wall_color, (px, py + self.cell_size),
                                     (px + self.cell_size, py + self.cell_size), wall_thickness)
                if cell & Wall.E:
                    pygame.draw.line(self.screen, wall_color, (px + self.cell_size, py),
                                     (px + self.cell_size, py + self.cell_size), wall_thickness)
                if cell & Wall.W:
                    pygame.draw.line(self.screen, wall_color, (px, py), (px, py + self.cell_size), wall_thickness)

    def run(self) -> None:
        """Główna pętla zdarzeń Pygame."""
        animator = self.generate_animation_steps()
        running = True
        finished_generating = False

        while running:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False

            if not finished_generating:
                try:
                    # Wykonaj 5 kroków algorytmu na klatkę (przyspiesza animację)
                    for _ in range(1):
                        next(animator)
                except StopIteration:
                    finished_generating = True
                    print("Generowanie labiryntu (Kruskal + Braiding) zakończone!")

            self.draw()
            pygame.display.flip()
            self.clock.tick(60)

        pygame.quit()
        sys.exit()


if __name__ == "__main__":
    try:
        # Rozmiar 24x24 komórki, wielkość pikselowa 30px
        app = MazeAnimator(cols=30, rows=15, cell_size=3)
        app.run()
    except MazeAnimationError as e:
        print(f"Błąd inicjalizacji: {e}")