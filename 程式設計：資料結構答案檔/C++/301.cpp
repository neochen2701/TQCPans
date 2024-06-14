#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

class Player {
public:
    int Id;
    std::string Name;
    int Level;
    int Score;

    Player(int id, std::string name, int level, int score) 
        : Id(id), Name(name), Level(level), Score(score) {}
};

bool comparePlayers(const Player& a, const Player& b) {
    if (a.Score != b.Score) return a.Score > b.Score;
    return a.Id > b.Id;
}

std::vector<Player> ReadCsvFile(const std::string &filePath) {
    std::vector<Player> players;
    std::ifstream file(filePath);
    std::string line;

    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::vector<std::string> result;
        while (ss.good()) {
            std::string substr;
            std::getline(ss, substr, ',');
            result.push_back(substr);
        }
        if (result.size() == 4) {
            players.emplace_back(std::stoi(result[0]), result[1], std::stoi(result[2]), std::stoi(result[3]));
        }
    }

    return players;
}

int main() {
    auto players = ReadCsvFile("read.csv");
    
    std::sort(players.begin(), players.end(), comparePlayers);
    
    int n;
    std::cin >> n;
    
    if (n > players.size()) {
        std::cout << "Exceeds data upper limit" << std::endl;
    } else {
        for (int i = 0; i < n; ++i) {
            std::cout << i + 1 << " | " << players[i].Id << " | " << players[i].Name 
                      << " | " << players[i].Level << " | " << players[i].Score << std::endl;
        }
    }
    
    return 0;
}
