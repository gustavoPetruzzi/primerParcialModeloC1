typedef struct{
    int codigoProducto;
    char descripcion[50];
    float importe;
    int cantidad;
    int isEmpty;
}eProductos;

int initArray(eProductos* pProducto, int length);
char mostrarMenu( char textomenu[], char min, char max );
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit);
int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit);
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);
int obtenerEspacioLibre(eProductos lista[],int cantidadItems);
void pedirDatos(int* codigoProducto,float* importe, int* cantidad,char* descripcion, int pedirCodigo);
eProductos cargarProducto(int codigoProducto, float importe, int cantidad,  char descripcion[]);
int buscarPorCodigo(eProductos lista[], int cantidadItems, int codigo);


