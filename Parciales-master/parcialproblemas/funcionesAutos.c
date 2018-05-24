#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<strings.h>
#include<string.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"
#include "funcionesAutos.h"

int inicializarAutos( eAutos autos[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && autos != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            autos[i].estado= 0;
        }
    }
    return retorno;
}

int mostrarListadoAutos(eAutos autos[],int limite)
{

    int retorno = -1;
    int i;
    if(limite > 0 && autos != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(autos[i].estado==1)
            {

                mostrarUnoAutos(autos[i]);
            }
        }
    }
    return retorno;
}

int mostrarUnoAutos(eAutos autos)
{


     printf("\n %d - %s - %d\n\n\n",autos.idProp,autos.patente,autos.marca);

}

int altaAuto(eAutos autos[],ePropietarios propietarios[], int limite)
{
    int retorno =-1;
    int i;
    char auxI[50];
    char auxP[50];
    char auxM[50];
    int idPropAlta;
    int respuesta;
    int busqueda;

    int idProp;
    int idAuto;
    char patente[50];
    int marca;
    int estado;

    i=buscarLugarLibre(autos,limite);

    //mostrarListado(propietarios,limite);
    if(i>=0)
    {

        getString("\nIngrese id del propietario: ",auxI);
        while(esNumero(auxI)==0)
        {
            getString("\nERROR! los IDs son numericos, intenta nuevamente: ",auxI);
        }

        idPropAlta=atoi(auxI);

        busqueda=buscarPorId(propietarios,idPropAlta,limite);

        if(busqueda==-1)
        {
            printf("\nERROR! ID incorrecto\n");
        }
        else
        {
            ("Ingrese la patente: ",auxP);
            while(esSoloLetras(auxP)==0)
            {
               getString("ERROR! Ingrese solo letras: ",auxP);
            }

            getString("Ingrese la marca: ",auxM);
            while(esNumero(auxM)==0)
            {
               getString("ERROR! Ingrese solo numeros: ",auxM);
            }

            printf("\nIngrese s para dar de alta al siguiente auto:\n\n %s - %s \nEn el siguiente usuario: %s - %s \n\n", auxP, auxM, auxI,propietarios[busqueda].idProp);
            respuesta=getch();

            if (respuesta=='s')
            {
                autos[i].idProp=propietarios[busqueda].idProp;
                autos[i].idAuto=idIncremental(autos,limite);
                strcpy(autos[i].patente, auxP);
                strcpy(autos[i].marca, auxM);
                autos[i].estado=1;

                printf("\n\n\nAlta Exitosa!\n\n");

                printf("\n\nIngrese s si desea ver el listado\n\n");
                respuesta=getch();
                if (respuesta=='s')
                {
                    mostrarListadoAutos(autos, limite);
                }

            }
            else
            {
                printf("\n\n\n Alta cancelada\n\n\n");
            }

        return 0;
        }
    }

}
/*
void bajaAuto ()
{


    int i;
    int monto;
    int auxPropietario;

    i=buscarLugarLibre(autos,limite);

    if(autos[i].marca==1)
    {
        monto = tiempo*150;
    }
    if(autos[i].Marca==2)
    {
        monto = tiempo*175;
    }
    if(autos[i].Marca==3)
    {
        monto = tiempo*200;
    }
    if (autos[i].marca==4)
    {
        monto = tiempo*250;
    }


    autos[i].Tiempo=tiempo;
    autos[i].Monto=monto;
    autos[i].Estado=2;

    system("cls");


    auxPropietario=buscarPorID(propietarios[],autos[],limite);

    printf("\n\nPatente: %s\n",Output[libre].Patente);

    if(Output[libre].Marca==1)
    {
        printf("\n\nMarca: Alpha Romeo.\n");
    }
    else if(Output[libre].Marca==2)
    {
        printf("\n\nMarca: Ferrari.\n");
    }
    else if(Output[libre].Marca==3)
    {
        printf("\n\nMarca: Audi.\n");
    }
    else
    {
        printf("\n\nMarca: Otro.\n");
    }

    printf("\n\nHoras de estadia: %dhs\n",Output[libre].Tiempo);
    printf("\n\nMonto a pagar: $%d\n",Output[libre].Monto);


    printf("\n\nPropietario: %s.\n\n\n",Persona[auxPropietario].NombreCompleto);
    system("pause");
    system("cls");

    printf("\n\n\n\t\t\t\t\t~Se ha retirado el auto correctamente~\n\t\t\t\t\tSera redirijido al menu principal.\n\n\n\n");
    system("pause");
}







}
*/
