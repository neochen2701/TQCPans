def main():

  array=[ [] for i in range(4)]
  in_t=[int(i) for i in input().split(" ")]
  for i in range(0,len(in_t),3):
    for j in range(3):
      array[i//3].append(in_t[i+j])
  
  for i in range(4):
    array[i].sort()
    if array[i][2]>=(array[i][0]+array[i][1]):
      print("n")
      return

  for i in range(3):
    for j in range(i+1,4):
      if not((array[i][0] in array[j])and(array[i][1] not in array[j])and(array[i][2] not in array[j])or\
          (array[i][1] in array[j])and(array[i][0] not in array[j])and(array[i][2] not in array[j])or\
          (array[i][2] in array[j])and(array[i][0] not in array[j])and(array[i][1] not in array[j])
             ):
        print("n")
        return

  print("y")  

main()

