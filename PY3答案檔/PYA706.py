num_alph = 26
k = eval(input())


for i in range(k):
    sentence = input()
    alphabet = set(sentence.lower())
    alphabet.remove(' ')
    print(len(alphabet) == num_alph)
