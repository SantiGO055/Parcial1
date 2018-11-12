#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "negocio.h"
#include "input.h"

int initClie(eCliente* clie,int CLIENTE){
    int i;
    int retorno=-1;
    for(i=0;i<CLIENTE;i++){
        clie[i].isEmpty=1;
        retorno=0;
    }
    return retorno;
}
int initJuego(eJuego* juego,int JUEGOS){
    int i;
    int retorno=-1;
    for(i=0;i<JUEGOS;i++){
        juego[i].isEmpty=1;
        retorno=0;
    }
    return retorno;
}
int initAlquiler(eAlquiler* alquiler,int ALQUILER){
    int i;
    int retorno=-1;
    for(i=0;i<ALQUILER;i++){
        alquiler[i].isEmpty=1;
        retorno=0;
    }
    return retorno;
}

int getFreeSpaceCliente(eCliente* clie, int CLIENTE){
    int i,retorno=-1;
    for(i=0;i<CLIENTE;i++){
        if(clie[i].isEmpty==1){
            retorno=i;
            break;
        }
    }
    return retorno;
}

int getFreeSpaceJuego(eJuego *juego, int JUEGOS){
    int i,retorno=-1;
    for(i=0;i<JUEGOS;i++){
        if(juego[i].isEmpty==1){
            retorno=i;
            break;
        }
    }
    return retorno;
}
int getFreeSpaceAlquiler(eAlquiler* alquiler, int ALQUILER){
    int i,retorno=-1;
    for(i=0;i<ALQUILER;i++){
        if(alquiler[i].isEmpty==1){
            retorno=i;
            break;
        }
    }
    return retorno;
}
int altaCliente(eCliente *clie,int CLIENTE,char* apellido,
                char* nombre, char* dom,char* tel,int idClie){
    int i,retorno=-1;
    i=getFreeSpaceCliente(clie,CLIENTE);
        if(i!=-1){

            clie[i].isEmpty=0;
            strcpy(clie[i].apellido,apellido);
            strcpy(clie[i].nombre,nombre);
            strcpy(clie[i].dom,dom);
            strcpy(clie[i].tel,tel);
            clie[i].idClie=idClie;
            retorno=0;

        }
    return retorno;
}
int altaJuego(eJuego *juego,int JUEGOS,char* descr,
                float importe,int idJuego){
    int i,retorno=-1;
    i=getFreeSpaceJuego(juego,JUEGOS);
        if(i!=-1){

            juego[i].isEmpty=0;
            strcpy(juego[i].descr,descr);
            juego[i].idJue=idJuego;
            juego[i].importe=importe;
            retorno=0;

        }
    return retorno;
}
int altaAlquiler(eAlquiler* alquiler,int ALQUILER, int idClieAlq,
                 int idJuegoAlq,int dia, int mes, int anio,int idAlquiler){
    int i,retorno=-1;
    i=getFreeSpaceAlquiler(alquiler,ALQUILER);
        if(i!=-1){

            alquiler[i].isEmpty=0;
            alquiler[i].idClie=idClieAlq;
            alquiler[i].idJue=idJuegoAlq;
            alquiler[i].idAlq=idAlquiler;
            alquiler[i].fecha.dia=dia;
            alquiler[i].fecha.mes=mes;
            alquiler[i].fecha.anio=anio;
            retorno=0;

        }
    return retorno;
}

