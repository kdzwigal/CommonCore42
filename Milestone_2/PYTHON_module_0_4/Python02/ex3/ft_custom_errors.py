#!/usr/bin/env python3
class GardenError(Exception):
    def __init__(self, message: str = "Unknown garden error") -> None:
        Exception.__init__(self, message)


class PlantError(GardenError):
    def __init__(self, message: str = "Unknown plant error") -> None:
        GardenError.__init__(self, message)


class WaterError(GardenError):
    def __init__(self, message: str = "Unknown water error") -> None:
        GardenError.__init__(self, message)


def raise_plant_issue() -> None:
    raise PlantError("The tomato plant is wilting!")


def raise_water_issue() -> None:
    raise WaterError("Not enough water in the tank!")


def test_custom_errors() -> None:
    print("=== Custom Garden Errors Demo ===")

    print("\nTesting PlantError...")
    try:
        raise_plant_issue()
    except PlantError as e:
        print(f"Caught PlantError: {e}")

    print("\nTesting WaterError...")
    try:
        raise_water_issue()
    except WaterError as e:
        print(f"Caught WaterError: {e}")

    print("\nTesting catching all garden errors...")
    try:
        raise_plant_issue()
    except GardenError as e:
        print(f"Caught GardenError: {e}")

    try:
        raise_water_issue()
    except GardenError as e:
        print(f"Caught GardenError: {e}")


if __name__ == "__main__":
    test_custom_errors()
    print("\nAll custom error types work correctly!")
