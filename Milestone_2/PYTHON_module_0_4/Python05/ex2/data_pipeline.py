import typing
from abc import abstractmethod, ABC
from typing import Protocol


class DataProcessor(ABC):
    def __init__(self) -> None:
        self._data: typing.List[str] = []
        self._rank_index: int = 0

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
            return all(isinstance(x, (int, float))
                       and not isinstance(x, bool) for x in data)
        else:
            return False

    def ingest(self, data: typing.Union[int, float, typing.
               List[typing.Union[int, float]]]) -> None:
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
            return all(isinstance(x, str) for x in data)
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
            return all(isinstance(key, str) and isinstance(val, str)
                       for key, val in data.items())
        if isinstance(data, list):
            return all(isinstance(dic, dict)
                       and all(isinstance(key, str)
                               and isinstance(val, str)
                               for key, val in dic.items())
                       for dic in data)
        return False

    def ingest(self, data: typing.Union[typing.Dict[str, str], typing.
               List[typing.Dict[str, str]]]) -> None:
        if not self.validate(data):
            raise Exception("Improper log data")
        items = data if isinstance(data, list) else [data]
        for item in items:
            formatted_string = ": ".join(item.values())
            self._data.append(formatted_string)

class DataStream:
    def __init__(self) -> None:
        self._processors: typing.List[DataProcessor] = []
        self._stats: typing.Dict[DataProcessor, int] = {}

    def register_processor(self, proc: DataProcessor) -> None:
        self._processors.append(proc)
        self._stats[proc] = 0

    def process_stream(self, stream: list[typing.Any]) -> None:
        for element in stream:
            handled = False
            for proc in self._processors:
                if proc.validate(element):
                    item_count = len(element) if (
                        isinstance(element, list)) else 1
                    proc.ingest(element)
                    self._stats[proc] += item_count
                    handled = True
                    break
            if not handled:
                print(f"DataStream error: - Can't process "
                      f"element in stream: {element}")

    def print_processors_stats(self) -> None:
        print("\n=== DataStream statistics ===")
        if not self._processors:
            print("No processors found, no data")
            return

        for proc in self._processors:
            total = self._stats[proc]
            remaining = len(proc._data)
            class_name = proc.__class__.__name__.replace("Processor", " Processor")
            print(f"{class_name}: total {total} items processed, "
                  f"remaining {remaining} on processor")

    def output_pipeline(self, nb: int, plugin: 'ExportPlugin') -> None:


        for proc in self._processors:
            extracted_data: list[tuple[int, str]] = []
            for _ in range(nb):
                try:
                    rank, val = proc.output()
                    extracted_data.append((rank, val))
                except Exception:
                    break
            if extracted_data:
                plugin.process_output(extracted_data)

class ExportPlugin(Protocol):
    def process_output(self, data: list[tuple[int, str]]) -> None:
        pass

class CSVExportPlugin:
    def process_output(self, data: list[tuple[int, str]]) -> None:
        if not data:
            return
        print("CSV Output:")
        print(",".join([val for _, val in data]))

class JSONExportPlugin:
    def process_output(self, data: list[tuple[int, str]]) -> None:
        if not data:
            return
        print("JSON Output:")
        items = []
        for rank, val in data:
            items.append((f'"item_{rank}": "{val}"'))
        print("{" + ", ".join(items) + "}")


def main():
    print("=== Code Nexus - Data Pipeline ===")
    print("\nInitialize Data Stream...\n")
    data_stream = DataStream()
    data_stream.print_processors_stats()

    print("\nRegistering Processors\n")
    num_proc = NumericProcessor()
    text_proc = TextProcessor()
    log_proc = LogProcessor()

    data_stream.register_processor(num_proc)
    data_stream.register_processor(text_proc)
    data_stream.register_processor(log_proc)

    data_batch_1 = [
        'Hello world',
        [3.14, -1, 2.71],
        [{'log_level': 'WARNING', 'log_message': 'Telnet access! Use ssh instead'},
         {'log_level': 'INFO', 'log_message': 'User wil is connected'}],
        42,
        ['Hi', 'five']
    ]

    print(f"\nSend first batch of data on stream: {data_batch_1}")
    data_stream.process_stream(data_batch_1)
    data_stream.print_processors_stats()

    print("\nSend 3 processed data from each processor to a CSV plugin:")
    csv_plugin = CSVExportPlugin()
    data_stream.output_pipeline(3, csv_plugin)

    data_stream.print_processors_stats()

    data_batch_2 = [
        21,
        ['I love AI', 'LLMs are wonderful', 'Stay healthy'],
        [{'log_level': 'ERROR', 'log_message': '500 server crash'},
         {'log_level': 'NOTICE', 'log_message': 'Certificate expires in 10 days'}],
        [32, 42, 64, 84, 128, 168],
        'World hello'
    ]

    print(f"\nSend another batch of data: {data_batch_2}")
    data_stream.process_stream(data_batch_2)
    data_stream.print_processors_stats()

    print("\nSend 5 processed data from each processor to a JSON plugin:")
    json_plugin = JSONExportPlugin()
    data_stream.output_pipeline(5, json_plugin)

    data_stream.print_processors_stats()


if __name__ == "__main__":
    main()