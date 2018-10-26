word1 = input()
word2 = input()
word3 = input()
word4 = input()
word5 = input()
word6 = input()

# 靠右對齊
print("|%12s %12s|" % (word1, word2))
print("|%12s %12s|" % (word3, word4))
print("|%12s %12s|" % (word5, word6))

# 靠左對齊
print("|%-12s %-12s|" % (word1, word2))
print("|%-12s %-12s|" % (word3, word4))
print("|%-12s %-12s|" % (word5, word6))
