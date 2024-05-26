#ifndef TYPEDEF_COMMON_H
#define TYPEDEF_COMMON_H

typedef enum
{
    FALSE,
    TRUE
} BOOL;

typedef unsigned    char           UINT8;
typedef signed      char           SINT8;

typedef unsigned    short int      UINT16;
typedef signed      short int      SINT16;

typedef unsigned    long int       UINT32;
typedef signed      long int       SINT32;

typedef BOOL ReturnType;

#define E_OK    FALSE
#define E_NOK   TRUE

#endif