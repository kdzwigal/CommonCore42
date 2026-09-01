#!/usr/bin/env python3
class Plant:

    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self.height = height
        self.plant_age = age

    def show(self) -> None:
        print(f"{self.name.capitalize()}: "
              f"{self.height:.1f}cm, {self.plant_age} days old")


class Flower(Plant):
    def __init__(self, name: str, height: float, age: int, color: str) -> None:
        super().__init__(name, height, age)
        self.color = color
        self.blooming = False

    def bloom(self) -> None:
        print(f"[asking the {self.name} to bloom]")
        self.blooming = True

    def show(self) -> None:
        super().show()
        print(f" Color: {self.color}")
        if self.blooming:
            print(" Rose is blooming beautifully!")
        else:
            print(" Rose has not bloomed yet")


class Tree(Plant):
    def __init__(self, name: str, height: float, age: int,
                 trunk_diameter: float) -> None:
        super().__init__(name, height, age)
        self.trunk_diameter = trunk_diameter

    def shade(self) -> None:
        print(f"[asking the {self.name} to produce shade]")
        print(f"Tree {self.name.capitalize()} now produces a shade of "
              f"{self.height:.1f}cm long and "
              f"{self.trunk_diameter:.1f}cm wide.")

    def show(self) -> None:
        super().show()
        print(f" Trunk diameter: {self.trunk_diameter:.1f}cm")


class Vegetable(Plant):
    def __init__(self, name: str, height: float, age: int,
                 harvest_season: str) -> None:
        super().__init__(name, height, age)
        self.nutritional_value = 0
        self.harvest_season = harvest_season

    def show(self) -> None:
        super().show()
        print(f" Harvest season: {self.harvest_season.capitalize()}")
        print(f" Nutritional value: {self.nutritional_value}")

    def age(self) -> None:
        self.plant_age += 1
        self.nutritional_value += 1

    def grow(self, days: int) -> None:
        print(f"[make {self.name} grow and age for {days} days]")
        for i in range(0, days):
            self.height += (self.height / self.plant_age)
            self.height += round(self.height, 1)
            self.age()


def main() -> None:
    print("=== Garden Plant Types ===")
    rose = Flower("rose", 15, 10, "red")
    print(f"=== {rose.__class__.__name__}")
    rose.show()
    rose.bloom()
    rose.show()
    print("")
    oak = Tree("oak", 250, 10, 6)
    print(f"=== {oak.__class__.__name__}")
    oak.show()
    oak.shade()
    print("")
    tomato = Vegetable("tomato", 5, 10, "april")
    print(f"=== {tomato.__class__.__name__}")
    tomato.show()
    tomato.grow(20)
    tomato.show()
    print("")


if __name__ == '__main__':
    main()
