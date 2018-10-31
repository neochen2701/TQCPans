f_name = input()
string = input()

file = open(f_name, "r+")
data = file.read()

print("=== Before the deletion")
print(data)

print("=== After the deletion")
data = data.replace(string, '')
print(data)

file.seek(0)
file.truncate()
file.write(data)
file.close()