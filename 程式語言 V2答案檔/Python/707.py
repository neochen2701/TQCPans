tc = int(input())
ans = []
for i in range(tc):
    a, b = input().split()
    a, b = int(a), int(b)
    tup = (a, b, a*b)
    ans.append(tup)
f_ans = sorted(ans, key = lambda x:x[2])
for i in range(tc):
    print(str(f_ans[i][0])+'x'+str(f_ans[i][1])+'='+str(f_ans[i][2]))