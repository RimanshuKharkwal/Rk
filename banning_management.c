#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100

typedef struct {
    int id;
    char name[50];
    int violations;
    int banned; // 1 = banned, 0 = not banned
} User;

void addUser(User users[], int *count) {
    if (*count >= MAX_USERS) {
        printf("User limit reached.\n");
        return;
    }

    printf("Enter user ID: ");
    scanf("%d", &users[*count].id);
    printf("Enter user name: ");
    scanf("%s", users[*count].name);
    users[*count].violations = 0;
    users[*count].banned = 0;

    (*count)++;
    printf("User added successfully.\n");
}

void reportViolation(User users[], int count) {
    int id;
    printf("Enter user ID to report violation: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (users[i].id == id) {
            users[i].violations++;
            printf("Violation reported. Total violations: %d\n", users[i].violations);
            if (users[i].violations >= 3) {
                users[i].banned = 1;
                printf("User %s has been banned.\n", users[i].name);
            }
            return;
        }
    }
    printf("User not found.\n");
}

void listUsers(User users[], int count) {
    printf("\nUser List:\n");
    printf("ID\tName\t\tViolations\tBanned\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%d\t\t%s\n", users[i].id, users[i].name, users[i].violations, users[i].banned ? "Yes" : "No");
    }
}

int main() {
    User users[MAX_USERS];
    int userCount = 0;
    int choice;

    do {
        printf("\n--- PBL Banning System ---\n");
        printf("1. Add User\n");
        printf("2. Report Violation\n");
        printf("3. List Users\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addUser(users, &userCount);
                break;
            case 2:
                reportViolation(users, userCount);
                break;
            case 3:
                listUsers(users, userCount);
                break;
            case 4:
                printf("Exiting system.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}
