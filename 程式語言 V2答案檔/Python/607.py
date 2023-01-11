flower = ['S', 'H', 'D', 'C']
cards = input().split(' ')
if flower.index(cards[0][0]) < flower.index(cards[1][0]):
    print(cards[0] + ' > ' + cards[1])
elif flower.index(cards[0][0]) > flower.index(cards[1][0]):
    print(cards[0] + ' < ' + cards[1])
else:
    if int(cards[0][1:]) < int(cards[1][1:]):
        print(cards[0] + ' < ' + cards[1])
    elif int(cards[0][1:]) > int(cards[1][1:]):
        print(cards[0] + ' > ' + cards[1])
    else:
        print(cards[0] + ' = ' + cards[1])