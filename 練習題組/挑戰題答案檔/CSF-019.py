def convert_to_base(n, base):
  conversion = "0123456789ABCDEF"
  result = ""
  while n > 0:
    result = conversion[n % base] + result
    n //= base
  return result

def is_prime(num):
  if num <= 3:
    return True
  elif num % 2 == 0:
    return False
  for i in range(3,int(num**0.5)+1,2):
    if num % i == 0:
      return False
  return True

def main():
  n, base = [int(i) for i in input().split(" ")]
  converted = convert_to_base(n, base)
  prime_status = "YES" if is_prime(n) else "NO"
  print(f"{converted} {prime_status}")

main()
