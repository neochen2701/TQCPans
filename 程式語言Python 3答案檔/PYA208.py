num = eval(input())

if 0 <= num <= 9:  hex_num = num
elif num == 10:    hex_num = 'A'
elif num == 11:    hex_num = 'B'
elif num == 12:    hex_num = 'C'
elif num == 13:    hex_num = 'D'
elif num == 14:    hex_num = 'E'
elif num == 15:    hex_num = 'F'

print(hex_num)