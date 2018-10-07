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
            printf("\tJuegos:\nDescripcion: %s\nImporte: %.02f\nID Juego: %d",juego[i].descr,juego[i].importe,juego[i].idJue);
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

int sortCliente(eCliente* clie,int CLIENTE,char* apellido, char* nombre){
    eCliente clieAux;
    int i, j;
        for(i=0;i<CLIENTE-1;i++){
            for(j=i;j<CLIENTE;j++){
                if(clie[i].isEmpty==0&&clie[j].isEmpty==0){
                    if(strcmp(clie[i].apellido,clie[j].apellido)>0){
                        clieAux=clie[i];
                        clie[i]=clie[j];
                        clie[j]=clieAux;
                    }
                    if(strcmp(clie[i].apellido,clie[j].apellido)==0){
                        if(strcmp(clie[i].nombre,clie[j].nombre)>0){
                            clieAux=clie[i];
                            clie[i]=clie[j];
                            clie[j]=clieAux;
                        }
                    }
                }
            }
        }
    return 0;
}
int sortJuego(eJuego* juego,int JUEGOS,float importe, char* nombre){
    eJuego jueAux;
    int i, j;
       /* for(i=0;i<CLIENTE-1;i++){
                for(j=i;j<CLIENTE;j++){
                if(emp[i].isEmpty==0&&emp[j].isEmpty==0){
                    if(emp[i].sector>emp[j].sector){
                        empAux=emp[i];
                        emp[i]=emp[j];
                        emp[j]=empAux;
                    }
                }
            }
        }*/
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
        printf("ERROR! Debera realizar la carga de un cliente o empleado\n");
        printf("___________________________________________________________________\n");
        retorno=0;
    }
    return retorno;
}



void modifyClie(eCliente *clie,int CANT,char* apellido,
                    char* nombre, char* dom,char* tel,int idClie,int opcionModifClie){
            if(opcionModifClie==1)
            strcpy(clie[idClie].nombre,nombre);
            if(opcionModifClie==2)
            strcpy(clie[idClie].apellido,apellido);
            if(opcionModifClie==3)
            strcpy(clie[idClie].dom,dom);
            if(opcionModifClie==4)
            strcpy(clie[idClie].tel,tel);
}

void modifyJuego(eJuego *juego,int JUEGOS,char* descr,
                  float importe,int idJuego,int opcionModifJuego){
            if(opcionModifJuego==1)
            strcpy(juego[idJuego].descr,descr);
            if(opcionModifJuego==2)
            juego[idJuego].importe=importe;
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
