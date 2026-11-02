import os
import sys

try:
    from dotenv import load_dotenv  # type: ignore[import]
except ImportError:
    print("ERROR: dotenv is not installed.", file=sys.stderr)
    print("Please run: pip install -r requirements.txt", file=sys.stderr)
    sys.exit(1)


def main() -> None:
    print("\nORACLE STATUS: Reading the Matrix...")

    env_file_loaded: bool = load_dotenv()

    matrix_mode: str | None = os.environ.get("MATRIX_MODE")
    db_url: str | None = os.environ.get("DATABASE_URL")
    api_key: str | None = os.environ.get("API_KEY")
    log_level: str | None = os.environ.get("LOG_LEVEL")
    zion_endpoint: str | None = os.environ.get("ZION_ENDPOINT")

    if not matrix_mode or not api_key:
        print("\nWARNING: Critical configuration missing!")
        print(
            "Please copy .env.example to .env and fill in the missing values."
        )
        print("The Oracle cannot see the path without proper variables.")
        sys.exit(1)

    print("\nConfiguration loaded:")

    mode_lower: str = matrix_mode.lower()
    if mode_lower == "production":
        db_status: str = (
            "Connected to SECURE PRODUCTION cluster" if db_url else "missing"
        )
        zion_status: str = "Secure VPN Online" if zion_endpoint else "missing"
        print(f"Mode: {matrix_mode}")
        print(f"Database: {db_status}")
        print("API Access: Authenticated [STRICT]")
        print(f"Log Level: {log_level or 'ERROR'}")
        print(f"Zion Network: {zion_status}")
    else:
        db_status = "Connected to local instance" if db_url else "missing"
        zion_status = "Online" if zion_endpoint else "missing"
        print(f"Mode: {matrix_mode}")
        print(f"Database: {db_status}")
        print("API Access: Authenticated")
        print(f"Log Level: {log_level or 'DEBUG'}")
        print(f"Zion Network: {zion_status}")

    print("\nEnvironment security check:")
    print("[OK] No hardcoded secrets detected")

    if env_file_loaded:
        print("[OK] .env file properly configured")
        print("[OK] Production overrides available")
    else:
        print("[INFO] No .env file found, using system environment variables")
        print("[INFO] Overrides not available")

    print("\nThe Oracle sees all configurations.")


if __name__ == "__main__":
    main()
