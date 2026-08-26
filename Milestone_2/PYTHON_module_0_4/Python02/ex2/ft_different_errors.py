#!/usr/bin/env python3
def garden_operations(operation_number: int) -> None:
    if operation_number == 0:
        int("abc")
    elif operation_number == 1:
        1 / 0
    elif operation_number == 2:
        open('/non/existent/file')
    elif operation_number == 3:
        "string" + 5
    else:
        return


def test_error_types():
    print("=== Garden Error Types Demo ===")
    for i in [0, 1, 2, 3, 4]:
        print(f"Testing operation {i}...")
        try:
            garden_operations(i)
        except ValueError as e:
            print(f"Caught ValueError: {e}")
        except ZeroDivisionError as e:
            print(f"Caught ZeroDivisionError: {e}")
        except FileNotFoundError as e:
            print(f"Caught FileNotFoundError: {e}")
        except TypeError as e:
            print(f"Caught TypeError: {e}")
        else:
            print("Operation completed successfully")


def test_error_types_one_try():
    print("=== Garden Error Types Demo ===")
    for i in [0, 1, 2, 3, 4]:
        print(f"Testing operation {i}...")
        try:
            garden_operations(i)
        except (ValueError, ZeroDivisionError, FileNotFoundError,
                TypeError) as e:
            print(f"Caught an error: {e}")


def main() -> None:
    test_error_types()
    print("\nAll error types tested successfully!")
    test_error_types_one_try()


if __name__ == '__main__':
    main()
