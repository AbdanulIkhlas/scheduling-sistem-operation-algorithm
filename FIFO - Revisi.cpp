#include <stdio.h>
#include <string.h>

int main() {
    int n, ar[100], b[100], i, j, tmp, wt[100], ta[100], time[100];
    int totWT = 0, totTA = 0;
    float AvWT, AvTA;
    char name[20][20], tmpName[20];

    printf("+-------------------------------------+\n");
    printf("| Nama    : Muhammad Abdanul Ikhlas   |\n");
    printf("| NIM     : 123210009                 |\n");
    printf("| Kelas   : IF - C                    |\n");
    printf("+-------------------------------------+\n");

    printf("Program Penjadwalan CPU FIFO\n\n");
    printf("Banyak Proses = ");
    scanf("%d", &n);
    printf("\n");

    for (i = 0; i < n; i++) {
        fflush(stdin);
        printf("Nama Proses   = ");
        gets(name[i]);
        printf("Arrival time  = ");
        scanf("%d", &ar[i]);
        printf("Burst time    = ");
        scanf("%d", &b[i]);
        printf("\n");
    }

    // SORTING Data berdasarkan arrival time
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (ar[i] > ar[j]) {
                // Tukar nama
                strcpy(tmpName, name[i]);
                strcpy(name[i], name[j]);
                strcpy(name[j], tmpName);

                // Tukar arrival time
                tmp = ar[i];
                ar[i] = ar[j];
                ar[j] = tmp;

                // Tukar burst time
                tmp = b[i];
                b[i] = b[j];
                b[j] = tmp;
            }
        }
    }

    time[0] = ar[0];
    
    printf("-------------- Process Table -------------\n");
    printf("==========================================\n");
    printf("| no | proses\t | time arrival\t | burst |\n");
    printf("==========================================\n");

    for (i = 0; i < n; i++) {
        printf("| %2d | %s\t |  \t%d\t | %d\t |\n", i + 1, name[i], ar[i], b[i]);
        time[i + 1] = time[i] + b[i];
        wt[i] = time[i] - ar[i];
        ta[i] = time[i + 1] - ar[i];
        totWT += wt[i];
        totTA += ta[i];
    }

    printf("==========================================\n\n");
    printf("\tTotal waiting time\t= %d \n", totWT);
    printf("\tTurn around time\t= %d \n\n", totTA);

    printf("---------------- Time Process Table --------------\n");
    printf("==================================================\n");
    printf("| no | proses\t | waiting time\t | turn around\t |\n");
    printf("==================================================\n");

    for (i = 0; i < n; i++) {
        printf("| %2d | %s\t |  \t%d\t | \t%d\t |\n", i + 1, name[i], wt[i], ta[i]);
    }

    printf("==================================================\n\n");

    printf("-------------------- Gantt Chart -------------------\n");
    
    for (i = 0; i < n; i++) {
        printf("%s         ", name[i]);
    }
    printf("\n");
    
    for (i = 0; i < n; i++) {
        printf("|=========");
    }
    printf("|\n");
    
    for (i = 0; i <= n; i++) {
        printf("%d         ", time[i]);
    }
    
    printf("\n\ndiperoleh dari penjumlahan Burst\n\n");
    
    AvWT = (float)totWT / n; // Rata-rata waiting time
    AvTA = (float)totTA / n; // Rata-rata turn around time
    printf("\tAverage Waiting Time : %f\n", AvWT);
    printf("\tAverage Turn Around Time : %f\n", AvTA);

    return 0;
}
