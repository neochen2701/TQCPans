def largest_rectangle_area(heights):
    stack = []
    max_area = 0
    max_rect = (0, 0, 0, 0)
    i = 0

    while i < len(heights):
        if not stack or heights[i] >= heights[stack[-1]]:
            stack.append(i)
            i += 1
        else:
            while stack and heights[i] < heights[stack[-1]]:
                top = stack.pop()
                width = i if not stack else i - stack[-1] - 1
                area = heights[top] * width
                if area > max_area:
                    max_area = area
                    left = stack[-1] + 1 if stack else 0
                    right = i - 1
                    max_rect = (top, left, top + heights[top] - 1, right)
            stack.append(i)
            i += 1

    while stack:
        top = stack.pop()
        width = i if not stack else i - stack[-1] - 1
        area = heights[top] * width
        if area > max_area:
            max_area = area
            left = stack[-1] + 1 if stack else 0
            right = i - 1
            max_rect = (top, left, top + heights[top] - 1, right)

    return max_area, max_rect

def largest_white_rectangle(matrix):
    if not matrix or not matrix[0]:
        return 0, None, None

    rows = len(matrix)
    cols = len(matrix[0])
    heights = [0] * cols
    max_area = 0
    max_rect = None

    for i in range(rows):
        for j in range(cols):
            if matrix[i][j] == '1':
                heights[j] += 1
            else:
                heights[j] = 0

        area, rect = largest_rectangle_area(heights)
        if area > max_area:
            max_area = area
            top, left, bottom, right = rect
            max_rect = (i - bottom + top, left, i, right)

    return max_area, max_rect

rows,cols = map(int, input().split())
matrix = []
for _ in range(rows):
    row = input().split()
    matrix.append(row)

area, max_rect = largest_white_rectangle(matrix)
print(area)
if area > 0 and max_rect:
    top_left = (max_rect[0], max_rect[1])
    bottom_right = (max_rect[2], max_rect[3])
    print(top_left)
    print(bottom_right)
