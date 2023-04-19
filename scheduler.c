#include <stdio.h>
#include <string.h>

int main()
{
    char p[10][50], temp[50];
    int i, j, pt[10], wt[10] = {0}, totwt = 0, pr[10], temp1, n;
    float avgwt;

    int ts, pid[10], need[10], wt1[10] = {0}, tat[10], j1, bt[10], flag[10], ttat = 0, twt = 0;
    float awt, atat;

    printf("Enter the number of processes for Priority Scheduling: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter the name of process %d: ", i + 1);
        scanf("%s", p[i]);
        printf("Enter the process time: ");
        scanf("%d", &pt[i]);
        printf("Enter the priority: ");
        scanf("%d", &pr[i]);
    }

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(pr[i] > pr[j])
            {
                temp1 = pr[i];
                pr[i] = pr[j];
                pr[j] = temp1;

                temp1 = pt[i];
                pt[i] = pt[j];
                pt[j] = temp1;

                strcpy(temp, p[i]);
                strcpy(p[i], p[j]);
                strcpy(p[j], temp);
            }
        }
    }

    for(i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + pt[i - 1];
        totwt += wt[i];
    }

    avgwt = (float) totwt / n;

    printf("\nProcess Name\t Process Time\t Priority\t Waiting Time\n");

    for(i = 0; i < n; i++)
    {
        printf(" %s\t\t %d\t\t %d\t\t %d\n", p[i], pt[i],pr[i], wt[i]);
}
printf("\nTotal waiting time for Priority Scheduling: %d\nAverage waiting time for Priority Scheduling: %f\n\n", totwt, avgwt);

printf("Enter the number of processes for Round Robin Scheduling: ");
scanf("%d", &n);

printf("Enter the time slice: ");
scanf("%d", &ts);

for(i = 1; i <= n; i++)
{
    printf("Enter the process ID for process %d: ", i);
    scanf("%d", &pid[i]);

    printf("Enter the burst time for process %d: ", i);
    scanf("%d", &bt[i]);

    need[i] = bt[i];
}

for(i = 1; i <= n; i++)
{
    flag[i] = 1;
    wt1[i] = 0;
}
while(n!=0)
{
    for(i=1;i<=n;i++)
    {
        if(need[i]>=ts)
        {
            for(j1=1;j1<=n;j1++)
            {
                if((i!=j1)&&(flag[i]==1)&&(need[j1]!=0))
                    wt1[j1]+=ts;
            }
            need[i]-=ts;
            if(need[i]==0)
            {
                flag[i]=0;
                n--;
            }
        }
        else
        {
            for(j1=1;j1<=n;j1++)
            {
                if((i!=j1)&&(flag[i]==1)&&(need[j1]!=0))
                    wt1[j1]+=need[i];
            }
            need[i]=0;
            n--;
            flag[i]=0;
        }
    }
}

for(i=1;i<=n;i++)
{
    tat[i]=wt1[i]+bt[i];
    twt+=wt1[i];
    ttat+=tat[i];
}

awt=(float)twt/i;
atat=(float)ttat/i;

printf("\n\nProcess\t Burst Time\t Wait Time\t Turn Around Time\n");
for(i=1;i<=n;i++)
    printf("%d\t\t%d\t\t%d\t\t%d\n",pid[i],bt[i],wt1[i],tat[i]);

printf("\nAverage Wait Time:%.2f\n",awt);
printf("Average Turn Around Time:%.2f\n",atat);

return 0;
}
