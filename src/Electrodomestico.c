#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Electrodomestico.h"
#include "utn_inputs.h"

/**
 * Imprime todos los datos de una Electrodomestico
 * @param puntero a estructura Electrodomestico a imprimir
 * @return 0 Éxito -1 Error
 */

int electro_imprimir(Electrodomestico *pElectro, char *descripcion) {

	int ret = -1;

	if (pElectro != NULL && pElectro->isEmpty == 0) {

		printf("%10d | %20d  | %20s | %20d |\n", pElectro->id, pElectro->serie,
				descripcion, pElectro->anio);

		ret = 0;

	}
	return ret;
}

void electro_imprimirColumnas(void) {

	printf(
			"---------------------------------------------------------------------------------------------\n");

	printf("%10s  %20s   %20s  %20s  \n", "ID", "SERIE", "MARCA", "MODELO");
}
/**
 * Imprime todos los datos de una Marca
 * @param pMarca Puntero a array Marca
 * @return 0 Éxito -1 Error
 */

int marca_imprimir(Marca *pMarca) {

	int ret = -1;

	if (pMarca != NULL && pMarca->isEmpty == 0) {

		printf("%10d | %20s  |\n", pMarca->id, pMarca->descripcion);

		ret = 0;

	}
	return ret;
}

int marca_descripcionPorId(char *descripcion, Marca *array, int length, int id) {

	int ret = -1;

	if (array != NULL && length > 0) {

		for (int i = 0; i < length; i++) {

			if (array[i].id == id && array[i].isEmpty == 0) {

				strncpy(descripcion, array[i].descripcion, MAX_DESC_MARCA);

				ret = 0;

				break;

			}

		}
	}

	return ret;

}

/** \brief Imprime la lista de Electrodomesticos con sus respectivos datos
 * \param list puntero a array de Electrodomesticos
 * \param len largo del array
 * \return 0 Éxito -1 Error
 *
 */

int electro_marcaPorSerie(int *idMarca, Electrodomestico *array, int length,
		int serie) {

	int ret = -1;

	if (idMarca != NULL && array != NULL) {

		for (int i = 0; i < length; i++) {

			if (array[i].isEmpty == 0 && array[i].serie == serie) {

				*idMarca = array[i].idMarca;
				ret = 0;

			}

		}

	}

	return ret;

}

int electro_imprimirArray(Electrodomestico *array, int length, Marca *arrayM,
		int lengthM) {

	int ret = -1;

	char descripcion[MAX_DESC_MARCA];

	if (array != NULL && length > 0) {

		electro_imprimirColumnas();

		for (int i = 0; i < length; i++) {

			if (array[i].isEmpty == 0) {

				marca_descripcionPorId(descripcion, arrayM, lengthM,
						array[i].idMarca);

				electro_imprimir(&array[i], descripcion);
			}

		}

		printf(
				"---------------------------------------------------------------------------------------------\n");

		ret = 0;
	}
	return ret;
}

int electro_imprimirPorId(Electrodomestico *array, int length, Marca *arrayM,
		int lengthM, int id) {

	int ret = -1;

	char descripcion[MAX_DESC_MARCA];

	if (array != NULL && length > 0) {

		for (int i = 0; i < length; i++) {

			if (array[i].isEmpty == 0 && array[i].id == id) {

				marca_descripcionPorId(descripcion, arrayM, lengthM,
						array[i].idMarca);

				printf("Se eligió:\n");

				electro_imprimirColumnas();

				electro_imprimir(&array[i], descripcion);

				break;
			}

		}

		printf(
				"---------------------------------------------------------------------------------------------\n");

		ret = 0;
	}
	return ret;
}

/**
 * Imprime la lista de Marcas con sus datos
 * @param array puntero a array Marcas
 * @param length largo del array
 * @return 0 Éxito -1 Error
 */
