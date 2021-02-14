#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, L, r, O[100000];
int M[100000];
//bool visited[100000];

int dir(int s, int l) {
    return s-l ? -1 : 1;
}

void print_M() {
    cout << "print_M():\n";
    for (int i=0; i<N; i++)
        cout << M[i] << " ";
    cout << "\n";
}

int main(void) {
    /*
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    */
    cin >> N >> L >> r;
    int i;
    for (i=0; i<N; i++) cin >> O[i];
    M[0] = r;
    for (i=1; i<N; i++) M[i] = M[i-1]+2*r+1;
    if (M[N-1]+r < L) {
        cout << -1; return 0;
    }
    for (i=0; i<N; i++) M[i] = O[i];
    i = 0;
    for (int l=0; l<=L; l++) {
        if (i+1 < N && abs(M[i]-l) >= abs(M[i+1]-l))
            i++;
        if (r < abs(M[i]-l)) {
            int pre = M[i];
            if (l == 0) M[i] = r;
            else M[i] = l+dir(M[i], l)*r;
            if (M[i]-pre > 0) {
                for (int j=i-1; j>=0; j--) {
                    int sr = M[j]+r+1, sl = M[j+1]-r;
                    if (sr < sl) M[j] += sl-sr;
                    else break;
                }
            }
            else if (M[i]-pre < 0) {
                for (int j=i+1; j<=N; j++) {
                    int sr = M[j-1]+r+1, sl = M[j]-r;
                    if (sr < sl) M[j] -= sl-sr;
                    else break;
                }
            }
        }
    }
    print_M();
    vector<int> moved;
    for (i=0; i<N; i++)
        if (O[i] != M[i]) moved.push_back(i);

    cout << "moved:\n";
    for (int k=0; k<moved.size(); k++) {
        cout << moved[k] << " ";
    } cout << "\n";

    int answer = 0;
    int p = 0,  left = 0, right = 0;
    for (int j=0; j<moved.size(); j++) {
        i = moved[j];
        answer += O[i]-p;
        if (left == p) left = O[i]; p = O[i];
        left = min(M[i], left); right = max(p, right);
        printf("p: %d, left: %d, ", p, left);
        if (j+1 != moved.size()) {
            right = max(max(O[moved[j+1]], M[i]), right);
            printf("right: %d\n", right);
            if (p-left <= right-p) {
                answer += 2*(p-left);
                left = p;
            }
        }
        else {
            right = max(M[i], right);
            printf("right: %d\n", right);
            if (p-left <= right-p)
                answer += 2*(p-left)+right-p;
            else
                answer += 2*(right-p)+p-left;
        }
    }
    /*
    vector<int> moved;
    for (i=0; i<N; i++) 
        if (O[i] != M[i]) moved.push_back(i);
    int answer = 0;
    if (!moved.empty()) {
        int fr = moved.front(), ba = moved.back();
        int ol = O[fr], ml = M[fr];
        int oh = O[ba], mh = M[ba];
        answer += oh;
        int low = oh;
        for (int j: moved) {
            if (M[j] < O[j]) {
                low = j; break;
            }
        }
        answer += oh-
    }
    print_M();
    */
    /*
    int p = 0, answer = 0;
    for (i=0; i<N; i++) {
        if (visited[i])
            answer += abs(M[i]-p);
        else if (O[i] != M[i])
            answer += O[i]-p+abs(M[i]-O[i]);
        int low = min(p, M[i]), high = max(O[i], M[i]);
        p = M[i];
        for (int j=i+1; j<N; j++) {
            if (low <= O[j] && O[j] <= high)
                visited[j] = 1;
            else break;
        }
    }
    */
    cout << answer;
    return 0;
}