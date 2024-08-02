def canMeasure(A,B,L):
    canGetList = [False] * (A+B+1)
    canGetList[A+B] = True
    canGetList[0] = True
    if A < B:
        A,B = B,A
    
    i = B
    while not canGetList[i]:
        while i <= A:
            canGetList[B+i] = True
            canGetList[i] = True
            i+=B
        i = i % A
    return canGetList[L]

def main():
    A = int(input())
    B = int(input())
    n = int(input())
    mList = [int(m) for m in input().split()]
    for m in mList:
        if not canMeasure(A,B,m):
            print("fail")
            return
    else:
        print("pass")
    
    
if __name__ == "__main__":
    main()