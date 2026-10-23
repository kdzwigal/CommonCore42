import sys
import importlib

REQUIRED_PACKAGES = {
    'pandas': 'Data manipulation ready',
    'numpy': 'Numerical computation ready',
    'matplotlib': 'Visualization ready'
}


def check_dependencies() -> list[str]:
    print("LOADING STATUS: Loading programs...")
    print("Checking dependencies:")

    missing_packages: List[str] = []

    for pkg, description in REQUIRED_PACKAGES.items():
        try:
            module = importlib.import_module(pkg)
            version = getattr(module, '__version__', 'unknown')
            print(f"[OK] {pkg} ({version}) - {description}")
        except ImportError:
            missing_packages.append(pkg)

    return missing_packages


def run_matrix_analysis() -> None:
    import numpy as np
    import pandas as pd
    import matplotlib.pyplot as plt

    print("Analyzing Matrix data...")
    num_points = 1000
    print(f"Processing {num_points} data points...")

    time_index = np.linspace(0, 100, num_points)
    signal_noise = np.random.normal(0, 0.5, num_points)
    signal = np.sin(time_index) + signal_noise

    df = pd.DataFrame({'Time': time_index, 'Signal': signal})

    df['Clean_Signal'] = df['Signal'].rolling(window=15).mean()

    print("Generating visualization...")

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
        print("-" * 80)
        print("Using pip:")
        print("  pip install -r requirements.txt")
        print("  python3 loading.py")
        print("-" * 80)
        print("Using Poetry:")
        print("  poetry install --no-root")
        print("  poetry run python3 loading.py")
        sys.exit(1)

    run_matrix_analysis()


if __name__ == "__main__":
    main()
