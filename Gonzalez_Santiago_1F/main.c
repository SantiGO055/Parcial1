#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"
#include "negocio.h"
#define CLIENTE 100
#define JUEGOS 20
#define CHAR 51
#define ALQUILER (CLIENTE*JUEGOS)
int main()
{
    int opcionMain,sector,flag=0,idClie=0,idJuego=0,findClienteAux,findJuegoAux,idAux,contEmp=0;
    int opcionAlta,opcionModif,validaNum,opcionModifClie,opcionModifJuego,idRemClie,opcionRem,idRemJue;
    int opcionList,idAlquiler,idClieAlq,idJuegoAlq,dia,mes,anio;
    eCliente clie[CLIENTE];
    eJuego juego[JUEGOS];
    eAlquiler alquiler[CLIENTE*JUEGOS];
    char nombre[CHAR], apellido[CHAR],dom[CHAR],tel[21];
    char descr[CHAR];

    float importe;

    do{
        utn_getEntero(&opcionMain,"\tMenu\n1- Alta\n2- Modificar\n3- Baja\n4- Listar\n\n5- Salir\n","Opcion incorrecta, reingrese numero",1,2,2);
        switch(opcionMain){
            case 1: //opcion principal
                utn_getEntero(&opcionAlta,"1- Clientes\n2- Juegos\n3- Alquileres","Opcion incorrecta, reingrese numero",1,3,2);
                switch(opcionAlta){
                case 1: //alta de clientes
                    system("cls");
                    if(flag==0){
                        if(initClie(clie,CLIENTE)==0){
                            initClie(clie,CLIENTE);
                            flag=1;
                        }
                    }
                    if(getFreeSpaceCliente(clie,CLIENTE)!=-1){
                        idClie++;
                    }
                    else{
                        printf("No hay espacio para agregar clientes!\n");
                        break;
                    }
                    utn_getStringAvanzado(apellido,"Ingrese apellido: ","ERROR! El domicilio debe ser solo letras\n",CHAR,2);
                    utn_getStringAvanzado(nombre,"Ingrese nombre: ","ERROR! El nombre debe ser solo letras\n",CHAR,2);
                    utn_getStringAvanzado(dom,"Ingrese domicilio: ","ERROR! El domicilio debe ser solo letras\n",CHAR,2);
                    utn_getStringAvanzado(tel,"Ingrese telefono: ","ERROR! El telefono debe ser solo letras\n",CHAR,2);
                    altaCliente(clie,CLIENTE,apellido, nombre,dom,tel,idClie);
                    system("cls");
                    printf("Accion: Cliente agregado correctamente\n");
                    break;
                case 2: //alta de juegos
                    system("cls");
                    if(flag==0){
                        if(initJuego(juego,JUEGOS)==0){
                            initJuego(juego,JUEGOS);
                            flag=1;
                        }
                    }
                    if(getFreeSpaceJuego(juego,JUEGOS)!=-1){
                        idJuego++;
                    }
                    else{
                        printf("No hay espacio para agregar juegos!\n");
                        break;
                    }
                    utn_getStringAvanzado(descr,"Ingrese descripcion del juego: ","ERROR! La descripcion debe ser solo letras\n",CHAR,2);
                    utn_getFlotante(&importe,"Ingrese importe del juego: ","Error ingrese un importe positivo",0,30000,2);
                    altaJuego(juego,JUEGOS,descr,importe,idJuego);
                    system("cls");
                    printf("Accion: Juego agregado correctamente\n");
                    break;
                }
                case 3:
                    system("cls");
                    if(flag==0){
                        if(initAlquiler(alquiler,ALQUILER)==0){
                            initJuego(alquiler,ALQUILER);
                            flag=1;
                        }
                    }
                    if(getFreeSpaceAlquiler(alquiler,ALQUILER)!=-1){
                        idAlquiler++;
                    }
                    else{
                        printf("No hay espacio para agregar alquiler!\n");
                        break;
                    }
                    printCliente(clie,CLIENTE);
                    printJuego(juego,JUEGOS);
                    utn_getEntero(&idClieAlq,"Ingrese el cliente que va a alquilar","Opcion incorrecta, reingrese numero",1,CLIENTE,2);
                    utn_getEntero(&idJuegoAlq,"Ingrese el juego que desea alquilar","Opcion incorrecta, reingrese numero",1,JUEGOS,2);
                    utn_getEntero(&dia,"Ingrese el dia actual (solo numeros)","Opcion incorrecta, solo numeros",1,31,2);
                    utn_getEntero(&mes,"Ingrese el mes actual (solo numeros)","Opcion incorrecta, solo numeros",1,12,2);
                    utn_getEntero(&anio,"Ingrese el anio actual (solo numeros)","Opcion incorrecta, solo numeros",2010,2019,2);
                    altaAlquiler(alquiler,ALQUILER,idClieAlq,idJuegoAlq,dia,mes,anio,idAlquiler);
                    system("cls");
                    printf("Accion: Juego agregado correctamente\n");



                    break;
            case 2: //modificacion
                system("cls");
                utn_getEntero(&opcionModif,"¿Que desea modificar?\n1- Clientes\n2- Juegos\n","Opcion incorrecta, reingrese numero",1,2,2);
                switch(opcionModif){
                    case 1:
                    if(firstClienteJuego(flag)!=0){ //si no es la primera vez
                        printCliente(clie,CLIENTE);
                        utn_getEntero(&idClie,"Ingrese el codigo de cliente a modificar: ","ERROR! Ingrese numero entre 1 y 100\n",1,CLIENTE,2);
                        findClienteAux=findClieById(clie,CLIENTE,idClie);
                        if(findClienteAux!=-1){ //si lo encontro
                            utn_getEntero(&opcionModifClie,"Ingrese valor que desea modificar\n1- Apellido\n2- Nombre\n3- Domicilio\n4-Telefono\n",
                                          "ERROR! Ingrese numero entre 1 y 4\n",1,4,2);
                            switch(opcionModifClie){
                                case 1:
                                    utn_getStringAvanzado(nombre,"Ingrese nombre: ",
                                                          "ERROR! El nombre debe ser solo letras\n",CHAR,2);
                                    modifyClie(clie,CLIENTE,apellido,nombre,dom,tel,idClie,opcionModifClie);
                                break;
                                case 2:
                                    utn_getStringAvanzado(apellido,"Ingrese apellido: ",
                                                          "ERROR! El apellido debe ser solo letras\n",CHAR,2);
                                    modifyClie(clie,CLIENTE,apellido,nombre,dom,tel,idClie,opcionModifClie);
                                break;
                                case 3:
                                    utn_getStringAvanzado(dom,"Ingrese domicilio: ",
                                                          "ERROR! El domicilio debe ser solo letras\n",CHAR,2);
                                    modifyClie(clie,CLIENTE,apellido,nombre,dom,tel,idClie,opcionModifClie);
                                break;
                                case 4:
                                    utn_getStringAvanzado(dom,"Ingrese telefono: ",
                                                          "ERROR! El telefono debe ser solo letras\n",CHAR,2);
                                    modifyClie(clie,CLIENTE,apellido,nombre,dom,tel,idClie,opcionModifClie);
                                break;
                                system("cls");
                                printf("Accion: Cliente modificado correctamente\n");
                            }
                        }
                        else{
                            system("cls");
                            printf("No se encuentra el Codigo de Cliente\n");
                        }
                    }
                    break;
                    case 2:
                        if(firstClienteJuego(flag)!=0){ //si no es la primera vez
                        printJuego(juego,JUEGOS);
                        utn_getEntero(&idJuego,"Ingrese el codigo de juego a modificar: ","ERROR! Ingrese numero entre 1 y 20\n",1,JUEGOS,2);
                        findJuegoAux=findJuegoById(clie,JUEGOS,idJuego);
                        if(findJuegoAux!=-1){ //si lo encontro
                            utn_getEntero(&opcionModifJuego,"Ingrese valor que desea modificar\n1- Descripcion\n2- Importe\n",
                                          "ERROR! Ingrese numero entre 1 y 2\n",1,2,2);
                            switch(opcionModifJuego){
                                case 1:
                                    utn_getStringAvanzado(nombre,"Ingrese descripcion: ",
                                                          "ERROR! El nombre debe ser solo letras\n",CHAR,2);
                                    modifyJuego(juego,JUEGOS,descr,importe,idJuego,opcionModifJuego);
                                break;
                                case 2:
                                    utn_getStringAvanzado(apellido,"Ingrese apellido: ",
                                                          "ERROR! El apellido debe ser solo letras\n",CHAR,2);
                                    modifyJuego(juego,JUEGOS,descr,importe,idJuego,opcionModifJuego);
                                break;
                                system("cls");
                                printf("Accion: Juego modificado correctamente\n");
                            }
                        }
                        else{
                            system("cls");
                            printf("No se encuentra el codigo de Juego\n");
                        }
                    }
                }
                break;
            case 3:
                utn_getEntero(&opcionRem,"¿Que desea eliminar?\n1- Clientes\n2- Juegos\n","Opcion incorrecta, reingrese numero",1,2,2);
                switch(opcionRem){
                    case 1:
                        system("cls");
                        if(firstClienteJuego(flag)!=0){ //si no es la primera vez
                                printCliente(clie,CLIENTE);
                                utn_getEntero(&idRemClie,"Ingrese codigo de cliente a eliminar: ",
                                              "ERROR! Ingrese numero entre 1 y 100\n",1,CLIENTE,2);
                                removeCliente(clie,CLIENTE,idRemClie);
                        }
                    break;
                    case 2:
                        system("cls");
                        if(firstClienteJuego(flag)!=0){ //si no es la primera vez
                                printJuego(juego,JUEGOS);
                                utn_getEntero(&idRemJue,"Ingrese codigo de juego a eliminar: ",
                                              "ERROR! Ingrese numero entre 1 y 20\n",1,JUEGOS,2);
                                removeJuego(juego,JUEGOS,idRemJue);
                        }
                }
                break;
            case 4:
                utn_getEntero(&opcionList,"¿Que desea listar?\n1- Clientes\n2- Juegos\n","Opcion incorrecta, reingrese numero",1,2,2);
                switch(opcionList){
                 //si no es la primera vez
                    case 1:
                        system("cls");
                        if(firstClienteJuego(flag)!=0){
                            sortCliente(clie,CLIENTE,apellido,nombre);
                            printCliente(clie,CLIENTE);
                        }
                    break;
                    case 2:
                        system("cls");
                        if(firstClienteJuego(flag)!=0){
                            sortJuego(juego,JUEGOS,importe,descr);
                            printJuego(clie,CLIENTE);
                        }
                    break;
                        }


            break;
        }
    }while(opcionMain!=5);

    return 0;
}
