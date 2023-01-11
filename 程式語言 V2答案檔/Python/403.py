str = input()
trans_str = ''
for c in str:
    if c.isupper():
        trans_str += c.lower()
    else:
        trans_str += c.upper()
print(trans_str)