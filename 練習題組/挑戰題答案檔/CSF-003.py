def cost_transform(c):
    if c >= 'a' and c<='z':
        return ord(c) - ord('a') + 1

    if c>= 'A' and c<='Z':
        return ord(c) - ord('A') + 1

    return 0

def isVowel(c):
    vowel = ['a','e','i','o','u']
    if c in vowel:
        return True
    return False

def cost_Adjust(cost_list,vocabulary):

    cost_list[0] = cost_transform(vocabulary[0])*2
    
    for i in range(1,len(vocabulary)-1):
        if(isVowel(vocabulary[i-1])):
            if(isVowel(vocabulary[i+1])):
                cost_list[i] = cost_list[i] * 3               
            else:
                cost_list[i] = cost_list[i] + cost_list[i+1]   
        else:
            if(isVowel(vocabulary[i+1])):
                cost_list[i] = cost_list[i] + cost_list[i-1]  
            else:
                cost_list[i] = cost_list[i] * 1                

    cost_list[-1] = cost_transform(vocabulary[-1])*4

    return cost_list

def calculate_single_vocabulary(vocabulary):

    cost_list = [0]*len(vocabulary)
    
    for i in range(len(vocabulary)):
        cost_list[i] = cost_transform(vocabulary[i])
    
    cost_list = cost_Adjust(cost_list,vocabulary)

    return sum(cost_list)

def func(content):
    vocabulary_list = [i for i in content.split(' ')]
    
    total = 0
    symbol_count = 0

    for vocabulary in vocabulary_list:
        vocabulary.lower()
        symbol_count += vocabulary.count('.') + vocabulary.count('?')
        vocabulary = vocabulary.replace('.','')
        vocabulary = vocabulary.replace('?','')
        total += calculate_single_vocabulary(vocabulary)

   
    total += symbol_count
    return total


if __name__ == "__main__":
    n = int(input())
    total = 0
    for i in range(n):
        content = input()
        total += func(content)
    print(total)