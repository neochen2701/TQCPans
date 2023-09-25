text = ''

with open("read.txt", "r") as file:
    text = file.read()

with open("write.txt", "w") as file:
    file.write(text)