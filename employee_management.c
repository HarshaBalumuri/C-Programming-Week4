#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

// Add Employee
void addEmployee() {
    FILE *fp;
    struct Employee emp;

    fp = fopen("employee.txt", "a");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);

    printf("Enter Employee Name: ");
    scanf(" %[^\n]", emp.name);

    printf("Enter Employee Salary: ");
    scanf("%f", &emp.salary);

    fprintf(fp, "%d %s %.2f\n", emp.id, emp.name, emp.salary);

    fclose(fp);

    printf("\nEmployee Added Successfully!\n");
}

// View Employees
void viewEmployees() {
    FILE *fp;
    struct Employee emp;

    fp = fopen("employee.txt", "r");

    if (fp == NULL) {
        printf("\nNo employee records found!\n");
        return;
    }

    printf("\n===============================\n");
    printf(" Employee Records\n");
    printf("===============================\n");

    while (fscanf(fp, "%d %s %f", &emp.id, emp.name, &emp.salary) != EOF) {
        printf("\nEmployee ID   : %d", emp.id);
        printf("\nEmployee Name : %s", emp.name);
        printf("\nSalary        : %.2f\n", emp.salary);
        printf("-------------------------------\n");
    }

    fclose(fp);
}

// Search Employee
void searchEmployee() {
    FILE *fp;
    struct Employee emp;
    int id, found = 0;

    fp = fopen("employee.txt", "r");

    if (fp == NULL) {
        printf("\nNo employee records found!\n");
        return;
    }

    printf("\nEnter Employee ID to Search: ");
    scanf("%d", &id);

    while (fscanf(fp, "%d %s %f", &emp.id, emp.name, &emp.salary) != EOF) {

        if (emp.id == id) {
            printf("\nEmployee Found!\n");
            printf("ID     : %d\n", emp.id);
            printf("Name   : %s\n", emp.name);
            printf("Salary : %.2f\n", emp.salary);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nEmployee Not Found!\n");

    fclose(fp);
}

// Count Employees
void countEmployees() {
    FILE *fp;
    struct Employee emp;
    int count = 0;

    fp = fopen("employee.txt", "r");

    if (fp == NULL) {
        printf("\nNo employee records found!\n");
        return;
    }

    while (fscanf(fp, "%d %s %f", &emp.id, emp.name, &emp.salary) != EOF)
        count++;

    printf("\nTotal Employees = %d\n", count);

    fclose(fp);
}

int main() {

    int choice;

    do {

        printf("\n====================================");
        printf("\n EMPLOYEE MANAGEMENT SYSTEM");
        printf("\n====================================");
        printf("\n1. Add Employee");
        printf("\n2. View Employees");
        printf("\n3. Search Employee");
        printf("\n4. Count Employees");
        printf("\n5. Exit");
        printf("\n====================================");
        printf("\nEnter your choice: ");

        scanf("%d", &choice);

        switch(choice) {

            case 1:
                addEmployee();
                break;

            case 2:
                viewEmployees();
                break;

            case 3:
                searchEmployee();
                break;

            case 4:
                countEmployees();
                break;

            case 5:
                printf("\nThank You!\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while(choice != 5);

    return 0;
}