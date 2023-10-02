//ROUND ROBIN
#include<stdio.h>
#include<conio.h>
 main()
 {
 int st[10],bt[10],wt[10],tat[10],n,tq;
 int i,count=0,swt=0,stat=0,temp,sq=0;
 float awt=0.0,atat=0.0;
 
 // NAMA DAN NIM
printf("+-----------------------------------+\n");
printf("| Nama	: Muhammad Abdanul Ikhlas   |\n");
printf("| NIM	: 123210009                 |\n");
printf("| Kelas	: IF - C                    |\n");
printf("+-----------------------------------+\n");
 
// clrscr();
 printf("Enter number of processes:");
 scanf("%d",&n);
 puts("");
 //printf("Enter burst time for sequences:");
 for(i=0;i<n;i++)
 {
 printf("Proses :P=");scanf("%d",&st[i]);
 printf("Burst Time P:%d=",i+1);scanf("%d",&bt[i]);
 st[i]=bt[i];
 puts("");
 }
 printf("Enter time quantum:");
 scanf("%d",&tq);
 puts("");
 while(1)
 {
 for(i=0,count=0;i<n;i++)
 {
 temp=tq;
 if(st[i]==0)
 {
 count++;
 continue;
 }
 if(st[i]>tq)
 st[i]=st[i]-tq;
 else
 if(st[i]>=0)
 {
 temp=st[i];
 st[i]=0;
 }
 sq=sq+temp;
 tat[i]=sq;
 }
 if(n==count)
 break;
 }
 for(i=0;i<n;i++)
 {
 wt[i]=tat[i]-bt[i];
 swt=swt+wt[i];
 stat=stat+tat[i];
 }
 awt=(float)swt/n;
 atat=(float)stat/n;
 puts("\t ------------------------------------------------------------------------");
 printf("\t | Process_no \t| Burst time \t| Wait time \t| Turn around time \t|");
 puts("");
 for(i=0;i<n;i++)
 printf("\t | %d \t   \t| %d \t   \t| %d \t  \t| %d \t\t\t|\n",i+1,bt[i],wt[i],tat[i]);
 puts("\t ------------------------------------------------------------------------");
 printf("\n\tAvg wait time is %f \n",awt);
 printf("\tturn around time is %f",atat);
 getch();
 }
