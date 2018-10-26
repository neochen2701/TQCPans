def compute(sentence, w):
    return sentence.count(w)

sentence = input()
word = input()
print(word, "occurs", compute(sentence, word), "time(s)")