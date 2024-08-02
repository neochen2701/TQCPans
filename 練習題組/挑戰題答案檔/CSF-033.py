def is_subsequence(s, t):
    i, j = 0, 0
    while i < len(s) and j < len(t):
        if s[i] == t[j]:
            i += 1
        j += 1

    return i == len(s) and s in t

def remove_subsequence(s, t):
    result = ""
    i, j = 0, 0
    while i < len(s) and j < len(t):
        if s[i] == t[j]:
            i += 1
        else:
            result += t[j]
        j += 1

    result += t[j:]

    return result

def main():
    
    N = int(input())
    result_list = []
    for i in range(N):
        s, t = input().split()

        if is_subsequence(s, t):
            result = remove_subsequence(s, t)
            if len(result) == 0:
                result_list.append("Perfect")
            else:
                result_list.append(result)
        else:
            result_list.append("No")
    
    for i in range(N):
        print(result_list[i])
        

if __name__ == '__main__':
    main()