int printCliente(eCliente* clie,int CLIENTE){
    int i,retorno=-1;
    for(i=0;i<CLIENTE;i++){
        if(clie[i].isEmpty==0){
            printf("___________________________________________________________________\n");
            printf("\tCliente:\nApellido: %s\nNombre: %s\nID Cliente: %d\n",
                   clie[i].apellido,clie[i].nombre,clie[i].idClie);
            printf("___________________________________________________________________\n");
            retorno=i;
        }

    }
    return retorno;
}
int printJuego(eJuego* juego,int JUEGOS){
    int i,retorno=-1;
    for(i=0;i<JUEGOS;i++){
        if(juego[i].isEmpty==0){
            printf("___________________________________________________________________\n");
            printf("\tJuegos:\nDescripcion: %s\nImporte: %.02f\nID Juego: %d\n",juego[i].descr,juego[i].importe,juego[i].idJue);
            printf("___________________________________________________________________\n");
            retorno=i;
        }

    }
    return retorno;
}
int findClieById(eCliente* clie, int CLIENTE,int idClie){
    int i;
    int retorno=-1;
    for(i=0;i<CLIENTE;i++){
        if(clie[i].isEmpty==0){ //si esta ocupado
            if(clie[i].idClie==idClie){ //si lo encontro
                retorno=i;
                break;
            }
        }
    retorno=-1;
    }
    return retorno;
}
int findJuegoById(eJuego* juego, int JUEGOS,int idJuego){
    int i;
    int retorno=-1;
    for(i=0;i<JUEGOS;i++){
        if(juego[i].isEmpty==0){ //si esta ocupado
            if(juego[i].idJue==idJuego){ //si lo encontro
                retorno=i;
                break;
            }
        }
    retorno=-1;
    }
    return retorno;
}

int sortCliente(eCliente* clie,int CLIENTE){
    int j,p;
    eCliente clieAux;
                for (p = 1; p < CLIENTE; p++){
                        clieAux = clie[p];
                        j = p - 1;
                    while ((j >= 0) && (stricmp(clie[p].apellido,clie[j].apellido))<0){
                        clie[j + 1] = clie[j];
                        j--;
                    }
                        clie[j + 1] = clieAux;
                }

    return 0;
}
int sortJuego(eJuego* juego,int JUEGOS,float importe, char* nombre){
    eJuego jueAux;
    int i, j;
        for(i=0;i<JUEGOS-1;i++){
            for(j=i;j<JUEGOS;j++){
                if(juego[i].isEmpty==0&&juego[j].isEmpty==0){
                    if(juego[i].importe<juego[j].importe){
                        jueAux=juego[i];
                        juego[i]=juego[j];
                        juego[j]=jueAux;
                    }
                    if(juego[i].importe==juego[j].importe){
                        if(strcmp(juego[i].descr,juego[j].descr)>0){
                            jueAux=juego[i];
                            juego[i]=juego[j];
                            juego[j]=jueAux;
                        }
                    }
                }
            }
        }
    return 0;
}

int firstClienteJuego(int flag){
    int retorno=-1;
    if(flag!=1){
        system("cls");
        printf("___________________________________________________________________\n");
        printf("ERROR! Debera realizar la carga de un cliente o juego\n");
        printf("___________________________________________________________________\n");
        retorno=0;
    }
    return retorno;
}



void modifyClie(eCliente *clie,int CANT,char* apellido,
                    char* nombre, char* dom,char* tel,int opcionModifClie){
            int i;
            for(i=0;i<CANT;i++){
                if(opcionModifClie==1)
                strcpy(clie[i].apellido,apellido);
                if(opcionModifClie==2)
                strcpy(clie[i].nombre,nombre);
                if(opcionModifClie==3)
                strcpy(clie[i].dom,dom);
                if(opcionModifClie==4)
                strcpy(clie[i].tel,tel);
            }
}

void modifyJuego(eJuego *juego,int JUEGOS,char* descr,
                  float importe,int opcionModifJuego){
        int i;
        for(i=0;i<JUEGOS;i++){
            if(opcionModifJuego==1)
            strcpy(juego[i].descr,descr);
            if(opcionModifJuego==2)
            juego[i].importe=importe;
            }
}

