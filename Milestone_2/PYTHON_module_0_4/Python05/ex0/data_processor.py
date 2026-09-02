import typing
from abc import abstractmethod, ABC


class DataProcessor(ABC):
    def __init__(self) -> None:
        self._data: typing.List[str] = []
        self._rank_index :int = 0

    def output(self) -> tuple[int, str]:
        if not self._data:
            raise Exception("Data is empty")
        value = self._data.pop(0)
        current_rank = self._rank_index
        self._rank_index += 1
        return current_rank, value

    @abstractmethod
    def validate(self, data: typing.Any) -> bool:
        pass
    @abstractmethod
    def ingest(self, data: typing.Any) -> None:
        pass


class NumericProcessor(DataProcessor):

    def validate(self, data: typing.Any) -> bool:
        if isinstance(data, (int, float)) and not isinstance(data, bool):
            return True
        if isinstance(data, list):
            return all(isinstance(x, (int, float)) and not isinstance(x, bool) for x in data)
        else:
            return False

    def ingest(self, data: typing.Union[int, float, typing.List[typing.Union[int, float]]]) -> None:
            if not self.validate(data):
                raise Exception("Improper numeric data")
            if isinstance(data, list):
                for x in data:
                    self._data.append(str(x))
            else:
                self._data.append(str(data))

class TextProcessor(DataProcessor):
    def validate(self, data: typing.Any) -> bool:
        if isinstance(data, str):
            return True
        if isinstance(data, list):
            return all(isinstance(x,str) for x in data)
        return False

    def ingest(self, data: typing.Union[str, typing.List[str]]) -> None:
        if not self.validate(data):
            raise Exception("Improper text data")
        if isinstance(data, list):
            self._data.extend(data)
        else:
            self._data.append(data)

class LogProcessor(DataProcessor):
    def validate(self, data: typing.Any) -> bool:
        if isinstance(data, dict):
            return all(isinstance(key, str) and isinstance(val, str) for key, val in data.items())
        if isinstance(data, list):
            return all(isinstance(dic, dict) and all(isinstance(key, str) and isinstance(val, str) for key, val in dic.items()) for dic in data)
        return False

    def ingest(self, data: typing.Union[typing.Dict[str, str], typing.List[typing.Dict[str, str]]]) -> None:
        if not self.validate(data):
            raise Exception("Improper log data")
        items = data if isinstance(data, list) else [data]
        for item in items:
            formatted_string = ": ".join(item.values())
            self._data.append(formatted_string)

def main():

    print("=== Code Nexus - Data Processor ===")

    # --- Numeric Processor Test ---
    print("\nTesting Numeric Processor...")
    num_proc = NumericProcessor()
    print(f"Trying to validate input '42': {num_proc.validate('42')}")
    print(f"Trying to validate input 'Hello': {num_proc.validate('Hello')}")

    print("Test invalid ingestion of string 'foo' without prior validation:")
    try:
        num_proc.ingest("foo")  # type: ignore (Intentionally forcing invalid type for testing)
    except Exception as e:
        print(f"Got exception: {e}")

    num_data = [1, 2, 3, 4, 5]
    print(f"Processing data: {num_data}")
    num_proc.ingest(num_data)

    print("Extracting 3 values...")
    for _ in range(3):
        rank, val = num_proc.output()
        print(f"Numeric value {rank}: {val}")

    # --- Text Processor Test ---
    print("\nTesting Text Processor...")
    text_proc = TextProcessor()
    print(f"Trying to validate input '42': {text_proc.validate(42)}")

    text_data = ['Hello', 'Nexus', 'World']
    print(f"Processing data: {text_data}")
    text_proc.ingest(text_data)

    print("Extracting 1 value...")
    rank, val = text_proc.output()
    print(f"Text value {rank}: {val}")

    # --- Log Processor Test ---
    print("\nTesting Log Processor...")
    log_proc = LogProcessor()
    print(f"Trying to validate input 'Hello': {log_proc.validate('Hello')}")

    log_data = [
        {'log_level': 'NOTICE', 'log_message': 'Connection to server'},
        {'log_level': 'ERROR ', 'log_message': 'Unauthorized access!!'}
    ]
    print(f"Processing data: {log_data}")
    log_proc.ingest(log_data)

    print("Extracting 2 values...")
    for _ in range(2):
        rank, val = log_proc.output()
        print(f"Log entry {rank}: {val}")


if __name__ == "__main__":
    main()
