import alchemy

def main() -> None:

    print("=== Alembic 4 ===")
    print("Accessing the alchemy module using 'import alchemy'")
    print(f"Testing create_air: ", end="")
    print(alchemy.create_air())
    print("Now show that not all functions can be reached")
    print("This will raise an exception!")
    print(f"Testing the hidden create_earth: ", end="")
    try:
        print(alchemy.create_earth())
    except Exception as e:
        print({e})

if __name__ == "__main__":
    main()
