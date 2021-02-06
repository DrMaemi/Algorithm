#include <iostream>
#include <vector>
using namespace std;

#define parent(x) (x-1)/2
#define child(x) 2*x+1

int N;
vector<int> minheap;
vector<int> answers;

template<class T>
void swap(T& arr, int p, int q) {
    auto temp = arr[p];
    arr[p] = arr[q];
    arr[q] = temp;
}

void insert_minheap(int input) {
    minheap.push_back(input);
    int child = minheap.size()-1;
    while (child) {
        int parent = parent(child);
        if (minheap[child] < minheap[parent]) {
            swap(minheap, parent, child);
            child = parent;
        }
        else break;
    }
}

int pop_minheap() {
    int cursor = minheap.size();
    if (!cursor) return 0;
    swap(minheap, 0, cursor---1);
    int min = minheap[cursor];
    int parent = 0;
    while (parent <= cursor/2-1) {
        int child = child(parent);
        if (child+1 < cursor && minheap[child+1] < minheap[child]) {
            child++;
        }
        if (minheap[child] < minheap[parent]) {
            swap(minheap, parent, child);
            parent = child;
        }
        else break;
    }
    minheap.pop_back();
    return min;
}

void print_answers() {
    for (int i=0; i<answers.size(); i++) {
        cout << answers[i] << "\n";
    }
}

int main(void) {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;
    int buf;
    for (int i=0; i<N; i++) {
        cin >> buf;
        if (buf) 
            insert_minheap(buf);
        else
            answers.push_back(pop_minheap());
    }
    print_answers();
    return 0;
}