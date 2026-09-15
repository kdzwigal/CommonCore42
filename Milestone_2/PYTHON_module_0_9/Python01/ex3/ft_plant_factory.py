#!/usr/bin/env python3
class Plant:
    plants: list['Plant'] = []

    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age

        Plant.plants.append(self)

    def show(self) -> None:
        print(f"{self.name.capitalize()}: {round(self.height, 1)}cm, "
              f"{self.age} days old")


def main() -> None:

    Plant("rose", 60.0, 2)
    Plant("sunflower", 80.0, 45)
    Plant("cactus", 15.0, 120)
    Plant("tree", 30.0, 10)
    Plant("grass", 30.0, 10)

    print("=== Plant Factory Output ===")
    for plant in Plant.plants:
        print("Created: ", end='')
        plant.show()


if __name__ == '__main__':
    main()
