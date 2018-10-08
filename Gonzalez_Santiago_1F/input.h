#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED
/** \brief Valida si es una letra incluido el espacio
 * \param *input puntero al array char
 * \return Retorna (-1) si hay error, (1) si no hay error.
 */
int esLetra(char* input);

/** \brief Obtiene una cadena de caracteres
 * \param *input puntero al array char
 * \param *msg puntero al array char
 * \return No retorna nada ya que es una funcion void
 */
void utn_getString(char*,char*);
/** \brief Obtiene una cadena de caracteres validando solo letras
 * \param *input puntero al array char
 * \param *msg puntero al array char
 * \param *msgErr puntero al array char
 * \param int cant entero de la cantidad total del array
 * \param id reintentos reintentos para ingresar bien la cadena
 * \return Retorna (0) si hay error, (1) si no hay error.
 */
int utn_getStringAvanzado(char*,char*,char*,int, int);
/** \brief Obtiene un numero entero
 * \param *pEntero puntero a la variable int
 * \param *msg puntero al array char
 * \param *msgErr puntero al array char
 * \param int min rango de valor minimo del entero a obtener
 * \param int max rango de valor maximo del entero a obtener
 * \param id reintentos reintentos para ingresar bien el entero
 * \return Retorna (-1) si hay error, (0) si no hay error.
 */
int utn_getEntero(int*,char*,char*,int, int,int);
/** \brief Obtiene un numero flotante
 * \param *pFlotante puntero a la variable float
 * \param *msg puntero al array char
 * \param *msgErr puntero al array char
 * \param int min rango de valor minimo del flotante a obtener
 * \param int max rango de valor maximo del flotante a obtener
 * \param id reintentos reintentos para ingresar bien el flotante
 * \return Retorna (-1) si hay error, (0) si no hay error.
 */
int utn_getFlotante( float*,char*,char*,int,int,int);
/** \brief Obtiene una cadena de caracteres validando numeros
 * \param *input puntero al array char
 * \param *msg puntero al array char
 * \param *msgErr puntero al array char
 * \param int cant entero de la cantidad total del array
 * \param id reintentos reintentos para ingresar bien la cadena
 * \return Retorna (-1) si hay error, (0) si no hay error.
 */
int utn_getTelefono(char*,char*,char*,int,int);
#endif // INPUT_H_INCLUDED
