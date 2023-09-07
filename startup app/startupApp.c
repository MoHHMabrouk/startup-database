#include "startupApp.h"
#include <windows.h>

// Define an array to store employee data and an ID counter.
employeeType employeeDatabase[DATABASE_SIZE];
int id;

void stringPrint(char *str)
{
    for (int counter = 0; str[counter] != '\0'; counter++)
    {
        printf("%c", str[counter]);
    }
}

// Function to add a new employee to the database.
static void addNew(void)
{
    printf("Employee Name:");
    fflush(stdin);
    gets(employeeDatabase[id].employeeName);
    printf("Employee Salary:");
    scanf("%d", &employeeDatabase[id].employeeSalary);
}

// Function to start the process of adding employees.
databaseType startupAddEmployee(void)
{
    addType add;
    system("cls");

    // Check if the database is already full.
    if (id >= DATABASE_SIZE)
    {
        return DATABASE_FULL;
    }

    printf("\n\n\n\t\t\t\t\t");
    printf("Please select below:\n\t\t\t\t\t1-Add all employees.\n\t\t\t\t\t2-Add one employee.\n");
    scanf("%d", &add);
    system("cls");

    switch (add)
    {
    case ADD_ALL:
        while (id < DATABASE_SIZE)
        {
            system("cls");
            printf("Add Employee %d.\n", id + 1);
            addNew();
            id++;
        }
        break;

    case ADD_ONE:
        system("cls");
        printf("Add Employee %d.\n", id + 1);
        addNew();
        id++;
        break;
    }
}

// Function to print a single employee's information.
static void startupPrintOne(int idSearch)
{
    printf("%2d\t\t\t", idSearch + 1);
    stringPrint(employeeDatabase[idSearch].employeeName);
    printf("\t\t\t\t%5d\n", employeeDatabase[idSearch].employeeSalary);
}

// Function to print all employees' information.
static void startupPrintAll(void)
{
    system("cls");
    printf("ID\t\t\tName\t\t\t\tSalary\n");
    for (int counter = 0; counter < id; counter++)
    {
        startupPrintOne(counter);
    }
}

// Function to search for an employee by ID.
void searchByID(void)
{
    int idSearch;
    system("cls");
    printf("Enter Employee ID:");
    scanf("%d", &idSearch);
    printf("ID\t\t\tName\t\t\t\tSalary\n");
    startupPrintOne(--idSearch);
}

// Function to search for an employee by name.
void searchByName(void)
{
    char employeeName[20];
    system("cls");
    printf("Enter Employee Name:");
    fflush(stdin);
    gets(employeeName);
    printf("ID\t\t\tName\t\t\t\tSalary\n");
    for (int idSearch = 0; idSearch < id; idSearch++)
    {
        // Compare the input name with employee names in the database.
        if (!strcmp(employeeName, employeeDatabase[idSearch].employeeName))
        {
            startupPrintOne(idSearch);
        }
    }
}

// Function to search for an employee with the maximum salary.
void searchByMaxSalary(void)
{
    int maxSalary = employeeDatabase[0].employeeSalary;
    int idSearch = 0;

    // Iterate through the database to find the employee with the highest salary.
    for (int counter = 1; counter < id; counter++)
    {
        if (employeeDatabase[counter].employeeSalary > maxSalary)
        {
            maxSalary = employeeDatabase[counter].employeeSalary;
            idSearch = counter;
        }
    }

    // Print the employee with the maximum salary.
    printf("ID\t\t\tName\t\t\t\tSalary\n");
    startupPrintOne(idSearch);
}

// Function to start the application and handle user interactions.
void startupRunnable(void)
{
    selectionType select;
    printf("\n\n\n\t\t\t\t\t");
    printf("Welcome to the employee database.....");
    Sleep(2000);
    system("cls");

    while (1)
    {
        printf("\n\n\n\t\t\t\t\t");
        printf("Please select below:\n\t\t\t\t\t1-Add.\n\t\t\t\t\t2-Print.\n\t\t\t\t\t3-Search by ID.\n\t\t\t\t\t4-Search by Name.\n\t\t\t\t\t5-Search for Maximum Salary.\n");
        scanf("%d", &select);

        switch (select)
        {
        case ADD:
            if (startupAddEmployee() == DATABASE_FULL)
            {
                system("cls");
                printf("\n\n\n\t\t\t\t\t");
                printf("Database is full...");
                Sleep(2000);
            }
            break;

        case PRINT:
            startupPrintAll();
            break;
        case SEARCH_BY_ID:
            searchByID();
            break;
        case SEARCH_BY_NAME:
            searchByName();
            break;
        case SEARCH_MAX_SALARY:
            searchByMaxSalary();
            break;
        }
    }
}
