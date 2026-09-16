import sys
import os
import site


def main():
    is_venv = sys.prefix != sys.base_prefix

    if is_venv:
        venv_name = os.path.basename(sys.prefix)

        print("MATRIX STATUS: Welcome to the construct\n")
        print(f"Current Python: {sys.executable}")
        print(f"Virtual Environment: {venv_name}")
        print(f"Environment Path: {sys.prefix}\n")
        print("SUCCESS: You're in an isolated environment!")
        print("Safe to install packages without affecting the "
              "global system.\n")
        print("Package installation path:")

        site_packages = ""
        if hasattr(site, 'getsitepackages'):
            paths = site.getsitepackages()
            for p in paths:
                if 'site-packages' in p:
                    site_packages = p
                    break
            if not site_packages and paths:
                site_packages = paths[0]

        print(site_packages)

    else:
        print("MATRIX STATUS: You're still plugged in\n")
        print(f"Current Python: {sys.executable}")
        print("Virtual Environment: None detected\n")
        print("WARNING: You're in the global environment!")
        print("The machines can see everything you install.\n")
        print("To enter the construct, run:")
        print("python -m venv matrix_env")
        print("source matrix_env/bin/activate # On Unix")
        print("matrix_env\\Scripts\\activate # On Windows")
        print("Then run this program again.")


if __name__ == "__main__":
    main()
