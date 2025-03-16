//header guards so the file is not processed multiple times(problem with struct redefinition)
#ifndef PathTest.h
#define PathTest.h

#include <stdio.h>

#define MAX_TASKS 10

int Test(int number,tasks Tasks[MAX_TASKS], int alreadyVisited[10], int sizeOfAV);

int Test(int number,tasks Tasks[MAX_TASKS], int alreadyVisited[10], int sizeOfAV)
{
    if(Tasks[number-1].Dependencies>0)
    {
        alreadyVisited[sizeOfAV]=number;
        sizeOfAV++;
        printf("%d->",number);
        for(int j=1;j<=Tasks[number-1].Dependencies;j++){
            int next = Tasks[number-1].dependencies[Tasks[number-1].Dependencies-j];
            for(int i=0;i<sizeOfAV;i++)
            {
                if(alreadyVisited[i]==next)
                {
                    printf("%d->",next);
                    printf("( !!!!!!!!!! Warning: Potential circular dependency !!!!!!!!!!!!!!) \n");
                    break;
                }
            }
            if(next >= number)
            {
                printf("--> A paradox occured!!!!\n");
                return 0;
            }
            Test(next, Tasks, alreadyVisited, sizeOfAV);
        }
    }
    else
    {
        for(int i=1;i<sizeOfAV;i++)
        {
            printf("%d->",alreadyVisited[i]);
        }
        printf("%d\n",number);
    }
    return 1;
}
//header guard so the file is not processed multiple times
#endif PathTest.h

