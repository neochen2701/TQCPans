def is_prime(n):
    if n <= 1:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

def rotate_number(num):
    num_str = str(num)
    rotated_numbers = [int(num_str[i:] + num_str[:i]) for i in range(len(num_str))]
    return rotated_numbers

def count_circular_primes_in_range(start, end):
    circular_primes_count = 0
    for num in range(start, end + 1):
        if is_prime(num):
            rotated_numbers = rotate_number(num)
            if all(is_prime(rotated) for rotated in rotated_numbers):
                circular_primes_count += 1
    return circular_primes_count

def main():
    result_list = []
    while True:
        inputs = input().split()
        if len(inputs) == 1 and inputs[0] == "-1":
            for item in result_list:
                if item == 0:
                    print("No Circular Primes")
                else:
                    print(f"{item}")
            break

        i, j = map(int, inputs)
        result = count_circular_primes_in_range(i, j)
        result_list.append(result)

if __name__ == "__main__":
    main()