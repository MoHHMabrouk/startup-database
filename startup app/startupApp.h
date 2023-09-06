#ifndef _STARTUPAPP_
#define _STARTUPAPP_

#include "startupAppCfg.h"
#include <stdio.h>
#include <string.h>

// Define a structure to represent an employee
typedef struct
{
    char employeeName[20];
    int employeeSalary;
} employeeType;

// Define an enumeration to represent the state of the database
typedef enum
{
    DATABASE_EMPTY=0, // Database is empty
    DATABASE_FULL   // Database is full
} databaseType;

// Define an enumeration to specify different search criteria
typedef enum
{
    ID=1,     // Search by employee ID
    NAME,   // Search by employee name
    SALARY  // Search by employee salary
} searchType;

// Define an enumeration to provide feedback on search results
typedef enum
{
    NOT_FOUND=0, // Employee not found in the database
    FOUND      // Employee found in the database
} searchFeedBackType;

// Define an enumeration to specify different selection types for the application
typedef enum
{
    ADD=1,
    PRINT,
    SEARCH_BY_ID,      // Search for an employee by ID
    SEARCH_BY_NAME,    // Search for an employee by name
    SEARCH_MAX_SALARY  // Search for the employee with the highest salary
} selectionType;


typedef enum
{
    ADD_ALL=1,
    ADD_ONE
}addType;

// Function prototypes

// Function to add an employee to the database
databaseType startupAddEmployee(void);

// Function to search for an employee in the database based on the specified criteria
databaseType startupEmployeeSearch(searchType search);

void startupRunnable(void);

#endif
