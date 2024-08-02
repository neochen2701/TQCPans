def componentToComputer(component, target):
    ans = 0
    answ = 0
    tmpp = 1      
    component = sorted(component)
        
    for i in component:
        while i > tmpp:
            ans += 1
            tmpp *= 2    
        tmpp += i
        if tmpp > target:
            break

    while tmpp <= target:
        ans += 1
        tmpp *= 2

    if component[0] >= target:
        component = [0]
        tmpp = 1
        for i in component:
            while i > tmpp:
                answ += 1
                tmpp *= 2    
            tmpp += i
            if tmpp > target:
                break

        while tmpp <= target:
            answ += 1
            tmpp *= 2
            
        return ans if ans < answ else answ
    
    return ans

def main():
    total_num = int(input())
    components = list(map(int, input().split()))
    target = int(input())
    answers = componentToComputer(components, target)

    print(answers)

if __name__ == '__main__':
    main() 
