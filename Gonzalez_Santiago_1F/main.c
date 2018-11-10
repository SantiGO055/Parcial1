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
    int opcionMain,flagClie=0,flagJue=0,flagAlq=0,idClie=0,idJuego=0,findClienteAux,findJuegoAux;
    int opcionAlta,opcionModif,opcionModifClie,opcionModifJuego,idRemClie,opcionRem,idRemJue;
    int opcionList,idAlquiler,idClieAlq,idJuegoAlq,dia,mes,anio;
    int idAux;
    eCliente clie[CLIENTE];
    eJuego juego[JUEGOS];
    eAlquiler alquiler[CLIENTE*JUEGOS];
    char nombre[CHAR], apellido[CHAR],dom[CHAR],tel[21];
    char descr[CHAR];

    /*eCliente clie[]=
    {
        {1, "gonzalez", "santi","maza","11234", 1},
    };
    eJuego juego[]=
    {
        {1, "battlefield 1",12,1},
        {2, "mario bros",12,1},
    };*/


    float importe;

    do{
        utn_getEntero(&opcionMain,"\tMenu\n1- Alta\n2- Modificar\n3- Baja\n4- Listar\n\n5- Salir\n","Opcion incorrecta, reingrese numero",1,6,2);
        switch(opcionMain){
            case 1: //opcion principal
                system("cls");
                utn_getEntero(&opcionAlta,"1- Clientes\n2- Juegos\n3- Alquileres\n",
                              "Opcion incorrecta, reingrese numero",1,3,2);
                switch(opcionAlta){
                case 1: //alta de clientes
                    system("cls");
                    if(flagClie==0){
                        if(initClie(clie,CLIENTE)==0){
                            initClie(clie,CLIENTE);
                            flagClie=1;
                        }
                    }
                    if(getFreeSpaceCliente(clie,CLIENTE)!=-1){
                        idClie++;
                    }
                    else{
                        printf("No hay espacio para agregar clientes!\n");
                        break;
                    }
                    utn_getStringAvanzado(apellido,"Ingrese apellido: ","ERROR! El apellido debe ser solo letras\n",CHAR,2);
                    utn_getStringAvanzado(nombre,"Ingrese nombre: ","ERROR! El nombre debe ser solo letras\n",CHAR,2);
                    utn_getStringAvanzado(dom,"Ingrese domicilio: ","ERROR! El domicilio debe ser solo letras\n",CHAR,2);
                    utn_getTelefono(tel,"Ingrese telefono: ","ERROR! El telefono debe ser solo letras\n",CHAR,2);
                    altaCliente(clie,CLIENTE,apellido, nombre,dom,tel,idClie);
                    system("cls");
                    printf("Accion: Cliente agregado correctamente\n");
                    break;
                case 2: //alta de juegos
                    system("cls");
                    if(flagJue==0){
                        if(initJuego(juego,JUEGOS)==0){
                            initJuego(juego,JUEGOS);
                            flagJue=1;
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
                case 3:
                    system("cls");
                    if(flagAlq==0){
                        if(initAlquiler(alquiler,ALQUILER)==0){
                            initAlquiler(alquiler,ALQUILER);
                            flagAlq=1;
                        }
                    }
                    if(firstClienteJuego(flagAlq)!=0){
                    if(getFreeSpaceAlquiler(alquiler,ALQUILER)!=-1){
                        idAlquiler++;
                    }
                    else{
                        printf("No hay espacio para agregar alquiler!\n");
                        break;
                    }
                    if(firstClienteJuego(flagClie)!=0&&firstClienteJuego(flagJue)!=0){
                        printCliente(clie,CLIENTE);
                        printJuego(juego,JUEGOS);
                        utn_getEntero(&idClieAlq,"Ingrese el codigo de cliente que va a alquilar: ","Opcion incorrecta, reingrese numero\n",1,CLIENTE,2);
                        utn_getEntero(&idJuegoAlq,"Ingrese el juego que desea alquilar: ","Opcion incorrecta, reingrese numero\n",1,JUEGOS,2);
                        utn_getEntero(&dia,"Ingrese el dia actual (solo numeros): ","Opcion incorrecta, ingrese dia valido\n",1,31,2);
                        utn_getEntero(&mes,"Ingrese el mes actual (solo numeros): ","Opcion incorrecta, ingrese mes valido\n",1,12,2);
                        utn_getEntero(&anio,"Ingrese el a%co actual (desde 2010 a la actualidad): ","Opcion incorrecta, ingrese anio valido\n",2010,2019,2);
                        altaAlquiler(alquiler,ALQUILER,idClieAlq,idJuegoAlq,dia,mes,anio,idAlquiler);
                        system("cls");
                        printf("Accion: Alquiler agregado correctamente\n");
                        break;
                        }
                    }
                }
                break;
            case 2: //modificacion
                system("cls");
                 //si no se cargo cliente o juego
                utn_getEntero(&opcionModif,"Que desea modificar?\n1- Clientes\n2- Juegos\n","Opcion incorrecta, reingrese numero",1,2,2);
                switch(opcionModif){
                    case 1:
                        if(firstClienteJuego(flagClie)!=0){
                        printCliente(clie,CLIENTE);
                        utn_getEntero(&idClie,"Ingrese el codigo de cliente a modificar: ","ERROR! Ingrese numero entre 1 y 100\n",1,CLIENTE,2);
                        findClienteAux=findClieById(clie,CLIENTE,idClie);
                        if(findClienteAux!=-1){ //si lo encontro
                            system("cls");
                            utn_getEntero(&opcionModifClie,"Ingrese valor que desea modificar\n1- Apellido\n2- Nombre\n3- Domicilio\n4-Telefono\n",
                                          "ERROR! Ingrese numero entre 1 y 4\n",1,4,2);
                            switch(opcionModifClie){
                                case 1:
                                    utn_getStringAvanzado(apellido,"Ingrese apellido: ",
                                                          "ERROR! El nombre debe ser solo letras\n",CHAR,2);
                                    modifyClie(clie,CLIENTE,apellido,nombre,dom,tel,opcionModifClie);
                                break;
                                case 2:
                                    utn_getStringAvanzado(nombre,"Ingrese nombre: ",
                                                          "ERROR! El apellido debe ser solo letras\n",CHAR,2);
                                    modifyClie(clie,CLIENTE,apellido,nombre,dom,tel,opcionModifClie);
                                break;
                                case 3:
                                    utn_getStringAvanzado(dom,"Ingrese domicilio: ",
                                                          "ERROR! El domicilio debe ser solo letras\n",CHAR,2);
                                    modifyClie(clie,CLIENTE,apellido,nombre,dom,tel,opcionModifClie);
                                break;
                                case 4:
                                    utn_getTelefono(tel,"Ingrese telefono: ",
                                                    "ERROR! El telefono debe ser solo letras\n",CHAR,2);
                                    modifyClie(clie,CLIENTE,apellido,nombre,dom,tel,opcionModifClie);
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
                    case 2: //si no es la primera vez
                        if(firstClienteJuego(flagJue)!=0){
                        printJuego(juego,JUEGOS);
                        utn_getEntero(&idJuego,"Ingrese el codigo de juego a modificar: ","ERROR! Ingrese numero entre 1 y 20\n",1,JUEGOS,2);
                        findJuegoAux=findJuegoById(juego,JUEGOS,idJuego);
                        if(findJuegoAux!=-1){ //si lo encontro
                            utn_getEntero(&opcionModifJuego,"Ingrese valor que desea modificar\n1- Descripcion\n2- Importe\n",
                                          "ERROR! Ingrese numero entre 1 y 2\n",1,2,2);
                            switch(opcionModifJuego){
                                case 1:
                                    utn_getStringAvanzado(descr,"Ingrese descripcion a modificar: ",
                                                          "ERROR! El nombre debe ser solo letras\n",CHAR,2);
                                    modifyJuego(juego,JUEGOS,descr,importe,opcionModifJuego);
                                    system("cls");
                                break;
                                case 2:
                                    utn_getFlotante(&importe,"Ingrese el importe a modificar: ",
                                                  "ERROR! Ingrese un importe positivo\n",1,999999,2);
                                    modifyJuego(juego,JUEGOS,descr,importe,opcionModifJuego);
                                    system("cls");
                                break;
                            }
                            system("cls");
                            printf("Accion: Juego modificado correctamente\n");
                        }
                        else{
                            system("cls");
                            printf("No se encuentra el codigo de Juego\n");
                        }
                    }
                }
                break;
            case 3:
                if(firstClienteJuego(flagClie)!=0||firstClienteJuego(flagJue)!=0){
                utn_getEntero(&opcionRem,("Que desea eliminar?\n1- Clientes\n2- Juegos\n"),"Opcion incorrecta, reingrese numero",1,2,2);
                switch(opcionRem){
                    case 1:
                        system("cls");
                                printCliente(clie,CLIENTE);
                                utn_getEntero(&idRemClie,"Ingrese codigo de cliente a eliminar: ",
                                              "ERROR! Ingrese numero entre 1 y 100\n",1,CLIENTE,2);
                                removeCliente(clie,CLIENTE,idRemClie);

                    break;
                    case 2:
                        system("cls");//si no es la primera vez
                                printJuego(juego,JUEGOS);
                                utn_getEntero(&idRemJue,"Ingrese codigo de juego a eliminar: ",
                                              "ERROR! Ingrese numero entre 1 y 20\n",1,JUEGOS,2);
                                removeJuego(juego,JUEGOS,idRemJue);
                        }
                }
                break;
            case 4: //listar
                system("cls");
                if(firstClienteJuego(flagClie)!=0||firstClienteJuego(flagJue)!=0){
                //printf("El total de los importes de juegos alquilados es de: %.02f\n",totalImporte(alquiler,juego,ALQUILER,JUEGOS));
                //printf("El promedio de los importes de juegos alquilados es de: %.02f\n",averageImporte(alquiler,juego,ALQUILER,JUEGOS));
                //printf("La cantidad de juegos cuyo importe no supera el promedio es de: %d\n",cantidadJuegosNoSuperan(alquiler,juego,ALQUILER,JUEGOS));
                //sortImporte(juego,JUEGOS);
                //printJuego(juego,JUEGOS);
                utn_getEntero(&opcionList,"1- Promedio y total de los importes de los juegos alquilados\n"
                              "2- Cantidad de juegos que no superan el promedio de los juegos alquilados\n"
                              "3- Listar todos los clientes que alquilaron un juego determinado\n"
                              "4- Listar todos los juegos que fueron alquilados por un cliente determinado\n"
                              "5- Listar los juegos menos alquilados\n"
                              "6- Listar los clientes que realizaron mas alquileres\n"
                              "7- Listar los juegos alquilados en una fecha determinada\n"
                              "8- Listar los clientes que realizaron al menos un alquiler en una fecha determinada\n"
                              "9- Listar juegos ordenados por importe(descendiente) por metodo burbujeo\n"
                              "10- Listar clientes ordenados por apellido(ascendente) por metodo de insercion\n","Opcion incorrecta, reingrese numero",1,10,2);
                switch(opcionList){
                    case 1:
                        system("cls");
                            printf("Total: %.02f\n",totalImporte(alquiler,juego,ALQUILER,JUEGOS));
                            printf("Promedio: %.02f\n",averageImporte(alquiler,juego,ALQUILER,JUEGOS));
                    break;
                    case 2:
                        system("cls");
                        if(cantidadJuegosNoSuperan(alquiler,juego,JUEGOS,ALQUILER)!=-1){
                            printf("Cantidad de juegos que no superan el promedio: %d\n",cantidadJuegosNoSuperan(alquiler,juego,JUEGOS,ALQUILER));
                        }

                    break;
                    case 3:
                        utn_getEntero(&idAux,("Que desea eliminar?\n1- Clientes\n2- Juegos\n"),"Opcion incorrecta, reingrese numero",1,2,2);
                        printAlqJuegoDeterminado(idAux,alquiler,juego,clie,JUEGOS,ALQUILER,CLIENTE);
                        break;
                    case 4:
                        break;
                    case 5:
                        //juegosMenosAlquilados(idAux,alquiler,juego,JUEGOS,ALQUILER);
                        break;
                    case 6:
                        break;
                    case 7:
                        break;
                    case 8:
                        break;
                    case 9:
                        break;
                    case 10:
                        break;
                        }

                }
            break;
        }
    }while(opcionMain!=6);

    return 0;
}
