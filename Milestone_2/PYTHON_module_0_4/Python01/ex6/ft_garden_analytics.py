#!/usr/bin/env python3
class Plant:
    class Stats:
        def __init__(self) -> None:
            self.grow_calls = 0
            self.age_calls = 0
            self.show_calls = 0
            self.produce_shade_calls = 0

        def display(self) -> None:
            print(f"Stats: {self.grow_calls} grow, {self.age_calls} age, "
                  f"{self.show_calls} show")
            if self.produce_shade_calls > 0:
                print(f" {self.produce_shade_calls} shade")

    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self.height = height
        self.plant_age = age
        self.stats = self.Stats()

    def show(self) -> None:
        self.stats.show_calls += 1
        print(f"{self.name.capitalize()}: "
              f"{self.height:.1f}cm, {self.plant_age} days old")

    @staticmethod
    def year_old(days: int) -> None:
        print(f" Is {days} days more than a year? -> ", end="")
        if days <= 365:
            print("False")
        else:
            print("True")

    @classmethod
    def anonymous(cls) -> 'Plant':
        return cls("unknown plant", 0, 0)


class Flower(Plant):
    def __init__(self, name: str, height: float, age: int, color: str) -> None:
        super().__init__(name, height, age)
        self.color = color
        self.blooming = False

    def bloom(self) -> None:
        if not isinstance(self, Seed):
            print(f"[asking the {self.name} to grow and bloom]")
            self.stats.grow_calls += 1
            self.height += 8
        self.blooming = True

    def show(self) -> None:
        super().show()
        print(f" Color: {self.color}")
        if self.blooming:
            print(f" {self.name.capitalize()} is blooming beautifully!")
        else:
            print(f" {self.name.capitalize()} has not bloomed yet")


class Seed(Flower):
    def __init__(self, name: str, height: float, age: int, color: str) -> None:
        super().__init__(name, height, age, color)
        self.seeds = 0

    def show(self) -> None:
        super().show()
        print(f" Seeds: {self.seeds}")

    def grow_seeds(self, days: int) -> None:
        print(f"[make {self.name} grow, age and bloom]")
        self.stats.grow_calls += 1
        self.stats.age_calls += 1
        for i in range(0, days):
            self.height += (self.height / self.plant_age)
            self.height = round(self.height, 1)
            self.plant_age += 1
        self.bloom()
        self.seeds += 42


class Tree(Plant):
    def __init__(self, name: str, height: float, age: int,
                 trunk_diameter: float) -> None:
        super().__init__(name, height, age)
        self.trunk_diameter = trunk_diameter
        self.stat_shade = 0

    def produce_shade(self) -> None:
        self.stat_shade += 1
        self.stats.produce_shade_calls += 1
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
        self.stats.age_calls += 1

    def grow(self, days: int) -> None:
        print(f"[make {self.name} grow and age for {days} days]")
        self.stats.grow_calls += 1
        for i in range(0, days):
            self.height += (self.height / self.plant_age)
            self.height = round(self.height, 1)
            self.age()


def display_plant_statistics(plant: Plant) -> None:
    print(f"[statistics for {plant.name.capitalize()}]")
    plant.stats.display()


def main() -> None:
    print("=== Garden statistics ===")

    print("=== Check year-old")
    Plant.year_old(40)
    Plant.year_old(400)
    print("")

    rose = Flower("rose", 15, 10, "red")
    print("=== Flower")
    rose.show()
    display_plant_statistics(rose)
    rose.bloom()
    rose.show()
    display_plant_statistics(rose)
    print("")

    oak = Tree("oak", 250, 10, 6)
    print("=== Tree")
    oak.show()
    display_plant_statistics(oak)
    oak.produce_shade()
    display_plant_statistics(oak)
    print("")

    sunflower = Seed("sunflower", 80, 45, "yellow")
    print("=== Seed")
    sunflower.show()
    sunflower.grow_seeds(20)
    sunflower.show()
    display_plant_statistics(sunflower)
    print("")

    anonymous = Plant.anonymous()
    print("=== Anonymous")
    anonymous.show()
    display_plant_statistics(anonymous)
    print("")


if __name__ == '__main__':
    main()
