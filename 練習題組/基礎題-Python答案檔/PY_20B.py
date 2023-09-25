score = int(input())

if score >= 60:
	result = score + 5
	print(int(result))
else:
	result = 10*(score**0.5)
	print(int(result))