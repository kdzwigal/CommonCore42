def ft_count_harvest_recursive() -> None:
    def recursion(i: int, day: int) -> None:
        if i <= day:
            print(f"Day {i}")
            i += 1
            recursion(i, day)
    day = int(input("Days until harvest: "))
    recursion(1, day)
    print("Harvest time!")
