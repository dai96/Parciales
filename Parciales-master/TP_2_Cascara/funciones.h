#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    int idProp;
    char nombre[50];
    //char apellido [50];
    char direccion [50];
    char tarjeta[50];
    int estado;

}ePropietarios;

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


int obtenerEspacioLibre(ePropietarios propietarios[]);


int buscarPorDni(ePropietarios propietarios[], int dni, int tamanio);

// FUNCIONES_H_INCLUDED

int inicializar(ePropietarios propietarios[],int limite);
int mostrarListado(ePropietarios propietarios[],int limite);
int mostrarUno(ePropietarios propietarios);

int alta(ePropietarios propietarios[],int limite);
void cargarHardCode(ePropietarios propietarios[]);

int baja(ePropietarios propietarios[],int limite);

void LimpiarPantalla();

void ordenarAlfabeticamete(ePropietarios propietarios [],int limite);
void ordenarNumericamente(ePropietarios propietarios [],int limite);

int idIncremental(ePropietarios propietarios[],int limite);

void modificacion (ePropietarios propietarios[], int limite);

int buscarPorId(ePropietarios persona[],int id,int limite);
void listaDeBorrados(ePropietarios propietarios[],int limite);

#endif
