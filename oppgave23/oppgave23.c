#include<stdio.h>
#include<math.h>

int summerKvadrater(int tall, int tall2, int tall3);

int main() {
    printf("\nSummen er: %i\n", summerKvadrater(2, 4, 6));
    return 0;
}
int summerKvadrater(int tall, int tall2, int tall3) {
    int sum = (tall * tall) + (tall2 * tall2) + (tall3 * tall3);
    return sum;
}
