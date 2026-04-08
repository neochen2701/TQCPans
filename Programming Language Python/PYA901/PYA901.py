file = open("write.txt", "w")


for i in range(5):
    data = input()
    file.write(data + '\n')

file.close()