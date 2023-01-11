keyboard = [['q','w','e','r','t','y','u','i','o','p']
            , ['a','s','d','f','g','h','j','k','l']
            , ['z','x','c','v','b','n','m']]

def find_right_alpha(c):
    global keyboard
    output_c = ''
    for i in range(len(keyboard)):
        if c in keyboard[i]:
            idx = keyboard[i].index(c)
            # print(idx)
            if idx == len(keyboard[i]) - 1:
                output_c = keyboard[i][idx]
            else:
                output_c = keyboard[i][idx + 1]
    return output_c

input_str = input()
output_str = ''
for c in input_str:
    if c.isupper():
        c = c.lower()
        # print(c)
        output_str += find_right_alpha(c).upper()
    else:
        output_str += find_right_alpha(c)
print(output_str)
                    
        
