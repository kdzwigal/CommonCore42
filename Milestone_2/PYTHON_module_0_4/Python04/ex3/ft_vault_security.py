#!/usr/bin/env python3
import sys


def secure_archive(file_name: str, opt: str, to_write: str) \
        -> tuple[bool, str]:

    if opt.lower() == "write":
        try:
            with open(file_name, "x") as file:
                print("Using 'secure_archive' to write previous content to "
                      "a new file:")
                file.write(to_write)
                t_send = (True, "'Content successfully written to file'")
                return t_send
        except FileExistsError as e:
            print("Using 'secure_archive' to write an existing file:")
            return False, str(e)
        except OSError as e:
            f_send = (False, str(e))
            return f_send
    else:
        try:
            with open(file_name, "r") as file:
                print("Using 'secure_archive' to read from a regular file:")
                text: str = file.read()
                t_send = (True, text)
                return t_send
        except IsADirectoryError as e:
            print("Using 'secure_archive' to read from a directory:")
            return False, str(e)
        except FileNotFoundError as e:
            print("Using 'secure_archive' to read from a nonexistent file:")
            return False, str(e)
        except PermissionError as e:
            print("Using 'secure_archive' to read from an inaccessible file:")
            return False, str(e)
        except OSError as e:
            print("Using 'secure_archive' with Error:")
            return False, str(e)


def archive_test() -> None:
    print("=== Cyber Archives Security ===\n")
    print(secure_archive("/not/existing/file", "read", ""))
    print("")
    print(secure_archive("nonaccess", "read", ""))
    print("")
    print(secure_archive("test", "read", ""))
    print("")
    print(secure_archive("test1.txt", "write", "Lorem ipsum..."))


def main() -> None:
    arguments = len(sys.argv)
    if arguments == 1:
        archive_test()
    elif arguments == 2:
        status = secure_archive(sys.argv[1], "read", "")
        print(status)
    elif arguments == 3:
        status = secure_archive(sys.argv[1], sys.argv[2], "")
        print(status)
    elif arguments == 4:
        status = secure_archive(sys.argv[1], sys.argv[2], sys.argv[3])
        print(status)
    else:
        print("Too much arguments! Usage: ft_vault.py <file> "
              "<read/write> <if write: string to write>")

    sys.exit(0)


if __name__ == "__main__":
    main()