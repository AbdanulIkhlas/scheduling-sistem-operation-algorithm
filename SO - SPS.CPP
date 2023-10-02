//priority scheduling
#include<stdio.h>
#include<string.h>
main()
{
int n, ar[100], b[100], i, j, tmp, wt[100], ta[100], time[100];
int totWT=0, totTA=0;
float AvWT, AvTA;
char name[20][20], tmpName[20];

// NAMA DAN NIM
printf("+-----------------------------------+\n");
printf("| Nama	: Muhammad Abdanul Ikhlas   |\n");
printf("| NIM	: 123210009                 |\n");
printf("| Kelas	: IF - C                    |\n");
printf("+-----------------------------------+\n");

printf("Program Penjadwalan Priority Scheduling");
puts("");
printf("Banyak Proses\t= "); scanf("%d",&n);
puts("");
// Masukkan data yang diproses
for(i=0; i<n; i++){
fflush(stdin);
printf("Nama Proses\t= "); gets(name[i]);
//printf("Arrival time=0\t= "); scanf("%d", &ar[i]);
printf("Burst time\t= "); scanf("%d", &b[i]);
puts("");

}
// SORTING Data
for(i=0; i<n; i++){
for(j=i+1; j<n; j++)
if(ar[i]>ar[j]){
//tukar nama
strcpy(tmpName, name[i]);
strcpy(name[i], name[j]);
strcpy(name[j], tmpName);
//tukar arrival time
tmp=ar[i];
ar[i]=ar[j];
ar[j]=tmp;
//tukar burst
tmp=b[i];
b[i]=b[j];
b[j]=tmp;
}
}
time[0]=ar[0];
puts("\n\t.:: Process Table ::.");
puts("==========================================");
printf("| no | proses\t | time arrival\t | burst |\n");
puts("=========================================");
for (i=0; i<n; i++){
printf("| %2d | %s\t |  \t%d\t | %d\t |\n", i+1, name[i], ar[i], b[i]);
time[i+1]=time[i]+b[i]; //menghitung time pada ganchart
wt[i]=time[i]-ar[i];
ta[i]=time[i+1]-ar[i];
totWT+=wt[i];
totTA+=ta[i];
}
puts("==========================================");
printf("\tTotal waiting time\t= %d \n", totWT);
printf("\tTurn arround time\t= %d \n", totTA);
puts("\n\t.:: Time Process Table ::.");
puts("==================================================");
printf("| no | proses\t | waiting time\t | turn arround\t |\n");
puts("====================================================");
for(i=0; i<n; i++){
printf("| %2d | %s\t |  \t%d\t | \t%d\t |\n", i+1, name[i], wt[i], ta[i]);
}
puts("==================================================");
//untuk Gant Chart
puts("");
puts("\t.:: Gant-Chart ::.\n");
for(i=0; i<n; i++){
printf("%s\t ", name[i]);
}
puts("");
for(i=0; i<n; i++){
printf("|=========");
}
printf("|\n");
for(i=0; i<=n; i++){
printf(" %d\t ", time[i]);
}

printf("\tdiperoleh dari penjumlahan Burst\n");
puts("");
AvWT=(float)totWT/n; //average waiting time
AvTA=(float)totTA/n; //average turn arround time
printf("\tAverage Waiting Time : %f\n", AvWT);
printf("\tAverage Turn Arround TIme : %f\n", AvTA);
}