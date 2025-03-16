//header guards so the file is not processed multiple times
#ifndef template.h
#define template.h

#include <stdio.h>
#include "display.h"
#include "PathTest.h"

void templateGraph();

void templateGraph()
{
    tasks task1, task2, task3, task4, task5, task6;
    int numOfTasks=6;
    memset(task1.name,"#",80);
    strcpy(task1.name,"Come_up_with_the_idea");
    memset(task2.name,"#",80);
    strcpy(task2.name,"Think_of_a_project_name");
    memset(task3.name," ",80);
    strcpy(task3.name,"Set_up_a_github_account");
    memset(task4.name," ",80);
    strcpy(task4.name,"Gather_friends");
    memset(task5.name," ",80);
    strcpy(task5.name,"Write_code");
    memset(task6.name," ",80);
    strcpy(task6.name,"Upload_your_code_online");

    task1.startMonth = 1;
    task1.endMonth = 1;
    task2.startMonth = 2;
    task2.endMonth = 2;
    task3.startMonth = 3;
    task3.endMonth = 3;
    task4.startMonth = 4;
    task4.endMonth = 5;
    task5.startMonth = 6;
    task5.endMonth = 11;
    task6.startMonth = 12;
    task6.endMonth = 12;

    task1.Dependencies=0;
    task2.Dependencies=1;
    task2.dependencies[0]=1;
    task3.Dependencies=1;
    task3.dependencies[0]=3;
    task4.Dependencies=2;
    task4.dependencies[0]=2;
    task4.dependencies[1]=3;
    task5.Dependencies=1;
    task5.dependencies[0]=3;
    task6.Dependencies=1;
    task6.dependencies[0]=5;

    tasks tasks[6] = {task1, task2, task3, task4, task5, task6};
    createGraph(tasks, 6);

    char editOrTest[MAX], edit[MAX];

// while strcmp = edit / test . if = edit bang. if = test bang. else

    while (1) {
        char editOrTest[10];

        printf("Would you like to edit or test? (Type 'edit', 'test', or 'quit' to exit): ");
        scanf("%s", editOrTest);

        if (strcmp(editOrTest, "edit") == 0) {

            printf("Please enter the exact task name you wish to edit: ");
            char edit[50]; // Adjust size as needed
            scanf("%s", edit);

            bool found = false;

            for (int i = 0; i < numOfTasks; i++) {
                if (strcmp(edit, tasks[i].name) == 0) {
                    found = true;

                    printf("Editing task: %s\n", tasks[i].name);

                    printf("Enter new task name (or re-enter the old one): ");
                    scanf("%s", tasks[i].name);

                    printf("Start month (1-12): ");
                    scanf("%d", &tasks[i].startMonth);

                    printf("End month (1-12): ");
                    scanf("%d", &tasks[i].endMonth);

                    printf("Enter how many dependencies this task has: ");
                    scanf("%d", &tasks[i].Dependencies);

                    for(int j=0;j<tasks[i].Dependencies;j++)
                    {
                        printf("%d Dependency: ", j+1);
                        scanf("%d",&tasks[i].dependencies[j]);
                    }
                    clearScreen();
                    createGraph(tasks,numOfTasks);

                    break; // Stop searching once found
                }
            }

            if (!found) {
                printf("Task not found.\n");
            }
        }

        else if (strcmp(editOrTest, "test") == 0) {
            printf("\nEnter for which Task you want to run the test: ");
            char TestTaskName[80];
            scanf("%s",TestTaskName);
            int arr[10];
            for(int k=0;k<numOfTasks;k++)
            {
                if(strcmp(TestTaskName, tasks[k].name)==0)
                {
                    printf("\nFound the task\n");
                    Test(k+1, tasks,arr,0);
                    break;
                }
            }

            /*printf("Dependencies:");

            bool circularDep = false;

            for (int i = 0; i < numOfTasks; i++) {

                if (i < numOfTasks - 1 && task[i].Dependencies < task[i + 1].Dependencies) {

                    circularDep = true;

                }

                printf("%d -> ", task[i].Dependencies);

            }

            if (circularDep) {
                printf("( !!!!!!!!!! Warning: Potential circular dependency !!!!!!!!!!!!!!) ");
            }

            printf("\n");*/
        }

        else if (strcmp(editOrTest, "quit") == 0) {
            printf("_________§§§§§§§§§§§§§§§§§§§§§§§§\n");
            printf("_________§§§_§_§_§_§_§_§_§_§§§§§_§\n");
            printf("________§___§_§_§_§_§_§_§_§_§§§§§_§\n");
            printf("_______§_____§_§_§_§_§_§_§_§_§§§§__§\n");
            printf("______§__§§___§_§_§_§_§_§_§_§_§§§§§§§\n");
            printf("_____§__§§§§___§_§_§_§_§_§_§_§_§§§§§_§\n");
            printf("____§_§§§§§§§§__§_§_§_§_§_§_§_§§§§§§§_§\n");
            printf("___§_§§§§§§§§§§__§_§_§_§_§_§_§_§§§§§_§_§\n");
            printf("__§__§§§§§§§§§§___§_§_§_§_§_§_§_§_§§§§§_§\n");
            printf("_§____§§§§§§§§_____§_§_§_§_§_§_§_§_§_§§§_§\n");
            printf("§_______§§§§________§_§_§_§_§_§_§_§_§_§§§_§\n");
            printf("§____§§§§§§§§§________§_§_§_§_§_§_§§_§§§_§_§\n");
            printf("§___§§_________§§_____§§§§§§§§§§§§§§§§§§§§§§\n");
            printf("§_§§___§§§_§§§___§§___§____________________§\n");
            printf("§§§__§§§§§_§§§§§__§§__§____________________§\n");
            printf("§§§_§§§§§§_§§§§§§_§§__§____§§§§§§§§§§§_____§\n");
            printf("§§__§§_§§§_§§§_§§__§§_§____§§___§___§§_____§\n");
            printf("§§_§_____§_§_____§_§§_§____§§§§§§§§§§§_____§\n");
            printf("§§_§§§_§§§_§§§_§§§_§§_§____§§___§___§§_____§\n");
            printf("§§_§§§§§§§_§§§§§§§_§§_§____§§___§___§§_____§\n");
            printf("§§_________________§§_§____§§§§§§§§§§§_____§\n");
            printf("§§§§§§§§§§§§§§§§§§§§§_§____________________§\n");
            printf("§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§\n");
            printf("\nExiting program.\n");
            return -1;
            break;
        }

        else {
            printf("Invalid option. Please enter 'edit', 'test', or 'quit'.\n");
        }
    }
}
//header guard so the file is not processed multiple times
#endif template.h

