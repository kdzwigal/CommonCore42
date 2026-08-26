def ft_count_harvest_recursive():
    def recursion(i, day):
        if i <= day:
            print(f"Day {i}")
            i += 1
            recursion(i, day)
    day = int(input("Days until harvest: "))
    recursion(1, day)
    print("Harvest time!")