int removeCliente(eCliente* clie,int CLIENTE,int idRemClie){
    int iAux,retorno=-1;
    char rta;
        iAux=findClieById(clie,CLIENTE,idRemClie);
        if(iAux!=-1){//lo encontro
            do{
            printf("Eliminar registro? S/N: ");
            fflush(stdin);
            rta=toupper(getch());
            }while(rta!='S'&&rta!='N');
            if(rta=='S'){
                clie[iAux].isEmpty=1;
                system("cls");
                printf("Accion: Registro eliminado correctamente\n");
                retorno=0;
                }
            if(rta=='N'){
                system("cls");
                printf("Accion: No se elimino el registro\n");
                retorno=-1;
            }
        }
        else{
            system("cls");
            printf("Accion: No se encuentra el codigo de cliente\n");
        }

    return retorno;
}
int removeJuego(eJuego* juego,int JUEGOS,int idRemJue){
    int iAux,retorno=-1;
    char rta;
        iAux=findJuegoById(juego,JUEGOS,idRemJue);
        if(iAux!=-1){//lo encontro
            do{
            printf("Eliminar registro? S/N: ");
            fflush(stdin);
            rta=toupper(getch());
            }while(rta!='S'&&rta!='N');
            if(rta=='S'){
                juego[iAux].isEmpty=1;
                system("cls");
                printf("Accion: Registro eliminado correctamente\n");
                retorno=0;
                }
            if(rta=='N'){
                system("cls");
                printf("Accion: No se elimino el registro\n");
                retorno=-1;
            }
        }
        else{
            system("cls");
            printf("Accion: No se encuentra el codigo de cliente\n");
        }

    return retorno;
}

float totalImporte(eAlquiler* alquiler,eJuego* juego,int ALQUILER,int JUEGOS){
    int i,retorno=-1,j;
    float totalImporte=0;

    for(i=0;i<ALQUILER;i++){
        if(alquiler[i].isEmpty==0){
            for(j=0;j<JUEGOS;j++){
                if(juego[i].isEmpty==0&&alquiler[i].idJue==juego[j].idJue){
                    totalImporte+=juego[j].importe;
                    retorno=totalImporte;
                }
            }
        }
    }
    return retorno;
}

float averageImporte(eAlquiler* alquiler,eJuego* juego,int ALQUILER,int JUEGOS){
    int i,retorno=-1,j,cantidad=0;
    float totalImporte=0;

    for(i=0;i<ALQUILER;i++){
        if(alquiler[i].isEmpty==0){
            for(j=0;j<JUEGOS;j++){
                if(juego[i].isEmpty==0&&alquiler[i].idJue==juego[j].idJue){
                    totalImporte+=juego[j].importe;
                    cantidad++;
                    retorno=totalImporte/cantidad;
                }
            }
        }
    }
    return retorno;
}

int cantidadJuegosNoSuperan(eAlquiler* alquiler,eJuego* juego,int JUEGOS,int ALQUILER){
    int i,retorno=-1,contAux=0;
    float averageAux=averageImporte(alquiler,juego,ALQUILER,JUEGOS);
    for(i=0;i<JUEGOS;i++){
        if(juego[i].isEmpty==0){
            if(juego[i].importe<=averageAux){
                contAux++;
                retorno=contAux;
            }
        }
    }

    return retorno;
}

int printAlqJuegoDeterminado(int idCliente,eAlquiler* alquiler,eJuego* juego,eCliente* clie,
                         int JUEGOS,int ALQUILER,int CLIENTE){
    int i,retorno=-1,k;
    for(i=0;i<CLIENTE;i++){
        if(alquiler[i].isEmpty==0){
            for(k=0;k<ALQUILER;k++){
                if(alquiler[k].isEmpty==0&&alquiler[k].idClie==idCliente
                   &&juego[i].idJue == alquiler[k].idJue){
                    printf("___________________________________________________________________\n");
                    printf("\tCliente:\nID Juego: %d\nDescripcion: %s\nImporte: %.02f\n",
                           juego[i].idJue,juego[i].descr,juego[i].importe);
                    printf("___________________________________________________________________\n");
                    retorno=i;
                }
            }
        }

    }
    return retorno;
}

