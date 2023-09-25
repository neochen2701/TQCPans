text = input()

with open("read.txt", "a") as file:
    file.write(text)