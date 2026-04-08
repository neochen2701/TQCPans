def bin2dec(bin):
    dec = 0
    bin_reverse = bin[::-1]
    for idx in range(0, len(bin_reverse)):
        dec += int(bin_reverse[idx]) * (2 ** idx)
    return dec

def dec2bin(dec):
    if dec > 255:
        return '11111111'
    bin = ''
    while dec:
        bin = str(int(dec % 2)) + bin
        dec = int(dec/2)
    return bin

n1, n2 = input(), input()
print(str(bin2dec(n1)) + ' + ' + str(bin2dec(n2)) + ' = ' + str(int(n1, 2) + int(n2, 2)))
ans = str(dec2bin(int(n1, 2) + int(n2, 2)))
while(len(ans) < 8):
    ans = '0' + ans
print(ans)
