input_list = input().split('/')
cnt = 0
for idx in range(len(input_list)):
    cnt += int(input_list[idx])
    
    if idx != len(input_list) - 1:
        print(str(input_list[idx]), end = ' ')
    else:
        print(input_list[idx])
print(cnt)