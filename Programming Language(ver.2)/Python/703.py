n = int(input())
cnt_list = [0] * 5
output_str = ''

while n >= 50:
    n -= 50
    cnt_list[0] += 1
if cnt_list[0]:
    output_str += str(cnt_list[0]) + '*$50 '

while n >= 10:
    n -= 10
    cnt_list[1] += 1
if cnt_list[1]:
    output_str += str(cnt_list[1]) + '*$10 '

while n >= 5:
    n -= 5
    cnt_list[2] += 1
if cnt_list[2]:
    output_str += str(cnt_list[2]) + '*$5 '

while n >= 1:
    n -= 1
    cnt_list[3] += 1
if cnt_list[3]:
    output_str += str(cnt_list[3]) + '*$1 '

print(output_str[:-1])