

#ifndef ELECTRODOMESTICO_H_
#define ELECTRODOMESTICO_H_

#define QTY_ELECTRODOMESTICOS 100
#define QTY_MARCAS 5
#define QTY_TIPOS 2
#define MIN_ANIO 1900
#define MAX_ANIO 2050
#define MIN_ID 1
#define MAX_ID 10000
#define MIN_IDMARCA 1000
#define MAX_IDMARCA 1004
#define MAX_NUMSERIE 2000000

#define MAX_DESC_MARCA 21


struct {

int id;
int serie;
int idMarca;
int anio;

int isEmpty;
} typedef Electrodomestico;



struct {
int id;
char descripcion[MAX_DESC_MARCA];
int isEmpty;
} typedef Marca;




int electro_iniciar(Electrodomestico* list, int len);
int marca_iniciar(Marca *array, int length);

int electro_emptyIndex(Electrodomestico *array, int length, int* indice);
int electro_emptyArray(Electrodomestico *list, int length);


int electro_imprimir(Electrodomestico *pElectro, char *descripcion);
void electro_imprimirColumnas(void);
int electro_imprimirArray(Electrodomestico *array, int length, Marca *arrayM, int lengthM);
int electro_imprimirPorId(Electrodomestico *array, int length, Marca *arrayM, int lengthM, int id);

int marca_imprimirArray(Marca *array, int length);
int marca_imprimir(Marca *array);
int marca_descripcionPorId(char *descripcion, Marca *array, int length, int id);


int electro_alta(Electrodomestico *arrayE, int lengthE, Marca *arrayM, int lengthM);
int electro_buscarId(Electrodomestico *array, int length, int id, int *resultado);
int marca_buscarId(Marca *array, int length, int id, int *indice);
int marca_validarId (Marca *array,int length,int *id);
int electro_validarSerie(Electrodomestico *array, int length, Marca *arrayM, int lengthM, int *serie);
int electro_marcaPorSerie(int *idMarca, Electrodomestico *array, int length, int serie);


int electro_modificar(Electrodomestico *array, int length, Marca *arrayM, int lengthM);
int electro_baja(Electrodomestico *array, int length, Marca *arrayM, int lengthM);
int electro_ordenar(Electrodomestico *array, int length);

int electro_altaForzada (Electrodomestico *array, int length);

int marca_hardcodeo(Marca *array, int length, int *id);



#endif /* ELECTRODOMESTICO_H_ */

