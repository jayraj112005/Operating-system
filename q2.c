#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct
{
int arrivaltime;
int firstcpuburst;
int nextcpuburst;
int turnaroundtime;
int waitingtime;
}job;

void calculateaverage(job jobs[], int n,float *avgturnaround,float *avgwaiting)
{
int totalturnaround =0;
int totalwaiting =0;

for(int i=0;i<n;i++)
{
totalturnaround+=jobs[i].turnaroundtime;
totalwaiting +=jobs[i].waitingtime;
}

*avgturnaround= (float)totalturnaround / n;
*avgwaiting =(float)totalwaiting / n;
}

int main()
{
int n;
srand(time(NULL));
printf("enter the number of jobs:");
scanf("%d",&n);

job jobs[n];

for(int i=0;i<n;i++)
{
printf("job %d\n",i+1);
printf("arrival time:");
scanf("%d",&jobs[i].arrivaltime);
printf( "first cpu burst time:");
scanf("%d",&jobs[i].firstcpuburst);

jobs[i].nextcpuburst=0;
jobs[i].turnaroundtime=0;
jobs[i].waitingtime=0;
}

int currenttime=0;

for(int i=0;i<n;i++)
{
if(currenttime<jobs[i].arrivaltime)
{
currenttime =jobs[i].arrivaltime;
}
jobs[i].nextcpuburst=rand()%10+1;

jobs[i].turnaroundtime=currenttime + jobs[i].firstcpuburst +jobs[i].nextcpuburst-jobs[i].arrivaltime;
jobs[i].waitingtime=jobs[i].turnaroundtime-jobs[i].firstcpuburst-jobs[i].nextcpuburst;
currenttime+=jobs[i].firstcpuburst+jobs[i].nextcpuburst;
}

printf("\n Gantt Chart:\n");
printf("0");

for(int i=0;i<n;i++)
{
printf("-> Job%d -> %d",i + 1,currenttime);
}
printf("\n");

printf("\nTurn Around Time and Waiting Times:\n");
for(int i=0;i<n;i++)
{
printf("Job%d-Turnaround Time:%d,Waitingtime:%d\n",i + 1,jobs[i].turnaroundtime,jobs[i].waitingtime);
}

float avgturnaround,avgwaiting;
calculateaverage(jobs,n,&avgturnaround,&avgwaiting);
printf("\n Average Turn Around Time:%.2f\n",avgturnaround);
printf("Average Waiting Time:%.2f\n",avgwaiting);
return 0;
}





















