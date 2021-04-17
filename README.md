## Codeforces Round #715 (Div. 2)

[PROBLEMSET](https://codeforces.com/contest/1511)
 [POST](https://codeforces.com/topic/90245/en1)<br>
 [EDITORIAL](https://codeforces.com/blog/entry/89644)

<p>
  
The scoring distribution:<br>
500 — 1000 — 1500 — 2250 — 2500 — 3000
</p>

---

### Participation

<p>Realtime, 2021-04-16 23:35 UTC+9</p>

---

### Solved on contest

<p>A. B.</p>

---

### Tried but couldn't solve

<p>C.</p>

---

### Solved after referring to other source codes
<br>

---

### Review
<p>
A.<br>
입력받을 때 홀수끼리 짝수끼리 나누어 입력받아 출력해도 정답인 문제였다. 제출까지 7분 걸렸는데 영어 독해 실력이 좋았다면 2분만에 풀었을 것 같다.
</p>
<p>
B.<br>
M이 등장할 때마다 해당 M의 왼쪽, 오른쪽에 존재하는 모든 T의 개수를 헤아리는 방식으로 풀이를 접근했다. 로직을 생각해내는 데 생각보다 오래걸렸고, 구현하는 데도 생각보다 오래걸렸다. 시작 1시간 후에 제출했는데 문제를 많이 풀어보고 로직 구상 + 구현에 걸리는 시간을 줄이려고 노력해야겠다.
</p>
<p>
C.<br>
남은 1시간 15분을 전부 썼는데 제출하지 못했다. Contest 중 입력받을 때 수가 중복된다면 가장 많이 중복된 수들 우선순위로 정답 배열을 구성하며 중복 횟수가 같은 수 중에선 정답배열 내 특정 index 전까지 등장한 수의 min, max 값이 해당 특정 index의 수가 등장한 후 변화량이 최소가 되는 수가 우선 등장하게끔 로직을 구상했다.<br>
로직을 구상하는 것도 힘들었는데 구현하는 건 더더욱 힘들었다. 종료 1분 전에 코드를 완성했는데 검토 중 문제를 발견해서 제출하지 못했다.<br>
더 쉬운 풀이가 있을 것이라 생각한다. 역시 코포 문제를 많이 풀어봐야할 것 같다.
</p>

### Up-Solving
<p>
C.<br>
역시 다른 풀이가 있었다. 수열 a를 입력받고 이를 정렬하면 최소, 최대값을 알 수 있는데 이 최소, 최대값 중 한 가지가 정답배열에서 가장 늦게 나타나야 discripancy의 합이 최소가 됨이 자명하다.<br>
한 편 수열 a에서 기술한 것처럼 풀이한 경우 최소, 최대값 중 한 값이 빠진 부분 수열에 대해서 문제 정의를 동일하게 할 수 있다. 따라서 DP에 사용할 배열을 선언하여 특정 부분수열에 대해 최소값이나 최대값이 제외되는 각각의 경우에 대해 discripancy 합이 최소가 되는 값을 DP 배열에 저장해놓는 방식으로 풀이해야 한다.
</p>