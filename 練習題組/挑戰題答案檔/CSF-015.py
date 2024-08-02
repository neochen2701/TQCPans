def main():
  n = int(input())
  arr = [int(input()) for i in range(n)]

  max_length = 1
  current_length = 1

  for i in range(1, len(arr)):
    if (arr[i] % 2 != arr[i-1] % 2):
      current_length += 1
      max_length = max(max_length, current_length)
    else:
        current_length = 1
  print(max_length)

main()
