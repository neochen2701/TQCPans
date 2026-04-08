def if_leap_year(y):
    if y % 400 == 0 or (y % 4 == 0 and not (y % 100 == 0)):
        return True
    else:
        return False

cnt = 0
date = input().split(' ')
date = [int(x) for x in date]
month_day = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

if if_leap_year(date[0]):
    month_day[2] += 1

if date[2] > month_day[date[1]]:
    print('error')
    exit()

for i in range(1, len(month_day)):
    month_day[i] += month_day[i - 1]

print(month_day[date[1] - 1] + date[2])