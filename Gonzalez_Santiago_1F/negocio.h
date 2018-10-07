#ifndef NEGOCIO_H_INCLUDED
#define NEGOCIO_H_INCLUDED
typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;
typedef struct{
    int idJue;
    char descr[51];
    float importe;
    int isEmpty;
}eJuego;
typedef struct{
    int idClie;
    char apellido[51];
    char nombre[51];
    char dom[51];
    char tel[21];
    int isEmpty;
}eCliente;
typedef struct{
    int idClie;
    int idJue;
    int idAlq;
    eFecha fecha;
    int isEmpty;
}eAlquiler;

/** \brief inicializa el array cliente
 * \param puntero del array char
 * \param longitud del array
 * \return retorna (-1) si hay error, 0 si esta bien
 */
int initClie(eCliente*,int);

/** \brief inicializa el array juego
 * \param puntero del array char
 * \param longitud del array
 * \return retorna (-1) si hay error, 0 si esta bien
 */
int initJuego(eJuego*,int);

/** \brief inicializa el array alquiler
 * \param puntero del array char
 * \param longitud del array
 * \return retorna (-1) si hay error, 0 si esta bien
 */
int initAlquiler(eAlquiler*,int);

/** \brief obtiene espacio libre del array cliente
 * \param puntero del array char
 * \param longitud del array
 * \return retorna (-1) si hay error, 0 si esta bien
 */
int getFreeSpaceCliente(eCliente*,int);

/** \brief obtiene espacio libre del array cliente
 * \param puntero del array char
 * \param longitud del array
 * \return retorna (-1) si hay error, 0 si esta bien
 */
int getFreeSpaceJuego(eJuego*,int);

/** \brief obtiene espacio libre del array cliente
 * \param puntero del array char
 * \param longitud del array
 * \return retorna (-1) si hay error, 0 si esta bien
 */
int getFreeSpaceAlquiler(eAlquiler*, int);

/** \brief obtiene espacio libre del array cliente
 * \param puntero del array char
 * \param longitud del array
 * \return retorna (-1) si hay error, 0 si esta bien
 */
int altaCliente(eCliente*,int,char*,char*,char*,char*,int);
int altaJuego(eJuego*,int,char*,float,int);
int altaAlquiler(eAlquiler*,int,int,int,int,int,int,int);

int printCliente(eCliente*,int);
int printJuego(eJuego*,int);

int findClieById(eCliente*,int,int);
int findJuegoById(eJuego*,int,int);

int removeCliente(eCliente*,int,int);
int removeJuego(eJuego*,int,int);

int sortCliente(eCliente*,int,char*,char*);
int sortJuego(eJuego*,int,float, char*);

int firstClienteJuego(int);

void modifyClie(eCliente*,int,char*,char*,char*,char*,int,int);
void modifyJuego(eJuego*,int,char*,float,int,int);


#endif // NEGOCIO_H_INCLUDED
