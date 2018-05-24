#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<strings.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"
#define TAM 20



int main()
{
    ePropietarios propietarios [TAM];
    eAutos autos [TAM];

    char seguir='s';
    int opcion=0;
    int opcionDos;

    inicializar(propietarios,TAM);
    cargarHardCode(propietarios);

    printf("Bienvenido!\n");
    while(seguir=='s')
    {
        printf("---------------------------------------------------------------------------");
        printf("\n                    Elija una opcion para continuar:\n\n");
        printf("1- Alta Propietario                   |  6- Egreso auto\n");
        printf("2- Modificar tarjeta de credito       |  7- Recaudacion total\n");
        printf("3- Baja Propietario                   |  8- Recaudacion por marca\n");
        printf("4- Alta Auto                          |  9- AUDI\n");
        printf("5- Buscar propietario                 |  10- Lista de autos\n\n");
        printf("0- Salir\n\n-");
        //printf("6-Modificar");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                LimpiarPantalla();
                alta(propietarios,TAM);
                break;
            case 2:
                LimpiarPantalla();
                modificacion(propietarios,TAM);
                break;
            case 3:
                LimpiarPantalla();
                baja(propietarios,TAM);
                break;
            case 4:
                LimpiarPantalla();
                altaAuto(autos, TAM);
                break;
            case 5:
                LimpiarPantalla();
                break;
            case 6:
                LimpiarPantalla();
                break;
            case 7:
                LimpiarPantalla();
                break;
            case 8:
                    LimpiarPantalla();
                break;
            case 9:
                LimpiarPantalla();
                break;
            case 10:
                LimpiarPantalla();
                break;
            case 0:
                seguir = 'n';
                break;

        }
    }

    return 0;
}





