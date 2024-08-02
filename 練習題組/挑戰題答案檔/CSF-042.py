def initDictRegister(register):
    dictRgister = dict()
    for name in register:
        dictRgister[name] = "Not Init"
    return dictRgister
        
def upperValue(M):
    return 2**(M-1)-1

def lowerValue(M):
    return -(2**(M-1))

def convertDecimal(value):
    total = 0
    value = value[-1::-1]
    for i in range(0, len(value)):
        total += int(value[i]) * (2**i)
    return total

def load(dictRgister, clearRgister, lower, upper, data):
    if(data[1] in dictRgister and data[1] in clearRgister):
        del clearRgister[data[1]]
    value = convertDecimal(data[2]) if data[2] not in dictRgister else dictRgister[data[2]]
    if(value=="Overflow" or value=="Not Init"):
        dictRgister[data[1]] = "Overflow"
    else:
        if(value>=upper or value<lower):
            dictRgister[data[1]] = "Overflow"
        else:
            dictRgister[data[1]] = value

def store(dictRgister, clearRgister, lower, upper, data):
    if(data[2] in dictRgister and data[2] in clearRgister):
        del clearRgister[data[2]]
    value = convertDecimal(data[1]) if data[1] not in dictRgister else dictRgister[data[1]]
    if(value=="Overflow" or value=="Not Init"):
        dictRgister[data[2]] = "Overflow"
    else:
        if(value>=upper or value<lower):
            dictRgister[data[2]] = "Overflow"
        else:
            dictRgister[data[2]] = value

def add(dictRgister, clearRgister, lower, upper, data):
    if(data[2] in dictRgister and data[2] in clearRgister):
        del clearRgister[data[2]]
    if(data[3] in dictRgister and data[3] in clearRgister):
        del clearRgister[data[3]]
    value1 = convertDecimal(data[2]) if data[2] not in dictRgister else dictRgister[data[2]]
    value2 = convertDecimal(data[3]) if data[3] not in dictRgister else dictRgister[data[3]]
    if(value1=="Overflow" or value1=="Not Init" or value2=="Overflow" or value2=="Not Init"):
        dictRgister[data[1]] = "Overflow"
    else:
        value = value1 + value2
        if(value>=upper or value<lower):
            dictRgister[data[1]] = "Overflow"
        else:
            dictRgister[data[1]] = value
            
def sub(dictRgister, clearRgister, lower, upper, data):
    if(data[2] in dictRgister and data[2] in clearRgister):
        del clearRgister[data[2]]
    if(data[3] in dictRgister and data[3] in clearRgister):
        del clearRgister[data[3]]
    value1 = convertDecimal(data[2]) if data[2] not in dictRgister else dictRgister[data[2]]
    value2 = convertDecimal(data[3]) if data[3] not in dictRgister else dictRgister[data[3]]
    if(value1=="Overflow" or value1=="Not Init" or value2=="Overflow" or value2=="Not Init"):
        dictRgister[data[1]] = "Overflow"
    else:
        value = value1 - value2
        if(value>=upper or value<lower):
            dictRgister[data[1]] = "Overflow"
        else:
            dictRgister[data[1]] = value

def clear(clearRgister, data):
    clearRgister[data[1]] = 4

def checkResetStatus(dictRgister, clearRgister):
    deleteList = []
    for key in clearRgister:
        clearRgister[key] -= 1
        if(clearRgister[key]==0):
            dictRgister[key] = 0
            deleteList.append(key)
    for item in deleteList:
        del clearRgister[item]

def showResult(dictRgister):
    for key in dictRgister:
        print(key, dictRgister[key])

def main():
    _input = input().split(" ")
    N = int(_input[0])
    M = int(_input[1])
    upper = upperValue(M)
    lower = lowerValue(M)
    registerName = input().split(" ")
    dictRgister = initDictRegister(registerName)
    clearRgister = dict()
    _input = input()
    while(_input != "-1"):
        data = _input.split(" ")
        if(data[0] == "LOAD"):
            load(dictRgister, clearRgister, lower, upper, data)
        elif(data[0] == "STORE"):
            store(dictRgister, clearRgister, lower, upper, data)
        elif(data[0] == "ADD"):
            add(dictRgister, clearRgister, lower, upper, data)
        elif(data[0] == "SUB"):
            sub(dictRgister, clearRgister, lower, upper, data)
        elif(data[0] == "CLEAR"):
            clear(clearRgister, data)
        checkResetStatus(dictRgister, clearRgister)
        _input = input()
    showResult(dictRgister)

main()