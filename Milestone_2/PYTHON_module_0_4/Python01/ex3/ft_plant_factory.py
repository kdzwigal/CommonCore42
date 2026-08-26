#!/usr/bin/env python3
class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age
        print(f"Created: {name.capitalize()}: {height:.1f}cm, {age:} days old")

    def show(self):
        print(f"{self.name.capitalize()}: "
              f"{self.height:.1f}cm, {self.age} days old")


if __name__ == '__main__':
    print("=== Plant Factory Output ===")
    rose = Plant("Rose", 60, 2)
    sunflower = Plant("Sunflower", 80, 45)
    cactus = Plant("Cactus", 15, 120)
    tree = Plant("Tree", 30, 10)
    grass = Plant("Grass", 30, 10)
