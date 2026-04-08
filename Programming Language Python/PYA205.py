c = input()

if ('a' <= c <= 'z') or ('A' <= c <= 'Z'):
    print (c, "is an alphabet.")
elif ('0' <= c <= '9'):
    print (c, "is a number.")
else :
    print (c, "is a symbol.")