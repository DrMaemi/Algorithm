#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int testcase;
    vector<int> costs;
    vector<int> answers;
    cin >> testcase;
    for (int tc=0; tc<testcase; tc++) {
        int chapter;
        cin >> chapter;
        for (int ct=0; ct<chapter; ct++) {
            int cost;
            cin >> cost;
            costs.push_back(cost);
        }
        sort(costs.begin(), costs.end());
        int cursor = 0;
        int size = costs.size();
        while (true) {
            for (; cursor<size-1; cursor+=2) {
                costs.push_back(costs[cursor]+costs[cursor+1]);
            }
            if (cursor == size-1) {
                costs.push_back(costs[cursor]);
            }
            int increasedSize = costs.size();
            if (increasedSize-size == 1) break;
            sort(costs.begin()+size, costs.end());
            cursor = size;
            size = increasedSize;
        }
        vector<int>::iterator it = costs.end();
        answers.push_back(*it);
    }
    for (int i=0; i<answers.size(); i++) {
        cout << answers[i] << "\n";
    }
    return 0;
}