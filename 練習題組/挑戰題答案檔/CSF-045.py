def initInput():
    num=int(input())
    part1=input().split(" ")
    return part1



def findMaxLength(i,part1:list,passed_lst:list):
    all_result=[]
    for j in part1:
        if(i[-1]==j[0]):
            temp=part1.copy()
            temp.remove(j)
            temp2=passed_lst.copy()
            temp2.append(j)
            all_result.append(findMaxLength(j,temp,temp2))
    if(len(all_result)!=0):
        temp=sorted(all_result,key=lambda x:x,reverse=True)
        return temp[0]
    return len(passed_lst)


def fun():
    part1=initInput()
    max_length=0
    for i in part1:
        temp=part1.copy()
        temp.remove(i)
        temp_max=findMaxLength(i,temp,[i])
        max_length=temp_max if(temp_max>max_length) else max_length
    print(max_length)
   

if __name__=="__main__":
    fun()


