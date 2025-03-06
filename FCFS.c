#include<stdio.h>
#include<conio.h>
#define MAX 100

int main(){
    int n;
    printf("No of processes: ");
    scanf("%d", &n);
    int AT[n];
    int BT[n];
    int CT[n];
    int TAT[n];
    int WT[n];

    printf("ARRIVAL TIME OF EACH PROCESS: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &AT[i]);
    }
    printf("BURST TIME OF EACH PROCESS: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &BT[i]);
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += BT[i];
        CT[i] = sum;
    }
    for(int i = 0; i < n; i++){
        TAT[i] = CT[i] - AT[i];
    }
    for(int i = 0; i < n; i++){
        WT[i] = TAT[i] - BT[i];
    }
    float avgCT = 0, avgTAT = 0, avgWT = 0;
    for(int i = 0; i < n; i++){
        avgWT += WT[i];
        avgCT += CT[i];
        avgTAT += TAT[i];
    }
    avgWT /= n;
    avgCT /= n;
    avgTAT /= n;

    printf("Average Completion Time: %f\nAverage Turnaround Time: %f\nAverage Waiting Time: %f\n", avgCT, avgTAT, avgWT);
    return 0;
}
