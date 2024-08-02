def getMatrixValue(dpMatrix,n,m,sticks):
    if m == 0:
        dpMatrix[n][m] = 0
    elif n == 0:
        dpMatrix[n][m] = -1
    else:
        if dpMatrix[n][m] == 0:
            if m-sticks[n-1] < 0:
                putValue = -1
            else:
                putValue = getMatrixValue(dpMatrix,n-1,m-sticks[n-1],sticks)
                if putValue != -1:
                    putValue += 1
            
            noputValue = getMatrixValue(dpMatrix,n-1,m,sticks)
            dpMatrix[n][m] = max(putValue,noputValue)
    return dpMatrix[n][m]

def main():
    n = int(input())
    sticks = [int(x) for x in input().split()[:n]]

    m = int(input())
    dpMatrix = [ [0] * (m+1) for _ in range(n+1) ]
    print(getMatrixValue(dpMatrix,n,m,sticks))


if __name__ == "__main__":
    main()
