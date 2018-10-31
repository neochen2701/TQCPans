state = ""
height = eval(input())
while height != -9999:
    weight = eval(input())
    bmi = weight / (height / 100 * height / 100)
    if weight == -9999:
        break
    elif bmi >= 30:
        state = "fat"
    elif bmi >= 25 and bmi < 29.9:
        state = "over weight"
    elif bmi >= 18.5 and bmi <= 24.9:
        state = "normal"
    elif bmi < 18.5:
        state = "under weight"
    print("BMI: %.2f" % bmi)
    print("State: %s" % state)

    height = eval(input())
