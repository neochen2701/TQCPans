#include <iostream>
#include <vector>

int main() {
    int m, n;
    std::cin >> m;
    std::cin >> n;

    std::vector<std::vector<int>> matrix(m, std::vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
        }
    }

    std::cout << "Original:\n";
    for (int i = 0; i < m; i++) {
        std::cout << "[";
        for (int j = 0; j < n; j++) {
            std::cout << matrix[i][j];
            if (j < n - 1) std::cout << " ";
        }
        std::cout << "]\n";
    }

    std::cout << "Transpose:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "[";
        for (int j = 0; j < m; j++) {
            std::cout << matrix[j][i];
            if (j < m - 1) std::cout << " ";
        }
        std::cout << "]\n";
    }

    return 0;
}
