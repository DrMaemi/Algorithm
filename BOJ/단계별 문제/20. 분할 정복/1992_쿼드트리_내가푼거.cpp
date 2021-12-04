#include <iostream>
#include <string>
using namespace std;

int** world;

void input_2d_arr(int** _2d_arr, int r, int c) {
    string buffer;
    for (int i=0; i<r; i++) {
        cin >> buffer;
        for (int j=0; j<c; j++) {
            _2d_arr[i][j] = buffer[j]-'0';
        }
    }
}

int** malloc_2d_arr(int r, int c) {
    int** _2d_arr = (int**)malloc(sizeof(int*)*r);
    for (int i=0; i<r; i++) {
        _2d_arr[i] = (int*)malloc(sizeof(int)*c);
    }
    return _2d_arr;
}

void print_all(int** _2d_arr, int r, int c) {
    cout << "\nprint_all():\n";
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cout << _2d_arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void solve_with_dac(int y, int x, int size) {
    int check = world[y][x];
    for (int i=y; i<y+size; i++) {
        for (int j=x; j<x+size; j++) {
            if (check != world[i][j]) {
                check = 2;
                break;
            }
        }
        if (check == 2) break;
    }
    if (check == 2) {
        int resize = size/2;
        cout << "(";
        solve_with_dac(y, x, resize);
        solve_with_dac(y, x+resize, resize);
        solve_with_dac(y+resize, x, resize);
        solve_with_dac(y+resize, x+resize, resize);
        cout << ")";
    }
    else if (check) {
        cout << "1";
    }
    else {
        cout << "0";
    }
}

int main(void) {
    int N;
    cin >> N;
    world = malloc_2d_arr(N, N);
    input_2d_arr(world, N, N);
    //print_all(world, N, N);
    solve_with_dac(0, 0, N);
    return 0;
}