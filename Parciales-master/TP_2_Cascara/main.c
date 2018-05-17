#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<strings.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"
#include "funcionesAutos.h"
#define TAM 20



int main()
{
    ePropietarios propietarios [TAM];

    char seguir='s';
    int opcion=0;

    inicializar(propietarios,TAM);
    cargarHardCode(propietarios);

    printf("Bienvenido!\n");
    while(seguir=='s')
    {
        printf("--------------------*o*----------------------");
        printf("\nElija una opcion para continuar:\n\n");
        printf("1- Alta Propietario\n");
        printf("2- Modificar tarjeta de credito\n");
        printf("3- Baja Propietario\n");
        printf("4- Mostrar lista propietarios\n\n");
        printf("5- Salir\n\n-");
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
                mostrarListado(propietarios,TAM);
                break;
            case 5:
                seguir = 'n';
                break;
            case 6:
                //listaDeBorrados(propietarios,TAM);
                //modificacion(propietarios,TAM);
                break;
        }
    }

    return 0;
}





