def caculate_sum_avg(inputs):
    for student_scores in inputs:
        scores = list(map(int, student_scores[1:]))
        sum_score = sum(scores)
        avg_score = sum_score / len(scores)
        student_scores.append(sum_score)
        student_scores.append(f'{avg_score:.2f}')

inputs = []
while True:
    input_str = input()
    if input_str == 'END':
        break
    input_scores = input_str.split()
    inputs.append(input_scores)

caculate_sum_avg(inputs)

inputs.sort(key=lambda x: -float(x[-2]))

for student_scores in inputs:
    print(*student_scores)