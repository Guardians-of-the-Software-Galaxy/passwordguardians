/*****************************************************************
//
//  NAME:        Password Guardians
//
//  CLASS:       ICS 427
//
//  INSTRUCTOR:  Barbara Endicott
//
//  DATE:        1/30/23
//
//  FILE:        database.h
//
//  DESCRIPTION:
//   <Contains prototypes to be used by the database>
//
****************************************************************/

int addLoginCredential(struct login_credential **, int, char[], char[]);
int findLoginCredential(struct login_credential *, int);
int deleteLoginCredential(struct login_credential **, int);
int decrypt(struct login_credential *)
int encrypt(struct login_credential *)
int readFile(struct login_credential **, char[]);
int writeFile(struct login_credential *, char[]);
void cleanUp(struct login_credential **);