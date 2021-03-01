#include <iostream>
#include <vector>
using namespace std;

int N, L, r, O[100000];
int M[100000];

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
    /* cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0); */
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
    vector<int> mi;
    for (i=0; i<N; i++)
        if (O[i] != M[i]) mi.push_back(i);
    if (mi.empty()) {
        cout << 0; return 0;
    }
    int p = 0, sum = 0, l = L, r = 0;
    // int r = max(O[mi.back()], M[mi.back()]);
    for (int i=0; i<mi.size()-1; i++) {
        int ci = mi[i], ni = mi[i+1];
        sum += O[ci]-p;
        p = O[ci];
        l = min(min(O[ci], M[ci]), l);
        // r = max(M[ci], O[ni]);
        //O[ni]-p+M[ci]-p;
        if (abs(l-p) <= M[ni]-p) {
            // printf("ci:%d | l:%d, r:%d, p:%d\n", ci, l, r, p);
            sum += 2*abs(l-O[ci]);
            l = L;
        }
    }
    sum += O[mi.back()]-p;
    p = O[mi.back()];
    l = min(min(p, M[mi.back()]), l);
    r = max(p, M[mi.back()]);
    if (abs(l-p) <= abs(r-p))
        sum += 2*abs(l-p)+abs(r-p);
    else
        sum += 2*abs(r-p)+abs(l-p);
    cout << sum;
    return 0;
}