int printAlqClienteDeterminado(int idJuego,eAlquiler* alquiler,eJuego* juego,eCliente* clie,
                         int JUEGOS,int ALQUILER,int CLIENTE){
    int i,retorno=-1,k;
    for(i=0;i<CLIENTE;i++){
        if(clie[i].isEmpty==0){
            for(k=0;k<ALQUILER;k++){
                if(alquiler[k].isEmpty==0&&alquiler[k].idJue==idJuego
                   &&clie[i].idClie == alquiler[k].idClie){
                    printf("___________________________________________________________________\n");
                    printf("ID Cliente: %d\nApellido: %s\nNombre: %s\nDomicilio: %s\nTel: %s",
                           clie[i].idClie,clie[i].apellido,clie[i].nombre,clie[i].dom,clie[i].tel);
                    printf("___________________________________________________________________\n");
                    retorno=i;
                }
            }
        }

    }
    return retorno;
}
void initAlquilerJuegos(Alquileres* alquilerJuegos,int ALQUILER){
    int h;
    for(h=0;h<ALQUILER;h++){
        alquilerJuegos[h].cantidadDeAlquileres=0;
        alquilerJuegos[h].idJue=0;
        alquilerJuegos[h].isEmpty=1;
    }
}

void cantidadVecesAlquiloJuego(Alquileres* alquilerJuegos,eAlquiler* alquiler,eJuego* juego,int JUEGOS,int ALQUILER){
    int i,h;
    initAlquilerJuegos(alquilerJuegos,ALQUILER);
    for(i=0;i<ALQUILER;i++){
        for(h=0;h<ALQUILER;h++){
            if(alquiler[i].isEmpty==0&&(juego[i].idJue==alquiler[h].idJue)){
                alquilerJuegos[i].isEmpty=0;
                alquilerJuegos[i].idJue=alquiler[h].idJue;
                alquilerJuegos[i].cantidadDeAlquileres++;
            }
        }
    }
}

int juegosMenosAlquilados(Alquileres* alquilerJuegos,eAlquiler* alquiler,eJuego* juego,int JUEGOS,int ALQUILER){
    int i,retorno=-1,k,min=ALQUILER;
    cantidadVecesAlquiloJuego(alquilerJuegos,alquiler,juego,JUEGOS,ALQUILER);
    for(k=0;k<ALQUILER;k++){
            if((alquilerJuegos[k].cantidadDeAlquileres<min&&alquiler[k].isEmpty==0)){
                min=alquilerJuegos[k].cantidadDeAlquileres;
                //flag=1;
            }
        }
        for(i=0;i<4;i++){ //cambiar el 4 por ALQUILER
            for(k=0;k<4;k++){ //cambiar el 4 por ALQUILER
                if(alquilerJuegos[i].isEmpty==0&&(alquilerJuegos[i].idJue==alquiler[k].idJue)&&
                    (alquilerJuegos[i].cantidadDeAlquileres<=min)&&alquiler[k].isEmpty==0){

                    printf("___________________________________________________________________\n");
                    printf("\nEl juego menos alquilado es:\n\tJuegos:\nDescripcion: %s\nImporte: %.02f\nID Juego: %d\n",
                           juego[i].descr,juego[i].importe,juego[i].idJue);
                    printf("___________________________________________________________________\n");
                    retorno=i;

                }
            }
        }


    return retorno;
}

int sortImporte(eJuego* juego,int JUEGOS){
    eJuego juegoAux;
    int i, j;
        for(i=0;i<JUEGOS-1;i++){
            for(j=i;j<JUEGOS;j++){
                if(juego[i].importe<juego[j].importe&&
                   juego[i].isEmpty==0&&juego[j].isEmpty==0){
                        juegoAux=juego[i];
                        juego[i]=juego[j];
                        juego[j]=juegoAux;
                }
            }

        }
    return 0;
}

int listarJuegosPorFecha(int dia,int mes,int anio,eAlquiler* alquiler, eJuego* juego,int JUEGOS,int ALQUILER){
    int i,k,retorno=-1;
     for (i=0; i<JUEGOS; i++ )
    {
        if(juego[i].isEmpty==0)
        for(k=0; k<ALQUILER; k++)
        {
            if(alquiler[k].isEmpty==0 && alquiler[k].idJue == juego[i].idJue&&
               alquiler[k].fecha.dia == dia&&alquiler[k].fecha.mes == mes&&
               alquiler[k].fecha.anio== anio){
             printf("___________________________________________________________________\n");
                printf("\nJuegos alquilados en la fecha: %d/%d/%d\n\nDescripcion: %s\nImporte: %.02f\nID Juego: %d\n",
                       dia,mes,anio,juego[i].descr,juego[i].importe,juego[i].idJue);
                printf("___________________________________________________________________\n");
                retorno=1;
            }
            else retorno=-1;
        }
    }
    return retorno;
}