int marca_imprimirArray(Marca *array, int length) {

	int ret = -1;

	if (array != NULL && length > 0) {

		printf(
				"---------------------------------------------------------------------------------------------\n");

		printf("%10s  %20s \n", "ID", "MARCA");

		for (int i = 0; i < length; i++) {

			if (array[i].isEmpty == 0) {

				marca_imprimir(&array[i]);
			}

		}

		printf(
				"---------------------------------------------------------------------------------------------\n");

		ret = 0;
	}
	return ret;
}

/**
 * Para indicar que todas las posiciones del array Electrodomestico están vacías,
 * pone la bandera (isEmpty) en TRUE en todas las posiciones
 * \param list puntero al array
 * \param len largo del array
 * \return 0 Éxito -1 Error
 *
 */
int electro_iniciar(Electrodomestico *array, int length) {

	int ret = -1;
	if (array != NULL && length > 0) {
		for (int i = 0; i < length; i++) {
			array[i].isEmpty = 1;
		}
		ret = 0;
	}

	return ret;

}

int marca_iniciar(Marca *array, int length) {

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
 * Busca un lugar vacio en el array de Electrdomesticos y lo asigna a puntero indice
 * @param list Puntero al array
 * @param len longitud del array
 * @param puntero indice
 * @return 0 Éxito -1 Error
 */

int electro_emptyIndex(Electrodomestico *array, int length, int *indice) {

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
 * Verifica si el array Electrodomesticos en su totalidad está vacio
 * @param list puntero a Array
 * @param length largo del Array
 * @return 1 Verdadero (Array vacio) 0 Falso
 */

int electro_emptyArray(Electrodomestico *list, int length) {

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
 * Verifica si el array Marca en su totalidad esta vacio
 * @param list puntero a Array de Marca
 * @param length largo del array
 * @return 1 True 0 Falso
 */
int marca_emptyArray(Electrodomestico *list, int length) {

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
 * Agrega una Electrodomestico al array de Electrodomesticos
 * @param list puntero a Array
 * @param len longitud del array
 * @param indice indice del Array donde se agregará
 * @param *pId puntero a contador de Id
 * @return 0 Éxito -1 Error
 */

int electro_alta(Electrodomestico *arrayE, int lengthE, Marca *arrayM,
		int lengthM) {

	Electrodomestico bufferElectro;

	int indice;

	char arrayCompleto[] = "No hay más espacio para realizar una carga \n";

	int ret = -1;

	if (arrayE != NULL && lengthE > 0 && arrayM != NULL && lengthM > 0) {

		if (electro_emptyIndex(arrayE, lengthE, &indice) == -1) {

			printf("%s", arrayCompleto);

		}

		else if (marca_validarId(arrayM, lengthM, &bufferElectro.idMarca)
				!= 0) {

			printf("El id seleccionado no corresponde a ninguna marca. \n");
		}

		else if (

		utn_getNumero(&bufferElectro.id, "Ingrese ID del Electrodoméstico \n",
				"Ingreso inválido \n", MIN_ID, MAX_ID, 2) == 0
				&& utn_getNumero(&bufferElectro.serie,
						"Ingrese codigo de serie del Electrodoméstico\n",
						"Ingreso inválido \n", 1,
						MAX_NUMSERIE, 2) == 0
				&& utn_getNumero(&bufferElectro.anio,
						"Ingrese número correspondiente al modelo (año) \n",
						"Número inválido \n", MIN_ANIO, MAX_ANIO, 2) == 0) {

			bufferElectro.isEmpty = 0;

			arrayE[indice] = bufferElectro;

			ret = 0;

		}
	}

	return ret;
}

/**
 * Verifica si existe una posición ocupada del array Electrdomesticos
 * que coincida con el valor del id y la asigna a puntero indice
 * @param list Puntero al array
 * @param len longitud del array
 * @param id id a buscar
 * @param puntero a indice
 * @return posición del array
 */
int electro_buscarId(Electrodomestico *array, int length, int id,
		int *resultado) {

	int ret = -1;

	if (array != NULL && length > 0 && id >= MIN_ID) {

		for (int i = 0; i < length; i++) {

			if (array[i].isEmpty == 0 && array[i].id == id) {

				ret = 0;

				*resultado = i;

				break;

			}

		}
	}

	return ret;
}

/**
 * Verifica si el numero de serie ingresado se encuentra
 * en alguna posicion del array Electrodomesticos
 * @param array puntero a Array de electrodomesticos
 * @param length Largo del array
 * @param serie Puntero a Numero de serie encontrado
 * @return 0 Éxito -1 Error
 */
int electro_validarSerie(Electrodomestico *array, int length, Marca *arrayM,
		int lengthM, int *serie) {

	int ret = -1;

	int serieAux;

	int flag = 0;

	if (utn_getNumero(&serieAux,
			"Ingrese el número de SERIE correspondiente al Electrodomestico \n",
			"Ingreso inválido \n", 1, MAX_NUMSERIE, 2) == 0) {

		for (int i = 0; i < length; i++) {

			if (array[i].serie == serieAux && array[i].isEmpty == 0) {

				electro_imprimirPorId(array, length, arrayM, lengthM,
						array[i].id);

				ret = 0;
				flag = 1;
				*serie = serieAux;
				break;

			}
		}
	}

	if (flag == 0) {

		printf(
				"El número de SERIE ingresado no corresponde a ningún Electrodoméstico \n");
	}

	return ret;

}

/**
 * Busca un id en el Array de Marca
 * y lo devuelve mediante puntero
 * @param array puntero a array marca
 * @param length largo del array
 * @param id puntero a Id encontrado
 * @return 0 Éxito -1 Error
 */
int marca_validarId(Marca *array, int length, int *id) {

	int ret = -1;

	int idAux;
	int indice;

	if (utn_getNumero(&idAux, "Ingrese el ID de la Marca \n",
			"Ingreso Invalido \n", MIN_IDMARCA, MAX_IDMARCA, 2) == 0) {

		if (marca_buscarId(array, length, idAux, &indice) == 0) {

			ret = 0;
			*id = idAux;

		}

	}

	return ret;

}

/**
 * Busca un id en el array de Marca y devuelve la posicion
 * donde se encuentra
 * @param array
 * @param length
 * @param id
 * @param indice
 * @return
 */
int marca_buscarId(Marca *array, int length, int id, int *indice) {

	int ret = -1;

	if (array != NULL && length > 0 && id >= MIN_ID) {

		for (int i = 0; i < length; i++) {

			if (array[i].isEmpty == 0 && array[i].id == id) {

				ret = 0;

				*indice = i;

				printf("Se eligió:\n %10s  %20s \n", "ID", "MARCA");

				marca_imprimir(&array[i]);

				printf(
						"---------------------------------------------------------------------------------------------\n");

				break;

			}

		}
	}

	return ret;
}

/**
 * Actualiza uno de los datos del Electrodomestico
 * en el array, verificando si existe su id
 * @param list puntero al array
 * @param len longitud del array
 * @return 0 Éxito -1 Error
 */
int electro_modificar(Electrodomestico *array, int length, Marca *arrayM,
		int lengthM) {

	int ret = -1;
	int indice = -1;
	int opcion;
	char idError[] = "No existe el Id seleccionado \n";

	int serie;
	int anio;
	int id;

	if (array != NULL && length > 0
			&& utn_getNumero(&id,
					"Ingrese el Id del Electrodomestico a modificar \n",
					"Número inválido \n", 0, 1000, 2) == 0) {

		electro_buscarId(array, QTY_ELECTRODOMESTICOS, id, &indice);

		if (indice != -1

		&& electro_imprimirPorId(array, length, arrayM, lengthM, id) == 0

		&& utn_getNumero(&opcion, "Ingrese el número correspondiente a la opción: "
			"\n 1-Modificar SERIE ""\n 2-Modificar MODELO(AÑO) \n", "Opción inválida \n",
			1, 2, 2) == 0) {

			switch (opcion) {

			case 1:

				if (utn_getNumero(&serie, "Ingrese nuevo número de Serie \n",
						"Ingreso inválido \n", 1, MAX_NUMSERIE, 2) == 0) {

					array[indice].serie = serie;

					ret = 0;
				}

				break;

			case 2:

				if (utn_getNumero(&anio, "Ingrese MODELO (AÑO)\n",
						"Número fuera de rango", MIN_ANIO, MAX_ANIO, 2) == 0) {

					array[indice].anio = anio;

					ret = 0;
				}

				break;
			}
		}

		else if (indice == -1) {
			(printf("%s", idError));
		}
	}

	return ret;
}

/**
 * Pide un Electrodomestico del array a eliminar por id,
 * verifica que existe y pone la bandera Is Empty en 1
 * @param list puntero al array
 * @param len largo del array
 * @return
 */

int electro_baja(Electrodomestico *array, int length, Marca *arrayM,
		int lengthM) {

	int option = 2; // Cancelar

	int ret = -1;

	int id;

	int indice = -1;

	char cancel[] = "Se canceló la operación \n";

	char idError[] = "No existe el Id seleccionado \n";

	if (array != NULL && length > 0
			&& utn_getNumero(&id,
					"Ingrese el Id del Electrodoméstico a borrar \n",
					"Número inválido \n", MIN_ID, MAX_ID, 2) == 0) {

		electro_buscarId(array, QTY_ELECTRODOMESTICOS, id, &indice);

		if (indice != -1

		&& electro_imprimirPorId(array, length, arrayM, lengthM, id) == 0

				&& utn_getNumero(&option, "Ingrese: 1 para BORRAR - "
						"2 para CANCELAR OPERACIÓN \n", "Opción inválida \n", 1,
						2, 2) == 0 && option == 1) {

			array[indice].isEmpty = 1;

			ret = 0;

		}

		else if (indice == -1) {
			printf("%s", idError);
		}

		else if (option != 1) {

			printf("%s", cancel);
		}

	}
	return ret;
}

/**
 * Ordena los elementos del array Electrodomestico
 * de manera ascendente en base a Año y Serie
 * @param array puntero a array
 * @param largo del array
 * @return 0 Éxito -1 Error
 *
 */

int electro_ordenar(Electrodomestico *array, int length) {

	int ret = -1;
	int flagSwap;
	Electrodomestico buffer;

	do {

		flagSwap = 0;

		for (int i = 0; i < length - 1; i++) {

			if (array[i].anio > array[i + 1].anio
					|| (array[i].anio == array[i + 1].anio
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

/**
 * Inserta un Electrodomestico en el array Electrodomesticos
 * con los datos ya cargados
 * @param array Puntero al array
 * @param length Largo del array
 * @return 0 Éxito -1 Error
 */

int electro_altaForzada(Electrodomestico *array, int length) {

	int ret = -1;

	if (array != NULL && length > 0) {

		int serie[3] = { 1400, 2345, 1234 };
		int idMarca[3] = { 1000, 1001, 1002 };
		int anio[3] = { 2005, 1990, 1990 };
		int id[3] = { 1, 15, 35 };

		for (int i = 0; i < 3; i++) {

			array[i].serie = serie[i];
			array[i].idMarca = idMarca[i];
			array[i].anio = anio[i];
			array[i].id = id[i];
			array[i].isEmpty = 0;

		}

		ret = 0;

	}

	return ret;

}

int marca_hardcodeo(Marca *array, int length, int *id) {

	int ret = -1;

	if (array != NULL && length > 0) {

		char descripcion[5][MAX_DESC_MARCA] = { "Wirpool", "Sony", "Liliana", "Gafa", "Philips" };

		for (int i = 0; i < 5; i++) {

			strncpy(array[i].descripcion, descripcion[i], MAX_DESC_MARCA);
			array[i].id = *id;
			array[i].isEmpty = 0;
			(*id)++;

		}

		ret = 0;

	}

	return ret;
}

