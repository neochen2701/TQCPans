from queue import Queue

def calculate_time(num_drinks):
    time = num_drinks * 2
    return time

def queuing_up_to_buy_drinks(customer_queue):
    current_time = 0
    while not customer_queue.empty():
        name, remaining_drinks = customer_queue.get()
        making_drinks = 0

        if remaining_drinks > 3:
            making_drinks = 3
            remaining_drinks -= 3
            customer_queue.put((name, remaining_drinks))
        else:
            making_drinks = remaining_drinks
            remaining_drinks = 0
        
        current_time += calculate_time(making_drinks) 

        if remaining_drinks == 0:
            print(f"{name} {current_time}")

N = int(input())
customer_queue = Queue()
for _ in range(N):
    name, drinks = input().split()
    drinks = int(drinks)
    customer_queue.put((name, drinks))
queuing_up_to_buy_drinks(customer_queue)
