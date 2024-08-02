def run_length_encoding(s):
    encoded_string = ""
    count = 1

    for i in range(1, len(s)):
        if s[i] == s[i - 1]:
            count += 1
        else:
            encoded_string += s[i - 1] + str(count)
            count = 1

    encoded_string += s[-1] + str(count)

    return encoded_string

def main():
    
    data_length = int(input())

    result_list = []

    for i in range(data_length):
        input_string = input()
        encoded_result = run_length_encoding(input_string)
        result_list.append(encoded_result)

    for i in range(len(result_list)):
        print(result_list[i])

if __name__ == '__main__':
    main()
