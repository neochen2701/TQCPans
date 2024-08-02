class Player:
    def __init__(self, name):
        self.name = name
        self.money = 100
        self.position = 0
        self.total_distance = 0

def move_player(player, steps):
    player.position = (player.position + steps) % len(board)
    player.total_distance += steps

def apply_event(player, event):
    if event == 'R':
        player.money += 50
    elif event == 'P':
        player.money -= 50
    elif event == 'F':
        move_player(player, 2)
        apply_event(player, board[player.position])
    elif event == 'B':
        move_player(player, -2)
        apply_event(player, board[player.position])

def game_result(players):
    sorted_players = sorted(players, key=lambda x: (-x.money, -x.total_distance, players.index(x)))
    for rank, player in enumerate(sorted_players, start=1):
        print(f"{player.name} {player.money} {player.total_distance}")


# Input
N = int(input())
board = input().split()
K = int(input())

players = []
for player in range(K):
    player_info = input().split()
    player = Player(player_info[0])
    for steps in player_info[1:]:
        move_player(player, int(steps))
        apply_event(player, board[player.position])
    players.append(player)
game_result(players)