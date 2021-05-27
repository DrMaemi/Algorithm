#include <iostream>
#include <vector>
using namespace std;

#define parent(x) (x-1)/2

void swap(vector<int> &V, int p, int q) {
    int temp = V[p];
    V[p] = V[q];
    V[q] = temp;
}

void MaxHeapify(vector<int> &V, int size) {
    if (size < 2) return;
    int parent, child;
    for (int i=1; i<size; i++) {
        child = i;
        while (child != 0) {
            parent = parent(child);
            if (V[parent] < V[child]) {
                swap(V, parent, child);
                child = parent;
            }
            else break;
        }
    }
}

void AscendingHeapSort(vector<int> &minHeap, int size) {
    int parent, child;
    int cursor = size;
    while (cursor > 1) {
        parent = 0;
        while (parent <= cursor/2-1) {
            child = 2*parent+1;
            if (child+1 < cursor && minHeap[child] < minHeap[child+1]) {
                child++;
            }
            if (minHeap[parent] < minHeap[child]) {
                swap(minHeap, parent, child);
                parent = child;
            }
            else break;
        }
        swap(minHeap, 0, cursor---1);
    }
}

void print_all(vector<int> &V, int size) {
    for (int i=0; i<size; i++) {
        cout << V[i] << " ";
    }
    cout << "\n";
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    vector<int> V;
    cin >> N;
    for (int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        V.push_back(temp);
    }
    MaxHeapify(V, N);
    AscendingHeapSort(V, N);
    print_all(V, N);
    return 0;
}