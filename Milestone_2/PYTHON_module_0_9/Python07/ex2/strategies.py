from abc import ABC, abstractmethod
import typing

from ex0.creatures import Creature


class InvalidStrategyError(Exception):
    pass


class BattleStrategy(ABC):

    @abstractmethod
    def act(self, creature: Creature) -> None:
        pass

    @abstractmethod
    def is_valid(self, creature: Creature) -> bool:
        pass


class NormalStrategy(BattleStrategy):

    def act(self, creature: Creature) -> None:
        if not self.is_valid(creature):
            raise InvalidStrategyError(f"Invalid Creature "
                                       f"'{creature.name}' "
                                       f"for this normal strategy")
        print(creature.attack())

    def is_valid(self, creature: Creature) -> bool:
        return True


class AggressiveStrategy(BattleStrategy):

    def act(self, creature: Creature) -> None:
        if not self.is_valid(creature):
            raise InvalidStrategyError(f"Invalid Creature "
                                       f"'{creature.name}' "
                                       f"for this aggressive strategy")

        transform_fun: typing.Callable[[], str] = getattr(creature,
                                                          "transform")
        revert_fun: typing.Callable[[], str] = getattr(creature,
                                                       "revert")

        print(transform_fun())
        print(creature.attack())
        print(revert_fun())

    def is_valid(self, creature: Creature) -> bool:
        has_transform = (hasattr(creature, "transform")
                         and callable(getattr(creature, "transform")))
        has_revert = (hasattr(creature, "revert")
                      and callable(getattr(creature, "revert")))
        return has_transform and has_revert


class DefensiveStrategy(BattleStrategy):

    def act(self, creature: Creature) -> None:
        if not self.is_valid(creature):
            raise InvalidStrategyError(f"Invalid Creature "
                                       f"'{creature.name}' for "
                                       f"this defensive strategy")

        heal_fun: typing.Callable[[], str] = getattr(creature, "heal")

        print(creature.attack())
        print(heal_fun())

    def is_valid(self, creature: Creature) -> bool:
        return hasattr(creature, "heal") and callable(getattr(creature,
                                                              "heal"))
