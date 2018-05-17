#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<strings.h>
#include<string.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"


int getInt (char mensaje[])
{
   int aux;
    printf("%s",mensaje);
    scanf("%d",&aux);
    return aux;
}

float getFloat (char mensaje[])
{
   float aux;
   printf("%s",mensaje);
   scanf("%f",&aux);
   return aux;
}

char getChar (char mensaje[])
{
    char aux;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&aux);
    return aux;
}

int esNumero (char bector[])
{
    int i=0;
    while(bector[i] != '\0')
    {
        if (bector[i]<'0' || bector[i]>'9')
        return 0;
        i++;
    }
    return 1;
}

int esTelefono(char bector[])
{
    int i=0;
    int contar=0;
    while (bector[i] != '\0')
    {
        if ((bector[i] != ' ') && (bector[i] != '-') && (bector[i]< '0' || bector[i]>'9'))
            return 0;
        if (bector[i]=='-')
            contar++;
        i++;


    }
      if (contar==1)
        return 1;

       return 0;

}

int esAlfaNumerico(char bector[])
{
    int i=0;
    while (bector[i] != '\0')
    {
    if (bector[i] != ' ' && (bector[i] < 'a' || bector[i] > 'z' ) && (bector[i] < 'A' || bector[i] > 'Z' ) && (bector[i] < '0' || bector[i] > '9'))
        return 0;
    i++;

    }
    return 1;
}

int esSoloLetras(char bector [])
{
    int i=0;
    while(bector[i] != '\0')
    {

     if((bector[i] != ' ') && (bector[i] < 'a' || bector[i] > 'z' ) && (bector[i] < 'A' || bector[i] > 'Z' ) )

        return 0;
        i++;


    }

    return 1;//letra

}

void getString(char mensaje [], char input [])
{
   printf(mensaje);
   fflush(stdin);
   gets(input);

}

int getStringLetras(char mensaje[], char input [])
{
    char aux [256];
    getString(mensaje, aux);
    if (esSoloLetras(aux)==1)
    {
        strcpy(input,aux);
        return 1;
    }
   /** else
    {
        printf("ERROR! Ingrese solo letras");
    }*/
}

int getStringNumeros(char mensaje [], char input[])
{
    char aux [256];
    getString(mensaje, aux);
    if (esNumero(aux))
    {
        strcpy(input, aux);
        return 1;
    }


}

int inicializar( ePropietarios propietarios[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && propietarios != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            propietarios[i].estado= 0;
        }
    }
    return retorno;
}

int mostrarListado(ePropietarios propietarios[],int limite)
{




    int retorno = -1;
    int i;
    if(limite > 0 && propietarios != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(propietarios[i].estado==1)
            {

                mostrarUno(propietarios[i]);
            }
        }
    }
    return retorno;
}

int mostrarUno(ePropietarios propietarios)
{


     printf("\n %d - %s - %s - %s \n\n\n",propietarios.idProp,propietarios.nombre,propietarios.direccion,propietarios.tarjeta);

}

