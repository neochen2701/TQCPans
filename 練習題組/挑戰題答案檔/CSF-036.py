def find_animals_combination(h, m, n):
    for c in range(h + 1):
        for r in range(h + 1):
            s = h - c - r
            if (2*c + 4*r + 8*s == n) and (2*c + 2*r + 4*s == m):
                print(f"{c} {r} {s}")
                return
    print("No solution")


if __name__ == "__main__":
    h, m, n = map(int, input().split())
    find_animals_combination(h, m, n)
