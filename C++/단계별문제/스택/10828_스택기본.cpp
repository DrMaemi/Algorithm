#include <iostream>
#include <vector>

using namespace std;

vector<int> answers;

int main(void) {
    int N, num;
    string command;
    vector<int> stack;

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> command;
        if (command == "push") {
            cin >> num;
            stack.push_back(num);
        }
        else if (command == "top") {
            if (!stack.empty()){
                answers.push_back(stack[stack.size()-1]);
                //cout << stack[stack.size()-1] << "\n";
            }
            else {
                answers.push_back(-1);
            }
        }
        else if (command == "size") {
            answers.push_back(stack.size());
            //cout << stack.size() << "\n";
        }
        else if (command == "pop") {
            if (!stack.empty()) {
                answers.push_back(stack[stack.size()-1]);
                //cout << stack[stack.size()-1] << "\n";
                stack.pop_back();
            }
            else {
                answers.push_back(-1);
                //cout << -1;
            }
        }
        else if (command == "empty") {
            answers.push_back(stack.empty());
            //cout << stack.empty() << "\n";
        }
    }

    for (int i=0; i<answers.size(); i++) {
        cout << answers[i] << "\n";
    }

    return 0;
}