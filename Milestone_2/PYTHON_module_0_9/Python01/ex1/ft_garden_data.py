#!/usr/bin/env python3
class Plant:

    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self.heigh = height
        self.age = age

    def show(self) -> None:
        print(f"{self.name}: {self.heigh}cm, {self.age} days old")


def main() -> None:
    print("=== Garden Plant Registry ===")
    rose = Plant("Rose", 60, 2)
    rose.show()

    sunflower = Plant("Sunflower", 80, 45)
    sunflower.show()

    cactus = Plant("Cactus", 15, 120)
    cactus.show()

    tree = Plant("Tree", 30, 10)
    tree.show()

    grass = Plant("Grass", 30, 10)
    grass.show()


if __name__ == '__main__':
    main()
