#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"
/** \brief inicializa el array de estructuras
 *
 * \param eProductos* pProducto puntero del array a inicializar
 * \param int length tamaño maximo del array
 * \return devuelve -1 si no lo pudo inicializar (pProducto == NULL o length < 0)
 *         y 0 si esta ok
 */

int initArray(eProductos* pProducto, int length)
{
    int retorno = -1;
    int i;
    if(pProducto != NULL && length> 0)
    {
        for(i=0;i<length;i++)
        {
            pProducto[i].isEmpty = 1;
        }
        retorno = 0;
    }
    return retorno;
}
/** \brief crea un menu segun los parametros pasados por el usuario
 *
 * \param char textomenu[] Es la cadena que sirve como menu a ser mostrado
 * \param char min valor minimo que puede tomar el menu
 * \param char min valor maximo que puede tomar el menu
 * \return la opcion elegida por el usuario segun los parametros min y max
 *
 */

char mostrarMenu( char textomenu[], char min, char max )
{
    char opcion ='|';
    int flagPrimera = 1;


    do
    {
        if((opcion < min || opcion > max) && flagPrimera != 1)
        {
            printf("ERROR: reingrese\n");
        }
        printf("%s", textomenu);
        fflush(stdin);
        scanf("%c",&opcion);
        flagPrimera = 0;
    }while(opcion < min || opcion > max);
    return opcion;
}

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @param cantidadItems la cantidad total de items
 * @return el primer indice disponible o [-1] si no hay espacio libre
 */
int obtenerEspacioLibre(eProductos lista[],int cantidadItems)
{
    int index = -1;
    int i;

    for(i= 0; i<cantidadItems; i++)
    {
        if(lista[i].isEmpty == 1)
        {
            index = i;
            break;
        }
    }

    return index;
}


/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*/
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int auxInt;
    int flag = -1;
    int resp;
    printf("%s", message);
    fflush(stdin);
    resp = scanf("%d", &auxInt);
    if(resp == 1)
    {
        if(auxInt > lowLimit && auxInt < hiLimit)
        {
            *input = auxInt;
            flag = 0;
        }
    }
    if(flag == -1)
    {
        system("cls");
        printf("%s", eMessage);
    }
    return flag;
}


/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit)
{
    float auxFloat;
    int resp;
    printf("%s", message);
    fflush(stdin);
    resp = scanf("%f", &auxFloat);
    if(resp == 1)
    {
        if(auxFloat >= lowLimit && auxFloat <= hiLimit)
        {
            *input = auxFloat;
            return 0;

        }
        /*else
        {
            printf("%s", eMessage);
            return -1;
        }*/
    }


    printf("%s", eMessage);
    return -1;
}

/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    char auxChar[50];
    printf("%s", message);
    fflush(stdin);
    gets(auxChar);
    if(strlen(auxChar)>lowLimit && strlen(auxChar) < hiLimit )
    {
            strcpy(input, auxChar);
            return 0;
    }
    printf("%s", eMessage);
    return -1;
}


/** \brief Solicita los datos al usuario
 *
 * \param puntero codigoProducto donde va a a guardar el codigo del producto solicitada
 * \param puntero importe donde va a a guardar el importe solicitada
 * \param puntero cantidad donde va a a guardar la cantidad del producto solicitada
 * \param puntero descripcion donde va a guardar la descripcion
 * \param int pedirCodigo si es 1 se le solicita el codigo, si es 0 no lo pide
 * \return
 *
 */

void pedirDatos(int* codigoProducto,float* importe, int* cantidad,char* descripcion, int pedirCodigo)
{
    int auxInt;
    int auxCodigo;
    float auxImporte;
    int auxCantidad;
    char auxDescripcion[50];
    do
    {
        auxInt = getString(auxDescripcion, "Ingrese su descripcion: ", "ERROR: Maximo 50 caracteres\n", 2, 50);
    }while(auxInt!=0);
    strcpy(descripcion, auxDescripcion);
    system("cls");
    if(pedirCodigo)
    {
        do
        {
            auxInt = getInt(&auxCodigo,"Ingrese el codigo del producto: ", "ERROR: solo se permiten numeros entre 1 y 1000\n", 1,1000);
        }while(auxInt!=0);
        *codigoProducto = auxCodigo;
        system("cls");
    }

    do
    {
        auxInt = getFloat(&auxImporte,"Ingrese el importe: ", "ERROR: solo se permiten numeros \n", 0,99999999);
    }while(auxInt!=0);
    *importe = auxImporte;
    system("cls");

    do
    {
        auxInt = getInt(&auxCantidad,"Ingrese cantidad: ", "ERROR: solo se permiten numeros\n", 0,99999999);
    }while(auxInt!=0);
    *cantidad = auxCantidad;
    system("cls");

}

/** \brief carga los datos pasados por parametro a un elemento del array
 *
 * \param edad la edad de tipo entera se pasa como parametro
 * \param dni el dni de tipo entera se pasa como parametro
 * \param nombre se para por parametro
 * \return una variable del tipo Epersona con los campos completos
 *
 */
eProductos cargarProducto(int codigoProducto, float importe, int cantidad,  char descripcion[])
{
    eProductos auxProductos;

    auxProductos.codigoProducto = codigoProducto;
    auxProductos.importe = importe;
    strcpy(auxProductos.descripcion, descripcion);
    auxProductos.isEmpty = 0;

    return auxProductos;
}


/**
 * Obtiene el indice que coincide con el codigo pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param codigo el codigo a ser buscado en el array.
 * @param cantidadItems la cantidad total de items
 * @return el indice en donde se encuentra el elemento que coincide con el parametro
   o [-1] si no existe.
 */
int buscarPorCodigo(eProductos lista[], int cantidadItems, int codigo)
{
    int i;
    int index = -1;
    for(i=0;i<cantidadItems; i++)
    {
        if(lista[i].codigoProducto == codigo)
        {
            index = i;
            break;
        }
    }
    return index;
}
