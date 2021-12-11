#include <iostream>
using namespace std;

#define divisor 1000000000
#define mod(x) (x)%divisor

int N;
int memo[10][100];

void initialize() {
	cin >> N;
	for (int i=0; i<10; i++) {
		memo[i][0] = 1;
	}
}

int get_answer() {
	int answer = 0;
	for (int num=1; num<10; num++) {
		answer = mod(answer+memo[num][N-1]);
	}
	return answer;
}

int main(void) {
	initialize();
	for (int pos=1; pos<N; pos++) {
		for (int num=0; num<10; num++) {
			if (!num)
				memo[num][pos] = memo[num+1][pos-1];
			else if (num == 9)
				memo[num][pos] = memo[num-1][pos-1];
			else
				memo[num][pos] = mod(memo[num-1][pos-1]+memo[num+1][pos-1]);
		}
	}
	cout << get_answer();
	return 0;
}