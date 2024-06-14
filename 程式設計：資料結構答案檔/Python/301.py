import csv

class Player:
    def __init__(self, Id, Name, Level, Score):
        self.Id = int(Id)
        self.Name = Name
        self.Level = int(Level)
        self.Score = int(Score)

    def __repr__(self):
        return f"{self.Id} | {self.Name} | {self.Level} | {self.Score}"

def read_csv_file(file_path):
    players = []
    with open(file_path, newline='') as csvfile:
        reader = csv.reader(csvfile)
        next(reader, None)  # Skip the header
        for row in reader:
            player = Player(*row)
            players.append(player)
    return players

def sort_players(players):
    return sorted(players, key=lambda x: (-x.Score, -x.Id))

def display_sorted_player_data(players, n):
    if n > len(players):
        print("Exceeds data upper limit")
        return
    for index, player in enumerate(players[:n], start=1):
        print(f"{index} | {player}")

def main():
    file_path = "read.csv"
    players = read_csv_file(file_path)
    sorted_players = sort_players(players)
    
    try:
        n = int(input())
        display_sorted_player_data(sorted_players, n)
    except ValueError:
        print("Please enter a valid number.")

if __name__ == "__main__":
    main()
