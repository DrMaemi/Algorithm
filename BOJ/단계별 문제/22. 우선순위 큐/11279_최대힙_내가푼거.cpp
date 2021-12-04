#include <iostream>
#include <vector>
using namespace std;

#define parent(x) (x-1)/2

int N;
vector<int> maxheap;
vector<int> answers;

void swap(int p, int q) {
    int temp = maxheap[p];
    maxheap[p] = maxheap[q];
    maxheap[q] = temp;
}

void insert_maxheap(int input) {
    maxheap.push_back(input);
    int parent, child;
    child = maxheap.size()-1;
    while (child) {
        parent = parent(child);
        if (maxheap[parent] < maxheap[child]) {
            swap(parent, child);
            child = parent;
        }
        else break;
    }
}

int pop_maxheap() {
    if (maxheap.empty()) {
        return 0;
    }
    int cursor = maxheap.size();
    swap(0, cursor---1);
    int parent = 0;
    while (parent <= cursor/2-1) {
        int child = 2*parent+1;
        if (child+1 < cursor && maxheap[child] < maxheap[child+1]) {
            child++;
        }
        if (maxheap[parent] < maxheap[child]) {
            swap(parent, child);
            parent = child;
        }
        else break;
    }
    int max = maxheap[cursor];
    maxheap.pop_back();
    return max;
}

void print_answers() {
    for (int i=0; i<answers.size(); i++) {
        cout << answers[i] << "\n";
    }
}

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;
    int buf;
    for (int i=0; i<N; i++) {
        cin >> buf;
        if (buf) 
            insert_maxheap(buf);
        else
            answers.push_back(pop_maxheap());
    }
    print_answers();
    return 0;
}