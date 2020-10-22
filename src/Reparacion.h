

#ifndef REPARACION_H_
#define REPARACION_H_

#include "Electrodomestico.h"
#include "Cliente.h"


#define QTY_REPARACIONES 1000
#define QTY_SERVICIOS 4
#define MIN_IDREPA 1
#define MAX_IDREPA 1000
#define MIN_IDSERV 20000
#define MAX_IDSERV 20004
#define MIN_ANIO_REPA 2020
#define MAX_ANIO_REPA 2050
#define MAX_DESC_SERV 26



struct{

int dia;
int mes;
int anio;
int isEmpty;

} typedef Fecha;


struct {

char descripcion[MAX_DESC_SERV];
float precio;
int id;
int isEmpty;
} typedef Servicio;


struct {
int serie;
Fecha fecha;
int idServicio;
int idCliente;
int id;
int isEmpty;
} typedef Reparacion;


int reparacion_imprimir(Reparacion *pReparacion, char *marca, char *servicio, char *nombre, char *apellido, float precio);
void reparacion_imprimirColumnas(void);
int servicio_imprimir(Servicio *pServicio);
int reparacion_imprimirDescripcion(Reparacion *reparacion, Electrodomestico *arrayE, int lengthE, Marca *arrayM,int lengthM, Servicio *arrayS, int lengthS, Cliente *arrayC,int lengthC);
int reparacion_imprimirArray(Reparacion *array, int lengthR, Electrodomestico *arrayE, int lengthE, Marca *arrayM, int lengthM, Servicio *arrayS, int lengthS, Cliente *arrayC, int lengthC);
int servicio_imprimirArray(Servicio *array, int length);
int servicio_descripcionPorId(char *descripcion, Servicio *array, int length, int id);
int servicio_precioPorId(float* precio, Servicio *array, int length, int id);
int reparacion_nombreClientePorId(char *nombre,Cliente *array,int length,int id);
int reparacion_apellidoClientePorId(char *apellido,Cliente *array,int length,int id);

int reparacion_ordenarPorServicio(Reparacion *array, int length);



int reparacion_iniciar(Reparacion* list, int len);
int servicio_iniciar(Servicio *array, int length);


int reparacion_emptyIndex(Reparacion *array, int length, int* indice);
int reparacion_emptyArray(Reparacion *list, int length);

int reparacion_alta(Reparacion *arrayR, int lengthR, Cliente *arrayC, int lengthC, Servicio *arrayS, int lengthS, Electrodomestico *arrayE, int lengthE, Marca *arrayM, int lengthM, int *pId);

int reparacion_buscarId(Reparacion *array, int length, int id, int* indice);
int servicio_buscarId(Servicio *array, int length, int id, int *indice);
int servicio_validarId(Servicio *array, int length, int *id);
int reparacion_validarFecha(Fecha *fecha);



int reparacion_modificar(Reparacion *array, int length);
int reparacion_baja(Reparacion *list, int len);
int reparacion_ordenar(Reparacion *array, int length);

int servicio_hardcodeo(Servicio *array, int length, int *id);
int reparacion_altaForzada(Reparacion *array, int length, int *pId);



#endif /* PANTALLA_H_ */

