#!/usr/bin/env python3
def input_temperature(temp_str: str) -> int:
    return int(temp_str)


def test_temperature() -> None:
    data = "25"
    print(f"Input data is '{data}'")
    try:
        temp = input_temperature(data)
        print(f"Temperature is now {temp}°C\n")
    except ValueError as e:
        print(f"Caught input_temperature error: {e}\n")

    data = "abc"
    print(f"Input data is '{data}'")
    try:
        temp = input_temperature(data)
        print(f"Temperature is now {temp}°C\n")
    except ValueError as e:
        print(f"Caught input_temperature error: {e}\n")


if __name__ == "__main__":
    print("=== Garden Temperature ===\n")
    test_temperature()
    print("All tests completed - program didn't crash!")
