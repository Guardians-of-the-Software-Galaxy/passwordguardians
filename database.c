/*****************************************************************
//
//  NAME:        Password Guardian
//
//  CLASS:       ICS 427
//
//  INSTRUCTOR:  Barbara Endicott
//
//  DATE:        1/30/23
//
//  FILE:        database.c
//
//  DESCRIPTION:
//   <Stubs for database functions>
//
****************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "login_credential.h"
#include "database.h"


/*****************************************************************
//
//  Function name: int addLoginCredential
//
//  DESCRIPTION:   takes the application/website name, username,
//                 and password to create a login_credential object
//
//  Parameters:    start: struct record **, the address of the login
//                        credential in the list
//                 app_name:  char[], the name of the website or
//                            application
//                 user_name:  char [], the name of account holder
//                 password: char [], the password for this application
//
//
//  Return values:  0 : success
//                  -1: failure
//
//
****************************************************************/

int addLoginCredential (struct record **head, char[] app_name, char user_namename[], char password[])
{

    struct record *currentLoginCredential;
    struct record *nextLoginCredential;
    struct record *newLoginCredential;
    // TODO: below is old code to modify

    int i;
    char x;
    char y;
    int j;
    int v;

    currentRec = NULL;
    nextRec = NULL;
    newRec = NULL;
    i = 1;
    j = 0;
    v = 0;
    x = 'c';
    y = 'd';

    if(debugmode == 1)
    {

        printf("\n***In addRecord function database***\n");
        printf("\n***Account num recieved %d***\n", accountNum);
        printf("\n***Name recieved is %s***\n", name);
        printf("\n***Address recieved is:\n%s*** \n", address);

    }

    if(*start == NULL || (*start)->accountno > accountNum)
    {

        currentRec = (struct record *)malloc(sizeof(struct record));
        currentRec->accountno = accountNum;

        while(x != '\0')
        {

            currentRec->name[j] = name[j];
            j++;
            x = name[j];

        }

        currentRec->name[j] = x;

        while(y != '\0')
        {

            currentRec->address[v] = address[v];
            v++;
            y = address[v];

        }

        currentRec->address[v] = y;

        currentRec->next = *start;
        *start = currentRec;
        i = 0;

    }

    else
    {

        currentRec = *start;

        while(i > 0)
        {

            nextRec = currentRec->next;

            if(accountNum == currentRec->accountno)
            {

                i = -1;

            }

            else if(accountNum > currentRec->accountno && currentRec->next == NULL)
            {

                nextRec = (struct record *)malloc(sizeof(struct record));
                nextRec->accountno = accountNum;

                while(x != '\0')
                {

                    nextRec->name[j] = name[j];
                    j++;
                    x = name[j];

                }

                nextRec->name[j] = x;


                while(y != '\0')
                {

                    nextRec->address[v] = address[v];
                    v++;
                    y = address[v];

                }

                nextRec->address[v] = y;

                nextRec->next = NULL;
                currentRec->next = nextRec;
                i = 0;

            }

            else if(accountNum < nextRec->accountno)
            {

                newRec = (struct record *)malloc(sizeof(struct record));
                newRec->accountno = accountNum;

                while(x != '\0')
                {

                    newRec->name[j] = name[j];
                    j++;
                    x = name[j];


                }

                newRec->name[j] = x;

                while(y != '\0')
                {

                    newRec->address[v] = address[v];
                    v++;
                    y = address[v];


                }

                newRec->address[v] = y;

                newRec->next = nextRec;
                currentRec->next = newRec;
                i = 0;

            }
            else
            {

                currentRec = currentRec->next;

            }

        }

    }

    return i;

}

/****************************************************************
//
//  Function name: findLoginCredential
//
//  DESCRIPTION:   finds a login_credential in the heap via app_name
//
//
//  Parameters:    loginFind: struct login_credential *, first login_credential in list
//                 app_name: char[], the login_credential to locate
//
//  Return values: 0 : success
//                 -1: failure
//
*****************************************************************/

int findRecord(struct login_credential *loginFind, char[] app_name)
{

    struct login_credential *currentLoginCredential;
    int i;

    // TODO: below is old code to modify
    currentRec = recFind;
    i = 1;

    if(debugmode == 1)
    {

        printf("\n***In findRecord function***\n");
        printf("\n***Account to find is %d***\n", accountNum);

    }

    if(currentRec == NULL)
    {

        i = -1;

    }

    else if(accountNum == currentRec->accountno)
    {

        printf("Record found! Record info:\n");
        printf("%d\n", currentRec->accountno);
        printf("%s\n", currentRec->name);
        printf("%s\n", currentRec->address);
        i = 0;

    }

    else if(currentRec != NULL)
    {

        while(i == 1)
        {

            if(accountNum > currentRec->accountno && currentRec->next != NULL)
            {

                currentRec = currentRec->next;

            }

            else if(accountNum == currentRec->accountno)
            {

                printf("Record found! Record info:\n");
                printf("%d\n", currentRec->accountno);
                printf("%s\n", currentRec->name);
                printf("%s\n", currentRec->address);
                i = 0;

            }

            else
            {

                i = -1;

            }

        }

    }

    else
    {

        i = -1;

    }

    return i;

}

/****************************************************************
//
//  Function name: deleteLoginCredential
//
//  DESCRIPTION:   deletes a login_credential struct
//
//
//  Parameters:    start: struct login_credential ** address of first login_credential
//                        in the list
//                 app_name: char[], the application name to
//                             be deleted
//
//  Return values: 0 : success
//                 -1: failure
//
****************************************************************/

