def main():
  
  article = [ k for k in (''.join( i if i.isalnum() or i == "'" else " " for i in input().lower())).split(" ") if k != "" ]
  hash = {}
  
  for word in article:
    
    if word in hash:
      hash[word] += 1
    elif word.replace("'","").isalpha() :
      hash[word] = 1

  array = [ [i, j] for i, j in hash.items()]
  array = sorted(array, key=lambda x: (-x[1], x[0]))
  if len(array) < 3:
    print("not an article.")
    return
  print(array[0][0])
  print(array[1][0])
  print(array[2][0])

main()
