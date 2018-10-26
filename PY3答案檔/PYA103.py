word1 = input()
word2 = input()
word3 = input()
word4 = input()

# 靠右對齊
print("|%10s %10s|" % (word1, word2))
print("|%10s %10s|" % (word3, word4))

# 靠左對齊
print("|%-10s %-10s|" % (word1, word2))
print("|%-10s %-10s|" % (word3, word4))
