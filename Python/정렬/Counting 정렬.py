max_num = 1000 # 입력될 수 있는 최대 숫자
N = int(input())
data = [int(input()) for _ in range(N)]
# 0으로 초기화된 입력될 max_num+1 길이의 배열 count 생성
count = [0]*(max_num+1)
# 누적합 저장 배열 생성
countSum = [0]*(max_num+1)
# 숫자 등장 횟수 세기
for idx in range(N):
    count[data[idx]] += 1
# 숫자 등장 횟수 누적합 구하기
countSum[0] = count[0]
for idx in range(1, max_num+1):
    countSum[idx] = countSum[idx-1]+count[idx]
result = [0]*(N+1)
for idx in range(N-1, -1, -1):
    result[countSum[data[idx]]] = data[idx]
    countSum[data[idx]] -= 1
for val in result: print(val)