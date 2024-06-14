def optimal_order_selection(orders, available_time):
    n = len(orders)
    dp = [[0] * (available_time + 1) for _ in range(n + 1)]

    for i in range(1, n + 1):
        order_number, time, value = orders[i - 1]

        for j in range(available_time + 1):
            if time > j:
                dp[i][j] = dp[i - 1][j]
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - time] + value)

    selected_orders = []
    i, j = n, available_time
    while i > 0 and j > 0:
        if dp[i][j] != dp[i - 1][j]:
            selected_orders.append(orders[i - 1][0])
            j -= orders[i - 1][1]
        i -= 1

    return dp[n][available_time], selected_orders[::-1]

def check():
    n = int(input())
    orders = []
    for i in range(n):
       data = input().split()
       orders.append([int(data[0]), int(data[1]), int(data[2])])

    available_time = int(input())
           
    total_value, selected_order_numbers = optimal_order_selection(orders, available_time)
    print(' '.join(map(str, sorted(selected_order_numbers))))
    print(total_value)

check()