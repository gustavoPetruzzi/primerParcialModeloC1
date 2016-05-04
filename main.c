#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define MAX 5

int main()
{
    eProductos misproductos[50];
    int auxInt;
    char opcion;
    int indice;
    float promedio;
    float total;
    int mayoresPromedio;

    auxInt = initArray(misproductos, MAX);
    if(auxInt== -1)
    {
        printf("Un error ha ocurrido");
    }

    do
    {

        opcion = mostrarMenu("1-ALTAS\n2-MODIFICAR\n3-BAJA\n4-INFORMAR\n5-LISTAR\n6-SALIR\n", '1', '6');
        system("cls");
        switch(opcion)
        {
            case '1':
                indice = obtenerEspacioLibre(misproductos, MAX);
                agregarProducto(misproductos, indice);
                system("pause");
                system("cls");
                break;
            case '2':
                auxInt = isEmpty(misproductos, MAX);
                if(auxInt ==0)
                {
                    modificar(misproductos, MAX);
                }
                else
                {
                    printf("No hay ningun producto cargado!\n");
                }
                break;
            case '3':
                auxInt = isEmpty(misproductos, MAX);
                if(auxInt ==0)
                {
                    borrar(misproductos, MAX);
                }
                else
                {
                    printf("No hay ningun producto cargado!\n");
                }
                system("pause");
                system("cls");
                break;
            case '4':
                auxInt = isEmpty(misproductos, MAX);
                if(auxInt== 0)
                {
                    indice = buscarMayorMenor(misproductos, MAX, 1);
                    mostrarUno(misproductos[indice]);
                    calculosImportes(misproductos, &total, &promedio, &mayoresPromedio, MAX);
                    printf("Importe total: %.2f\n", total);
                    printf("Promedio: %.2f\n", promedio);
                    printf("Mayores promedio: %d\n", mayoresPromedio);
                }
                system("pause");
                system("cls");
                break;
            case '5':
                ordenaPorCantidad(misproductos, MAX);
                mostrarProductos(misproductos, MAX);
                system("pause");
                system("cls");
                break;
            case '6':
                break;
        }
    }while(opcion!= '6');
    return 0;
}
