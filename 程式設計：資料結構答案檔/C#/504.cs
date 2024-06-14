
using System;
using System.Collections.Generic;
using System.Linq;

class Order {
    public int OrderNumber { get; set; }
    public int Time { get; set; }
    public int Value { get; set; }

    public Order(int orderNumber, int time, int value) {
        OrderNumber = orderNumber;
        Time = time;
        Value = value;
    }
}

class Validate {
    public List<Order> Orders { get; set; } = new List<Order>();
    public int TotalValue { get; set; } = 0;
}

class Program {
    static void GetOrdersFromFile(out List<Order> orders, out int availableTime) {
        orders = new List<Order>();
        int n = int.Parse(Console.ReadLine());
        for (int i = 0; i < n; i++) {
            var parts = Console.ReadLine().Split().Select(int.Parse).ToArray();
            orders.Add(new Order(parts[0], parts[1], parts[2]));
        }
        availableTime = int.Parse(Console.ReadLine());
    }

    static void PrintAnswer(Validate v) {
        Console.WriteLine(string.Join(" ", v.Orders.Select(o => o.OrderNumber)));
        Console.WriteLine(v.TotalValue);
    }

    static Validate FindSelectedOrders(List<Order> orders, int availableTime) {
        int n = orders.Count;
        var dp = new int[n + 1, availableTime + 1];
        for (int i = 1; i <= n; i++) {
            for (int w = 0; w <= availableTime; w++) {
                if (orders[i - 1].Time > w) {
                    dp[i, w] = dp[i - 1, w];
                } else {
                    dp[i, w] = Math.Max(dp[i - 1, w], dp[i - 1, w - orders[i - 1].Time] + orders[i - 1].Value);
                }
            }
        }

        var v = new Validate();
        int j = availableTime;
        for (int i = n; i > 0; i--) {
            if (dp[i, j] != dp[i - 1, j]) {
                v.Orders.Add(orders[i - 1]);
                v.TotalValue += orders[i - 1].Value;
                j -= orders[i - 1].Time;
            }
        }

        v.Orders.Reverse();
        return v;
    }

    static void Main() {
        GetOrdersFromFile(out List<Order> orders, out int availableTime);
        var v = FindSelectedOrders(orders, availableTime);
        v.Orders.Sort((a, b) => a.OrderNumber.CompareTo(b.OrderNumber));
        PrintAnswer(v);
    }
}
