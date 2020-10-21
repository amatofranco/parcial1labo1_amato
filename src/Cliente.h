/*
 * Cliente.h
 *
 *  Created on: Oct 20, 2020
 *      Author: francoamato
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_


#define MAX_NOMRBRE 51
#define MAX_APELLIDO 51
#define MIN_ID_CLIENTE 1
#define MAX_ID_CLIENTE 3
#define QTY_CLIENTES 100

struct{

char nombre[MAX_NOMRBRE];
char apellido[MAX_APELLIDO];
int id;
int isEmpty;

} typedef Cliente;


int cliente_iniciar(Cliente *array, int length);

int cliente_imprimir(Cliente *pCliente);

int cliente_imprimirArray(Cliente *array, int length);

int cliente_validarId(Cliente *array, int length, int *id);


int cliente_hardcodeo(Cliente *array, int length, int *id);


#endif /* CLIENTE_H_ */
