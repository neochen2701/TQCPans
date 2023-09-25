text = input()

text_length = len(text)
status = "OK" if text_length >= 8 else "FAILED"

print(status)