Implementing a Gantt Chart generator on a command line with a text interface
Contributors: Zuzanna Dąbrowska and Liam O'Connor(main.c)


> How is the Gantt displayed

    printf("-%*s,text) to print given text followed by a certain(*) number of empty spaces to make each collumn the same width. 
    The horizontal lines are printed using printf("-") multiple times;


> How to map the task to struct

    created a struck Task with following properies 
    char name[80];
    int startMonth;
    int endMonth;
    //number of Dependecies
    int Dependencies;
    //array for storing dependencies
    int dependencies[10];

> How did you edit and change tasks

    Getting the Task Name using scanf and then iterating through the task Array to find a task name using strcmp. Then new Task Name 
    is inputted, also the start and end month and the dependencies. The new task Array is then passed to the createGraph() function 
    in display.h header file which draws the Gantt Chart

> How did you implement search for a circular dependency

    the PathTest file holds a function Test(), which takes a Task number and recursively calls the function with the dependencies as 
    the arguments. It does so, traversing the dependencies, until a dependency has no other dependencies or it is the first task. It 
    then displays the dependencies traversed on the console using printf("%d -> );. The function checks if there is a possibiling of 
    a circular dependency by checking if the next dependency to be traversed already exists in array AlreadyVisited[]. if so it 
    displays printf("( !!!!!!!!!! Warning: Potential circular dependency !!!!!!!!!!!!!!) \n");

> What’s your Ascii art about? 

    The Ascii art displays a little House which represents the longing for the study break which we will spend at home with our 
    families and which was our longing through the creation of this assignment
