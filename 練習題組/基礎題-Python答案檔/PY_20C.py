hour = int(input())

if hour < 12:
    print("上午")
elif 12 <= hour <= 18:
    print("下午")
else:
    print("晚上")
