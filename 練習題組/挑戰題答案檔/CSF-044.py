def findDegOneNodeConnectNode(node,edgeList):
    for e in edgeList:
        if node in e:
            for eNode in e:
                if eNode != node:
                    return eNode
    return -1

def getNodeAdjacentNodes(node,edgeList):
    AdjacentNodes = set()
    adjEdges = [edge for edge in edgeList if node in edge]
    for e in adjEdges:
        for eNode in e:
            if eNode != node:
                AdjacentNodes.add(eNode)
    return AdjacentNodes

def getNodeDegreeList(edgeList):
    nodeDegreeDict = dict()
    for edge in edgeList:
        for node in edge:
            if node in nodeDegreeDict.keys():
                nodeDegreeDict[node] += 1
            else:
                nodeDegreeDict[node] = 1
    nodeDegreeList = sorted([[node,deg] for node,deg in nodeDegreeDict.items()],key = lambda x:x[1])
    return nodeDegreeList

def reduceNode(node,edgeList):
    i = 0
    while i < len(edgeList):
        edge = edgeList[i]
        if node in edge:
            edgeList.remove(edge)
        else:    
            i+=1

def getCandidateNode(edgeList,nodeDegreeList):
    candidateNodes = list()
    hasDegOneNode = False
    for nodeDegPair in nodeDegreeList:
        node = nodeDegPair[0]
        deg = nodeDegPair[1]
        if deg == 1:
            hasDegOneNode = True
            candidateNodes.append(findDegOneNodeConnectNode(node,edgeList))

    
    if not hasDegOneNode:
        maxDeg = nodeDegreeList[-1][1]
        maxDegNodeList = [nodePair[0] for nodePair in nodeDegreeList if nodePair[1] == maxDeg]
        candidateNodes = maxDegNodeList
    
    return candidateNodes[0]
        
def main():
    
    result = 0
    N = int(input())
    edgeList = list()
    for i in range(N):
        edge = set(int(x) for x in input().split())
        edgeList.append(edge)
    nodeDegreeList =  getNodeDegreeList(edgeList)
    totalReduceNode = 0
    totalNode = len(nodeDegreeList)
    while len(edgeList) > 0:
        candidateNode = getCandidateNode(edgeList,nodeDegreeList)
        candidateAdjNode = getNodeAdjacentNodes(candidateNode,edgeList)
        for node in candidateAdjNode:
            reduceNode(node,edgeList)
        reduceNode(candidateNode,edgeList)
        totalReduceNode += 1 + len(candidateAdjNode)
        nodeDegreeList = getNodeDegreeList(edgeList)
        result += 1
    result += (totalNode-totalReduceNode)
    print(result)

main()