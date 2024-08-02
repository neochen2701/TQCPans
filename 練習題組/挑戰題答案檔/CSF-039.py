import math

def generate_primes(n):
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False

    for i in range(2, int(n**0.5) + 1):
        if is_prime[i]:
            for multiple in range(i * i, n + 1, i):
                is_prime[multiple] = False

    prime_set = {i for i in range(2, n + 1) if is_prime[i]}
    return prime_set

def process_time_for_item(item, primes):
    if item in primes:
        return True, 40 
    elif math.isqrt(item)**2 == item:
        return False, 30
    elif item % 2 == 1:
        return True, 10
    else:
        return False, 10

def total_processing_time(N):
    time_line_1 = 0
    time_line_2 = 0
    primes = generate_primes(N)

    for item in range(1, N + 1):
        pipe, time = process_time_for_item(item, primes)
        if pipe:
            time_line_1 += time
        else:
            time_line_2 += time
    return max(time_line_1, time_line_2)

N = int(input())
result = total_processing_time(N)
print(f"{result}")