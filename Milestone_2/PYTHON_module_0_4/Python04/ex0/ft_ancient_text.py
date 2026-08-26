#!/usr/bin/env python3
import sys
import typing


def read_and_print(file: typing.IO) -> None:
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
        print(f"File '{name}' closed.")


def main() -> None:
    arguments = len(sys.argv)
    if arguments == 1 or arguments > 2:
        print("Usage: ft_ancient_text.py <file>")
    elif arguments == 2:
        op_file(sys.argv[1])
    sys.exit(0)


if __name__ == "__main__":
    main()
