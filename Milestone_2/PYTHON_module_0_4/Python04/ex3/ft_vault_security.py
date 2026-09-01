#!/usr/bin/env python3
import sys
import typing



def secure_archive(file_name: str, opt: str, to_write: str) -> tuple[bool, str]:
    r_w:str = "r"
    if opt.lower() == "write":
        r_w: str = "w"
        try:
            with open(file_name, r_w) as file:
                text:str = file.read()
                t_send = (True, text)
                return t_send
        except OSError as e:
            f_send = (False, str(e))
            return f_send
    else:
        try:
            with open(file_name, r_w) as file:
                print(f"Using 'secure_archive' to write previous content to a new file:")
                file.write(to_write)
                t_send = (True, "'Content successfully written to file'")
                return t_send
        except OSError as e:
            f_send = (False, str(e))
            return f_send






def main() -> None:
    arguments = len(sys.argv)
    if arguments == 1 or arguments > 2:
        print("Usage: ft_ancient_text.py <file>")
    elif arguments == 2:
        status = secure_archive(sys.argv[1])
        print(status)

    sys.exit(0)


if __name__ == "__main__":
    main()