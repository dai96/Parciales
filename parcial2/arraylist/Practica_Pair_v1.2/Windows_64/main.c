#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include <string.h>
#include "Employee.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{
ArrayList* lista;

lista=al_newArrayList();/**le pedimos memoria para esa variable-MALLOC*/

Employee* el;
Employee* eldos;
Employee* auxel;



int i;
int cantidad;//Cantidad que tiene el SIZE
int* ordenarE;
int comprobarOrdenar;
/**Hardcodeo estructura*/
/**4*/
el=(Employee*) malloc(sizeof(Employee));//employee_new();
el->id=666;
strcpy(el->name,"Juan");
strcpy(el->lastName,"gomez");
el->isEmpty=1;

eldos=(Employee*) malloc(sizeof(Employee));
eldos->id=777;
strcpy(eldos->name,"Lucas");
strcpy(eldos->lastName,"Ramirez");
eldos->isEmpty=2;

/**5*/
al_add(lista,el);
al_add(lista,eldos);

/**6*/
cantidad=al_len(lista);
printf("Size array=%d\n",cantidad);
/**7*/
for(i=0;i<cantidad;i++)
{
auxel=(Employee*)al_get(lista,i);/**no necesito hacer malloc porque va crear una nueva, lo tengo que castear porque devuelve puntero a void*/
/**8*/
employee_print(auxel);
//auxeldos=(Employee*)al_get(lista,0);
}
/**9*/
//ordenarE=employee_compare(el,eldos);
comprobarOrdenar=al_sort(lista,employee_compare,1);/**se le pasa solo en diseño de la funcion prque luego dentro se encargar solo de ordenar todo lo que tenga*/


if(comprobarOrdenar==0)
{
    printf("ok\n");
    for(i=0;i<cantidad;i++)
    {
       auxel=(Employee*)al_get(lista,i);
       employee_print(auxel);
    }
}


//employee_print(auxel);









    return 0;
}
