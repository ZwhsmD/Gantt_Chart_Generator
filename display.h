//header guards so the file is not processed multiple times
#ifndef display.h
#define display.h

#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 10

const char months[12][80] = {"January","February","March","April","May","June","July","August","September","October","November","December"};

void clearScreen();

void createGraph(tasks TaskArray[10], int numOfTasks);

void createGraph(tasks TaskArray[10], int numOfTasks)
{
    printf("\n---------------------------------------------------------------------------------------------------------------------------------");
    printf("-----------------------------------------------------------------|");
    printf("\n%-25s","TASK NAME");
    printf("|");
    for(int i=0;i<12;i++)
    {
        printf("%-12s|", months[i]);
    }
    printf("%-12s|\n", "Dependencies");
    printf("---------------------------------------------------------------------------------------------------------------------------------");
    printf("-----------------------------------------------------------------|\n");

    for(int i=0;i<numOfTasks;i++)
    {
        printf("%-25s|", TaskArray[i].name);
        for(int j=0;j<=12;j++)
        {
            if(TaskArray[i].startMonth==j+1)
            {
                for(int k=0;k<=(TaskArray[i].endMonth-TaskArray[i].startMonth);k++){

                    printf("%-12s|", "XXX");
                    j++;
                }
            }
            else printf("%-12s|","");
        }
        char text[TaskArray[i].Dependencies+numOfTasks];
        for(int j=0;j<TaskArray[i].Dependencies;j++)
        {
            printf("%d ", TaskArray[i].dependencies[j]);
        }
        printf("\n");
        printf("---------------------------------------------------------------------------------------------------------------------------------");
        printf("-----------------------------------------------------------------|\n");
    }
}

void clearScreen()
{
     system("cls");
}
//header guard so the file is not processed multiple times
#endif display.h

