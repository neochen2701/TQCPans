pw = input()

validPw = True

if len(pw) <= 7 \
   or pw.isalpha() \
   or pw.isdigit() \
   or pw.islower():
    validPw = False
else:
    for i in range(0, len(pw)):
        if not pw[i].isalpha() and not pw[i].isdigit():
            validPw = False
            break

if validPw:
    print("Valid password")
else:
    print("Invalid password")