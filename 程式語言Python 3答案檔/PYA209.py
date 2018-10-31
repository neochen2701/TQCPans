x = eval(input())
y = eval(input())
dist = ((x-5)**2 + (y-6)**2) ** 0.5

if dist <= 15:
    print("Inside")
else:
    print("Outside")