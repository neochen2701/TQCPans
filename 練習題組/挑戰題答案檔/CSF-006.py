def getScore(article, keyword):
    if('+' in keyword):
        score = 0
        keyword = keyword.split('+')
        compare1 = ""
        compare2 = ""
        for i in range(0, len(keyword)):
            if(i!=0):
                compare1 += ' '
            compare1 += keyword[i].upper()
        for i in range(0, len(keyword)):
            compare2 += keyword[i].upper()
        score += article.upper().count(compare1)
        score += article.upper().count(compare2)
        return score*3
    else:
        return article.upper().count(keyword.upper())

def sortArticle(articles):
    for i in range(len(articles)-1):
        for j in range(len(articles)-1):
            if(articles[j][0]<articles[j+1][0]):
                articles[j], articles[j+1] = articles[j+1], articles[j]
    return articles

def showResult(articles):
    flag = True
    for article in articles:
        if(article[0] > 0):
            flag = False
            print(article[1])
    if(flag):
        print("No relevant articles found")

def main():
    N = int(input())
    keywords = input().split(' ')
    records = []
    for index in range(N):
        records.append([input()])
    for record in range(len(records)):
        score = 0
        for keyword in keywords:
            score += getScore(records[record][0], keyword)
        records[record].insert(0, score)
    records = sortArticle(records)
    showResult(records)

main()