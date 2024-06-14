#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>

struct Student {
    std::string name;
    std::vector<int> scores;
    int sum;
    double avg;

    Student() : sum(0), avg(0.0) {}
};

std::vector<Student> read_input() {
    std::vector<Student> students;
    std::string line;
    while (std::getline(std::cin, line)) {
        if (line == "END") break;
        std::istringstream iss(line);
        Student student;
        iss >> student.name;
        int score;
        while (iss >> score) {
            student.scores.push_back(score);
        }
        students.push_back(student);
    }
    return students;
}

void calculate_sum_avg(std::vector<Student>& students) {
    for (auto& student : students) {
        student.sum = 0;
        for (int score : student.scores) {
            student.sum += score;
        }
        student.avg = student.scores.empty() ? 0.0 : static_cast<double>(student.sum) / student.scores.size();
    }
}

bool compare_students(const Student& a, const Student& b) {
    return a.avg > b.avg;
}

int main() {
    auto students = read_input();
    calculate_sum_avg(students);
    std::sort(students.begin(), students.end(), compare_students);

    for (const auto& student : students) {
        std::cout << student.name << " ";
        for (int score : student.scores) {
            std::cout << score << " ";
        }
        std::cout << student.sum << " " << std::fixed << std::setprecision(2) << student.avg << std::endl;
    }

    return 0;
}