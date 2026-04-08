with open(r'read.txt', 'r') as infile, open(r'write.txt', 'w') as outfile:
    data = infile.read()
    data = data.replace("*", "")
    outfile.write(data)