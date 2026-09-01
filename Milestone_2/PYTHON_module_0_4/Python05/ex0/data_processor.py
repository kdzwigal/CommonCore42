import typing
from abc import abstractmethod, ABC


class DataProcessor(ABC):

    def output(self) -> tuple[int, str]:
        pass

    @abstractmethod
    def validate(self, data: typing.Any) -> bool:
        pass

    def ingest(self, data: typing.Any) -> None:
        pass


class NumericProcessor(DataProcessor):
    @abstractmethod

class TextProcessor(DataProcessor):
    @abstractmethod

class LogProcessor(DataProcessor):
    @abstractmethod
