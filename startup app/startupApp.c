#include "startupApp.h"
#include <windows.h>
employeeType employeeDatabase[DATABASE_SIZE];
int id;

static void addNew(void)
{
    printf("Employee Name:");
    fflush(stdin);
    gets(employeeDatabase[id].employeeName);
    printf("Employee Salary:");
    scanf("%d", employeeDatabase[id].employeeSalary);
}

static databaseType startupAddEmployee(void)
{
    addType add;

    if (id >= DATABASE_SIZE)
    {
        return DATABASE_FULL;
    }

    printf("Please select below:\n1-Add all employess.\n2-Add one employee.");
    scanf("%d", &add);

    switch (add)
    {
    case ADD_ALL:
        for (id = 0; id < DATABASE_SIZE; id++)
        {
            printf("Add Employee %d.", id + 1);
            addNew();
        }
        break;

    case ADD_ONE:
        printf("Add Employee %d.", id + 1);
        addNew();
        id++;
        break;
    }
}

static void startupPrintOne(int id)
{
    printf("ID\t\t\tName\t\t\tSalary\n");
    printf("%2d\t\t\t", id + 1);
    puts(employeeDatabase[id].employeeName);
    printf("\t\t\t%5d", employeeDatabase[id].employeeSalary);
}

static void startupPrintAll(void)
{
    for (int counter = 0; counter < id; counter++)
    {
        startupPrintOne(counter);
    }
}

void startupRunnable(void)
{
    selectionType select;
    printf("Welcome to employee database.\nPlease select below:\n1-Add all employees.\n2-Add one employee.\n3-Search by ID.\n4-Search by Name.\n5-Search for Maximum Salary.\n");
    scanf("%d", &select);

    switch (select)
    {
    case ADD:
        system("cls");
        startupAddEmployee();
        break;

    case PRINT:
        startupPrintAll();
        break;
    case SEARCH_BY_ID:

        break;
    case SEARCH_BY_NAME:

        break;
    case SEARCH_MAX_SALARY:

        break;
    }
}