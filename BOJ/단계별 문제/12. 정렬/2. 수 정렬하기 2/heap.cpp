// DrMaemi - 8176KB, 752ms
#include <iostream>
#include <vector>
using namespace std;
#define parent(x) (x-1)/2

vector<int> A;

void swap(int p, int q) {
    int tmp = A[p];
    A[p] = A[q];
    A[q] = tmp;
}

void max_heapify() {
    if (A.size() < 2)
        return;

    for (int i=1; i<A.size(); i++) {
        int child = i;

        while (child) {
            int parent = parent(child);

            if (A[parent] < A[child]) {
                swap(parent, child);
                child = parent;
            }

            else break;
        }
    }
}

void ascending_heapsort() {
    int cursor = A.size();

    while (1 < cursor) {
        int parent = 0;

        while (parent <= cursor/2-1) {
            int child = 2*parent+1;

            if (child+1 < cursor && A[child] < A[child+1])
                child++;

            if (A[parent] < A[child]) {
                swap(parent, child);
                parent = child;
            }

            else break;
        }

        swap(0, cursor---1);
    }
}

int main() {
    int N;

    cin >> N;

    for (int i=0; i<N; i++) {
        int tmp;
        
        cin >> tmp;
        A.push_back(tmp);
    }

    max_heapify();
    ascending_heapsort();

    for (int i=0; i<N; i++)
        cout << A[i] << "\n";

    return 0;
}