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
//  FILE:        login_credential.h
//
//  DESCRIPTION:
//   <Contains the struct to hold a login/password>
//
****************************************************************/

struct record
{
    char            app_name[30];
    char            user_name[15];
    char            password[20];
    struct login_credential*  next;
};