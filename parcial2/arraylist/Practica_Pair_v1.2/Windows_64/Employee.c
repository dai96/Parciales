#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include <string.h>

/**Devuelve un puntero a void y vamos a comparar dos empleados*/
int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
Employee* e1;
Employee*e2;
Employee* aux;
int retorno;

e1=(Employee*) pEmployeeA;
e2=(Employee*) pEmployeeB;


retorno=strcmp(e1->name ,e2->name);

    return retorno; /**Solo le tengo que devolver si es 1,0, o -1 , la funcion array list se encargar de analizarlo*/
}


void employee_print(Employee* this)
{

        printf("\nId=%d  \nNombre=%s  \nApellido=%s  \nEmpty=%d\n",this->id,this->name,this->lastName,this->isEmpty);




}


Employee* employee_new(void)
{

    Employee* returnAux = NULL;

    return returnAux;

}

void employee_delete(Employee* this)
{


}

int employee_setId(Employee* this, int id)
{

    return 0;

}

int employee_getId(Employee* this)
{

    return 0;

}


