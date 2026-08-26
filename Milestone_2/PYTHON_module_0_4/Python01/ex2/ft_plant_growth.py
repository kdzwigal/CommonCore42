#!/usr/bin/env python3
class Plant:

    def __init__(self, name: str, height: float, plant_age: int) -> None:
        self.name = name
        self.height = height
        self.plant_age = plant_age
        self.init_height = height

    def show(self):
        print(f"{self.name.capitalize()}: "
              f"{self.height:.1f}cm, {self.plant_age} days old")

    def age(self):
        self.plant_age += 1

    def grow(self):
        print(f"=== Day {i} ===")
        self.height += (self.height / self.plant_age)
        self.height = round(self.height, 1)
        self.age()
        self.show()


def main() -> None:
    rose = Plant("Rose", 25, 30)
    for i in range(0, 8):
        if i == 0:
            print("=== Garden Plant growth ===")
            rose.show()
        else:
            rose.grow()
    print(f"Growth this week: {(rose.height - rose.init_height):.1f}cm")


if __name__ == '__main__':
    main()
