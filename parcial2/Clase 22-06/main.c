#include <stdio.h>
#include <stdlib.h>

    t=new_tramite();

    setId(t,5);
    setDni(t,"33333");

    mostrarTramite(t);




int main()
{
    int opcion;
    int i;
    int largo;
    char dni[20];

    int ultimoIdTramiteUrgente=0;
    int ultimoIdTramiteRegular=0;

    arraylist* listaTramitesUrgentes;
    arraylist* listaTramitesRegulares;

    arraylist* atendidosUrg;
    arraylist* atendidosReg;

    eTramite* t;
    eTramite* tramiteActual;


   listatramitesUrgente=al_newArrayList();
   listatramitesRegulares=al_newArrayList();


   do
   {
    printf("1-2-3-4-5")
    scanf("%d",&opcion);
    switch(opcion)
    {
    case 1:

        ultimoIdtramiteUrgente++;

        printf("ingrese su dni: ");
        fflush(stdin);
        gets(dni);

        cargarTramite(listatramitesUrgente,ultimoIdtramiteUrgente,dni);




        listatramitesUrgente->add(listatramitesUrgente, tramiteActual);
        break;

    case 2;
        tramiteActual =new_tramite();
        ultimoIdtramiteRegular++;
        setId(tramiteActual, ultimoIdtramiteRegular);
        printf("ingrese su dni: ");
        fflush(stdin);
        gets(dni);
        setDni(tramiteActual,dni);

        listatramitesUrgente->add(listatramitesUrgente, tramiteActual);



        break;

    case 3:
        if (listatramitesUrgente->isempy(listadetramitesutentes))
        {

           atenderTramite(listatramitesUrgente,atendidosUrg);
            printf("cliente a ser atendido (Urgente): ");

        }

         else
         {
             if (!listatramitesRegulares->isEmpty(listatramitesRegulares))
             {
                tramiteActual=(eTramite*) listatramitesRegulares->pop(listatramitesRegulares,0)
                printf("cliente a ser atendido (Regular): ");
                atendidosUrg->add(atendidosUrg,tramiteActual);
                mostrarTramite(tramiteActual);
             }
             else
             {
                 no hay clientes x atender lol printf
             }
         }

        break;


    case 4:

        if(!listatramitesUrgente->isEmpty(listadetramitesUrgentes))
        {

        largo=listatramitesUrgente->len(listatramitesUrgente);

        printf("\n Tramites Urgentes\n");
        //mostrarlistadetramites(listadetrmitesurgentes);
        for (int i=0;i<largo,i++);
        {
            tramiteActual=(eTramite*) listatramitesUrgente->get(listatramitesUrgente, i);
            mostrarTramite(tramiteActual);
        }
        }


        largo=listatramitesRegulares->len(listatramitesRegulares);

        printf("\n Tramites Urgentes\n");
        for (int i=0;i<largo,i++);
        {
            tramiteActual=(eTramite*) listatramitesUrgente->get(listatramitesUrgente, i);
           largo=listatramitesRegulares->len(listatramitesRegulares);
 mostrarTramite(tramiteActual);
        }
        break;


        case 5:LOMISMOPEROVAATENDIOSNOLISTADO

        if(!listatramitesUrgente->isEmpty(listadetramitesUrgentes))
        {

        largo=listatramitesUrgente->len(listatramitesUrgente);

        atendidosUrg->sort(atendidosUrg,compararPorDni,0//para ordenarlo del mas grande al mas chiquito);

        printf("\n Tramites Urgentes\n");
        for (int i=0;i<largo,i++);
        {
            tramiteActual=(eTramite*) listatramitesUrgente->get(listatramitesUrgente, i);
            mostrarTramite(tramiteActual);
        }
        }


        largo=listatramitesRegulares->len(listatramitesRegulares);
        atendidosReg->sort(atendidosUrg,compararPorDni,0)
        printf("\n Tramites Urgentes\n");
         //MostarListaDeTramites(listadetramitesRegulares);

        for (int i=0;i<largo,i++);
        {
            tramiteActual=(eTramite*) listatramitesUrgente->get(listatramitesUrgente, i);
           largo=listatramitesRegulares->len(listatramitesRegulares);
 mostrarTramite(tramiteActual);
        }
        break;

    }











   }


}
