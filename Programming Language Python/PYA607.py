score_lst = []
order_lst = ["1st", "2nd", "3rd"]

for i in range(3):
    print("The %s student:" % order_lst[i])
    score_lst.append([])
    for j in range(5):
        score_lst[i].append(eval(input()))


for i in range(3):
    print("Student %d" % (i + 1))
    print("#Sum %d" % (sum(score_lst[i])))
    print("#Average %.2f" % (sum(score_lst[i]) / 5))
