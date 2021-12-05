// DrMaemi - 1112KB, 2560ms
#include <stdio.h>
using namespace std;

int main() {
    int N, count[10001] = {0};

    scanf("%d", &N);

    for (int i=0; i<N; i++) {
        int tmp;

        scanf("%d", &tmp);
        count[tmp]++;
    }

    for (int i=0; i<10001; i++)
        for (int j=0; j<count[i]; j++)
            printf("%d\n", i);

    return 0;
}