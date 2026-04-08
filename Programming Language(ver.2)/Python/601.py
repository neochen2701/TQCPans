input, n = input(), int(input())
output = ''
if input[n].isupper():
    output = input[:n] + input[n].lower() + input[n+1:]
else:
    output = input[:n] + input[n].upper() + input[n+1:]
print('The letter that was selected is: ' + output[n])
print(output)