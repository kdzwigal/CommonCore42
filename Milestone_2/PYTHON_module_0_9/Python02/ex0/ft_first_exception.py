#!/usr/bin/env python3
def input_temperature(temp_str: str) -> int:
    return int(temp_str)


def test_temperature(data: str) -> None:

    print(f"Input data is '{data}'")
    try:
        temp = input_temperature(data)
        print(f"Temperature is now {temp}°C\n")
    except ValueError as e:
        print(f"Caught input_temperature error: {e}\n")


def main() -> None:
    print("=== Garden Temperature ===\n")
    test_temperature("25")
    test_temperature("abc")
    print("All tests completed - program didn't crash!")


if __name__ == "__main__":
    main()
