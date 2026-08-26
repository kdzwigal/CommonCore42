#!/usr/bin/env python3
import random


if __name__ == "__main__":
    init_list = ["Alice", "bob", "Charlie",
                  "dylan", "Emma", "Gregory", "john", "kevin", "Liam"]
    print("=== Game Data Alchemist ===")
    print(f"Initial list of players: {init_list}")
    cap_list = []
    cap_init_only = []
    i = 0
    while i < len(init_list):
        if init_list[i] == init_list[i].capitalize():
            cap_init_only.append(init_list[i])
        i += 1
    for player in init_list:
        cap_list.append(player.capitalize())
    print(f"New list with all names capitalized: {cap_list}")
    print(f"New list of capitalized names only: {cap_init_only}")