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
 * \return retorna (-1) si hay error, distinto de -1 si esta bien
 */
int getFreeSpaceCliente(eCliente*,int);

/** \brief obtiene espacio libre del array juego
 * \param puntero del array char
 * \param longitud del array
 * \return retorna (-1) si hay error, distinto de -1 si esta bien
 */
int getFreeSpaceJuego(eJuego*,int);

/** \brief obtiene espacio libre del array alquiler
 * \param puntero del array char
 * \param longitud del array
 * \return retorna (-1) si hay error, distinto de -1 si esta bien
 */
int getFreeSpaceAlquiler(eAlquiler*, int);
/** \brief Da de alta el cliente en una posicion libre del array
 * \param clie* puntero al array de clientes
 * \param CANT Entero del total del array
 * \param apellido char auxiliar, apellido del cliente
 * \param nombre char auxiliar, nombre del cliente
 * \param dom char auxiliar, domicilio del cliente
 * \param tel char auxiliar, teléfono del cliente
 * \param idClie int auxiliar, id del cliente
 * \return int Retorna (-1) si hay error, (0) si no hay error.
 */
int altaCliente(eCliente*,int,char*,char*,char*,char*,int);
/** \brief Da de alta el juego en una posicion libre del array
 * \param juego* puntero al array de juegos
 * \param CANT Entero del total del array
 * \param descr char auxiliar, descripción del juego
 * \param importe float auxiliar, precio del juego
 * \param int idJuego auxiliar, id del juego
 * \return int Retorna (-1) si hay error, (0) si no hay error.
 */
int altaJuego(eJuego*,int,char*,float,int);
/** \brief Da de alta el alquiler asociando id de cliente e id de juego
 * \param alquiler* puntero al array de alquiler
 * \param ALQUILER Entero del total del array
 * \param idClieAlq int auxiliar Entero del ID cliente
 * \param idJuegoAlq int auxiliar Entero del ID juego
 * \param dia int auxiliar, día de alta alquiler
 * \param mes int auxiliar, mes de alta alquiler
 * \param anio int auxiliar, año de alta alquiler
 * \param idAlquiler int auxiliar, id del alquiler
 * \return int Retorna (-1) si hay error, (0) si no hay error.
 */
int altaAlquiler(eAlquiler*,int,int,int,int,int,int,int);
/** \brief Imprime el cliente por consola
 * \param clie* puntero al array de cliente
 * \param CANT Entero del total del array
 * \return int Retorna (-1) si hay error, la posicion del array si no hay error.
 */
int printCliente(eCliente*,int);
int printJuego(eJuego*,int);
/** \brief Busca el empleado por id
 * \param emp* puntero al array de empleados
 * \param CANT Entero del total del array
 * \param id int auxiliar, id a ser buscado en el array
 * \return int Retorna (-1) si hay error o si el id no se encontro,
 * la posicion del array si no hay error.
 */
int findClieById(eCliente*,int,int);
int findJuegoById(eJuego*,int,int);
/** \brief Elimina el empleado buscandolo por id
 * \param emp* puntero al array de empleados
 * \param CANT Entero del total del array
 * \param id int auxiliar, id a ser eliminado en el array
 * \return int Retorna (-1) si no se encuentra el id
 * o no se elimina el empleado, 0 si se elimina correctamente
 */
int removeCliente(eCliente*,int,int);
int removeJuego(eJuego*,int,int);
/** \brief Ordena el empleado ascendente o descendente segun se desee
 * \param emp* puntero al array de empleados
 * \param CANT Entero del total del array
 * \param name char auxiliar, nombre del empleado
 * \param lastName char auxiliar, apellido del empleado
 * \param opcion int, opcion deseada para ordenar el empleado
 * \return int Retorna (0) cuando se ordena
 */
int sortCliente(eCliente*,int,char*,char*);
int sortJuego(eJuego*,int,float, char*);
/** \brief Valida que se haya cargado un empleado al menos
 * \param flag int
 * \return int Retorna (-1) si ya se cargo un empelado al menos,
 * 0 si no se cargo el empleado.
 */
int firstClienteJuego(int);
/** \brief Modifica el empleado solicitado por id
 * \param emp* puntero al array de empleados
 * \param CANT Entero del total del array
 * \param name char auxiliar, nombre del empleado a modificar
 * \param lastName char auxiliar, apellido del empleado a modificar
 * \param salary float auxiliar, salario del empleado a modificar
 * \param id int auxiliar, id del empleado a modificar
 * \return No retorna nada ya que es una funcion void
 */
void modifyClie(eCliente*,int,char*,char*,char*,char*,int);
void modifyJuego(eJuego*,int,char*,float,int);


#endif // NEGOCIO_H_INCLUDED
