def compute(W, H):
    for i in range(H):
        for j in range(W):
            print('*', end = '')
        print()
    print(W * H)

W = int(input())
H = int(input())
compute(W, H)