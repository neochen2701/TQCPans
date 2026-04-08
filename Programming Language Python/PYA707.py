X = set()
Y = set()

print("Enter group X's subjects:")
while True:
    subject = input()
    if subject == "end":
        break
    X.add(subject)

print("Enter group Y's subjects:")
while True:
    subject = input()
    if subject == "end":
        break
    Y.add(subject)

print(sorted(X | Y))
print(sorted(X & Y))
print(sorted(Y - X))
print(sorted(X ^ Y))
