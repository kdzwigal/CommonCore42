#!/usr/bin/env python3
import random


if __name__ == "__main__":
    init_list = ["Alice", "bob", "Charlie", "dylan",
                 "Emma", "Gregory", "john", "kevin", "Liam"]
    print("=== Game Data Alchemist ===")
    print(f"Initial list of players: {init_list}")
    cap_list = [name.capitalize() for name in init_list]
    cap_init_only = [name for name in init_list if name == name.capitalize()]
    print(f"New list with all names capitalized: {cap_list}")
    print(f"New list of capitalized names only: {cap_init_only}")
    score_dict = {name: random.choice(range(1000)) for name in cap_list}
    print(f"Score dict: {score_dict}")
    average_score = round(sum(score_dict.values()) / len(score_dict), 2)
    print(f"Score average: {average_score}")
    high_scores = {name: score for name, score in score_dict.items()
                   if score > average_score}
    print(f"High scores: {high_scores}")