int listarClientesPorFecha(int dia,int mes,int anio,eAlquiler* alquiler,eCliente* clie,int CLIENTE,int ALQUILER){
    int i,k,retorno=-1;
     for (i=0; i<CLIENTE; i++ )
    {
        if(clie[i].isEmpty==0)
        for(k=0; k<ALQUILER; k++)
        {
            if(alquiler[k].isEmpty==0 && alquiler[k].idClie == clie[i].idClie&&
               alquiler[k].fecha.dia == dia&&alquiler[k].fecha.mes == mes&&
               alquiler[k].fecha.anio== anio){
             printf("___________________________________________________________________\n");
                printf("\nClientes que alquilaron en la fecha: %d/%d/%d\n\nID: %d\nApellido: %s\nNombre: %s\nDomicilio: %s\nTel: %s\n",
                       dia,mes,anio,clie[i].idClie,clie[i].apellido,clie[i].nombre,clie[i].dom,clie[i].tel);
                printf("___________________________________________________________________\n");
                retorno=1;
            }
            else retorno=-1;

        }
    }
    return retorno;
}
void initAlquilerClientes(Alquileres* alquilerClientes,int ALQUILER){
    int h;
    for(h=0;h<ALQUILER;h++){
        alquilerClientes[h].cantidadDeAlquileres=0;
        alquilerClientes[h].idJue=0;
        alquilerClientes[h].isEmpty=1;
    }
}

void cantidadVecesAlquiloCliente(Alquileres* alquilerClientes,eAlquiler* alquiler,eCliente* clie,int CLIENTE,int ALQUILER){
    int i,h;
    initAlquilerClientes(alquilerClientes,ALQUILER);
    for(i=0;i<4;i++){
        for(h=0;h<4;h++){
            if(alquiler[i].isEmpty==0&&clie[i].isEmpty==0&&(clie[i].idClie==alquiler[h].idClie)){
                alquilerClientes[i].isEmpty=0;
                alquilerClientes[i].idJue=alquiler[h].idJue;
                alquilerClientes[i].cantidadDeAlquileres++;
            }
        }
    }
}

int clientesQueMasAlquilaron(Alquileres* alquilerClientes,eAlquiler* alquiler,eCliente* clie,int CLIENTE,int ALQUILER){
    int i,retorno=-1,k,max=0;
    cantidadVecesAlquiloCliente(alquilerClientes,alquiler,clie,CLIENTE,ALQUILER);
    for(k=0;k<ALQUILER;k++){
            if((alquilerClientes[k].cantidadDeAlquileres>max&&alquiler[k].isEmpty==0)&&
               (alquilerClientes[k].isEmpty==0)){
                max=alquilerClientes[k].cantidadDeAlquileres;
                //flag=1;
            }
        }
        for(i=0;i<4;i++){ //cambiar el 4 por ALQUILER
            for(k=0;k<4;k++){ //cambiar el 4 por ALQUILER
                if(alquilerClientes[i].isEmpty==0&&(alquilerClientes[i].idJue==alquiler[k].idJue)&&
                    (alquilerClientes[i].cantidadDeAlquileres>=max)&&alquiler[k].isEmpty==0){
                    alquilerClientes[i].isEmpty=1;
                    printf("___________________________________________________________________\n");
                    printf("Los clientes que mas alquilaron fueron\nID Cliente: %d\nApellido: %s\nNombre: %s\nDomicilio: %s\nTel: %s\n",
                           clie[i].idClie,clie[i].apellido,clie[i].nombre,clie[i].dom,clie[i].tel);
                    printf("___________________________________________________________________\n");
                    retorno=i;

                }
            }
        }


    return retorno;
}
