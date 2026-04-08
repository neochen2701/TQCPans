def bin2dec(bin):
    dec = 0
    bin_reverse = bin[::-1]
    for idx in range(0, len(bin_reverse)):
        dec += int(bin_reverse[idx]) * (2 ** idx)
    return dec

print(bin2dec(input()))