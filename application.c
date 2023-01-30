/*****************************************************************
//
//  NAME:        Password Guardian
//
//  CLASS:       ICS 434
//
//  INSTRUCTOR:  Barbara Endicott
//
//  DATE:        1/30/23
//
//  FILE:        application.c
//
//  DESCRIPTION:
//   <User interface for password guardian>
//
****************************************************************/

#include <stdio.h>
#include <string.h>

#include "login_credential.h"
#include "database.h"

void getLoginName();
void addMe();
void deleteMe();
void find();
void menu();
void print();
void menuSelect();
int getNumber();

int debugmode;

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Allows user to interface with the program via
//                 input to achieve a variety of things.
//
//
//  Parameters:    argc (int) : number of arguments
//                 argv (char*[] : array of arguments
//
//  Return values:  0
//
//
****************************************************************/

int main(int argc, char *argv[])
{

    struct login_credential *start = NULL;

    // TODO: below is old code to modify

    if(argc == 2 && strcmp(argv[1], "debug") == 0)
    {

        debugmode = 1;
        printf("\n***Welcome to debug mode, you are in main***\n");
        menuSelect(&start);

    }

    else
    {

        menuSelect(&start);

    }

    return 0;

}

/*****************************************************************
//
//  Function Name: menu
//
//  Description:  lists the options for the user and takes them
//                to their selected option. Loops until quit is entered.
//
//
//  Parameters:   none
//
//  Return Value: none
//
******************************************************************/

void menu()
{

    if(debugmode == 1)
    {

        printf("\n***In menu message function***\n");

    }

     printf("\nGood day! Welcome to the record database.\n");
     printf("\nPlease select from the following options\n");
     printf("\n1. Add new record to database: add");
     printf("\n3. Find records with account #: find");
     printf("\n4. Delete existing record(s) from database using account #: delete");
     printf("\n5. Quit the program: quit or [ENT]\n");

}

/***************************************************************************
//
//  Function Name: menuSelect
//
//  Description:   obtains the input to direct where the user goes
//
//  Parameters:    struct login_credential **: start the address to first login_credential in
//                                   the list
//
//  Return Value:  none
//
//
**************************************************************************/

void menuSelect(struct login_credential **start)
{

    char input[15];
    size_t length;
    int i;
    char fileName[25];

    i = 1;
    strcpy(fileName, "login_credentials.txt");

    // TODO: below is old code to modify
    readFile(start, fileName);

    if(debugmode == 1)
    {

        printf("\n***In menuSelect function***\n");

    }

    while( i == 1)
    {

        menu();
        fgets(input, 15, stdin);
        length = strlen(input) - 1;

        if(strncmp(input, "quit", length) == 0)
        {

            writeFile(*start, fileName);
            cleanUp(start);
            i = 0;

        }

        else if(strncmp(input, "printall", length) == 0)
        {

            print(start);

        }

        else if(strncmp(input, "find", length) == 0)
        {

            find(start);

        }

        else if(strncmp(input, "delete", length) == 0)
        {

            delete(start);

        }

        else if(strncmp(input, "add", length) == 0)
        {

            add(start);

        }

        else
        {

            printf("\nPlease enter one of the valid options or quit to exit.\n");

        }

    }

    if(debugmode == 1)
    {

        printf("*** Input obtained is: %s.***\n", input);

    }

}


/***************************************************************************
//
//  Function Name:  getLoginName
//
//  Description:    obtains an address from the user to be passed to add
//                  and then passed to addLoginCredential.
//
//  Parameters:    char []: the array to hold the user_name of login_credential holder
//                 int:     num the size of the char[]
//
****************************************************************************/

void getLoginName(int num, char user_name[])
{

    // TODO: below is old code to modify
    char d;
    int i;
    int j;

    i = 1;
    j = 0;

    if(debugmode == 1)
    {

        printf("\n***You are in getAddress function***\n");

    }

    printf("\nPlease enter an address and type ! when done.\n");

    while(i > 0  && i < num)
    {

        d = getchar();

        if(d != '!')
        {

            address[j] = d;
            j++;

        }

        else
        {

            address[j] = '\0';
            d = getchar();
            i = 0;

        }

    }



    if(debugmode == 1)
    {

        printf("\n***Address recieved is %s***\n", address);

    }

}

/***************************************************************************
//
//  Function name: addMe
//
//  Description:   obtains a user_name and app_name and password
//
//
//  Parameters:    struct login_credential **: the address of the first login_credential in the
//                                   list.
//
//  Return value:  none
//
****************************************************************************/

void addMe(struct login_credential **start)
{

    // TODO: below is old code to modify
    int addNum;
    int accNum;
    int last;
    int x;
    char name[25];
    char mail[50];

    addNum = 100;

    if(debugmode == 1)
    {

        printf("\n***You are in add function***\n");

    }

    printf("Please enter the name for the account you wish to add.\n");

    fgets(name, 25, stdin);
    last = strlen(name) - 1;
    name[last] = '\0';
    accNum = getNumber();
    getAddress(addNum, mail);

    if(debugmode == 1)
    {

        printf("\n***Name getting passed is %s***\n", name);
        printf("\n***Number getting passed is %d***\n", accNum);
        printf("\n***Mail address being passed is\n%s***\n", mail);

    }

    x = addRecord(start, accNum, name, mail);

    if(x == 0)
    {

        printf("Record number %d, has been added.\n", accNum);

    }

    else
    {

        printf("Record number %d already exists, please delete the existing record and try again or add a different account number.\n", accNum);

    }

}

/***************************************************************************
//
//  Function name: deleteMe
//
//  Description:   obtains login_credential to be deleted from the database
//
//  Parameters:    struct login_credential **: start, the address of the first
//                                   login_credential in the list.
//
//  Return Values: none
//
****************************************************************************/

void deleteMe(struct login_credential **start)
{

    // TODO: below is old code to modify
    int deleteNum;
    int x;

    if(debugmode == 1)
    {

        printf("\n***In delete function.***\n");

    }

    deleteNum = getNumber();

    if(debugmode == 1)
    {

        printf("\n*** Account number to be deleted is %d ***\n", deleteNum);

    }

    x = deleteRecord(start, deleteNum);

    if(x == 0)
    {

        printf("Record number %d, has been deleted.\n", deleteNum);

    }

    else
    {

        printf("Record number %d, does not exist.\n", deleteNum);

    }

}

/***************************************************************************
//
// Function Name: find
//
// Description:   obtains the login_credential for the user to find with
//                findLoginCredential
//
// Parameters:    struct login_credential **: start, the address of the first login_credential
//                                  in the list.
//
// Return Value:  none
//
****************************************************************************/

void find(struct login_credential **start)
{

    // TODO: below is old code to modify
    int findNum;
    int x;

    if(debugmode == 1)
    {

        printf("*** In find function ***\n");

    }

    findNum = getNumber();

    if(debugmode == 1)
    {

        printf("*** Record to find is %d. ***\n", findNum);

    }

    x = findRecord(*start, findNum);

    if(x == -1)
    {

        printf("That account number does not exist.\n");

    }

}

/**************************************************************************
//
//  Function Name: print FOR TROUBLESHOOTING purposes
//
//  Description:   takes user into printAllLoginCredentials function.
//                 !!!leaving this here so we can print the heap until we get it working right!!!
//
//
//  Parameters:    struct record **: start, the address of the first
//                                   record in the list
//
//  Return Value:  none
//
//
*************************************************************************/

void print(struct login_credential **start)
{

    if(debugmode == 1)
    {

        printf("***In the print function.***\n");

    }

   printAllRecords(*start);

}