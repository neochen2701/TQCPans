#include <iostream>
#include <vector>
#include <algorithm>

struct Order {
    int orderNumber;
    int time;
    int value;

    Order(int orderNumber, int time, int value) : orderNumber(orderNumber), time(time), value(value) {}
};

struct Validate {
    std::vector<Order> orders;
    int totalValue = 0;
};

void getOrdersFromFile(std::vector<Order>& orders, int& availableTime) {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int orderNumber, time, value;
        std::cin >> orderNumber >> time >> value;
        orders.emplace_back(orderNumber, time, value);
    }
    std::cin >> availableTime;
}

void printAnswer(const Validate& v) {
    for (size_t i = 0; i < v.orders.size(); i++) {
        std::cout << (i > 0 ? " " : "") << v.orders[i].orderNumber;
    }
    std::cout << "\n" << v.totalValue << "\n";
}

bool compareOrder(const Order& a, const Order& b) {
    return a.orderNumber < b.orderNumber;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Validate findSelectedOrders(const std::vector<Order>& orders, int availableTime) {
    int n = orders.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(availableTime + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= availableTime; j++) {
            if (orders[i - 1].time > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - orders[i - 1].time] + orders[i - 1].value);
            }
        }
    }

    Validate v;
    int j = availableTime;
    for (int i = n; i > 0; i--) {
        if (dp[i][j] != dp[i - 1][j]) {
            v.orders.push_back(orders[i - 1]);
            v.totalValue += orders[i - 1].value;
            j -= orders[i - 1].time;
        }
    }

    std::reverse(v.orders.begin(), v.orders.end());
    return v;
}

void dynamicProg(std::vector<Order>& orders, int availableTime) {
    Validate v = findSelectedOrders(orders, availableTime);
    std::sort(v.orders.begin(), v.orders.end(), compareOrder);
    printAnswer(v);
}

int main() {
    std::vector<Order> orders;
    int availableTime;
    getOrdersFromFile(orders, availableTime);
    dynamicProg(orders, availableTime);
    return 0;
}
