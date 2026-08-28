#!/usr/bin/env python3
import sys
import typing


def add_hash_and_save(file: typing.IO[str]) -> None:
    hashed_lines = []
    while True:
        line = file.readline()
        if not line:
            break
        hashed_lines.append(line.rstrip('\n') + "#")
    print("Transform data:")
    print("---\n")
    new_tekst = "\n".join(hashed_lines)
    for line in new_tekst.splitlines():
        print(line)
    print("\n---")
    print("Enter new file name (or empty): ", end="", flush=True)
    new_file = sys.stdin.readline().rstrip('\n')

    if new_file == "":
        print("Not saving data.")
        return
    elif new_file:
        print(f"Saving data to '{new_file}'")
        try:
            with open(new_file, "w") as file:
                file.write(new_tekst)
                print(f"Data saved in file '{new_file}'.")
        except OSError as e:
            print(f"[STDERR] Error opening file '{new_file}': {e}",
                  file=sys.stderr)


def read_and_print(file: typing.IO[str]) -> None:
    print("---\n")
    while True:
        line = file.readline()
        if not line:
            break
        print(line, end="")
    print("\n\n---")


def op_file(name: str) -> None:
    print("=== Cyber Archives Recovery ===")
    print(f"Accessing file '{name}'")
    try:
        with open(name, "r") as file:
            read_and_print(file)
        print(f"File '{name}' closed.\n")
    except OSError as e:
        print(f"[STDERR] Error opening file '{name}': {e}", file=sys.stderr)
        return

    try:
        with open(name, "r") as file:
            add_hash_and_save(file)
    except OSError as e:
        print(f"[STDERR] Error opening file '{name}': {e}", file=sys.stderr)


def main() -> None:
    arguments = len(sys.argv)
    if arguments == 1 or arguments > 2:
        print("Usage: ft_ancient_text.py <file>")
    elif arguments == 2:
        op_file(sys.argv[1])
    sys.exit(0)


if __name__ == "__main__":
    main()
