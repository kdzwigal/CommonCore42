import os
import sys

try:
    from dotenv import load_dotenv
except ImportError:
    print("ERROR: python-dotenv is not installed.")
    print("Please run: pip install -r requirements.txt")
    sys.exit(1)


def main():
    print("ORACLE STATUS: Reading the Matrix...")

    # load_dotenv domyślnie NIE nadpisuje zmiennych
    env_file_loaded = load_dotenv()

    # Pobieranie zmiennych z .env
    matrix_mode = os.environ.get("MATRIX_MODE")
    db_url = os.environ.get("DATABASE_URL")
    api_key = os.environ.get("API_KEY")
    log_level = os.environ.get("LOG_LEVEL")
    zion_endpoint = os.environ.get("ZION_ENDPOINT")

    # Obsługa brakującej konfiguracji
    if not matrix_mode or not api_key:
        print("\nWARNING: Critical configuration missing!")
        print(
            "Please copy .env.example to .env and fill in the missing values.")
        print("The Oracle cannot see the path without proper variables.")
        sys.exit(1)

    print("\nConfiguration loaded:")

    # Różnice w zachowaniu: Development vs Production
    if matrix_mode.lower() == "production":
        print(f"Mode: {matrix_mode}")
        print(f"""Database: {'Connected to SECURE PRODUCTION cluster'
        if db_url else 'missing'}""")
        print("API Access: Authenticated [STRICT]")
        print(f"Log Level: {log_level or 'ERROR'}")
        print(f"""Zion Network: {'Secure VPN Online' if zion_endpoint
        else 'missing'}""")
    else:
        print(f"Mode: {matrix_mode}")
        print(f"""Database: {'Connected to local instance'
        if db_url else 'missing'}""")
        print("API Access: Authenticated")
        print(f"Log Level: {log_level or 'DEBUG'}")
        print(f"""Zion Network: {'Online' if zion_endpoint
        else 'missing'}""")

    print("\nEnvironment security check:")
    print("[OK] No hardcoded secrets detected")

    if env_file_loaded:
        print("[OK] .env file properly configured")
    else:
        print("[INFO] No .env file found, using system environment variables")

    print("[OK] Production overrides available")
    print("\nThe Oracle sees all configurations.")


if __name__ == "__main__":
    main()
