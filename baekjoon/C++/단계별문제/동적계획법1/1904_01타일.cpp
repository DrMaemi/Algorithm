#include <iostream> 
#define mod 15746

using namespace std;

int main(void){
	int n;
    long long* answers;
	cin >> n;
	answers = new long long[n+1];
    if (n == 1 || n == 2) {
        cout << n << "\n";
        return 0;
    }
    answers[1] = 1;
    answers[2] = 2;
    for (int i=3; i<=n; i++) {
        answers[i] = (answers[i-2]+answers[i-1]) % mod;
    }
	cout << answers[n] << "\n";
    return 0;
}