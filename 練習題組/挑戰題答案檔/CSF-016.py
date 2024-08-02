def main():
  left_balance = right_balance = 0
  s = input()
  n = len(s)

  for i in range(n):
    if s[i] in "(*":
      left_balance += 1
    else:
      left_balance -= 1

    if left_balance < 0:
      print("False")
      return

  if left_balance == 0:
    print("True")
    return
      
  for i in range(n-1, -1, -1):
    if s[i] in ")*":
      right_balance += 1
    else:
      right_balance -= 1

    if right_balance < 0:
      print("False")
      return

  print("True")

main()
