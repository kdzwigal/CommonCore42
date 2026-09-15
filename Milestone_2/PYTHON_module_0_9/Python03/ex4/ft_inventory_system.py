#!/usr/bin/env python3
import sys


def parse_arguments(arg: str, items: dict[str, int]) -> dict[str, int]:
    if ':' not in arg:
        print(f"Error - invalid parameter '{arg}'")
        return {}
    tmp = {}
    parsed = []
    for item in arg.split(':'):
        parsed.append(str(item))
    if parsed[0] not in items:
        try:
            tmp[parsed[0]] = int(parsed[1])
        except ValueError as e:
            print(f"Quantity error for 'key': {e}")
            return {}
    else:
        print(f"Redundant item '{parsed[0]}' - discarding")
        return {}
    return tmp


def main() -> None:
    print("=== Inventory System Analysis ===")
    items: dict[str, int] = {}
    i = 1
    while i < len(sys.argv):
        items |= parse_arguments(sys.argv[i], items)
        i += 1
    if items:
        print(f"Got inventory: {items}")
        print(f"Item list: {list(items)}")
        print(f"Total quantity of the {len(items.keys())} items: "
              f"{sum(items.values())}")
        for key in items.keys():
            print(f"Item {key} represents "
                  f"{round(((items[key] / sum(items.values())) * 100), 1)}%")
        max_key = max(items, key=lambda k: items[k])
        max_value = items[max_key]
        print(f"Item most abundant: {max_key} with quantity {max_value}")
        min_key = min(items, key=lambda k: items[k])
        min_value = items[min_key]
        print(f"Item least abundant: {min_key} with quantity {min_value}")
        items = items | parse_arguments("magic_item:1", items)
        print(f"Updated inventory: {items}")


if __name__ == "__main__":
    main()
