#include <stdio.h>  // input output operations
#include <conio.h>  // input output on console
#include <stdlib.h> //  type conversion
#include <string.h> // string handling and manipulations..
#include <time.h>   // time and date decalrations to provide standardzed access to time/date manipulation and formatting.

void fileBug(int id)
{
    printf("\n*              __________________Bug Filing__________________              *");
    // Current Time
    time_t Current_Time;
    time(&Current_Time);

    char Name[20], BugDescription[1000], BugReport[30], BugPriority[30], BugType[50], Ids[10];
    int BugStatus;
    FILE *ptr;

    // User Name
    printf("\nEnter Your Name :");
    scanf("%s", &Name);
    itoa(id, Ids, 10);
    strcat(Name, Ids);
    char Ex[] = ".txt";
    strcat(Name, Ex);

    printf("filename : %s\n", Name); // filename of the bug.
    ptr = fopen(Name, "w");

    // case when file can't be created.
    if (ptr == NULL)
    {
        printf("*Can't Create file !!!");
    }
    // ID in the text file.
    fprintf(ptr, "Bug Id : %d\n", id);
    fprintf(ptr, "\n");
    printf("Bug Id : %d\n", id); // bug Id

    fprintf(ptr, "Bug filed by : %s\n", Name);
    fprintf(ptr, "\n");

    // Bug Type
    printf("Bug Type : ");
    scanf(" %[^\n]", BugType);
    fprintf(ptr, "TYPE OF BUG: %s\n", BugType);
    fprintf(ptr, "\n");

    // Bug Priority
    printf("Bug Priority : ");
    scanf(" %[^\n]s", BugPriority);

    fprintf(ptr, "Bug Priority : %s\n", BugPriority);
    fprintf(ptr, "\n");

    // Bug Description
    printf("Enter Bug Description : ");
    scanf(" %[^\n]s", BugDescription);

    fprintf(ptr, "BUg Description : %s\n", BugDescription);
    fprintf(ptr, "\n");

    printf("\nStatus of bug:\n1. NOT YET ASSIGNED\n2.IN PROCESS\n3.FIXED\n4.DELIVERED\n\nENTER YOUR CHOICE : ");

    int j;
    scanf("%d", &j);

    // date nd time of bug creation
    fprintf(ptr, "Date And Time : %s\n", ctime(&Current_Time));
    fprintf(ptr, "Bug Status :");

    switch (j)
    {
    case 1:
        fprintf(ptr, "NOT YET ASSIGNED\n");
        break;
    case 2:
        fprintf(ptr, "IN PROCESS\n");
        break;
    case 3:
        fprintf(ptr, "FIXED\n");
        break;
    case 4:
        fprintf(ptr, "DELIVERED\n");
        break;
    default:
        printf("*Invalid choice\n");
        break;
    }
    fclose(ptr);
}

void ChangeStatus()
{
    printf("*************");
    printf("Change status");
    printf("**************\n");

    // Current Time
    time_t CurrentTime;
    time(&CurrentTime);

    FILE *file;
    char name[50];

    // Bug File name
    printf("Enter file name:\n");
    scanf("%s", name);
    char ex[] = ".txt";
    strcat(name, ex);

    // Opening the Bug in Append Mode
    file = fopen(name, "a");

    printf("\n 1. NOT YET ASSIGNED\n2.IN PROCESS\n3.FIXED\n4.DELIVERED\n");
    printf("ENTER YOUR CHOICE:\n");
    printf(" ");

    // Change the Status
    int k;
    scanf("%d", &k);

    fprintf(file, "\n");
    fprintf(file, "DATE AND TIME : %s", ctime(&CurrentTime));

    fprintf(file, "BUG STATUS:");

    // Changing the status on the basis of the user input
    switch (k)
    {
    case 1:
        fprintf(file, "NOT YET ASSIGNED\n");
        break;
    case 2:
        fprintf(file, "IN PROCESS\n");
        break;
    case 3:
        fprintf(file, "FIXED\n");
        break;
    case 4:
        fprintf(file, "DELIVERED\n");
        break;
    default:
        printf("invalid choice\n");
        break;
    }
    fclose(file);
}

void Report()
{

    printf("**********");
    printf("REPORT");
    printf("**********\n");

    FILE *fp;
    char name[50];

    // Asking the Filename to report the bug of the file
    printf("Enter file name:\n");
    scanf("%s", name);
    char ex[] = ".txt";
    strcat(name, ex);

    // Opening the file into the Read mode
    fp = fopen(name, "r");

    char ch;
    ch = getc(fp);

    // Character of the File
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(fp);
    }

    fclose(fp);
    getch();
}

void main()
{
    printf("\n              ______________Bug Tracking System_____________              \n");
    int i = 1, id = 0, number; // id initialised to 0.

    while (i != 0)
    {
        printf("\nEnter 1 For File A Bug.\nEnter 2 For Chnage Status Of Bug.\nEnter 3 For Report Bug.\nEnter 4 For Exit.\n");

        printf("\nEnter Your Choice :");
        scanf("%d", &number);

        switch (number)
        {
        case 1:
            id++;
            fileBug(id);
            break;
        case 2:
            ChangeStatus();
            break;
        case 3:
            Report();
            break;
        case 4:
            i = 0;
            break;

        default:
            printf("*Invalid Choice");
            break;
        }
    }
}