def reverse_sum(num1, num2):
    result = num1 * num2
    reversed_sum = str(result)[::-1]

    temp_total = 0
    for idx in range(len(reversed_sum)):
        if reversed_sum[idx] == '-': continue
        if (idx+1) % 2 == 0 :
            temp_total -= int(reversed_sum[idx])
        else:
            temp_total += int(reversed_sum[idx])

    return temp_total

def find_max_unit_digit_pair(n, sequence):
    min_number = 1111
    max_unit_digit_sum = 11

    max_unit_digit_pair = (0, 0)

    for i in range(n - 1):
        for j in range(i + 1, n):

            current_sum = reverse_sum(sequence[i], sequence[j])
            while current_sum >= 10:
                current_sum = reverse_sum(current_sum, 1)

            while current_sum <= -10:
                current_sum = reverse_sum(current_sum, 1)

            if current_sum < max_unit_digit_sum and current_sum != 0:  
                min_num =  sequence[i] if sequence[i] < sequence[j] else sequence[j]
                max_unit_digit_sum = current_sum
                if min_number > min_num:
                    max_unit_digit_pair = (sequence[i], sequence[j])

    return max_unit_digit_pair

def main():
    n = int(input())
    sequence = list(map(int, input().split()))

    result_pair = find_max_unit_digit_pair(n, sequence)
    result_pair = sorted(result_pair)
    
    print(result_pair[0], result_pair[1])

if __name__ == "__main__":
    main()
