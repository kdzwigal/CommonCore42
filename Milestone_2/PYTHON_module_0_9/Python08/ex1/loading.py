import sys
import importlib

# Definiujemy wymagane pakiety i ich opisy do wyświetlenia
REQUIRED_PACKAGES = {
    'pandas': 'Data manipulation ready',
    'numpy': 'Numerical computation ready',
    'matplotlib': 'Visualization ready'
}


def check_dependencies():
    print("LOADING STATUS: Loading programs...")
    print("Checking dependencies:")

    missing_packages = []

    for pkg, description in REQUIRED_PACKAGES.items():
        try:
            # Próba dynamicznego zaimportowania modułu
            module = importlib.import_module(pkg)
            # Pobranie wersji (jeśli moduł ją udostępnia)
            version = getattr(module, '__version__', 'unknown')
            print(f"[OK] {pkg} ({version}) - {description}")
        except ImportError:
            missing_packages.append(pkg)

    return missing_packages


def run_matrix_analysis():
    # Moduły importujemy wewnątrz funkcji, ponieważ mamy już pewność,
    # że pakiety zostały pomyślnie sprawdzone i istnieją w środowisku.
    import numpy as np
    import pandas as pd
    import matplotlib.pyplot as plt

    print("Analyzing Matrix data...")
    num_points = 1000
    print(f"Processing {num_points} data points...")

    # Numpy jako wyłączne źródło danych (brak twardo zakodowanych
    # list czy funkcji range)
    # Symulacja zakłóceń sygnału w Matriksie
    time_index = np.linspace(0, 100, num_points)
    signal_noise = np.random.normal(0, 0.5, num_points)
    signal = np.sin(time_index) + signal_noise

    # Użycie pandas do manipulacji danymi
    df = pd.DataFrame({'Time': time_index, 'Signal': signal})
    # Obliczenie średniej kroczącej, aby wygładzić sygnał
    df['Clean_Signal'] = df['Signal'].rolling(window=15).mean()

    print("Generating visualization...")

    # Wykres matplotlib
    plt.figure(figsize=(10, 6))
    plt.plot(df['Time'], df['Signal'], color='gray', alpha=0.3,
             label='Raw Data Stream')
    plt.plot(df['Time'], df['Clean_Signal'], color='green', linewidth=2,
             label='Decoded Signal')
    plt.title('Matrix Data Stream Analysis')
    plt.xlabel('Time (ms)')
    plt.ylabel('Signal Strength')
    plt.legend()
    plt.grid(True, linestyle='--', alpha=0.7)

    # Zapis
    output_filename = 'matrix_analysis.png'
    plt.savefig(output_filename)
    plt.close()

    print("Analysis complete!")
    print(f"Results saved to: {output_filename}")


def main():
    missing = check_dependencies()

    if missing:
        print("\nERROR: Missing required dependencies!")
        print(f"Cannot find: {', '.join(missing)}")
        print(
            "\nTo enter the Matrix, install dependencies using pip OR Poetry:")
        print("-" * 55)
        print("Using pip:")
        print("  pip install -r requirements.txt")
        print("  python loading.py")
        print("-" * 55)
        print("Using Poetry:")
        print("  poetry install")
        print("  poetry run python loading.py")
        sys.exit(1)

    run_matrix_analysis()


if __name__ == "__main__":
    main()
