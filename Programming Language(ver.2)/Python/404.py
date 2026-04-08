str = input()
cnt_list = []
for c in str:
    cnt_list.append(str.count(c))
    
print(str[cnt_list.index(max(cnt_list))])
print(max(cnt_list))