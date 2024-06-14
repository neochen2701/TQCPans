
num_activities = int(input())

act_lst = []
for _ in range(num_activities):
    start, end = eval(input())
    act_lst.append([start, end])

act_lst.sort(key=lambda x:x[1])

select_lst = [act_lst[0]]
for i in range(1, len(act_lst)):
    if select_lst[-1][1] <= act_lst[i][0]:
        select_lst.append(act_lst[i])

print(len(select_lst))

