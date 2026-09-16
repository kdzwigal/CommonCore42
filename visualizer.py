import os
import matplotlib.pyplot as plt
from typing import List
from enum import IntFlag

class Wall(IntFlag):
    N = 1  # 0001
    E = 2  # 0010
    S = 4  # 0100
    W = 8  # 1000

class MazeVisualizerError(Exception):
    """Niestandardowy wyjątek dla błędów renderowania labiryntu."""
    pass

class MazeVisualizer:
    def __init__(self, filepath: str):
        if not os.path.exists(filepath):
            raise MazeVisualizerError(f"Plik {filepath} nie istnieje.")
        self.filepath = filepath
        self.maze_data: List[List[int]] = []
        self._load_data()

    def _load_data(self) -> None:
        """Odczytuje wiersze z pliku i konwertuje znaki hex na liczby całkowite."""
        try:
            with open(self.filepath, 'r') as f:
                for line in f:
                    line = line.strip()
                    if line:
                        # Rzutowanie każdego znaku szesnastkowego z powrotem na int
                        row = [int(char, 16) for char in line]
                        self.maze_data.append(row)
        except IOError as e:
            raise MazeVisualizerError(f"Błąd odczytu pliku: {e}")
        except ValueError as e:
            raise MazeVisualizerError(f"Nieprawidłowy format danych w pliku: {e}")

    def render_to_png(self, output_filename: str = "maze_render.png") -> None:
        """Rysuje labirynt na podstawie masek bitowych i zapisuje jako obraz."""
        if not self.maze_data:
            raise MazeVisualizerError("Brak danych labiryntu do narysowania.")

        height = len(self.maze_data)
        width = len(self.maze_data[0])

        # Przygotowanie płótna (figsize dobierasz według potrzeb)
        fig, ax = plt.subplots(figsize=(10, 10))
        ax.set_aspect('equal')
        ax.axis('off')  # Ukrywa osie X i Y

        # Odwracamy oś Y podczas rysowania, żeby wiersz 0 był na samej górze
        for y, row in enumerate(self.maze_data):
            for x, cell in enumerate(row):
                # Rysowanie odcinków tylko jeśli dany bit jest ustawiony na 1
                if cell & Wall.N:
                    ax.plot([x, x + 1], [height - y, height - y], color='orange', linewidth=2)
                if cell & Wall.S:
                    ax.plot([x, x + 1], [height - y - 1, height - y - 1], color='brown', linewidth=2)
                if cell & Wall.E:
                    ax.plot([x + 1, x + 1], [height - y, height - y - 1], color='blue', linewidth=2)
                if cell & Wall.W:
                    ax.plot([x, x], [height - y, height - y - 1], color='green', linewidth=2)

        # Zapis do pliku PNG w wysokiej jakości (300 DPI)
        try:
            plt.savefig(output_filename, bbox_inches='tight', dpi=300)
            print(f"Pomyślnie wygenerowano wizualizację: {output_filename}")
        except IOError as e:
            raise MazeVisualizerError(f"Nie udało się zapisać pliku graficznego: {e}")
        finally:
            plt.close()

# Użycie klasy
if __name__ == "__main__":
    try:
        # Wskazanie na wcześniej wygenerowany plik txt
        visualizer = MazeVisualizer('maze_output.txt')
        visualizer.render_to_png('maze_render.png')
    except MazeVisualizerError as err:
        print(f"Błąd wizualizatora: {err}")