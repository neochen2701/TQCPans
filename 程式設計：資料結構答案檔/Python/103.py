class Monster:
    def __init__(self, value):
        self.value = value
        self.next = None

class BattleSimulator:
    def __init__(self):
        self.head = None

    def create_monsters(self, input_str):
        values = input_str.split(',')
        for value in values:
            try:
                monster_attack = int(value)
                self.add_monster(monster_attack)
            except ValueError:
                print("input error")

    def add_monster(self, value):
        new_node = Monster(value)
        if not self.head:
            self.head = new_node
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = new_node

    def simulate_battle(self, player_hp):
        current = self.head
        level = 1
        while current:
            player_hp -= current.value
            if player_hp <= 0:
                print(f"game over! dead at level {level}")
                return False
            level += 1
            current = current.next
        print(f"game clear! hp left {player_hp}")
        return True

if __name__ == "__main__":
    input_str = input()
    battle = BattleSimulator()
    battle.create_monsters(input_str)
    player_hp = 100
    battle.simulate_battle(player_hp)
