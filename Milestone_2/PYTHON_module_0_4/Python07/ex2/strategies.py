from abc import ABC, abstractmethod



class BattleStrategy(ABC):

    @abstractmethod
    def act(self) -> str:
        pass

    @abstractmethod
    def is_valid(self) -> bool:
        pass

class NormalStrategy(BattleStrategy):

    def act(self) -> str:



class AggressiveStrategy(BattleStrategy):