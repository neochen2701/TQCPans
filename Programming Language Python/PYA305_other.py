
# 1 ---int 以數學先取餘數，再取商數倒回 解題
s = int(input())

while s != 0:
    print(s % 10, end='')
    s //= 10

'''
#2 ---str 以切片（slice） 解題
s = input()
print(s[::-1])

#3 ---str for迴圈反轉 解題
s = input()
for i in range((len(s)-1), -1, -1):
    print(s[i], end='')

# ---str 迭代 
迭代每個字元，一個個接起來
假設s是'abc'，
迴圈第一輪，r會變成'a' + '' 也就是'a'，
迴圈第二輪，r會變成'b' + 'a' 也就是'ba'，
迴圈第二輪，r會變成'c' + 'ba' 也就是'cba'，

#4 ---str 迭代 for迴圈 解題
s = input()

r = ''
for c in s:
    r = c + r

print(r)

#5 ---str 迭代 函式 解題
s = input()


def reverse_i(s):
    r = ''
    for c in s:
        r = c + r
    return r


print(reverse_i(s))
'''
