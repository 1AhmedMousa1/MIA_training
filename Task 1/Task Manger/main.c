
#include <stdio.h>
#include <stdlib.h>
#define MAX_TASKS 100

typedef struct {
    int ID;
    char description[200];
} Task;

int main() {
    Task tasks[MAX_TASKS];
    int numTasks = 0;
    int number;

    while (1) {
        printf("1.Add task \n");
        printf("2.View task \n");
        printf("3.Remove task \n");
        printf("4.Exit \n");
        printf("Select action: ");
        scanf("%d", &number);
        system("cls");

        if (number > 4 || number < 1) {
            printf("Your Number must be within (1-4).\n");
        }
        if (number == 1) {
            system("cls");
            printf("Adding Task...\n");
            sleep(3);

            system("cls");

            printf("Please enter your ID: ");
            scanf("%d", &tasks[numTasks].ID);
            getchar();

            system("cls");

            printf("Enter your description: ");
            fgets(tasks[numTasks].description, 200, stdin);
            system("cls");
            printf("Your ID is %d\n", tasks[numTasks].ID);
            printf("Your description is %s", tasks[numTasks].description);
            numTasks++;

            system("cls");

            char choice;
            printf("Press Y to go back to main menu: ");
            scanf(" %c", &choice);
            if (choice == 'y' || choice == 'Y') {
                system("cls");
                continue;
            }
        }
        if (number == 2) {
            system("cls");
            printf("Enter the ID of the task: ");
            int searchID;
            scanf("%d", &searchID);

            int found = 0;
            for (int i = 0; i < numTasks; i++) {
                if (tasks[i].ID == searchID) {
                    printf("Task found!\n");
                    printf("ID: %d\n", tasks[i].ID);
                    printf("Description: %s\n", tasks[i].description);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Task not found!\n");
            }

            char choice;
            printf("\nPress Y to go back to main menu: ");
            scanf(" %c", &choice);
            if (choice == 'y' || choice == 'Y') {
                system("cls");
                continue;
            }
        }
        if (number == 3) {
          system("cls");
          printf("Enter the ID of the task to remove: ");
          int removeID;
          scanf("%d", &removeID);

          int found = 0;
          for (int i = 0; i < numTasks; i++) {
              if (tasks[i].ID == removeID) {
                  found = 1;
                  for (int j = i; j < numTasks - 1; j++) {
                      tasks[j] = tasks[j + 1];
                  }
                  numTasks--;
                  break;
              }
          }
          if (found) {
              printf("\nTask removed successfully!\n");
          } else {
              printf("\nTask not found!\n");
          }

          char choice;
          printf("\nPress Y to go back to main menu: ");
          scanf(" %c", &choice);
          if (choice == 'y' || choice == 'Y') {
              system("cls");
              continue;
          }
        }
        if (number == 4) {
          system("cls");
          printf("Have a good day!!");
          break;
        }
    }

    return 0;
}


