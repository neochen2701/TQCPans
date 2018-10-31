even = odd = 0

for i in range(10):
    a = int(input())
    if a%2 == 0: 
        even += 1
    else:
        odd += 1
        
print("Even numbers:", even)
print("Odd numbers:", odd)