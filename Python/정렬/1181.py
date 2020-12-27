if __name__ == "__main__":
    numWords = int(input())
    wordsList = []
    for _ in range(numWords):
        wordsList.append(input())
    wordsList = sorted(wordsList, key=lambda x:(len(x), x))
    for idx in range(len(wordsList[:-1])):
        if wordsList[idx] == wordsList[idx+1]: continue
        print(wordsList[idx])
    print(wordsList[-1])