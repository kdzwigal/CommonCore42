from ex0 import AquaFactory, CreatureFactory, FlameFactory

def test_factory(factory: CreatureFactory) -> None:

    print("\nTesting factory")

    base_creature = factory.create_base()
    print(base_creature.describe())
    print(base_creature.attack())

    evolved_creature = factory.create_evolved()
    print(evolved_creature.describe())
    print(evolved_creature.attack())

def test_battle(factory1: CreatureFactory, factory2: CreatureFactory) -> None:

    print("\nTesting battle")
    fighter1 = factory1.create_base()
    fighter2 = factory2.create_base()

    print(f"{fighter1.describe()}\n vs. \n{fighter2.describe()}\n fight!")
    print(fighter1.attack())
    print(fighter2.attack())

def main() -> None:

    flame_factory = FlameFactory()
    aqua_factory = AquaFactory()

    test_factory(flame_factory)
    test_factory(aqua_factory)

    test_battle(flame_factory, aqua_factory)

if __name__ == "__main__":
    main()