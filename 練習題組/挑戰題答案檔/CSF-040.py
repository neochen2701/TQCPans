def RollDice(sequence):
    W = 3
    N = 2
    E = 4
    S = 5
    cur = 1

    for commands in sequence:
        if commands == 'F':
            N, cur, S = cur, S, 7 - cur
        elif commands == 'L':
            W, cur, E = cur, E, 7 - cur
        elif commands == 'R':
            E, cur, W = cur, W, 7 - cur
        elif commands == 'B':
            S, cur, N = cur, N, 7 - cur

    result = f"{cur} {7 - cur} {W} {E} {N} {S}"
    return result

def PrintResult(player1, dice1_result, player2, dice2_result):
    print(player1 + " " + dice1_result)
    print(player2 + " " + dice2_result)

    dice1_lower = int(dice1_result.split()[1])
    dice2_lower = int(dice2_result.split()[1])

    if dice1_lower == dice2_lower:
        print("Tie")
    elif dice1_lower > dice2_lower:
        print(player1)
    else:
        print(player2)

if __name__ == "__main__":
    player1 = input().strip()
    dice1 = input().strip()
    player2 = input().strip()
    dice2 = input().strip()

    dice1_result = RollDice(dice1)
    dice2_result = RollDice(dice2)

    PrintResult(player1, dice1_result, player2, dice2_result)
