#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100
#define MAX_TASKS 10

typedef struct tasks{
    char name[MAX];
    int startMonth;
    int endMonth;
    int Dependencies;
    int dependencies[MAX];
} tasks;

/*typedef enum eTASKS{
    //30 characters long task names
    TASK_NAME_1,
    TASK_NAME_2,
    TASK_NAME_3,
    TASK_NAME_4,
    TASK_NAME_5,
    TASK_NAME_6,
    TASK_NAME_7,
    TASK_NAME_8,
    TASK_NAME_9,
    TASK_NAME_10

}eTASKS;*/

#include "display.h"
#include "template.h"
#include "PathTest.h"

int main(void) {
    //eTASKS TaskEnum[10];
    tasks task[MAX_TASKS];
    int numOfTasks;
    char choice[MAX];

    printf("Welcome to the Gantt Generator\nWould you like to use the test example or create your own Gantt from scratch? (yes or no): ");
    scanf("%s", choice);

    if (strcmp(choice, "yes") == 0) {
        printf("How many tasks would you like to add: ");
        scanf("%d", &numOfTasks);
        for (int i = 0; i < numOfTasks; i++) {
            printf("Please enter the task name: ");
            scanf("%s", task[i].name);
            //TaskEnum[i] = task[i].name;

            printf("Start Month (1-12): ");
            scanf("%d", &task[i].startMonth);

            printf("End Month (1-12): ");
            scanf("%d", &task[i].endMonth);

            if (task[i].startMonth > task[i].endMonth) {

                printf("task cannot end before it starts! please re-enter the task");

                printf("Please enter the task name: ");
                scanf("%s", task[i].name);

                printf("Start Month (1-12): ");
                scanf("%d", &task[i].startMonth);

                printf("End Month (1-12): ");
                scanf("%d", &task[i].endMonth);
            }

            printf("Enter how many dependencies this task has: ");
            scanf("%d", &task[i].Dependencies);

            for(int j=0;j<task[i].Dependencies;j++)
            {
                printf("%d Dependency: ", j+1);
                scanf("%d",&task[i].dependencies[j]);
            }
            clearScreen();
            createGraph(task,numOfTasks);
        }
    } else {
        clearScreen();
        templateGraph();
        return 0;
    }

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
                if (strcmp(edit, task[i].name) == 0) {
                    found = true;

                    printf("Editing task: %s\n", task[i].name);

                    printf("Enter new task name (or re-enter the old one): ");
                    scanf("%s", task[i].name);

                    printf("Start month (1-12): ");
                    scanf("%d", &task[i].startMonth);

                    printf("End month (1-12): ");
                    scanf("%d", &task[i].endMonth);

                    printf("Enter how many dependencies this task has: ");
                    scanf("%d", &task[i].Dependencies);

                    for(int j=0;j<task[i].Dependencies;j++)
                    {
                        printf("%d Dependency: ", j+1);
                        scanf("%d",&task[i].dependencies[j]);
                    }
                    clearScreen();
                    createGraph(task,numOfTasks);

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
                if(strcmp(TestTaskName, task[k].name)==0)
                {
                    printf("\nFound the task\n");
                    Test(k+1, task,arr,0);
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

    printf("\n");

    return 0;
}
