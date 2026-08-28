#!/usr/bin/env python3
import sys
import typing


def add_hash_and_save(file: typing.IO[str]) -> None:
    tekst = file.read()
    print("Transform data:")
    print("---\n")
    hashed_lines = [line + "#" for line in tekst.splitlines()]
    new_tekst = "\n".join(hashed_lines)
    for line in new_tekst.splitlines():
        print(line)
    print("\n---")
    new_file = str(input("Enter new file name (or empty): "))
    if new_file == "":
        print("Not saving data.")
        return
    elif new_file:
        print(f"Saving data to '{new_file}'")
        with open(new_file, "w") as file:
            file.write(new_tekst)
            print(f"Data saved in file '{new_file}'.")


def read_and_print(file: typing.IO[str]) -> None:
    tekst = file.read()
    for line in tekst.splitlines():
        print(line)


def op_file(name: str) -> None:
    print("=== Cyber Archives Recovery ===")
    print(f"Accessing file '{name}'")
    try:
        file = open(name, "r")
    except FileNotFoundError as e:
        print(f"Error opening file '{name}': {e}")
        file = None
    if file is not None:
        print("---\n")
        read_and_print(file)
        print("\n---")
        file.close()
        print(f"File '{name}' closed.\n")
        file = open(name, "r")
        add_hash_and_save(file)


def main() -> None:
    arguments = len(sys.argv)
    if arguments == 1 or arguments > 2:
        print("Usage: ft_ancient_text.py <file>")
    elif arguments == 2:
        op_file(sys.argv[1])
    sys.exit(0)


if __name__ == "__main__":
    main()
