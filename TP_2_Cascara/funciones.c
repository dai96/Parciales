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
    if (esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;

    }

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

int inicializar( EPersona personas[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && personas != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            personas[i].estado= 0;
        }
    }
    return retorno;
}

int mostrarListado(EPersona personas[],int limite)
{




    int retorno = -1;
    int i;
    if(limite > 0 && personas != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(personas[i].estado==1)
            {

                mostrarUno(personas[i]);
            }
        }
    }
    return retorno;
}

int mostrarUno(EPersona personas)
{


     printf("\n %s - %d - %d - %d -%d\n\n\n",personas.nombre,personas.edad,personas.estado,personas.dni,personas.id);

}

int buscarLugarLibre(EPersona personas[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && personas != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(personas[i].estado == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int alta(EPersona personas[],int limite)
{
    int retorno =-1;
    int i;
    char auxN[50];
    char auxD[50];
    char auxE[50];
    int dni;
    int edad;
    int respuesta;

    i=buscarLugarLibre(personas,limite);
    if(i>=0)
    {
        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(auxN);
        while(esSoloLetras(auxN)==0)
        {
            printf("ERROR! Ingrese un nombre: ");
            fflush(stdin);
            gets(auxN);
        }

        printf("Ingrese la edad: ");
        fflush(stdin);
        gets(auxE);
        while(esNumero(auxE)==0)
        {
            printf("ERROR! Ingrese una edad: ");
            fflush(stdin);
            gets(auxE);
        }

        edad=atoi(auxE);



        printf("Ingrese el dni: ");
        fflush(stdin);
        gets(auxD);
        while(esNumero(auxD)==0)
        {
            printf("ERROR! Ingrese un dni: ");
            fflush(stdin);
            gets(auxD);
        }
        dni=atoi(auxD);

        printf("\nIngrese s para dar de alta los siguientes datos:\n\n %s - %d - %d ", auxN, edad, dni);
        respuesta=getch();

        if (respuesta=='s')
        {
        strcpy(personas[i].nombre, auxN);
        personas[i].edad=edad;
        personas[i].dni=dni;
        personas[i].id=idIncremental(personas,limite);
        personas[i].estado=1;


        printf("\n\n\nAlta Exitosa!\n\n");
        printf("\n\nIngrese s si desea ver el listado\n\n");
        respuesta=getch();
        if (respuesta=='s')
        {
            mostrarListado(personas, limite);

        }

        }
        else
        {
            printf("\n\n\n Alta cancelada\n\n\n");

        }
    }
    return 0;
}

 void cargarHardCode(EPersona personas[])
{
 int i;
    /**datos

    apellidos: "Miñarro""Flo""Gomez""Perez""Moix""Potter""Gonzales""Zaccari"
    numeros telefono 4454-1403 6380-4131 4453-0310 6390-2222 1111-3333 8888-2222 4444-6666
    direcciones "Castellar 2241" "Pazos 323" "Ibarrola 674" "Ribadavia 6320" "Haiti 330" "Misiones 1456" "Corrientes 997"
    legajo "123" "124" "125" "126" "127" """"""


    */
EPersona auxPersonas[15]= {{"Daira",22,1,39462131},{"Pedro",28,1,39462132},{"Belen",21,1,39462133},{"Julian",20,1,39462134},{"Natalia",30,1,39462135},{"Carlitos",37,1,39462136},{"Sofia",34,1,39462137},{"Lina",55,1,39462138},{"Javier",19,1,39462139},{"Luciana",6,1,39462140},{"Pablo",14,1,39462141},{"Maria",26,1,39462142},{"Ana",63,1,39462143},{"Mario",42,1,39462144},{"Francisca",60,1,39462145}};
    for(i=0; i<15; i++)
    {
        personas[i]=auxPersonas[i];
        personas[i].id=idIncremental(personas,20);

    }

}

int baja(EPersona personas[],int limite)
{
    char auxDniBa [235];
    int busqueda;
    char respuesta;
    int auxDniBaja;
    mostrarListado(personas,limite);

    getStringNumeros("\nIngrese DNI a dar de baja: ",auxDniBa);
    auxDniBaja=atoi(auxDniBa);

    busqueda=buscarPorDni(personas,auxDniBaja,limite);

     if(busqueda==-1)
    {
        printf("ERROR! Dni incorrecto.\n");

    }
    else
    {printf("Ingrese s para borrar el siguiente dato: \n\nDni:%d\nNombre:%s\nEdad:%d\n",personas[busqueda].dni,personas[busqueda].nombre,personas[busqueda].edad);
    respuesta=getche();

    if(respuesta=='s')
    {
        printf("\n\nBaja exitosa!\n\n");
        personas[busqueda].estado=3;
        printf("\n\nIngrese s si desea ver el listado\n\n");
        respuesta=getch();
        if (respuesta=='s')
        {
            mostrarListado(personas,limite);
        }

    }
    else
    {
        printf("\n\nBaja cancelada.\n\n");
    }
    }


    return 0;
}

int buscarPorDni(EPersona persona[],int dni,int limite)
{

    for(int i=0; i<limite; i++)
    {
        if(persona[i].estado==1 && persona[i].dni==dni)
        {
            return i;
        }
    }
    return -1;
}

int buscarPorId(EPersona persona[],int id,int limite)
{

    for(int i=0; i<limite; i++)
    {
        if(persona[i].estado==1 && persona[i].id==id)
        {
            return i;
        }
    }
    return -1;
}

void ordenarAlfabeticamete(EPersona personas [],int limite)
{
    EPersona auxiliar;
    int i;
    int j;
    for(i=0; i<limite-1; i++)
    {
        for(j=i+1; j<limite; j++)
        {

            //if(personas[i].idUsuario>personas[j].idUsuario)//asi para ordenar numeros
            if(strcmp(personas[i].nombre,personas[j].nombre)>0)//asi para orenar letras
            {

                auxiliar=personas[i];
                personas[i]=personas[j];
                personas[j]=auxiliar;
            }

        }
    }

}

void ordenarNumericamente(EPersona personas [],int limite)
{
    EPersona auxiliar;
    int i;
    int j;
    for(i=0; i<limite-1; i++)
    {
        for(j=i+1; j<limite; j++)
        {

            if(personas[i].edad>personas[j].edad)//asi para ordenar numeros. para ordenamiento desenderte cambia <>
            //if(strcmp(personas[i].nombre,personas[j].nombre)>0)//asi para orenar letras
            {

                auxiliar=personas[i];
                personas[i]=personas[j];
                personas[j]=auxiliar;
            }

        }
    }


}

void LimpiarPantalla(void)
{
    system("cls");
}


int idIncremental(EPersona personas[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && personas != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(personas[i].estado == 1)///si el anterior esta ocupado
            {
                    if(personas[i].id>retorno)///y esa id sea mayor al retorno
                    {
                         retorno=personas[i].id;///devuelve esa id
                    }

            }
        }
    }

    return retorno+1;///y retorna el lugar siguiente
}




void modificacion (EPersona personas[], int limite)
{
    char auxId[50];
    int auxiliarId;
    int busqueda;
    char auxN[50];
    char auxD[50];
    char auxE[50];
    int dni;
    int edad;

    mostrarListado(personas,limite);

    getStringNumeros("\nIngrese id a modificar: ",auxId);
    auxiliarId=atoi(auxId);

    busqueda=buscarPorId(personas,auxiliarId,limite);

     if(busqueda==-1)
    {
        printf("ERROR! ID incorrecto\n");

    }
    else
    {
        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(auxN);
        while(esSoloLetras(auxN)==0)
        {
            printf("ERROR! Ingrese un nombre: ");
            fflush(stdin);
            gets(auxN);
        }

        printf("Ingrese la edad: ");
        fflush(stdin);
        gets(auxE);
        while(esNumero(auxE)==0)
        {
            printf("ERROR! Ingrese una edad: ");
            fflush(stdin);
            gets(auxE);
        }

        edad=atoi(auxE);



        printf("Ingrese el dni: ");
        fflush(stdin);
        gets(auxD);
        while(esNumero(auxD)==0)
        {
            printf("ERROR! Ingrese un dni: ");
            fflush(stdin);
            gets(auxD);
        }
        dni=atoi(auxD);



        strcpy(personas[busqueda].nombre, auxN);
        personas[busqueda].edad=edad;
        personas[busqueda].dni=dni;
    }


}


void listaDeBorrados(EPersona personas[],int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        if(personas[i].estado==3)
        {
            mostrarUno(personas[i]);
        }
    }
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



//void mostrarUnoaMuchos(EPersona persona [])



/**void modificar(EPersona personas[],int limite)
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

    mostrarListado(personas, limite);

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
    busqueda=buscarPorId(personas,auxiliarbusqueda,limite);

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
                    strcpy(personas[busqueda].nombre,auxiliar);
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

