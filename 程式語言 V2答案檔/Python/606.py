for i in range(3):
    number = input()
    cnt = ((int(number[0]) + int(number[2]) + int(number[4])) + ((int(number[1]) + int(number[3])) * 5))% 26
    if cnt == ord(number[-1]) - ord('A') + 1:
        print('Pass')
    else:
        print('Fail')
