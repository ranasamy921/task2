#include <stdio.h>
#include <string.h>

enum ActivationStatus
{
    FALSE = 0,
    TRUE = 1
};

struct User
{
    char username[50];
    char password[50];
    enum ActivationStatus isActive;
};

void registerUser(struct User users[], int *userCount)
{
    printf("Enter Your Username: ");
    scanf("%s", users[*userCount].username);
    printf("Enter Your Password: ");
    scanf("%s", users[*userCount].password);

    int activationInput;
    int check = 1;
    do
    {
        printf("Please Confirm Your Activation (1 => Active, 0 => Inactive) : ");
        scanf("%d", &activationInput);

        if (activationInput == TRUE || activationInput == FALSE)
        {
            check = 0;
        }
        else
        {
            printf("Failed => Unknown Input . Please Enter 1 If You Are Active or 0 If You Are Inactive.\n");
        }
    } while (check);

    users[*userCount].isActive = activationInput;
    (*userCount)++;
    printf("Registration successful!\n");
}

int loginUser(struct User users[], int userCount, char username[], char password[])
{
    for (int i = 0; i < userCount; i++)
    {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0 && users[i].isActive == TRUE)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    struct User users[100];
    int userCount = 0;

    int choice;
    char username[50];
    char password[50];

    do
    {
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Please Enter The Number Of The Operation : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            registerUser(users, &userCount);
            break;
        case 2:
            printf("Enter Your Username : ");
            scanf("%s", username);
            printf("Enter Your Password : ");
            scanf("%s", password);
            if (loginUser(users, userCount, username, password))
            {
                printf("Login successful!\n");
            }
            else
            {
                printf("Login Failed. Invalid Username Or Password Or User Is Inactive.\n");
            }
            break;
        case 3:
            printf("Have A Nice Time .\n");
            break;
        default:
            printf("Failed! Please Enter A Valid Operation. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}