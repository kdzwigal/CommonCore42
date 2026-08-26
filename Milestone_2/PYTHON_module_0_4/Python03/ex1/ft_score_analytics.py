#!/usr/bin/env python3
import sys
if __name__ == "__main__":
    print("=== Player Score Analytics ===")
    scores = []
    i = 1
    while i < len(sys.argv):
        try:
            scores.append(int(sys.argv[i]))
        except ValueError:
            print(f"Invalid parameter: '{sys.argv[i]}'")
        i += 1
    if scores:
        print(f"Scores processed: {scores}")
        print(f"Total players: {len(scores)}")
        print(f"Total scores: {sum(scores)}")
        print(f"Average score: {sum(scores) / len(scores)}")
        print(f"High score: {max(scores)}")
        print(f"Low score: {min(scores)}")
        print(f"Score range: {max(scores) - min(scores)}")
    if len(scores) == 0:
        print("No scores provided. Usage: python3 ft_score_analytics.py "
              "<score1> <score2> ...")
    sys.exit()
