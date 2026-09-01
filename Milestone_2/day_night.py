import pygame
import math
import random
import sys

# Inicjalizacja biblioteki pygame
pygame.init()

# --- USTAWIENIA GŁÓWNE ---
GRID_W = 20  # Liczba kolumn (szerokość siatki)
GRID_H = 20  # Liczba wierszy (wysokość siatki)
CELL_SIZE = 30  # Rozmiar pojedynczego bloku w pikselach

GRID_WIDTH_PX = GRID_W * CELL_SIZE
GRID_HEIGHT_PX = GRID_H * CELL_SIZE

# Wymiary całego okna
WINDOW_WIDTH = GRID_WIDTH_PX + 200
WINDOW_HEIGHT = GRID_HEIGHT_PX + 250

# Przesunięcie siatki, aby była na środku ekranu
OFFSET_X = (WINDOW_WIDTH - GRID_WIDTH_PX) // 2
OFFSET_Y = 100

# --- KOLORY (zgodne z nagraniem) ---
COLOR_DAY = (224, 232, 227)  # Jasny, szaro-zielony
COLOR_NIGHT = (34, 76, 84)  # Ciemny, głęboki morski
COLOR_BG = (15, 20, 20)  # Kolor tła aplikacji
COLOR_TEXT = (140, 150, 140)  # Kolor tekstu z wynikiem


# --- KLASA PIŁKI ---
class Ball:
    def __init__(self, x, y, speed, angle, radius, color, target_type, fill_type):
        self.x = x
        self.y = y
        self.speed = speed
        self.vx = speed * math.cos(angle)
        self.vy = speed * math.sin(angle)
        self.r = radius
        self.color = color

        # Określa w jaki rodzaj klocków uderza i na jaki zamienia
        self.target_type = target_type
        self.fill_type = fill_type

    def add_jitter(self):
        """Dodaje delikatne odchylenie kąta, aby piłka nie wpadła w nieskończoną pętlę"""
        angle = math.atan2(self.vy, self.vx)
        angle += random.uniform(-0.05, 0.05)
        self.vx = self.speed * math.cos(angle)
        self.vy = self.speed * math.sin(angle)

    def move(self, grid):
        # 1. Ruch i kolizje w osi X
        self.x += self.vx

        # Odbicie od zewnętrznych ścian (lewa/prawa)
        if self.x - self.r < 0:
            self.x = self.r
            self.vx *= -1
            self.add_jitter()
        elif self.x + self.r > GRID_WIDTH_PX:
            self.x = GRID_WIDTH_PX - self.r
            self.vx *= -1
            self.add_jitter()

        # Odbicie od bloków siatki (oś X)
        test_x = self.x + self.r if self.vx > 0 else self.x - self.r
        cx = int(test_x // CELL_SIZE)
        cy = int(self.y // CELL_SIZE)

        if 0 <= cx < GRID_W and 0 <= cy < GRID_H:
            if grid[cy][cx] == self.target_type:
                grid[cy][cx] = self.fill_type  # Zmień kolor bloku
                self.vx *= -1  # Odbij piłkę
                self.x += self.vx  # Lekko cofnij, by uniknąć "zacinania się"
                self.add_jitter()

        # 2. Ruch i kolizje w osi Y
        self.y += self.vy

        # Odbicie od zewnętrznych ścian (góra/dół)
        if self.y - self.r < 0:
            self.y = self.r
            self.vy *= -1
            self.add_jitter()
        elif self.y + self.r > GRID_HEIGHT_PX:
            self.y = GRID_HEIGHT_PX - self.r
            self.vy *= -1
            self.add_jitter()

        # Odbicie od bloków siatki (oś Y)
        cx = int(self.x // CELL_SIZE)
        test_y = self.y + self.r if self.vy > 0 else self.y - self.r
        cy = int(test_y // CELL_SIZE)

        if 0 <= cx < GRID_W and 0 <= cy < GRID_H:
            if grid[cy][cx] == self.target_type:
                grid[cy][cx] = self.fill_type
                self.vy *= -1
                self.y += self.vy
                self.add_jitter()

    def draw(self, screen):
        pos = (OFFSET_X + int(self.x), OFFSET_Y + int(self.y))
        pygame.draw.circle(screen, self.color, pos, self.r)


def main():
    screen = pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT))
    pygame.display.set_caption("Dzień vs Noc")
    clock = pygame.time.Clock()

    # Inicjalizacja czcionki
    font = pygame.font.SysFont("couriernew", 22, bold=True)

    # Inicjalizacja siatki (0 = Dzień, 1 = Noc)
    grid = []
    for y in range(GRID_H):
        row = []
        for x in range(GRID_W):
            if x < GRID_W // 2:
                row.append(0)  # Lewa strona - Dzień
            else:
                row.append(1)  # Prawa strona - Noc
        grid.append(row)

    # Inicjalizacja piłek
    ball_speed = 40
    ball_radius = 9

    # Piłka Dnia (ciemna) - porusza się w jasnym polu, niszczy ciemne klocki
    angle_day = random.uniform(-0.5, 0.5)
    ball_day = Ball(GRID_WIDTH_PX / 4, GRID_HEIGHT_PX / 2, ball_speed, angle_day,
                    ball_radius, COLOR_NIGHT, target_type=1, fill_type=0)

    # Piłka Nocy (jasna) - porusza się w ciemnym polu, niszczy jasne klocki
    angle_night = random.uniform(math.pi - 0.5, math.pi + 0.5)
    ball_night = Ball(GRID_WIDTH_PX * 0.75, GRID_HEIGHT_PX / 2, ball_speed, angle_night,
                      ball_radius, COLOR_DAY, target_type=0, fill_type=1)

    running = True
    while running:
        # 1. Obsługa zdarzeń
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

        # 2. Logika gry
        ball_day.move(grid)
        ball_night.move(grid)

        # Liczenie wyniku
        day_score = sum(row.count(0) for row in grid)
        night_score = sum(row.count(1) for row in grid)

        # 3. Renderowanie grafiki
        screen.fill(COLOR_BG)

        # Rysowanie siatki klocków
        for cy in range(GRID_H):
            for cx in range(GRID_W):
                rect_color = COLOR_DAY if grid[cy][cx] == 0 else COLOR_NIGHT
                rect = (OFFSET_X + cx * CELL_SIZE, OFFSET_Y + cy * CELL_SIZE, CELL_SIZE, CELL_SIZE)
                pygame.draw.rect(screen, rect_color, rect)

        # Rysowanie piłek
        ball_day.draw(screen)
        ball_night.draw(screen)

        # Rysowanie tekstu z wynikiem
        score_text = f"day {day_score:03d} | night {night_score:03d}"
        text_surface = font.render(score_text, True, COLOR_TEXT)
        text_rect = text_surface.get_rect(center=(WINDOW_WIDTH // 2, WINDOW_HEIGHT - 60))
        screen.blit(text_surface, text_rect)

        # Aktualizacja ekranu
        pygame.display.flip()

        # Ograniczenie klatek na sekundę (60 FPS)
        clock.tick(60)

    pygame.quit()
    sys.exit()


if __name__ == "__main__":
    main()