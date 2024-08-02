def longest_substring_without_repeated_char(s):
    start_index = 0
    end_index = 0
    length = 0
    index = 0

    hashset = set()

    for i in range(len(s)):
        while s[i] in hashset:
            hashset.remove(s[index])
            index += 1

        hashset.add(s[i])

        if (i - index + 1) > length:
            length = i - index + 1
            start_index = index
            end_index = i

    return s[start_index:end_index + 1]

if __name__ == "__main__":
    content = input()
    result = longest_substring_without_repeated_char(content)
    print(result)
