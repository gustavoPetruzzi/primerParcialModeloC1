#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define MAX 5

int main()
{
    int i;
    eProductos misproductos[50];
    int auxInt;
    char opcion;
    int indice;
    int codigoProducto;
    float importe;
    int cantidad;
    char descripcion[50];
    int isEmpty = 1;

    auxInt = initArray(misproductos, MAX);
    if(auxInt== -1)
    {
        printf("Un error ha ocurrido");
    }

    do
    {
        opcion = mostrarMenu("1-ALTAS\n2-MODIFICAR\n3-BAJA\n4-INFORMAR\n5-LISTAR\n6-SALIR", '1', '6');
        system("cls");
        switch(opcion)
        {
            case '1':
                indice = obtenerEspacioLibre(misproductos, MAX);
                if(indice != -1)
                {
                    pedirDatos(&codigoProducto, &importe, &cantidad, descripcion,1);
                    misproductos[indice] = cargarProducto(codigoProducto, importe, cantidad, descripcion);
                    printf("producto cargado!");
                    isEmpty = 0;
                }
                else
                {
                    printf("No hay mas lugar\n");
                }
                system("pause");
                system("cls");
                break;
            case '2':
                if(isEmpty == 0)
                {
                    auxInt = getInt( &codigoProducto,"Ingrese el codigo a buscar", "ERROR: solo se permiten numeros del 1 al 1000", 1, 1000);
                    if(auxInt == 0)
                    {
                        indice = buscarPorCodigo(misproductos, MAX, codigoProducto);
                    }
                }
                break;
            case '3':
                break;
            case '4':
                for(i=0;i<MAX;i++)
                {
                    if(misproductos[i].isEmpty == 0)
                    {
                        printf("Codigo: %d\nImporte:%.2f\nCantidad:%d\nDescripcion:%s", misproductos[i].codigoProducto, misproductos[i].importe, misproductos[i].cantidad, misproductos[i].descripcion);
                    }
                }
                break;
            case '5':
                break;
            case '6':
                break;
        }
    }while(opcion!= '6');
    return 0;
}
