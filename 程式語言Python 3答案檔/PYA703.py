tup = ()

while True:
    word = input()
    if word == "end":
        break
    tup += (word, )

print(tup)
print(tup[0:3])
print(tup[-3:])
