f_name = input()

c_line = c_word = c_char = 0

with open(f_name,'r') as file:
    for line in file:
        c_line += 1
        
        word = line.strip('\n').split(' ')
        c_word += len(word)
        
        c_char += sum([len(x) for x in word])

print("%d line(s)" % c_line)
print("%d word(s)" % c_word)
print("%d character(s)" % c_char)        