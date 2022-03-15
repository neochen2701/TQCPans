f_name = "read.dat"
c_male = 0
c_female = 0
with open(f_name, 'r', encoding='UTF-8') as file:
    for row in file:
        print(row)
        row1 = row.split()
        if row1[2] == '1':
            c_male += 1
        elif row1[2] == '0':
            c_female += 1
print("Number of males:", c_male)
print("Number of females:", c_female)
