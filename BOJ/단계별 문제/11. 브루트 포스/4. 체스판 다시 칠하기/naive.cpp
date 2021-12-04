#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define MAX 2500

int main() {
    int N, M, ans = MAX;
    vector<vector<int>> board;
    
    cin >> N >> M;

    for (int i=0; i<N; i++) {
        string s;
        vector<int> row;

        cin >> s;

        for (char c: s) {
            if (c == 'W') {
                row.push_back(0);
            }

            else {
                row.push_back(1);
            }
        }

        board.push_back(row);
    }

    for (int y=0; y<N-7; y++) {
        for (int x=0; x<M-7; x++) {
            for (int _case=0; _case<2; _case++) {
                int cnt = 0;

                for (int i=y; i<y+8; i++) {
                    for (int j=x; j<x+8; j++) {
                        if ((i+j+-x-y+_case)%2 == board[i][j]) {
                            cnt++;
                        }
                    }
                }

                ans = cnt < ans? cnt: ans;
            }
        }
    }

    cout << ans;
    return 0;
}