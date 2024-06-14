#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>

#define MAX_VERTICES 60

int graph[MAX_VERTICES][MAX_VERTICES];
int num_vertices = 0;

void readGraphFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "File could not be opened.\n";
        exit(EXIT_FAILURE);
    }

    std::string line;
    int row = 0;
    while (getline(file, line)) {
        std::istringstream iss(line);
        std::string token;
        int col = 0;
        while (getline(iss, token, ',')) {
            graph[row][col++] = std::stoi(token);
        }
        if (row == 0) num_vertices = col;
        row++;
    }
    file.close();
}

int main() {
    readGraphFromFile("read.txt");

    int degrees[MAX_VERTICES] = {0};
    int max_weight = 0, min_weight = 1000000;

    for (int i = 0; i < num_vertices; i++) {
        int weight_sum = 0;
        for (int j = 0; j < num_vertices; j++) {
            if (graph[i][j] > 0) {
                degrees[i]++;
                weight_sum += graph[i][j];
            }
        }
        if (weight_sum > max_weight) max_weight = weight_sum;
        if (weight_sum < min_weight) min_weight = weight_sum;
    }

    std::cout << "Degree:";
    for (int i = 0; i < num_vertices; i++) {
        std::cout << degrees[i];
        if (i < num_vertices - 1) std::cout << ",";
    }
    std::cout << std::endl << max_weight - min_weight << std::endl;

    return 0;
}
