#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn_inputs.h"
#include "Reparacion.h"
#include "Electrodomestico.h"
#include "Cliente.h"

/**
 * Imprime todos los datos de una posicion de Reparacion
 * @param puntero a estructura Pantalla a imprimir
 * @return 0 Éxito -1 Error
 */

int reparacion_imprimir(Reparacion *pReparacion, char *marca, char *servicio,
		char *nombre, char *apellido, float precio) {

	int ret = -1;

	if (pReparacion != NULL && pReparacion->isEmpty == 0) {

		printf(
				"%5d |%10s, %5s | %20s  | %10s | %10d | %10.2f | %20d / %d / %d\n",
				pReparacion->id, apellido, nombre, servicio, marca,
				pReparacion->serie, precio, pReparacion->fecha.dia,
				pReparacion->fecha.mes, pReparacion->fecha.anio);

		ret = 0;

	}
	return ret;
}

/**
 * Imprime todos los datos de una posicion de Servicio
 * @param pServicio array Servicio
 * @return 0 Éxito -1 Error
 */
int servicio_imprimir(Servicio *pServicio) {

	int ret = -1;

	if (pServicio != NULL && pServicio->isEmpty == 0) {

		printf("%10d | %20s  | %20.2f|\n", pServicio->id,
				pServicio->descripcion, pServicio->precio);

		ret = 0;

	}
	return ret;
}

int servicio_descripcionPorId(char *descripcion, Servicio *array, int length,
		int id) {

	int ret = -1;

	if (array != NULL && length > 0) {

		for (int i = 0; i < length; i++) {

			if (array[i].id == id && array[i].isEmpty == 0) {

				strncpy(descripcion, array[i].descripcion, MAX_DESC_SERV);

				ret = 0;

				break;

			}

		}
	}

	return ret;

}

int servicio_precioPorId(float *precio, Servicio *array, int length, int id) {

	int ret = -1;

	if (array != NULL && length > 0) {

		for (int i = 0; i < length; i++) {

			if (array[i].id == id && array[i].isEmpty == 0) {

				*precio = array[i].precio;

				ret = 0;

				break;

			}

		}
	}

	return ret;

}

int reparacion_nombreClientePorId(char *nombre, Cliente *array, int length,
		int id) {
	int ret = -1;

	if (array != NULL && length > 0) {

		for (int i = 0; i < length; i++) {

			if (array[i].id == id && array[i].isEmpty == 0) {

				strncpy(nombre, array[i].nombre, MAX_NOMRBRE);

				ret = 0;

				break;

			}

		}
	}

	return ret;

}

int reparacion_apellidoClientePorId(char *apellido, Cliente *array, int length,
		int id) {
	int ret = -1;

	if (array != NULL && length > 0) {

		for (int i = 0; i < length; i++) {

			if (array[i].id == id && array[i].isEmpty == 0) {

				strncpy(apellido, array[i].apellido, MAX_APELLIDO);

				ret = 0;

				break;

			}

		}
	}

	return ret;

}

/**
 * Imprime dia, mes y año a partir de Estructura Fecha
 * @param pFecha
 * @return 0 Éxito -1 Error
 */
int fecha_imprimir(Fecha *pFecha) {

	int ret = -1;

	if (pFecha != NULL && pFecha->isEmpty == 0) {

		printf("Fecha: %d / %d / %d \n ", pFecha->dia, pFecha->mes,
				pFecha->anio);

		ret = 0;

	}
	return ret;
}

/** \brief Imprime la lista de Reparaciones con sus respectivos datos
 * \param list puntero a array de Reparacion
 * \param len largo del array
 * \return 0 Éxito -1 Error
 *
 */
int reparacion_imprimirArray(Reparacion *array, int lengthR,
		Electrodomestico *arrayE, int lengthE, Marca *arrayM, int lengthM,
		Servicio *arrayS, int lengthS, Cliente *arrayC, int lengthC) {

	int ret = -1;

	int idMarca;

	char descMarca[MAX_DESC_MARCA];

	char descServicio[MAX_DESC_SERV];

	char nombre[MAX_NOMRBRE];

	char apellido[MAX_APELLIDO];

	float precio;

	if (array != NULL && lengthR > 0) {

		printf(
				"------------------------------------------------------------------------------------------------------------------------------------------\n");

		printf("%5s  %20s  %15s   %10s  %15s   %10s  %20s \n", "ID", "CLIENTE",
				"SERVICIO", "MARCA", "SERIE", "PRECIO", "FECHA");

		for (int i = 0; i < lengthR; i++) {

			if (array[i].isEmpty == 0) {

				electro_marcaPorSerie(&idMarca, arrayE, lengthE,
						array[i].serie);

				marca_descripcionPorId(descMarca, arrayM, lengthM, idMarca);

				servicio_descripcionPorId(descServicio, arrayS, lengthS,
						array[i].idServicio);

				servicio_precioPorId(&precio, arrayS, lengthS,
						array[i].idServicio);

				reparacion_nombreClientePorId(nombre, arrayC, lengthC,
						array[i].idCliente);
				reparacion_apellidoClientePorId(apellido, arrayC, lengthC,
						array[i].idCliente);

				reparacion_imprimir(&array[i], descMarca, descServicio, nombre,
						apellido, precio);

			}

		}

		printf(
				"------------------------------------------------------------------------------------------------------------------------------------------\n");

		ret = 0;
	}
	return ret;
}

