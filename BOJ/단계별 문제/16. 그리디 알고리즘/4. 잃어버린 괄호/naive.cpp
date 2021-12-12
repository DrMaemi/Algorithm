#include <iostream>
#include <vector>
using namespace std;

int to_int(string s) {
    int r = 0;

    for (char x: s)
        r = 10*r+x-'0';   
    
    return r;
}

int main() {
    string s, buff;
    vector<int> operands;
    vector<char> operators;
    bool appeared = 0;

    cin >> s;
    for (char x: s) {
        if (x == '+' || x == '-') {
            operators.push_back(x);
            operands.push_back(to_int(buff));
            buff.clear();
        }

        else buff.push_back(x);
    }
    operands.push_back(to_int(buff));

    int ans = operands[0];

    for (int i=0; i<operators.size(); i++) {
        if (operators[i] == '-')
            appeared = 1;

        if (appeared)
            ans -= operands[i+1];
        
        else ans += operands[i+1];
    }

    cout << ans;
    return 0;
}