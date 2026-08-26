#!/usr/bin/env python3
import random


def gen_player_achievements(player_achievements: list) -> set:
    set_length = len(player_achievements)
    how_many = random.randint(4, set_length)
    ret_set = set()
    for x in range(how_many):
        ret_set.add(random.choice(player_achievements))
    return ret_set


def main() -> None:
    print("=== Achievement Tracker System ===\n")
    player_achievements = ['Crafting Genius', 'Strategist', 'World Savior',
                           'Speed Runner', 'Survivor', 'Master Explorer',
                           'Treasure Hunter', 'Unstoppable', 'First Steps',
                           'Collector Supreme', 'Untouchable', 'Sharp Mind',
                           'Boss Slayer']
    player_achievements_set = set()
    for x in player_achievements:
        player_achievements_set.add(x)

    p_alice = gen_player_achievements(player_achievements)
    p_bob = gen_player_achievements(player_achievements)
    p_charlie = gen_player_achievements(player_achievements)
    p_dylan = gen_player_achievements(player_achievements)

    common = set.intersection(p_alice, p_bob, p_charlie, p_dylan)

    only_alice = p_alice.difference(p_bob, p_charlie, p_dylan)
    only_bob = p_bob.difference(p_alice, p_charlie, p_dylan)
    only_charlie = p_charlie.difference(p_alice, p_bob, p_dylan)
    only_dylan = p_dylan.difference(p_alice, p_bob, p_charlie)

    print(f"Player Alice: {p_alice}")
    print(f"Player Bob: {p_bob}")
    print(f"Player Charlie: {p_charlie}")
    print(f"Player Dylan: {p_dylan}")

    print(f"\nAll distinct achievements: {player_achievements_set}")

    print(f"\nCommon achievements: {common}\n")

    print(f"Only Alice has: {only_alice}")
    print(f"Only Bob has: {only_bob}")
    print(f"Only Charlie has: {only_charlie}")
    print(f"Only Dylan has: {only_dylan}")
    print("")
    print(f"Alice is missing: "
          f"{player_achievements_set.difference(p_alice)}")
    print(f"Bob is missing: "
          f"{player_achievements_set.difference(p_bob)}")
    print(f"Charlie is missing: "
          f"{player_achievements_set.difference(p_charlie)}")
    print(f"Dylan is missing: "
          f"{player_achievements_set.difference(p_dylan)}")


if __name__ == "__main__":
    main()
