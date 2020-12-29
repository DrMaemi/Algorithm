#include <stdio.h>

#define parent(x) (x-1)/2

void heap(int* data, int num) {
    for (int i=1; i<num; i++) {
        int child = i;
        while (child > 0) {
            int root = parent(child);
            if (data[root] < data[child]) {
                int tmp = data[root];
                data[root] = data[child];
                data[child] = tmp;
            }
            child = root;
        }
    }
}

int main(void) {
    int num, tmp;
    int data[5];
    scanf("%d", &num);
    for (int i=0; i<num; i++) {
        scanf("%d", &data[i]);
    }
    heap(data, num);
    int loop = 1;
    printf("loop location: %d\nheap(data):\n", loop);
    for (int j=0; j<num; j++) {
        printf("%d ", data[j]);
    }
    printf("\n");
    for (int i=num-1; i>=0; i--) {
        int tmp = data[i];
        data[i] = data[0];
        data[0] = tmp;
        heap(data, i);
        printf("loop location: %d\n", ++loop);
        printf("heap(data):\n");
        for (int j=0; j<num; j++) {
            printf("%d ", data[j]);
        }
        printf("\n");
    }
    /*
    for (int i=0; i<num; i++) {
        printf("%d\n", data[i]);
    }
    */
    return 0;
}