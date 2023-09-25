text = ''

with open("read_隱2.txt", 'r') as file:
    text = file.read()

result = len(text)
print(result)