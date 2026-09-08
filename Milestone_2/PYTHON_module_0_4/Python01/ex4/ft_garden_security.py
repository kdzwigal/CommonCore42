#!/usr/bin/env python3
class Plant:

    def __init__(self, name: str, height: float, age: int) -> None:
        self._name = name

        if height >= 0:
            self._height = float(height)
        else:
            self._height = 0.0
            print("Error, height can't be negative")

        if age >= 0:
            self._age = int(age)
        else:
            self._age = 0
            print("Error, age can't be negative")

    def show(self) -> None:
        print(f"{self._name.capitalize()}: "
              f"{round(self.get_height(), 1)}cm, {self.get_age()} days old")

    def get_height(self) -> float:
        return self._height

    def set_height(self, height: float) -> None:
        if height >= 0:
            self._height = float(height)
            print(f"Height updated: {self._height}cm")
        else:
            print(f"{self._name.capitalize()}: Error, height can't be "
                  f"negative")
            print("Height update rejected")

    def get_age(self) -> int:
        return self._age

    def set_age(self, age: int) -> None:
        if age >= 0:
            self._age = int(age)
            print(f"Age updated: {self._age} days")
        else:
            print(f"{self._name.capitalize()}: Error, age can't be negative")
            print("Age update rejected")


def main() -> None:
    print("=== Garden Security System ===")
    rose = Plant("Rose", 15, 10)

    print("Plant created: ", end="")
    rose.show()
    print("")
    rose.set_height(25.0)
    rose.set_age(30)
    print("")
    rose.set_height(-10.0)
    rose.set_age(-5)
    print("")
    print("Current state: ", end="")
    rose.show()


if __name__ == '__main__':
    main()
