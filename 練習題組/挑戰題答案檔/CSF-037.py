def frequency_sort(s):
    vowels = set('aeiou')
    freq = {}
    for char in s:
        if char in freq:
            freq[char] += 1
        else:
            freq[char] = 1

    sorted_chars = sorted(freq.items(), key=lambda x: (-x[1], -int(x[0] in vowels), x[0]))

    result = ''
    for char, count in sorted_chars:
        result += char * count

    return result

s = input()
print(frequency_sort(s))