int deleteLoginCredential(struct login_credential **start, char[] app_name)
{

    int i;
    struct record *currentLoginCredential;
    struct record *nextLoginCredential;
    struct record *afterNextLoginCredential;

    // TODO: below is old code to modify

    i = 1;
    currentRec = NULL;
    nextRec = NULL;
    afterNextRec = NULL;

    if(debugmode == 1)
    {

        printf("\n***In deleteRecord function***\n");
        printf("\n***Account number recieved is %d***\n", accountNum);

    }

    if(*start == NULL || accountNum < (*start)->accountno || (accountNum > (*start)->accountno && (*start)->next == NULL))
    {

        i = -1;

    }

    else if(accountNum == (*start)->accountno)
    {

        currentRec = *start;
        *start = currentRec->next;
        free(currentRec);
        currentRec =NULL;
        i = 0;

    }

    else
    {

        currentRec = *start;
        nextRec = currentRec->next;

        while(i > 0)
        {

            if(accountNum == nextRec->accountno && nextRec->next != NULL)
            {

                afterNextRec = nextRec->next;
                free(nextRec);
                currentRec->next = afterNextRec;
                nextRec = NULL;
                i = 0;

            }

            else if(accountNum == nextRec->accountno && nextRec->next == NULL)
            {

                free(nextRec);
                currentRec->next = NULL;
                nextRec = NULL;
                i = 0;

            }

            else if(accountNum != nextRec->accountno && nextRec->next == NULL)
            {

                 i = -1;

            }

            else
            {

                currentRec = nextRec;
                nextRec = nextRec->next;

            }

        }

    }

    return i;

}

/****************************************************************
//
//  Function name: writeFile
//
//  Description: writes struct login_credentials from the heap to a file
//                and calls encrypt to store the info securely
//
//
//  Params: start (struct *): first login_credential in the list
//          fileName: char[], the file name to write to
//
//
//
//  Return Values: 0  : success, if file is empty it is still
//                      a success, it just means no login_credentials are
//                      added to heap in beginning
//
*****************************************************************/

int writeFile(struct login_credential *start, char fileName[])
{

    FILE * outFile;
    struct login_credential *currentLoginCredential;
    int i;
    int last;
    // TODO: below is old code to modify

    currentRec = start;
    i = 1;

    if(debugmode == 1)
    {

    printf("***In writeFile function.***\n");
    printf("***Writing to file name: %s.***\n", fileName);

    }

    outFile = fopen(fileName, "w");

    if(currentRec == NULL)
    {

        fprintf(outFile, "NULL");
        i = 0;
        fclose(outFile);

    }

    else
    {

        while(i > 0)
        {

            if(currentRec != NULL)
            {

                last = strlen(currentRec->address);
                currentRec->address[last] = '!';
                fprintf(outFile, "%d\n%s\n%s\n", currentRec->accountno, currentRec->name, currentRec->address);
                currentRec = currentRec->next;

            }

            else
            {

                i = 0;

            }

        }

        fclose(outFile);

    }

    return i;

}

/****************************************************************
//
//  Function Name: readFile
//
//  Description:   reads login_credentials from a file to populate the heap
//                 memory with records saved from last use,
//                 calls decrypt to make the credentials usable
//
//
//  Parameters:    start (struct login_credential **): a pointer to the
//                            pointer of the first record
//                 fileName (char []) : the name of the file
//                            to read from
//
//  Return Values: 0 : success
//                 -1: failure
//
****************************************************************/

int readFile(struct login_credential **start, char fileName[])
{

    FILE *inFile;
    int i;
    int j;
    char c;
    int lastName;
    char app_name[30];
    char user_name[15];
    char password[20];
    // TODO: below is old code to modify

    i = 1;
    j = 0;
    lastName = 0;

    inFile = fopen(fileName, "r");

    if(debugmode == 1)
    {

    printf("***In readFile function.***\n");
    printf("***Reading from %s.***\n", fileName);

    }

    if(inFile == NULL)
    {

        i = -1;

    }

    else if(inFile != NULL)
    {

        while((fscanf(inFile, "%d", &accountNum) == 1))
        {

            fgets(dummy, 50, inFile);
            fgets(name, 25, inFile);
            lastName = strlen(name) - 1;
            name[lastName] = '\0';
            j = 0;
            i = 1;

            while(i == 1)
            {

                c = fgetc(inFile);

                if(c != '!')
                {

                    address[j] = c;
                    j++;

                }

                else
                {

                    address[j] = '\0';
                    i = 0;
                    fgets(dummy, 50, inFile);
                    addRecord(start, accountNum, name, address);
                    j = 0;

                }

            }

        }

        fclose(inFile);

    }

    return i;

}

/****************************************************************
//
//  Function name : cleanUp
//
//  Description : cleans the heap memory before the program close
//
//
//  Params : start (struct login_credential **): the address of the first
//                                     record in the list
//
//  Return Values: none
//
//
***************************************************************/

void cleanUp(struct login_credential **start)
{

    struct record *currentLoginCredential;
    struct record *nextLoginCredential;
    int i;

    // TODO: below is old code to modify
    currentRec = NULL;
    nextRec = NULL;
    i = 1;

    if(debugmode == 1)
    {

        printf("***In cleanUp function.***\n");

    }

    if(*start == NULL)
    {

        i = 0;

    }

    else
    {

        currentRec = *start;
        nextRec = currentRec->next;
        *start = NULL;

        while(i == 1)
        {

            if(currentRec->next != NULL)
            {

                free(currentRec);
                currentRec = nextRec;
                nextRec = currentRec->next;

            }

            else
            {

                free(currentRec);
                currentRec = NULL;
                i = 0;

            }

        }

    }

}