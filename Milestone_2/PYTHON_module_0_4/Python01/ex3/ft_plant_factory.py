#!/usr/bin/env python3
class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age

    def show(self):
        print(f"Created: {self.name.capitalize()}: "
              f"{self.height:.1f}cm, {self.age:} days old")


def main() -> None:
    print("=== Plant Factory Output ===")
    Plant("rose", 60, 2).show()
    Plant("sunflower", 80, 45).show()
    Plant("cactus", 15, 120).show()
    Plant("tree", 30, 10).show()
    Plant("grass", 30, 10).show()


if __name__ == '__main__':
    main()