int buscarLugarLibre(ePropietarios propietarios[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && propietarios != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(propietarios[i].estado == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int alta(ePropietarios propietarios[],int limite)
{
    int retorno =-1;
    int i;
    char auxN[50];
    //char auxA[50];
    char auxD[50];
    char auxT[50];
    int respuesta;

    i=buscarLugarLibre(propietarios,limite);
    if(i>=0)
    {

        getString("Ingrese el nombre y apellido: ",auxN);
        while(esSoloLetras(auxN)==0)
        {
           getString("ERROR! Ingrese solo letras: ",auxN);
        }

        //getString("Ingrese el apellido: ",auxA);
        //while(esSoloLetras(auxA)==0)
        //{
          // getString("ERROR! Ingrese solo letras: ",auxA);
        //}

        getString("Ingrese la direccion: ",auxD);
        while(esAlfaNumerico(auxD)==0)
        {
           getString("ERROR! Ingrese solo letras o numeros: ",auxD);
        }

        getString("Ingrese el numero de tarjeta: ",auxT);
        while(esTelefono(auxT)==0)
        {
           getString("ERROR! Ingrese solo numeros: ",auxT);
        }

        printf("\nIngrese s para dar de alta los siguientes datos:\n\n %s - %s - %s \n\n", auxN, auxD, auxT);
        respuesta=getch();

        if (respuesta=='s')
        {
            propietarios[i].idProp=idIncremental(propietarios,limite);
            strcpy(propietarios[i].nombre, auxN);
            //strcpy(propietarios[i].apellido, auxA);
            strcpy(propietarios[i].direccion, auxD);
            strcpy(propietarios[i].tarjeta, auxT);
            propietarios[i].estado=1;

            printf("\n\n\nAlta Exitosa!\n\n");

            printf("\n\nIngrese s si desea ver el listado\n\n");
            respuesta=getch();
            if (respuesta=='s')
            {
                mostrarListado(propietarios, limite);
            }

        }
        else
        {
            printf("\n\n\n Alta cancelada\n\n\n");
        }

    return 0;
        }
}

 void cargarHardCode(ePropietarios propietarios[])
{
 int i;
    /**datos:
    apellidos: "Miñarro""Flo""Gomez""Perez""Moix""Potter""Gonzales""Zaccari"
    numeros telefono: 4454-1403 6380-4131 4453-0310 6390-2222 1111-3333 8888-2222 4444-6666
    direcciones: "Castellar 2241" "Pazos 323" "Ibarrola 674" "Ribadavia 6320" "Haiti 330" "Misiones 1456" "Corrientes 997"
    legajo: "123" "124" "125" "126" "127" """"""

    */
    int id[]= {1,2,3,4};
    char nombre[][50]= {"Juan","Luis","Maria","Jose"};
    char tarjeta [] [50] = {"111-111","222-222","333-333","444-444"};
    char direccion[][50]= {"Mitre","Urquiza","Belgrano","Alsina"};


    for(int i=0; i<4; i++)
    {
        propietarios[i].idProp=id[i];
        strcpy(propietarios[i].nombre,nombre[i]);
        strcpy(propietarios[i].direccion,direccion[i]);
        strcpy(propietarios[i].tarjeta,tarjeta[i]);
        propietarios[i].estado=1;
    }

}

int baja(ePropietarios propietarios[],int limite)
{
    char auxIdProp [50];
    int busqueda;
    char respuesta;
    int auxIdPropBaja;

    mostrarListado(propietarios,limite);

    getStringNumeros("\nIngrese Id a dar de baja: ",auxIdProp);
    auxIdPropBaja=atoi(auxIdProp);

    busqueda=buscarPorId(propietarios,auxIdPropBaja,limite);

     if(busqueda==-1)
    {
        printf("\nERROR! Id incorrecto.\n");

    }
    else
    {
        printf("\nIngrese s para borrar el siguiente dato: \n\n%s - %s - %s -%d\n\n",propietarios[busqueda].nombre,propietarios[busqueda].direccion,propietarios[busqueda].tarjeta, propietarios[busqueda].idProp);
        respuesta=getche();
        if(respuesta=='s')
        {
            printf("\n\nBaja exitosa!\n\n");
            propietarios[busqueda].estado=3;

            printf("\n\nIngrese s si desea ver el listado\n\n");
            respuesta=getch();
            if (respuesta=='s')
            {
                mostrarListado(propietarios,limite);
            }

        }
        else
        {
            printf("\n\nBaja cancelada.\n\n");
        }
    }


    return 0;
}

/**int buscarPorDni(ePropietarios persona[],int dni,int limite)
{

    for(int i=0; i<limite; i++)
    {
        if(persona[i].estado==1 && persona[i].dni==dni)
        {
            return i;
        }
    }
    return -1;
}*/

int buscarPorId(ePropietarios propietarios[],int id,int limite)
{

    for(int i=0; i<limite; i++)
    {
        if(propietarios[i].estado==1 && propietarios[i].idProp==id)
        {
            return i;
        }
    }
    return -1;
}

/**void ordenarAlfabeticamete(ePropietarios propietarios [],int limite)
{
    ePropietarios auxiliar;
    int i;
    int j;
    for(i=0; i<limite-1; i++)
    {
        for(j=i+1; j<limite; j++)
        {

            //if(propietarios[i].idUsuario>propietarios[j].idUsuario)//asi para ordenar numeros
            if(strcmp(propietarios[i].nombre,propietarios[j].nombre)>0)//asi para orenar letras
            {

                auxiliar=propietarios[i];
                propietarios[i]=propietarios[j];
                propietarios[j]=auxiliar;
            }

        }
    }

}*/

/**void ordenarNumericamente(ePropietarios propietarios [],int limite)
{
    ePropietarios auxiliar;
    int i;
    int j;
    for(i=0; i<limite-1; i++)
    {
        for(j=i+1; j<limite; j++)
        {

            if(propietarios[i].edad>propietarios[j].edad)//asi para ordenar numeros. para ordenamiento desenderte cambia <>
            //if(strcmp(propietarios[i].nombre,propietarios[j].nombre)>0)//asi para orenar letras
            {

                auxiliar=propietarios[i];
                propietarios[i]=propietarios[j];
                propietarios[j]=auxiliar;
            }

        }
    }


}*/

void LimpiarPantalla(void)
{
    system("cls");
}


int idIncremental(ePropietarios propietarios[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && propietarios != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(propietarios[i].estado == 1)///si el anterior esta ocupado
            {
                    if(propietarios[i].idProp>retorno)///y esa id sea mayor al retorno
                    {
                         retorno=propietarios[i].idProp;///devuelve esa id
                    }

            }
        }
    }

    return retorno+1;///y retorna el lugar siguiente
}


void modificacion (ePropietarios propietarios[], int limite)
{
    char auxIdProp[50];
    int auxiliarIdProp;
    int busqueda;
    char auxT[50];
    char respuesta;

    mostrarListado(propietarios,limite);

    getString("\nIngrese id a modificar: ",auxIdProp);
    while(esNumero(auxIdProp)==0)
    {
        getString("\nERROR! los IDs son numericos, intenta nuevamente: ",auxIdProp);
    }

    auxiliarIdProp=atoi(auxIdProp);
    busqueda=buscarPorId(propietarios,auxiliarIdProp,limite);

     if(busqueda==-1)
    {
        printf("\nERROR! ID incorrecto\n");
    }
    else
    {
        getString("\nIngrese el nuevo numero de tarjeta: ",auxT);
        while(esTelefono(auxT)==0)
        {
            getString("\nERROR! solo numeros son permitidos en la tarjeta, intenta otra vez: ",auxT);
        }

        printf("\nPrecione s para confirmar modificacion en usuario : \n\n%s - %d\n\n ",propietarios[busqueda].nombre,propietarios[busqueda].idProp);
        respuesta=getche();
        if (respuesta=='s')
        {
            strcpy(propietarios[busqueda].tarjeta, auxT);
        }
        else
        {
            printf("\nModificacion cancelada");
        }
    }

}


void listaDeBorrados(ePropietarios propietarios[],int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        if(propietarios[i].estado==3)
        {
            mostrarUno(propietarios[i]);
        }
    }
}


int devolverHorasEstadia()
{
    int horas;

    srand(time(NULL));

    horas = (rand()%24)+1;

    return horas ;

}


/**float calcularPromedio(float nota1, float nota2)
{
    float promedio;
    promedio = (float)(nota1+nota2)/2;
    return promedio;
}


  void mostrarUnoAMuchos(estructura1 uno[], int TAM1, estructura2 muchos[], int TAM2)
{
    int i;
    int j;
    for(i=0;i<TAM1;i++)///mostrar de todos los usuario una sola serie
    {
        for(j=0;j<TAM2;j++)
        {
            if(uno[i].estado!=0 && muchos[j].estado!=0)
            {
                if(uno[i].idSerie==muchos[j].idSerie)
                {
                    printf("\n%d %s %s\n",uno[i].idUsuario,uno[i].nombre,muchos[j].nombre);///depende de lo que se quiera mostrar
                    break;
                }
            }
        }
    }
    for(i=0;i<TAM1;i++)///al reves
    {
        for(j=0;j<TAM2;j++)
        {
            if(muchos[j].estado!=0 && uno[i].estado!=0)
            {
                if(muchos[j].idSerie==uno[i].idSerie)
                {
                    printf("\n%d %s %s %d %s\n",muchos[j].idSerie,muchos[j].nombre,muchos[j].genero,muchos[j].cantidadTemporadas,uno[i].nombre);
                    break;
                }
            }
        }
}



//void mostrarUnoaMuchos(ePropietarios persona [])



void modificar(ePropietarios propietarios[],int limite)
{
    int opcion;
    int busqueda;
    int dni;
    int edad;
    char auxD[50];
    char auxN[50];
    char auxE[50];
    char auxiliar[50];
    int auxiliarbusqueda;

    mostrarListado(propietarios, limite);

    printf("\n\nIngrese el id que desea modifcar:\n");
    fflush(stdin);
    gets(auxiliar);
    while(esNumero(auxiliar)==0)
    {
        printf("ERROR! Ingrese el ID: ");
        fflush(stdin);
        gets(auxiliar);
    }
    auxiliarbusqueda= atoi(auxiliar);
    busqueda=buscarPorId(propietarios,auxiliarbusqueda,limite);

    if(busqueda==-1)
    {
        printf("ERROR! ID incorrecto.\n");

    }
    else
    {
        printf("Ingrese dato a modificar\n1- Nombre\n2- Edad\n3- Dni\n");
        fflush(stdin);
        gets(opcion);

            switch(opcion)
            {
            case 1:

                    getString("Ingrese el nombre: ",auxN);

                    while(esSoloLetras(auxN)==0)
                    {
                        printf("ERROR! Ingrese un nombre: ");
                        fflush(stdin);
                        gets(auxN);
                    }
                    strcpy(propietarios[busqueda].nombre,auxiliar);
                    printf("se a cambiado correctamente el nombre \n");


                break;
            case 2:
                break;
            case 3:
                break;
            }


        }



}*/


/**void inicializarSeriesHardCode(eSerie serie[])
{
    int id[5] = {100,101,102,103,104};
    char nombre[][50]={"TBBT","TWD","GOT","BB","LCDP"};
    char genero[][50]={"Comedia","Terror","Suspenso","Policial","Policial"};
    int cantidad[5] = {10,9,7,5,2};

    int i;

    for(i=0; i<5; i++)
    {
        serie[i].idSerie=id[i];
        serie[i].cantidadTemporadas=cantidad[i];
        serie[i].estado=1;
        strcpy(serie[i].nombre, nombre[i]);
        strcpy(serie[i].genero, genero[i]);
    }
}
*/

