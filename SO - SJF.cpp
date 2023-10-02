#include <stdio.h>
#include <string.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int i, j, n, burst_time[10], start_time[10], end_time[10], wait_time[10], temp, total;
    float avg;

    printf("+-------------------------------------+\n");
    printf("| Nama    : Muhammad Abdanul Ikhlas   |\n");
    printf("| NIM     : 123210009                 |\n");
    printf("| Kelas   : IF - C                    |\n");
    printf("+-------------------------------------+\n");

    printf("Enter the No. of jobs: ");
    scanf("%d", &n);
    puts("");
    
    for (i = 1; i <= n; i++) {
        printf("Enter process %d burst time: ", i);
        scanf("%d", &burst_time[i]);
    }

    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            if (burst_time[i] > burst_time[j]) {
                swap(&burst_time[i], &burst_time[j]);
            }
        }

        if (i == 1) {
            start_time[1] = 0;
            end_time[1] = burst_time[1];
            wait_time[1] = 0;
        } else {
            start_time[i] = end_time[i - 1];
            end_time[i] = start_time[i] + burst_time[i];
            wait_time[i] = start_time[i];
        }
    }

    printf("\n +------------------------------------------------------+");
    printf("\n | BURST TIME  |  STARTING TIME | END TIME  | WAIT TIME |");
    printf("\n +------------------------------------------------------+\n");

    for (i = 1; i <= n; i++) {
       printf(" |  %3d        |     %3d        |   %3d     |    %3d    |\n", burst_time[i], start_time[i], end_time[i], wait_time[i]);
    }

    printf(" +------------------------------------------------------+");

    for (i = 1, total = 0; i <= n; i++) {
        total += wait_time[i];
    }

    avg = (float)total / n;
    printf("\n\n AVERAGE WAITING TIME=%f", avg);

    for (i = 1, total = 0; i <= n; i++) {
        total += end_time[i];
    }

    avg = (float)total / n;
    printf("\n\n AVERAGE TURNAROUND TIME=%f", avg);

    for (i = 1, total = 0; i <= n; i++) {
        total += start_time[i];
    }

    avg = (float)total / n;
    printf("\n\n AVERAGE RESPONSE TIME=%f\n\n", avg);

    return 0;
}
