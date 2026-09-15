#!/usr/bin/env python3
class Plant:

    def __init__(self, name: str, height: float, plant_age: int) -> None:
        self.name = name
        self.height = height
        self.plant_age = plant_age
        self.init_height = height

    def show(self) -> None:
        print(f"{self.name.capitalize()}: "
              f"{round(self.height, 1)}cm, {self.plant_age} days old")

    def age(self) -> None:
        self.plant_age += 1

    def grow(self) -> None:
        self.height += (self.height / self.plant_age)
        self.height = round(self.height, 1)
        self.age()


def main() -> None:
    rose = Plant("Rose", 25.0, 30)
    for i in range(0, 8):
        if i == 0:
            print("=== Garden Plant growth ===")
            rose.show()
        else:
            print(f"=== Day {i} ===")
            rose.grow()
            rose.show()
    print(f"Growth this week: {round((rose.height - rose.init_height), 1)}cm")


if __name__ == '__main__':
    main()
