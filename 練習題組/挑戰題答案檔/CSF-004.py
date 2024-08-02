def chklogicError(num):
    if(num<1 or num>10):
        return True
    return False

def initInput():
    list=[]
    content=""
    while(content!="0"):
        content=input()
        if(content!="0"):
            list.append(content)
    return list


def fun():
    list=initInput()
    prenum=5
    for i in list:
        prenum+=-1*int(i)
        if(chklogicError(prenum)):
            print("logic error")
            return False
    print(prenum)
    return True

if __name__=="__main__":
    fun()