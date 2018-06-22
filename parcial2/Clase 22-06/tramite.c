



eTramite* new_tramite
{
    eTramite* aux;
    aux=(eTramite)*malloc(sizeof(eTramite));
    return aux;
}


int serId (eTRamte* this, int id)
{
    int seteo=-1;
    if (this=!NULL);
    {
        this->idTramite=id;
        seteo=0;
    }
    return seteo;
}

int getId (tramite* this)
{
    int id=-1;
    if (this!=NULL)
    {
        id=this->idTramite;
    }
    return id;
}

int setDni(eTramite* this, char* dni)
{
    int seteo=-1;
    if(this!=NULL && sni!=NULL)
    {
        strcpy (this->dni, dni);
        seteo=0;
    }
    return seteo;
}

char* getDni (eTramite* this)
{
    char* dni=NULL;

    id (this!=NULL)
    {
        dni= this->dni;//Guardo la direccion de memoria
    }
    return dni;
}

int mostrarTramite (eTramite* this)
{
    int mostro=-1;
    if(this!=NULL)
    {
        printf("%d--%s\n",getId(this), getDni(this));
        mostro=1;
    }
    return mostro;

}

int compararPorDni(void* tramiteA, void* tramiteB)
{
    eTramite* tramite1;
    eTramite* tramite2;

    tramite1=(eTramite*) tramiteA;
    tramite2=(eTramite*) tramiteB;

    return strcmp(tramite1->dni, tramite2->dni);


}

int mostrarListaDeTramites(arraylist* listado)
{
    if listo=-1;
    int i;
    if (listado!=NULL)
    {
        len=listado->len(listado);
        for (i=0;i<len;i++)
        {
        tramiteActual=(eTramite*) listado->get(listado,i);
        mostrarTramite(tramiteActual);
        }
        listo=0;
    }
    return listo;
}


int cargarTramite(arrayList* listado, int id, char* din)
{

        int cargo=-1;

        eTramite* tramiteActual

        if listado=!null y id>0 y dni!= null
        {


        tramiteactual  =new_tramite();

        setId(tramiteActual, id);

        setDni(tramiteActual,dni);

        listado->add(listado, tramiteActual);
        cargo=0;
}

        return cargo;



}


int atenderTramite(arraylist* listapendientes, arraylist* listaatendidos)

{
    int atendio=-1;
    eTramite* tramiteActual;
    if (listapendientes!=NULL && listaatendidos!=NULL)
    {
            tramiteActual=(eTramite*) listapendientes->pop(listapendientes,0)
            atendidosUrg->add(atendidosUrg,tramiteActual);
            mostrarTramite(tramiteActual);
    }
}
