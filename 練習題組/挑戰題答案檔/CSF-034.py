def relocateBalls(nums, move_from, move_to):
    positions = nums
    positions_movement = [0] * len(nums)
    points = 0

    for idx in range(len(move_from)):
        for item in nums:
            if item == move_from[idx]:
                p_idx = positions.index(move_from[idx])
                positions[p_idx] = move_to[idx]
                positions_movement[p_idx] += 1
        
    for pp in positions_movement:
        if pp >= 2: points += 1

    return positions_movement, points

def main():
    balls = list(map(int, input().split()))
    move_from = list(map(int, input().split()))
    move_to = list(map(int, input().split()))

    pmv, points = relocateBalls(balls, move_from, move_to)
    print(' '.join(map(str, pmv)))
    print(points)

if __name__ == "__main__":
    main()