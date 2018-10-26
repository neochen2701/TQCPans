color_dict = {}

while True:
    key = input("Key: ")
    if key == "end":
        break
    value = input("Value: ")
    color_dict[key] = value

sortedDict = sorted(color_dict)

for i in sortedDict:
    print('%s: %s' % (i, color_dict[i]))
