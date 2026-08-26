#!/usr/bin/env python3
import sys
if __name__ == "__main__":
    print("=== Command Quest ===")
    print(f"Program name: {sys.argv[0]}")
    arguments = len(sys.argv)
    if arguments == 1:
        print("No arguments provided!")
    if arguments > 1:
        print(f"Arguments received: {arguments - 1}")
    i = 1
    while i < arguments:
        print(f"Argument {i}: {sys.argv[i]}")
        i += 1
    print(f"Total arguments: {arguments}\n")
