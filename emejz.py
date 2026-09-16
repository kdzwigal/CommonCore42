import random
from typing import List, Tuple, Generator
from enum import IntFlag


class Wall(IntFlag):
    N = 1  # 0001
    E = 2  # 0010
    S = 4  # 0100
    W = 8  # 1000


class MazeGenerationError(Exception):
    """Niestandardowy wyjątek dla błędów generowania labiryntu."""
    pass


class MazeGenerator:
    def __init__(self, width: int, height: int):
        if width <= 0 or height <= 0:
            raise MazeGenerationError("Wymiary labiryntu muszą być dodatnie.")
        self.width = width
        self.height = height
        # Inicjalizacja siatki: każda komórka ma wszystkie ściany (1111 -> 0xF)
        self.grid: List[List[int]] = [[Wall.N | Wall.E | Wall.S | Wall.W for _ in range(width)] for _ in range(height)]
        self.visited: set[Tuple[int, int]] = set()

    def _get_unvisited_neighbors(self, x: int, y: int) -> List[Tuple[int, int, Wall, Wall]]:
        neighbors = []
        directions = [
            (0, -1, Wall.N, Wall.S),  # Góra
            (1, 0, Wall.E, Wall.W),  # Prawo
            (0, 1, Wall.S, Wall.N),  # Dół
            (-1, 0, Wall.W, Wall.E)  # Lewo
        ]
        for dx, dy, wall, opp_wall in directions:
            nx, ny = x + dx, y + dy
            if 0 <= nx < self.width and 0 <= ny < self.height and (nx, ny) not in self.visited:
                neighbors.append((nx, ny, wall, opp_wall))
        return neighbors

    def generate_backtracker(self) -> None:
        """Generuje labirynt używając iteracyjnego Recursive Backtrackera."""
        stack: List[Tuple[int, int]] = []
        start_x, start_y = 0, 0
        self.visited.add((start_x, start_y))
        stack.append((start_x, start_y))

        while stack:
            x, y = stack[-1]
            neighbors = self._get_unvisited_neighbors(x, y)

            if neighbors:
                nx, ny, wall, opp_wall = random.choice(neighbors)
                # Burzenie ścian: operacja bitowa AND z negacją wybranej ściany
                self.grid[y][x] &= ~wall
                self.grid[ny][nx] &= ~opp_wall

                self.visited.add((nx, ny))
                stack.append((nx, ny))
            else:
                stack.pop()

    def stream_hex_rows(self) -> Generator[str, None, None]:
        """Generator strumieniujący wiersze labiryntu jako ciągi znaków szesnastkowych."""
        for row in self.grid:
            yield "".join(f"{cell:1X}" for cell in row)

    def export_to_txt(self, filepath: str) -> None:
        try:
            with open(filepath, 'w') as f:
                for hex_row in self.stream_hex_rows():
                    f.write(hex_row + '\n')
        except IOError as e:
            raise MazeGenerationError(f"Błąd podczas zapisu pliku: {e}")

    def draw_ascii(self) -> None:
        """Rysuje labirynt w konsoli przy użyciu znaków ASCII."""
        for y in range(self.height):
            # 1. Rysowanie poziomych (północnych) ścian dla obecnego wiersza
            for x in range(self.width):
                print("+", end="")
                if self.grid[y][x] & Wall.N:
                    print("---", end="")  # Ściana istnieje
                else:
                    print("   ", end="")  # Brak ściany (przejście)
            print("+")  # Zamykający prawy róg wiersza

            # 2. Rysowanie pionowych (zachodnich) ścian i pustego wnętrza komórek
            for x in range(self.width):
                if self.grid[y][x] & Wall.W:
                    print("|", end="")
                else:
                    print(" ", end="")
                print("   ", end="")  # Wnętrze komórki

            # Wschodnia ściana ostatniej komórki w wierszu (z prawej strony labiryntu)
            if self.grid[y][-1] & Wall.E:
                print("|")
            else:
                print(" ")

        # 3. Rysowanie dolnej (południowej) krawędzi ostatniego wiersza
        for x in range(self.width):
            print("+", end="")
            if self.grid[-1][x] & Wall.S:
                print("---", end="")
            else:
                print("   ", end="")
        print("+")

# Wywołanie dla wariantu 20x20
maze = MazeGenerator(5, 10)
maze.generate_backtracker()

maze.draw_ascii()
maze.export_to_txt('maze_output.txt')