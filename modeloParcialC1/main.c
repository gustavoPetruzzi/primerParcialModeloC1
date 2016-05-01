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
    int codigoProducto;
    float importe;
    int cantidad;
    char descripcion[50];
    int isEmpty = 1;
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
                    printf("producto cargado!\n");
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
                    auxInt = getInt( &codigoProducto,"Ingrese el codigo a modificar: ", "ERROR: solo se permiten numeros del 1 al 1000", 1, 1000);
                    system("cls");
                    if(auxInt == 0)
                    {
                        indice = buscarPorCodigo(misproductos, MAX, codigoProducto);
                        if(indice!= -1)
                        {
                            pedirDatos(&codigoProducto, &importe, &cantidad, descripcion, 0);
                            misproductos[indice] = cargarProducto(codigoProducto, importe, cantidad, descripcion);
                        }
                        else
                        {
                            printf("No existe ningun producto con ese codigo\n!");
                        }
                    }
                }
                break;
            case '3':
                if(isEmpty ==0)
                {
                    auxInt = getInt(&codigoProducto, "Ingrese el codigo a borrar:", "ERROR: solo se permiten numeros del 1 al 1000", 1, 1000);
                    if(auxInt== 0)
                    {
                        indice = buscarPorCodigo(misproductos, MAX, codigoProducto);
                        if(indice != -1)
                        {
                            misproductos[indice].isEmpty = 1;
                        }
                        else
                        {
                            printf("No existe ningun producto con ese codigo\n!");
                        }
                    }
                }
                break;
            case '4':
                indice = buscarMayorMenor(misproductos, MAX, 1);
                printf("Datos:\nCodigo: %d\nDescripcion: %s\nImporte: %.2f\nCantidad: %d\n", misproductos[indice].codigoProducto, misproductos[indice].descripcion, misproductos[indice].importe, misproductos[indice].cantidad);
                calculosImportes(misproductos, &total, &promedio, &mayoresPromedio, MAX);
                printf("Importe total: %.2f\n", total);
                printf("Promedio: %.2f\n", promedio);
                printf("Mayores promedio: %d\n", mayoresPromedio);
                break;
            case '5':
                ordenaPorCantidad(misproductos, MAX);
                mostrarProductos(misproductos, MAX);
                break;
            case '6':
                break;
        }
    }while(opcion!= '6');
    return 0;
}
