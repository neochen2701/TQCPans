def initInput():
    distance=int(input())
    all_site=[]
    for i in range(6):
        temp=input()
        for j in range(len(temp)):
            if(temp[j]=='1'):
                all_site.append([i,j])
    return distance,all_site

def chkSafe(distance,all_site):
    for i in range(10):
        for j in range(i+1,len(all_site)):
            row=((all_site[i][0]-all_site[j][0])**2)**0.5
            col=((all_site[i][1]-all_site[j][1])**2)**0.5
            if((row+col)<=distance):
                return False
    return True

def fun():
    distance,all_site=initInput()
    if(chkSafe(distance,all_site)):
        print("safe")
    else:
        print("unsafe")

if __name__=="__main__":
    fun()


