def compute():
    dic = {}
    while True:
        key = input("Key: ")
        if key == "end":
            return dic

        value = input("Value: ")
        dic[key] = value


print("Create dict1:")
dict1 = compute()

print("Create dict2:")
dict2 = compute()

merge_dict = dict1.copy()
merge_dict.update(dict2)

sortedDict = sorted(merge_dict)

for i in sortedDict:
    print('%s: %s' % (i, merge_dict[i]))
