import os
import site
import sys


def get_package_path() -> str:
    """Safely retrieves the site-packages installation path."""
    try:
        if hasattr(site, "getsitepackages"):
            paths: list[str] = site.getsitepackages()
            for path in paths:
                if "site-packages" in path:
                    return path
            if paths:
                return paths[0]
    except Exception as err:
        return f"Unavailable ({err})"
    return "Unknown"


def main() -> None:
    is_venv: bool = sys.prefix != sys.base_prefix

    if is_venv:
        venv_name: str = os.path.basename(sys.prefix)
        pkg_path: str = get_package_path()

        print("MATRIX STATUS: Welcome to the construct\n")
        print(f"Current Python: {sys.executable}")
        print(f"Virtual Environment: {venv_name}")
        print(f"Environment Path: {sys.prefix}\n")
        print("SUCCESS: You're in an isolated environment!")
        print("Safe to install packages without affecting")
        print("the global system.\n")
        print("Package installation path:")
        print(pkg_path)
    else:
        print("MATRIX STATUS: You're still plugged in\n")
        print(f"Current Python: {sys.executable}")
        print("Virtual Environment: None detected\n")
        print("WARNING: You're in the global environment!")
        print("The machines can see everything you install.\n")
        print("To enter the construct, run:")
        print("python -m venv matrix_env")
        print("source matrix_env/bin/activate # On Unix")
        print("matrix_env\\Scripts\\activate # On Windows\n")
        print("Then run this program again.")


if __name__ == "__main__":
    main()
