#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>

using namespace std;

vector<pair<string, string>> generateCombinations(const vector<string>& items) {
    vector<pair<string, string>> combinations;
    for (size_t i = 0; i < items.size(); ++i) {
        for (size_t j = i + 1; j < items.size(); ++j) {
            if (items[i] < items[j])
                combinations.push_back(make_pair(items[i], items[j]));
            else
                combinations.push_back(make_pair(items[j], items[i]));
        }
    }
    return combinations;
}

void compute(const set<string>& order, vector<int>& relations, const vector<pair<string, string>>& combinations) {
    for (size_t i = 0; i < combinations.size(); ++i) {
        if (order.find(combinations[i].first) != order.end() && order.find(combinations[i].second) != order.end()) {
            relations[i]++;
        }
    }
}

bool sortRelation(const pair<pair<string, string>, int>& a, const pair<pair<string, string>, int>& b) {
    if (a.second == b.second)
        return a.first > b.first;
    return a.second > b.second;
}

int main() {
    vector<string> items = {"apple", "watermelon", "pawpaw", "banana", "pineapple"};
    auto combinations = generateCombinations(items);
    vector<int> relations(combinations.size(), 0);
    
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        set<string> order;
        size_t pos = 0;
        while ((pos = line.find(' ')) != string::npos) {
            order.insert(line.substr(0, pos));
            line.erase(0, pos + 1);
        }
        order.insert(line);

        compute(order, relations, combinations);
    }

    vector<pair<pair<string, string>, int>> combined;
    for (size_t i = 0; i < combinations.size(); ++i) {
        combined.push_back(make_pair(combinations[i], relations[i]));
    }

    sort(combined.begin(), combined.end(), sortRelation);

    for (int i = 0; i < 3 && i < combined.size(); ++i) {
        cout << combined[i].first.first << " " << combined[i].first.second << " " << combined[i].second << endl;
    }

    return 0;
}