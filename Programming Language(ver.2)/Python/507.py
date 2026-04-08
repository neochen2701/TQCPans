ans = input()
input_list = []
for i in range(3):
    input_list.append(input())

cnt = [0] * 6
for pos in range(len(ans)):
    for idx in range(len(input_list)):
        for leng in range(len(input_list[0])):
            if ans[pos] == input_list[idx][leng]:
                if pos == leng:
                    cnt[idx * 2 + 0] += 1
                else:
                    cnt[idx * 2 + 1] += 1
                    
for i in range(0, 6, 2):
    print(str(cnt[i]) + 'A' + str(cnt[i + 1]) + 'B')