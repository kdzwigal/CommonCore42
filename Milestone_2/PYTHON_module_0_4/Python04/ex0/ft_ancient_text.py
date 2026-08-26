#!/usr/bin/env python3
import sys
import typing


def read_and_print(file: typing.IO) -> None:
    for line in file:
        print(line.rstrip())

def op_file(name: str) -> None:
    print("=== Cyber Archives Recover ===")
    print(f"Accessing file '{name}'")
    file = open(name, "r")
    read_and_print(file)



def main():
    arguments = len(sys.argv)
    if arguments == 1 or arguments > 2:
        print("Usage: ft_ancient_text.py <file>")
    elif arguments == 2:
        op_file(sys.argv[1])


if __name__ == "__main__":
    main()