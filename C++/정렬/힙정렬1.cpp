#include <iostream>
#include <vector>

#define parent(x) (x-1)/2

using namespace std;

void heapify(vector<int> &data, int num);
void heapsort(vector<int> &data, int num);

int main(void) {
    int num, tmp;
    vector<int> data;
    cin >> num;
    for (int i=0; i<num; i++){
        cin >> tmp;
        data.push_back(tmp);
    }
    heapsort(data, num);
    for (int i=0; i<num; i++) {
        cout << data[i] << "\n";
    }
    return 0;
}

void heapify(vector<int> &data, int num) {
    for (int i=1; i<num; i++) {
        int child = i;
        while (child > 0) {
            int root = parent(child);
            if (data[root] < data[child]) {
                int temp = data[root];
                data[root] = data[child];
                data[child] = temp;
                child = root;
            }
            else break;
        }
    }
}

void heapsort(vector<int> &data, int num) {
    heapify(data, num); // 힙으로 만듬, root node가 max
    for (int i=num-1; i>=0; i--) {
        //가장 큰 숫자(root)를 마지막 원소와 스왑
        int tmp = data[i];
        data[i] = data[0];
        data[0] = tmp;
        //마지막 원소를 제외하고 다시 힙을 만듬
        heapify(data, i);
    }
}