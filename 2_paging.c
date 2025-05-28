#include <stdio.h>

int main() {
    int ms, ps, nop, i;

    printf("Memory Size: ");
    scanf("%d", &ms);
    printf("Page Size: ");
    scanf("%d", &ps);

    int np = ms / ps;
    printf("Total Pages: %d\n", np);

    printf("Enter number of processes: ");
    scanf("%d", &nop);

    int req, rem = np;
    for (i = 0; i < nop; i++) {
        printf("Pages needed for P%d: ", i + 1);
        scanf("%d", &req);

        if (req <= rem) {
            printf("P%d allocated\n", i + 1);
            rem -= req;
        } else {
            printf("P%d not allocated (insufficient memory)\n", i + 1);
        }
    }

    return 0;
}




/*
Output:
Memory Size: 1000
Page Size: 100
Total Pages: 10
Enter number of processes: 3
Pages needed for P1: 4
P1 allocated
Pages needed for P2: 3
P2 allocated
Pages needed for P3: 5
P3 not allocated (insufficient memory)
*/
