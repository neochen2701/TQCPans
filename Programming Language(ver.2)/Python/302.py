def compute(score):
    if score < 0 or score > 100:
        return -1
    elif score >= 60:
        return score + 5
    else:
        return score + 10

score = int(input())
print(compute(score))
