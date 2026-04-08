grade = ""
score = int(input())
while score != -9999:
    if score >= 90 and score <= 100:
        grade = 'A'
    elif score >= 80 and score <= 89:
        grade = 'B'
    elif score >= 70 and score <= 79:
        grade = "C"
    elif score >= 60 and score <= 69:
        grade = "D"
    else:
        grade = "E"
    print(grade)

    score = eval(input())
