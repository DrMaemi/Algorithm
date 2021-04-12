## Educational Codeforces Round 107 (Rated for Div. 2)

[PROBLEMSET](https://codeforces.com/contest/1511)
 [POST](https://codeforces.com/blog/entry/89562)<br>

<p>
  
  The scoring distribution:<br>
  Unknown
</p>

---

### Participation

<p>Realtime, 2021-04-12 23:35 UTC+9</p>

---

### Solved on contest

<p>A. C.</p>

---

### Tried but couldn't solve

<p>B. D.</p>

---

### Solved after referring to other source codes
<br>

---

### Review
<p>
  A.<br>
  규칙을 잘 생각해보면 타입 1, 3이 모두 upvote함을 알 수 있었다. 지금까지 진행했던 모든 코포 문제 중에 가장 쉬웠다.
</p>

<p>
  B.<br>
  O(nq)로 풀었다간 무조건 TLE라고 판단했는데, 이후에 풀이 방법이 떠오르지 않았다. c = 1이면 에라토스테네스의 체로 수를 구해야되나.. 별 생각을 다 하다가 적절한 풀이를 못찾아 C로 넘어갔다.
</p>

<p>
  C.<br>
  가장 먼저 떠오른 풀이는 a를 벡터로 입력받고 쿼리마다 완탐 후 erase 함수를 사용하는 방식이었는데 push_front()를 해야하기 때문에 deque 자료구조를 사용해야된다는 생각까지 미친 후 시간복잡도를 계산했을 때 TLE라고 판단했다.<br>이후 t의 범위가 1부터 50까지인 것과 쿼리 특성상 특정 t가 등장하는 가장 빠른 index만을 요구한다는 점을 보고 배열에 값을 저장하는 형태로 풀이했다. 이 때 시간복잡도가 O(q)임을 확인하고 제출했다.
</p>

<p>
  D.<br>
  알파벳이 많아봤자 26개임을 이용해서 26개짜리 배열에 우선순위큐로 특정 알파벳(배열의 index가 0부터 k-1까지 a부터 a+k를 의미) 뒤에 k가지 알파벳이 등장한 횟수를 세어 가장 등장 횟수가 적고 사전 순이 빠른 알파벳을 정답 문자열에 더해가는 방식으로 풀이했는데, 구현해놓고 보니 특정 알파벳 뒤에 k가지 알파벳이 모두 동일하게 등장하면 다시 a부터 정답에 더해지는 문제를 해결하지 못하고 컨테스트가 종료됐다.
</p>