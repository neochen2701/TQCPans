def initInput():
    distance=int(input())
    all_site=[]
    for i in range(distance):
        all_site.append(input().split(" "))
    return all_site

def checkHorizonSymmertric(list1):
    for i in range(len(list1)//2):
        for j in range(len(list1)):
            if(list1[i][j]!=list1[len(list1)-i-1][j]):
                return False
    return True

def checkVerticalSymmertric(list1):
    for i in range(len(list1)):
        for j in range(len(list1)//2):
            if(list1[i][j]!=list1[i][len(list1)-j-1]):
                return False
    return True

def checksymmerty1symmertic(list1):
    for i in range(len(list1)):
        for j in range(len(list1)):
            if(list1[i][j]!=list1[j][i]):
                return False
    return True

def checksymmerty2symmertic(list1):
    for i in range(len(list1)):
        for j in range(len(list1)):
            if(list1[i][j]!=list1[len(list1)-j-1][len(list1)-i-1]):
                return False
    return True



def fun():
    all_site=initInput()
    if(checkHorizonSymmertric(all_site)):
        print("unsafe")
        return 0
    if(checkVerticalSymmertric(all_site)):
        print("unsafe")
        return 0
    if(checksymmerty1symmertic(all_site)):
        print("unsafe")
        return 0
    if(checksymmerty2symmertic(all_site)):
        print("unsafe")
        return 0
    print("safe")
    return 1

    

if __name__=="__main__":
    fun()


