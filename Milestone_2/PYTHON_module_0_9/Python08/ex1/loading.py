import sys
import importlib

REQUIRED_PACKAGES: dict[str, str] = {
    'pandas': 'Data manipulation ready',
    'numpy': 'Numerical computation ready',
    'matplotlib': 'Visualization ready'
}


def check_dependencies() -> list[str]:
    print("\n\nLOADING STATUS: Loading programs...")
    print("Checking dependencies:")

    missing_packages: list[str] = []

    for pkg, description in REQUIRED_PACKAGES.items():
        try:
            module = importlib.import_module(pkg)
            version: str = getattr(module, '__version__', 'unknown')
            print(f"[OK] {pkg} ({version}) - {description}")
        except ImportError:
            print(f"[MISSING] {pkg} - Not installed")
            missing_packages.append(pkg)

    return missing_packages


def show_package_manager_comparison() -> None:
    print("\n\nDependency Management Comparison:")
    print("  pip    : Uses requirements.txt, installs into active env.")
    print("  Poetry : Uses pyproject.toml & poetry.lock, manages venv")
    print("           automatically and guarantees deterministic builds.\n\n")


def run_matrix_analysis() -> None:
    np = importlib.import_module("numpy")
    pd = importlib.import_module("pandas")
    plt = importlib.import_module("matplotlib.pyplot")

    print("Analyzing Matrix data...")
    num_points: int = 1000
    print(f"Processing {num_points} data points...")

    try:
        time_index = np.linspace(0, 100, num_points)
        signal_noise = np.random.normal(0, 0.5, num_points)
        signal = np.sin(time_index) + signal_noise

        df = pd.DataFrame({'Time': time_index, 'Signal': signal})

        df['Clean_Signal'] = df['Signal'].rolling(window=15).mean()

        print("Generating visualization...")

        plt.figure(figsize=(10, 6))
        plt.plot(
            df['Time'],
            df['Signal'],
            color='gray',
            alpha=0.3,
            label='Raw Data Stream'
        )
        plt.plot(
            df['Time'],
            df['Clean_Signal'],
            color='green',
            linewidth=2,
            label='Decoded Signal'
        )
        plt.title('Matrix Data Stream Analysis')
        plt.xlabel('Time (ms)')
        plt.ylabel('Signal Strength')
        plt.legend()
        plt.grid(True, linestyle='--', alpha=0.7)

        output_filename: str = 'matrix_analysis.png'
        plt.savefig(output_filename)
        plt.close()

        print("Analysis complete!")
        print(f"Results saved to: {output_filename}")

    except Exception as err:
        print(f"ERROR: Data stream corruption detected: {err}",
              file=sys.stderr)
        sys.exit(1)


def main() -> None:
    missing: list[str] = check_dependencies()

    show_package_manager_comparison()

    if missing:
        print("\nERROR: Missing required dependencies!")
        print(f"Cannot find: {', '.join(missing)}")
        print(
            "\nTo enter the Matrix, install dependencies using pip OR Poetry:")
        print("-" * 60)
        print("Using pip:")
        print("  pip install -r requirements.txt")
        print("  python3 loading.py")
        print("-" * 60)
        print("Using Poetry:")
        print("  poetry install --no-root")
        print("  poetry run python3 loading.py")
        sys.exit(1)

    run_matrix_analysis()


if __name__ == "__main__":
    main()
