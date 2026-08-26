#!/usr/bin/env python3
import random
import typing


def gen_event(players: list[str], actions: list[str]) \
        -> typing.Generator[typing.Tuple[str, str], None, None]:
    while True:
        yield (random.choice(players), random.choice(actions))


def consume_event(to_del: list[tuple]) \
        -> typing.Generator[typing.Tuple[str, str], None, None]:
    for _ in range(len(to_del)):
        chosed = random.choice(to_del)
        to_del.remove(chosed)
        yield chosed


def main() -> None:
    print("=== Game Data Stream Processor ===")
    players = ["alice", "charlie", "dylan", "bob"]
    actions = ["run", "grab", "move", "jump", "use", "climb"]
    event_gen = gen_event(players, actions)
    for i in range(0, 999):
        event = next(event_gen)
        print(f"Event {i}: Player {event[0]} did action {event[1]}")
    ten_tupl = []
    for i in range(10):
        event = next(event_gen)
        ten_tupl.append(event)
    print(f"Built list of 10 events: {ten_tupl}")
    for consumed_event in consume_event(ten_tupl):
        print(f"Got event from list: {consumed_event}")
        print(f"Remains in list: {ten_tupl}")


if __name__ == '__main__':
    main()