/**
 * Imprime array de Servicios
 * @param array array de servicios
 * @param length largo del array
 * @return 0 Éxito -1 Error
 */
int servicio_imprimirArray(Servicio *array, int length) {

	int ret = -1;

	if (array != NULL && length > 0) {

		printf(
				"---------------------------------------------------------------------------------------------\n");

		printf("%10s  %20s   %20s\n", "ID", "DESCRIPCION", "PRECIO");

		for (int i = 0; i < length; i++) {

			if (array[i].isEmpty == 0) {

				servicio_imprimir(&array[i]);
			}

		}
		printf(
				"---------------------------------------------------------------------------------------------\n");

		ret = 0;
	}
	return ret;
}

/**
 * Para indicar que todas las posiciones del array Reparacion están vacías,
 * pone la bandera (isEmpty) en TRUE en todas las posiciones
 * \param list puntero al array
 * \param len largo del array
 * \return 0 Éxito -1 Error
 *
 */
int reparacion_iniciar(Reparacion *array, int length) {

	int ret = -1;
	if (array != NULL && length > 0) {
		for (int i = 0; i < length; i++) {
			array[i].isEmpty = 1;
		}
		ret = 0;
	}

	return ret;

}

int servicio_iniciar(Servicio *array, int length) {

	int ret = -1;
	if (array != NULL && length > 0) {
		for (int i = 0; i < length; i++) {
			array[i].isEmpty = 1;
		}
		ret = 0;
	}

	return ret;

}

/**
 * Busca un lugar vacio en el array Reparacion y lo asigna a puntero indice
 * @param list Puntero al array
 * @param len longitud del array
 * @param puntero indice
 * @return 0 Éxito -1 Error
 */

int reparacion_emptyIndex(Reparacion *array, int length, int *indice) {

	int ret = -1;

	if (array != NULL && length > 0) {
		for (int i = 0; i < length; i++) {

			if (array[i].isEmpty == 1) {

				ret = 0;
				*indice = i;
				break;

			}
		}
	}

	return ret;
}

/**
 * Verifica si el array Reparacion en su totalidad está vacio
 * @param list puntero a Array
 * @param length largo del Array
 * @return 1 Verdadero (Array vacio) 0 Falso
 */

int reparacion_emptyArray(Reparacion *list, int length) {

	int ret = 1; // TRUE

	if (list != NULL && length > 0) {
		for (int i = 0; i < length; i++) {

			if (list[i].isEmpty == 0) {

				ret = 0;
				break;
			}
		}
	}

	return ret;
}

/**
 * Agrega una Reparacion al array de Reparaciones
 * @param list puntero a Array
 * @param len longitud del array
 * @param indice indice del Array donde se agregará
 * @param *pId puntero a contador de Id
 * @return 0 Éxito -1 Error
 */

int reparacion_alta(Reparacion *arrayR, int lengthR, Cliente *arrayC,
		int lengthC, Servicio *arrayS, int lengthS, Electrodomestico *arrayE,
		int lengthE, Marca *arrayM, int lengthM, int *pId) {

	Reparacion bufferRepa;

	int indice;

	char arrayCompleto[] = "No hay más espacio para realizar una carga \n";

	int ret = -1;

	if (arrayR != NULL
			&& lengthR
					> 0&& arrayS != NULL && lengthS > 0 && arrayE != NULL && lengthE > 0 && pId != NULL) {

		if (reparacion_emptyIndex(arrayR, lengthR, &indice) == -1) {

			printf("%s", arrayCompleto);

		}

		else {

			if (cliente_imprimirArray(arrayC, lengthC) == 0
					&& cliente_validarId(arrayC, lengthC, &bufferRepa.idCliente)
							== 0

					&& electro_ordenar(arrayE,lengthE)==0
					&& electro_imprimirArray(arrayE, lengthE, arrayM, lengthM) == 0
					&& electro_validarSerie(arrayE, lengthE, arrayM, lengthM, &bufferRepa.serie) == 0
					&& servicio_imprimirArray(arrayS, lengthS) == 0
					&& servicio_validarId(arrayS, lengthS, &bufferRepa.idServicio) == 0
					&& reparacion_validarFecha(&bufferRepa.fecha) == 0) {

				bufferRepa.isEmpty = 0;
				bufferRepa.id = *pId;
				arrayR[indice] = bufferRepa;

				(*pId)++;
				ret = 0;
			}

		}

	}

	return ret;
}

/**
 * Verifica si existe una posición ocupada del array Reparacion
 * que coincida con el valor del id y la asigna a puntero indice
 * @param list Puntero al array
 * @param len longitud del array
 * @param id id a buscar
 * @param puntero a indice
 * @return posición del array
 */
