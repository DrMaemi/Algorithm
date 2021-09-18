#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int* numbers;

struct tup {
    int value;
    int count;
};

int get_avg(int* numbers, int size) {
    double avg = 0;
    for (int i=0; i<size; i++) {
        avg += numbers[i];
    }
    return round(avg/size);
}

vector<tup> get_cnts(int* numbers, int size) {
    vector<tup> cnts;
    if (size == 1) {
        tup buffer = {numbers[0], 1};
        cnts.push_back(buffer);
        return cnts;
    }
    int previous = numbers[0];
    int cnt = 1;
    for (int i=1; i<size; i++) {
        if (numbers[i] == previous) {
            cnt++;
            continue;
        }
        tup buffer = {previous, cnt};
        cnts.push_back(buffer);
        previous = numbers[i];
        cnt = 1;
    }
    tup buffer = {previous, cnt};
    cnts.push_back(buffer);
    return cnts;
}

bool comparator(tup a, tup b) {
    if (a.count < b.count) {
        return true;
    }
    else if (a.count > b.count) {
        return false;
    }
    else {
        return a.value > b.value;
    }
}

int get_mode(vector<tup> cnts) {
    int size = cnts.size();
    if (size == 1) {
        return cnts[size-1].value;
    }
    if (cnts[size-1].count == cnts[size-2].count) {
        return cnts[size-2].value;
    }
    return cnts[size-1].value;
}

int main(void) {
    cin >> N;
    numbers = (int*)malloc(sizeof(int)*N);
    for (int i=0; i<N; i++) {
        cin >> numbers[i];
    }
    sort(numbers, numbers+N);
    cout << get_avg(numbers, N) << "\n";
    cout << numbers[N/2] << "\n";
    vector<tup> cnts = get_cnts(numbers, N);
    sort(cnts.begin(), cnts.end(), comparator);
    cout << get_mode(cnts) << "\n";
    cout << numbers[N-1]-numbers[0] << "\n";
    return 0;
}