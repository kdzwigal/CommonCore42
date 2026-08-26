#!/usr/bin/env python3
import math


def get_player_pos() -> tuple:
    while True:
        user_input = input("Enter new coordinates as floats in format "
                           "'x,y,z': ")
        parts = user_input.split(",")
        if len(parts) != 3:
            print("Invalid syntax")
            continue
        error_found = False
        coords = []
        for part in parts:
            clean_part = part.strip()
            try:
                coords.append(float(clean_part))
            except ValueError as e:
                print(f"Error on parameter '{clean_part}': {e}")
                error_found = True
                break
        if not error_found:
            return tuple(coords)


if __name__ == "__main__":
    print("=== Game Coordinate System ===\n")
    print("Get a first set of coordinates")
    first = get_player_pos()
    print(f"Got a first tuple: ({first[0]}, {first[1]}, {first[2]})")
    print(f"It includes : X={first[0]}, Y={first[1]}, Z={first[2]}")
    cent_dist = math.sqrt((first[0] - 0)**2 + (first[1] - 0)**2 +
                          (first[2] - 0)**2)
    cent_dist_rounded = round(cent_dist, 4)
    print(f"Distance to center: {cent_dist_rounded}")

    print("\nGet a second set of coordinates")
    second = get_player_pos()
    points_dist = math.sqrt((second[0] - first[0])**2
                            + (second[1] - first[1])**2
                            + (second[2] - first[2])**2)
    points_dist_rounded = round(points_dist, 4)
    print(f"Distance between the 2 sets of coordinates: {points_dist_rounded}")