int reparacion_buscarId(Reparacion *array, int length, int id, int *indice) {

	int ret = -1;

	if (array != NULL && length > 0 && id >= MIN_IDREPA) {

		for (int i = 0; i < length; i++) {

			if (array[i].isEmpty == 0 && array[i].id == id) {

				ret = 0;

				*indice = i;

				break;

			}

		}
	}

	return ret;
}

int servicio_validarId(Servicio *array, int length, int *id) {

	int ret = -1;

	int idAux;

	int flag = 0;

	if (utn_getNumero(&idAux, "Ingrese el Id correspondiente al servicio \n",
			"Ingreso inválido \n", MIN_IDSERV, MAX_IDSERV, 2) == 0) {

		for (int i = 0; i < length; i++) {

			if (array[i].id == idAux && array[i].isEmpty == 0) {

				printf("Se eligió: \n %10s  %20s   %20s\n", "ID", "DESCRIPCION","PRECIO");

				servicio_imprimir(&array[i]);

				printf("---------------------------------------------------------------------------------------------\n");

				flag = 1;
				ret = 0;
				*id = idAux;
				break;

			}
		}
	}

	if (flag==0){

		printf("El ID ingresado no corresponde a ningún servicio. \n");
	}

	return ret;

}

int reparacion_validarFecha(Fecha *fecha) {

	int ret = -1;

	Fecha fechaAux;

	if (utn_getNumero(&fechaAux.dia,
			"Fecha de reparación \nIngrese día en números: \n",
			"Número inválido \n", 1, 31, 2) == 0
			&& utn_getNumero(&fechaAux.mes, "Ingrese mes en números: \n",
					"Número inválido \n", 1, 12, 2) == 0
			&& utn_getNumero(&fechaAux.anio, "Ingrese año en números: \n",
					"Número inválido \n", MIN_ANIO_REPA, MAX_ANIO_REPA, 2)
					== 0) {

		*fecha = fechaAux;
		ret = 0;

	}

	return ret;

}

/**
 * Verifica si existe una posición ocupada del array Servicio
 * que coincida con el valor del id y la asigna a puntero indice
 * @param list Puntero al array
 * @param len longitud del array
 * @param id id a buscar
 * @param puntero a indice
 * @return posición del array
 */
int servicio_buscarId(Servicio *array, int length, int id, int *indice) {

	int ret = -1;

	if (array != NULL && length > 0 && id >= MIN_IDREPA) {

		for (int i = 0; i < length; i++) {

			if (array[i].isEmpty == 0 && array[i].id == id) {

				ret = 0;

				*indice = i;

				servicio_imprimir(&array[i]);
				break;

			}

		}
	}

	return ret;
}

int servicio_hardcodeo(Servicio *array, int length, int *id) {

	int ret = -1;

	if (array != NULL && length > 0) {

		char descripcion[QTY_SERVICIOS][MAX_DESC_SERV] = { "Garantia",
				"Mantenimiento", "Repuestos", "Refaccion" };
		float precio[QTY_SERVICIOS] = { 250, 500, 400, 600 };

		for (int i = 0; i < 4; i++) {

			strncpy(array[i].descripcion, descripcion[i], MAX_DESC_SERV);
			array[i].precio = precio[i];
			array[i].id = *id;
			array[i].isEmpty = 0;
			(*id)++;

		}

		ret = 0;

	}

	return ret;
}

int reparacion_ordenarPorServicio(Reparacion *array, int length) {

	int ret = -1;
	int flagSwap;
	Reparacion buffer;

	do {

		flagSwap = 0;

		for (int i = 0; i < length - 1; i++) {

			if (array[i].idServicio > array[i + 1].idServicio
					|| (array[i].idServicio == array[i + 1].idServicio
							&& array[i].serie > array[i + 1].serie)) {

				flagSwap = 1;
				buffer = array[i];
				array[i] = array[i + 1];
				array[i + 1] = buffer;
			}
		}

		length--;

	} while (flagSwap == 1);

	ret = 0;

	return ret;
}



int reparacion_altaForzada(Reparacion *array, int length, int *pId) {

	int ret = -1;

	if (array != NULL && length > 0) {

		int serie[4] = { 1400, 2345, 1234,1234 };
		Fecha fecha[4] ={ { 10, 10, 2020 }, { 20, 11, 2020 }, { 12, 12, 2020 } ,{15,12,2020}};
		int idServicio[4] = { 20000, 20001, 20002,20000 };
		int idCliente[4] = { 1, 2, 3, 3 };

		for (int i = 0; i < 4; i++) {

			array[i].serie = serie[i];
			array[i].fecha = fecha[i];
			array[i].idServicio = idServicio[i];
			array[i].idCliente = idCliente[i];
			array[i].id = *pId;
			array[i].isEmpty = 0;
			(*pId)++;

		}

		ret = 0;

	}

	return ret;

}
