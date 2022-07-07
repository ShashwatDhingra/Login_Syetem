/* Login system

:- Functions

:- Sign Up ->
{
1. Enter user name
2. Enter Your Name
3. Enter Password
4. Confirm Password
}

:- Login ->
{
1. Enter User Name
2. Enter Password
}

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Structure for Entering the Details Entered By User*/
typedef struct signup_system
{
    char user_name[20];
    char name[20];
    char pass[20];

} signup;

/* Structure for Rendering Details from File*/
typedef struct login_system
{
    char user_name[20];
    char name[20];
    char pass[20];

} login;

int op1(signup user);
int op2(login login_user);

int main()
{

    int op;
    signup user;
    login login_user;

    printf("\n\n\n\n\n\t\t\t\t\t ==============================================");
    printf("\n\t\t\t\t\t |                LOGIN SYSTEM                |\n");
    printf("\t\t\t\t\t ==============================================\n");

again:
    printf(" ------------\n");
    printf("| 1. SIGNUP  |\n");
    printf(" ------------\n");

    printf(" ------------\n");
    printf("| 2. LOGIN   |\n");
    printf(" ------------\n");

    printf("\n\n Select :=> ");
    scanf("%d", &op);

    /*Switch statement for Choose Sign-Up or Login*/
    switch (op)
    {
    case (1):
    {
        op1(user);
    }
    break;

    case (2):
    {
        op2(login_user);
    }
    break;

    default:
    {
        printf("\nInvlaid Input\n\n");
        goto again;
    }
    }
    return 0;
}

int op1(signup user)
{

    FILE *fw; // Opening a File through Pointer.

    fw = fopen("data.txt", "w");

    int acc_created; // variable for Confirming Password
    int count = 3;

    char cnfrm_pass[20];

    printf("\n| Enter the Following Details to Sign-Up |\n\n");

    printf("\nEnter User Name : ");
    fflush(stdin);
    gets(user.user_name);

    printf("\nEnter Your First Name : ");
    fflush(stdin);
    gets(user.name);

    printf("\nEnter Password : ");
    fflush(stdin);
    gets(user.pass);

    while (count != 0)
    {
        printf("\nConfirm Password : ");
        scanf("%s", &cnfrm_pass);

        if (strcmp(user.pass, cnfrm_pass) == 0)
        {
            printf("\nAccount Created!\n");
            printf("===============");
            break;
        }

        else
        {
            printf(" \n ************** ");
            printf("\n*Doesn't Match!*\n");
            printf(" ************** ");
            count--;
        }

        /* When all three try got Failed */
        if (count == 0)
        {
            printf("\nTry Again Later!");
            return (0);
        }
    }

    fwrite(&user, sizeof(struct signup_system), 1, fw);

    fclose(fw);

    printf("\n\n");

    system("pause");
}

int op2(login login_user)
{
    int count = 3;

    int u_vierfy = 0, p_verify = 0; // username_verify, password_verify
    FILE *fr;                       // Pointer to read Data from a File

    fr = fopen("data.txt", "r");

    fread(&login_user, sizeof(login), 1, fr);

    char user_name[20];
    char pass[20];

    while (u_vierfy != 1)
    {
        printf("\nEnter User Name : ");
        scanf("%s", user_name);

        if (strcmp(user_name, login_user.user_name) == 0)
        {
            u_vierfy = 1;

            while (p_verify != 1)
            {
                printf("\nEnter Password : ");
                scanf("%s", pass);

                if (strcmp(pass, login_user.pass) == 0)
                {
                    printf("\n\t\t\t\t Welcome %s Sir!", login_user.name);
                    p_verify = 1;
                }

                else
                {
                    count--;

                    printf("\n  ===================================\n");
                    printf(" | ALERT : Password doesn't Match :/ |\n");
                    printf("  ===================================");

                    printf("\n\n");
                    p_verify = 0;
                }
                if (count == 0)
                {
                    printf("\nTry Again Later!");
                    return (0);
                }
            }
        }

        else
        {
            count--;

            printf("\n  ====================================\n");
            printf(" | ALERT : User Name doesn't Match :/ |\n");
            printf("  ====================================");

            printf("\n\n");
            u_vierfy = 0;
        }

        if (count == 0)
        {
            printf("\nTry Again Later!");
            return (0);
        }
    }

    fclose(fr);

    printf("\n\n");


    system("pause");
}