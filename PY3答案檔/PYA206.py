score = eval(input())

if 80 <= score <= 100:
    grade = 'A'
elif 70 <= score <= 79:
    grade = 'B'
elif 60 <= score <=69:
    grade = 'C'
elif score <= 59:
    grade = 'F'

print(grade)