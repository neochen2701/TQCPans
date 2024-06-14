import queue

n = int(input())
x = int(input())

allIds = queue.Queue()
for i in range(1, n+1):
    allIds.put(i)

while allIds.qsize() > 1:
    for i in range(1, x):
        t = allIds.get()
        allIds.put(t)
    allIds.get()

print(allIds.get())
