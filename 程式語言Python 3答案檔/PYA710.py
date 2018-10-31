my_dict = {}

while True:
    key = input("Key: ")
    if key == "end":
        break
    value = input("Value: ")
    my_dict[key] = value

search_key = input("Search key: ")
print(search_key in my_dict)
