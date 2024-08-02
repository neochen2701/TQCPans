def calculateSubMaxLength(s, start):
    space = []
    count = 0
    for index in range(start, len(s)):
        if(s[index] in space):
            return count
        space.append(s[index])
        count += 1
    return count

def main():
    s = input()
    _max = 0
    for start in range(len(s)):
        length = calculateSubMaxLength(s, start)
        if(_max<length):
            _max = length
    print(_max)

main()