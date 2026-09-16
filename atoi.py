def atoi(s: str) -> int:
    try:
        return int(s)
    except ValueError:
        return 0

print(atoi("-121233"))