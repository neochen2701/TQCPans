f_name = "data.dat"
file = open(f_name, "w")

for i in range(5):
    inp = str(input())
    b_inp = inp + '\n'
    file.write(b_inp)

file.close()

print('The content of "%s":' % f_name)
with open(f_name, "r") as file:
    for line in file:
        print(line)
