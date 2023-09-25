text = ''

with open("read.txt", 'r') as file:
    text = file.read()

c = input()
result = len(text) - len(text.replace(c, ''))
print(result)