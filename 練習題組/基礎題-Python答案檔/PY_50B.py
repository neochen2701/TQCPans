number = 5

def multiple_number(a):
    global number
    number *= a

a = int(input())
multiple_number(a)
print(number)