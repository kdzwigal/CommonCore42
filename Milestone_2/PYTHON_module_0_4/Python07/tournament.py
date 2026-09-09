import typing

from ex0 import AquaFactory, CreatureFactory, FlameFactory
from ex1 import HealingCreatureFactory, TransformCreatureFactory
from ex2 import (
    AggressiveStrategy,
    BattleStrategy,
    DefensiveStrategy,
    InvalidStrategyError,
    NormalStrategy,
)

Opponent = tuple[CreatureFactory, BattleStrategy]


def run_tournament(opponents: list[Opponent]) -> None:
    print("*** Tournament ***")
    print(f"{len(opponents)} opponents involved")

    try:
        for i in range(len(opponents)):
            for j in range(i + 1, len(opponents)):
                print("\n* Battle *")

                factory1, strategy1 = opponents[i]
                factory2, strategy2 = opponents[j]

                fighter1 = factory1.create_base()
                fighter2 = factory2.create_base()

                print(fighter1.describe())
                print(" vs.")
                print(fighter2.describe())
                print(" now fight!")

                strategy1.act(fighter1)
                strategy2.act(fighter2)

    except InvalidStrategyError as e:
        print(f"Battle error, aborting tournament: {e}")


def main() -> None:

    flame_factory = FlameFactory()
    aqua_factory = AquaFactory()
    healing_factory = HealingCreatureFactory()
    transform_factory = TransformCreatureFactory()

    normal_strat = NormalStrategy()
    aggressive_strat = AggressiveStrategy()
    defensive_strat = DefensiveStrategy()

    print("Tournament 0 (basic)")
    print(" [ (Flameling+Normal), (Healing+Defensive) ]")
    run_tournament([
        (flame_factory, normal_strat),
        (healing_factory, defensive_strat)
    ])

    print("Tournament 1 (error)")
    print(" [ (Flameling+Aggressive), (Healing+Defensive) ]")
    run_tournament([
        (flame_factory, aggressive_strat),
        (healing_factory, defensive_strat)
    ])

    print("Tournament 2 (multiple)")
    print(" [ (Aquabub+Normal), (Healing+Defensive), (Transform+Aggressive) ]")
    run_tournament([
        (aqua_factory, normal_strat),
        (healing_factory, defensive_strat),
        (transform_factory, aggressive_strat)
    ])


if __name__ == "__main__":
    main()