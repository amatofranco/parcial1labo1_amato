#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cliente.h"
#include "utn_inputs.h"

int cliente_iniciar(Cliente *array, int length) {

	int ret = -1;
	if (array != NULL && length > 0) {
		for (int i = 0; i < length; i++) {
			array[i].isEmpty = 1;
		}
		ret = 0;
	}

	return ret;

}




int cliente_imprimir(Cliente *pCliente) {

	int ret = -1;

	if (pCliente != NULL && pCliente->isEmpty == 0) {

		printf("%10d | %20s  | %30s\n",
				pCliente->id, pCliente->apellido, pCliente->nombre);

		ret = 0;

	}
	return ret;
}



int cliente_imprimirArray(Cliente *array, int length) {

	int ret = -1;

	if (array != NULL && length > 0) {

		printf("---------------------------------------------------------------------------------------------\n");

			printf("%10s  %20s   %30s\n","ID","APELLIDO","NOMBRE");

		for (int i = 0; i < length; i++) {

			if (array[i].isEmpty == 0) {

				cliente_imprimir(&array[i]);
			}

		}

		printf("---------------------------------------------------------------------------------------------\n");


		ret = 0;
	}
	return ret;
}


int cliente_validarId(Cliente *array, int length, int *id) {

	int ret = -1;

	int idAux;

	utn_getNumero(&idAux,
			"Ingrese el Id correspondiente al Cliente \n",
			"Ingreso inválido \n", MIN_ID_CLIENTE, MAX_ID_CLIENTE, 2);

	for (int i = 0; i < length; i++) {

		if (array[i].id == idAux && array[i].isEmpty == 0) {

			printf("Se eligió: \n %10s  %20s   %30s\n","ID","APELLIDO","NOMBRE");
			cliente_imprimir(&array[i]);
			printf("---------------------------------------------------------------------------------------------\n");

			ret = 0;
			*id = idAux;
			break;

		}
	}

	if (ret==-1){

		printf("El id seleccionado no corresponde a ningún cliente. \n");
	}

	return ret;

}



int cliente_hardcodeo(Cliente *array, int length, int *id) {

	int ret = -1;

	if (array != NULL && length > 0) {

		char nombre[3][MAX_NOMRBRE] = {"Juan", "María", "Rosa"};
		char apellido[3][MAX_APELLIDO] = {"Perez", "Gomez", "Gonzalez"};

		for (int i = 0; i < 3; i++) {

			strncpy(array[i].nombre,nombre[i],MAX_NOMRBRE);
			strncpy(array[i].apellido,apellido[i],MAX_NOMRBRE);
			array[i].id = *id;
			array[i].isEmpty = 0;
			(*id)++;

		}

		ret = 0;

	}

	return ret;
}
