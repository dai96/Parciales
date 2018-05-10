#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;
    int id;

}EPersona;

/**typedef struct
{
    int id;
    int idSeries;
      int idSerie;
    char nombre[50];
    char genero[20];
    int cantidadTemporadas;
int estado;

}eSerie;*/


int obtenerEspacioLibre(EPersona personas[]);


int buscarPorDni(EPersona personas[], int dni, int tamanio);

#endif // FUNCIONES_H_INCLUDED

int inicializar(EPersona personas[],int limite);
int mostrarListado(EPersona personas[],int limite);
int mostrarUno(EPersona personas);

int alta(EPersona personas[],int limite);
void cargarHardCode(EPersona personas[]);

int baja(EPersona personas[],int limite);

void LimpiarPantalla();

void ordenarAlfabeticamete(EPersona personas [],int limite);
void ordenarNumericamente(EPersona personas [],int limite);

int idIncremental(EPersona personas[],int limite);

void modificacion (EPersona personas[], int limite);

int buscarPorId(EPersona persona[],int id,int limite);
void listaDeBorrados(EPersona personas[],int limite);

