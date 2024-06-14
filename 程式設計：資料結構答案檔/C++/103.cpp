#include <iostream>
#include <sstream>

class Monster {
public:
    int Value;
    Monster* Next;

    Monster(int value) : Value(value), Next(nullptr) {}
};

class BattleSimulator {
private:
    Monster* head;

public:
    BattleSimulator() : head(nullptr) {}

    void CreateMonsters(const std::string& input) {
        std::istringstream ss(input);
        std::string value;

        while (std::getline(ss, value, ',')) {
            try {
                int monsterAttack = std::stoi(value);
                AddMonster(monsterAttack);
            } catch (const std::invalid_argument& e) {
                std::cout << "input error" << std::endl;
            }
        }
    }

    void AddMonster(int value) {
        Monster* newNode = new Monster(value);

        if (head == nullptr) {
            head = newNode;
        } else {
            Monster* current = head;
            while (current->Next != nullptr) {
                current = current->Next;
            }
            current->Next = newNode;
        }
    }

    bool SimulateBattle(int playerHP) {
        Monster* current = head;
        int level = 1;

        while (current != nullptr) {
            playerHP -= current->Value;

            if (playerHP <= 0) {
                std::cout << "game over! dead at level " << level << std::endl;
                return false;
            }

            level++;
            current = current->Next;
        }

        std::cout << "game clear! hp left " << playerHP << std::endl;
        return true;
    }
};

int main() {
    std::string input;
    std::getline(std::cin, input);

    BattleSimulator battle;
    battle.CreateMonsters(input);

    int playerHP = 100;
    battle.SimulateBattle(playerHP);

    return 0;
}
