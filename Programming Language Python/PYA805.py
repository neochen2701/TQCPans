string = input()
if len(string) == 6:
    print("|%-10s|" % (string))
    print("|%s|" % string.center(10))
    print("|%10s|" % (string))
