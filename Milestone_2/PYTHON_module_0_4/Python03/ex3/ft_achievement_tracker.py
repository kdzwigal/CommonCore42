#!/usr/bin/env python3
import random


def gen_player_achievements(player_achievements: list) -> set:
    set_length = len(player_achievements)
    how_many = random.randint(4, set_length)
    ret_set = set()
    for x in range(how_many):
        ret_set.add(random.choice(player_achievements))
    return ret_set


if __name__ == "__main__":
    print("=== Achievement Tracker System ===\n")
    player_achievements = ['Crafting Genius', 'Strategist', 'World Savior',
                           'Speed Runner', 'Survivor', 'Master Explorer',
                           'Treasure Hunter', 'Unstoppable', 'First Steps',
                           'Collector Supreme', 'Untouchable', 'Sharp Mind',
                           'Boss Slayer']
    player_achievements_set = set()
    for x in player_achievements:
        player_achievements_set.add(x)
    player_alice = gen_player_achievements(player_achievements)
    player_bob = gen_player_achievements(player_achievements)
    player_charlie = gen_player_achievements(player_achievements)
    player_dylan = gen_player_achievements(player_achievements)
    print(f"Player Alice: {player_alice}")
    print(f"Player Bob: {player_bob}")
    print(f"Player Charlie: {player_charlie}")
    print(f"Player Dylan: {player_dylan}")
    print(f"\nAll distinct achievements: {player_achievements_set}")

    print(f"\nCommon achievements: {set.intersection(
        player_bob, player_charlie, player_dylan, player_alice)}\n")

    print(f"Only Alice has: {player_alice.difference(
        player_bob, player_charlie, player_dylan)}")
    print(f"Only Bob has: {player_bob.difference(
        player_alice, player_charlie, player_dylan)}")
    print(f"Only Charlie has: {player_charlie.difference(
        player_alice, player_dylan, player_bob)}")
    print(f"Only Dylan has: {player_dylan.difference(
        player_alice, player_charlie, player_bob)}")
    print("")
    print(f"Alice is missing: "
          f"{player_achievements_set.difference(player_alice)}")
    print(f"Bob is missing: "
          f"{player_achievements_set.difference(player_bob)}")
    print(f"Charlie is missing: "
          f"{player_achievements_set.difference(player_charlie)}")
    print(f"Dylan is missing: "
          f"{player_achievements_set.difference(player_dylan)}")
