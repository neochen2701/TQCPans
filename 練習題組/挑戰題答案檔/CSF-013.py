def getMaxCandy(candyList):
    candyList.sort(reverse=True)
    if (candyList[1] == candyList[2] == 0):
        if(candyList[0] < 3):
            return 0
        else:
            among =  int(candyList[0]/3)
            candyList[0] %= 3
            candyList[0] += among
    else:
        among = 1
        candyList[0] -= 1
        candyList[1] -= 1
        candyList[2] += 1
    return among + getMaxCandy(candyList)


def main():
    r = int(input())
    g = int(input())
    b = int(input())
    candyList = [r,g,b]
    result = sum(candyList) + getMaxCandy(candyList)
    print(result)

if __name__ == "__main__":
    main()