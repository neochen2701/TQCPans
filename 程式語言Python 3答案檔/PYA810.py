k = eval(input())

for i in range(k):
    str_num = input()
    str_num_list = str_num.split(' ')
    str_num_list = [eval(x) for x in str_num_list]
    print("%.2f" % (max(str_num_list) - min(str_num_list)))