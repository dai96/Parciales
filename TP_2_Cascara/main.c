#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<strings.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"
#define TAM 20
#define TAME 10


int main()
{
    EPersona personas [TAM];

    char seguir='s';
    int opcion=0;




    inicializar(personas,TAM);
    cargarHardCode(personas);
    //inicializarSeriesHardCode()
    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");
        printf("6-Modificar\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                alta(personas,TAM);
                break;
            case 2:
                baja(personas,TAM);
                break;
            case 3:
                ordenarAlfabeticamete(personas,TAM);
                mostrarListado(personas,TAM);
                break;
            case 4:
                break;
            case 5:
                seguir = 'n';
                break;
            case 6:
                modificacion(personas,TAM);
                break;
        }
    }

    return 0;
}





