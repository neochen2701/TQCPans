def initInput():
    part1=input().split(" ")
    part2=input().split(" ")
    part1_ans=input().split(" ")
    part2_ans=input().split(" ")
    return part1,part2,part1_ans,part2_ans

def checkPart1Grade(part1,part1_ans):
    score=0
    for i in range(len(part1)):
        if(part1[i]==part1_ans[i]):
            score+=10
        else:
            if(part1[i]!="0"):
                score-=3
    return score

def checkPart2Grade(part2,part2_ans):
    score=0
    for i in range(len(part2)):
        if(part2[i]==part2_ans[i]):
            score+=10
        elif(part2[i]=="0"):
            score+=0
        else:
            temp_score=10
            for j in part2[i]:
                if(j not in part2_ans[i]):
                    temp_score-=3
            for j in part2_ans[i]:
                if(j not in part2[i]):
                    temp_score-=3
            if(temp_score>0):
                score+=temp_score
    return score

def fun():
    part1,part2,part1_ans,part2_ans=initInput()
    score=checkPart1Grade(part1,part1_ans)
    score+=checkPart2Grade(part2,part2_ans)
    if(score>0):
        print(score)
    else:
        print(0)
    

if __name__=="__main__":
    fun()


