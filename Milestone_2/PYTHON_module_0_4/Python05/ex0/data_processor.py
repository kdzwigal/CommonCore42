import typing
from abc import abstractmethod, ABC


class DataProcessor(ABC):
    def __init__(self, data: typing.Any) -> None:
        self.data = data
        self.counter : int = 0
        self.rank_index :int = 0

    def output(self) -> tuple[int, str]:
        return

    @abstractmethod
    def validate(self, data: typing.Any) -> bool:
        pass

    def ingest(self, data: typing.Any) -> None:
        pass


class NumericProcessor(DataProcessor):
    def __init__(self, data: typing.Any) -> None:
        super().__init__(data)

    def validate(self, data: typing.Any) -> bool:
        if isinstance(data, (int, float)):
            return True
        if isinstance(data, list):
            return all(isinstance(x, (int, float)) for x in data)
        else:
            return False

    def ingest(self, data: typing.Any) -> None:
            datas: typing.List[str] = []
            # if isinstance(data, (int, float)):
            #     self.data = str(data)
            # if isinstance(data, list):
            for x in data:
                datas.append(str(x))
            self.data = datas

class TextProcessor(DataProcessor):
    def __init__(self, data: typing.Any) -> None:
        super().__init__(data)

class LogProcessor(DataProcessor):
    def __init__(self, data: typing.Any) -> None:
        super().__init__(data)

def main():
    numproc = NumericProcessor.ingest([1, 2, 3, 4, 5, 6, 7, 8, 9])
    numproc.output()

