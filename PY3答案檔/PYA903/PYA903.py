file = open("data.txt", "a+")
for i in range(5):
    file.write('\n' + input())

print("Append completed!")
print('Content of "data.txt":')

file.seek(0, 0)
print(file.read())

file.close()