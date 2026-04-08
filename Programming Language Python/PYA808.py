s = input()

isSSN = (len(s) == 11)
if isSSN:
    for i in range(len(s)):
        if i == 3 or i == 6:
            if s[i] != '-':
                isSSN = False
                break
        elif not s[i].isdigit():
            isSSN = False
            break

if isSSN:
    print('Valid SSN')
else:
    print('Invalid SSN')
