#!/usr/bin/env python3
class Plant:
    class _Stats:
        def __init__(self) -> None:
            self._grow_calls = 0
            self._age_calls = 0
            self._show_calls = 0

        def add_grow(self) -> None: self._grow_calls += 1
        def add_age(self) -> None: self._age_calls += 1
        def add_show(self) -> None: self._show_calls += 1

        def display(self) -> None:
            print(f"Stats: {self._grow_calls} grow, {self._age_calls} age, "
                  f"{self._show_calls} show")

    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self._height = height
        self._plant_age = age
        self.stats = self._Stats()

    def show(self) -> None:
        self.stats.add_show()
        print(f"{self.name.capitalize()}: "
              f"{self._height:.1f}cm, {self._plant_age} days old")

    def grow(self, amount: float) -> None:
        self._height += amount
        self.stats.add_grow()

    def age(self, days: int) -> None:
        self._plant_age += days
        self.stats.add_age()

    def display_stats(self) -> None:
        self.stats.display()

    @staticmethod
    def year_old(days: int) -> None:
        print(f" Is {days} days more than a year? -> ", end="")
        if days <= 365:
            print("False")
        else:
            print("True")

    @classmethod
    def create_anonymous(cls) -> 'Plant':
        return cls("unknown plant", 0.0, 0)


class Flower(Plant):
    def __init__(self, name: str, height: float, age: int, color: str) -> None:
        super().__init__(name, height, age)
        self.color = color
        self.blooming = False

    def bloom(self) -> None:
        if not isinstance(self, Seed):
            print(f"[asking the {self.name} to grow and bloom]")
            self.stats.add_grow()
            self._height += 8
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
        day_grow: float = 0
        for i in range(0, days):
            day_grow += round((self._height / self._plant_age), 1)
        self.grow(day_grow)
        self.age(days)
        self.bloom()
        self.seeds += 42


class Tree(Plant):
    class _TreeStats(Plant._Stats):
        def __init__(self) -> None:
            super().__init__()
            self._shade_calls = 0

        def add_shade(self) -> None:
            self._shade_calls += 1

        def display(self) -> None:
            super().display()
            print(f"{self._shade_calls} shade")

    def __init__(self, name: str, height: float, age: int,
                 trunk_diameter: float) -> None:
        super().__init__(name, height, age)
        self.trunk_diameter = trunk_diameter
        self.stats = self._TreeStats()

    def produce_shade(self) -> None:
        if isinstance(self.stats, Tree._TreeStats):
            self.stats.add_shade()
        print(f"[asking the {self.name} to produce shade]")
        print(f"Tree {self.name.capitalize()} now produces a shade of "
              f"{self._height:.1f}cm long and "
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

    def age(self, days: int) -> None:
        super().age(days)
        self.nutritional_value += 1

    def grow(self, amount: float) -> None:
        super().grow(amount)


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
    print(f"=== {rose.__class__.__name__}")
    rose.show()
    display_plant_statistics(rose)
    rose.bloom()
    rose.show()
    display_plant_statistics(rose)
    print("")

    oak = Tree("oak", 250, 10, 6)
    print(f"=== {oak.__class__.__name__}")
    oak.show()
    display_plant_statistics(oak)
    oak.produce_shade()
    display_plant_statistics(oak)
    print("")

    sunflower = Seed("sunflower", 80, 45, "yellow")
    print(f"=== {sunflower.__class__.__name__}")
    sunflower.show()
    sunflower.grow_seeds(20)
    sunflower.show()
    display_plant_statistics(sunflower)
    print("")

    anonymous = Plant.create_anonymous()
    print("=== Anonymous")
    anonymous.show()
    display_plant_statistics(anonymous)
    print("")


if __name__ == '__main__':
    main()
