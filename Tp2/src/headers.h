/*
 * headers.h
 *
 *  Created on: 29 abr. 2020
 *      Author: asato fumihito
 */

#ifndef HEADERS_H_
#define HEADERS_H_
#define EMPTY 0
#define FILLED 1
typedef struct //declaro una estructura con los datos de un empleado
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}eEmployee; // el nombre que toma la estructura

int findEmpty(eEmployee*, int);
void loadEmployeeList(eEmployee[],int,int*);
eEmployee loadEmployee(void);
void showEmployee(eEmployee);
int searchEmployeeById(eEmployee[], int,int);
void modifyEmployee(eEmployee[],int);
int modifyName(eEmployee[], int,int );
int modifyLastName(eEmployee[],int,int);
int modifySalary(eEmployee[] ,int,int);
int modifySector(eEmployee[] ,int,int);
int deleteEmployee(eEmployee[] ,int );
void showEmployeeList(eEmployee[], int );
void sortEmployee(eEmployee[], int );
#endif /* HEADERS_H_ */
