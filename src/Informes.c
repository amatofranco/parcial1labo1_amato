#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cliente.h"
#include "Reparacion.h"
#include "Electrodomestico.h"
#include "utn_inputs.h"

int idServicioPorDescripcion(char *descripcion, Servicio *array, int len,
		int *idServicio) {

	int retorno = -1;
	int i;

	if (array != NULL && len > 0 && descripcion != NULL) {

		for (i = 0; i < len; i++) {
			if (strcmp(array[i].descripcion, descripcion) == 0) {
				*idServicio = array[i].id;
				retorno = 0;

				break;
			}
		}
	}

	return retorno;
}

int cargarDescripcionServicioPorId(int idServicio, Servicio *array, int length,
		char *descripcion) {
	int retorno = -1;
	int i;

	if (array != NULL && length > 0 && descripcion != NULL) {
		for (i = 0; i < length; i++) {
			if (array[i].id == idServicio) {
				strncpy(descripcion, array[i].descripcion, MAX_DESC_SERV);
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int informarPorServicio(Reparacion *array, int lengthR,
		Electrodomestico *arrayE, int lengthE, Marca *arrayM, int lengthM,
		Servicio *arrayS, int lengthS, Cliente *arrayC, int lengthC) {

	int ret = -1;

	int idMarca;

	char descMarca[MAX_DESC_MARCA];

	char descServicio[MAX_DESC_SERV];

	char nombre[MAX_NOMRBRE];

	char apellido[MAX_APELLIDO];

	float precio;

	int idServicio;

	int flag = 0;

	int cont = 0;

	if (array != NULL && lengthR > 0) {

		servicio_imprimirArray(arrayS, lengthS);

		if (utn_getNumero(&idServicio,
				"Ingrese el ID del Servicio a informar \n",
				"Ingreso inválido \n", MIN_IDSERV, MAX_IDSERV, 2) == 0) {

			reparacion_ordenarPorServicio(array, lengthR);

			printf(
					"------------------------------------------------------------------------------------------------------------------------------------------\n");

			printf("%5s  %20s  %15s   %10s  %15s   %10s  %20s \n", "ID",
					"CLIENTE", "SERVICIO", "MARCA", "SERIE", "PRECIO", "FECHA");

			for (int i = 0; i < lengthR; i++) {

				if (array[i].isEmpty == 0
						&& array[i].idServicio == idServicio) {

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

					reparacion_imprimir(&array[i], descMarca, descServicio,
							nombre, apellido, precio);

					flag = 1;

					cont++;

				}

			}

			printf(
					"------------------------------------------------------------------------------------------------------------------------------------------\n");

		}

	}

	if (flag != 0) {

		printf("Se registraron %d servicios de %s \n", cont, descServicio);

		ret = 0;

	} else {

		printf("No se registran cargas relacionadas al Servicio elegido \n");
	}

	return ret;
}

int informarCantidadServicios(Reparacion *array, int lengthR,
		Electrodomestico *arrayE, int lengthE, Marca *arrayM, int lengthM,
		Servicio *arrayS, int lengthS, Cliente *arrayC, int lengthC) {

	int ret = -1;

	int idMarca;

	char descMarca[MAX_DESC_MARCA];

	char descServicio[MAX_DESC_SERV];

	char nombre[MAX_NOMRBRE];

	char apellido[MAX_APELLIDO];

	float precio;

	int cont = 0;

	if (array != NULL && lengthR > 0) {

		reparacion_ordenarPorServicio(array, lengthR);

		for (int i = 0; i < lengthS; i++) {

			servicio_descripcionPorId(descServicio, arrayS, lengthS,
					arrayS[i].id);

			printf("Servicio: %s  \n", descServicio);

			printf(
					"------------------------------------------------------------------------------------------------------------------------------------------\n");

			printf("%5s  %20s  %15s   %10s  %15s   %10s  %20s \n", "ID",
					"CLIENTE", "SERVICIO", "MARCA", "SERIE", "PRECIO", "FECHA");

			for (int j = 0; j < lengthR; j++) {

				if (array[j].isEmpty == 0
						&& array[j].idServicio == arrayS[i].id) {

					electro_marcaPorSerie(&idMarca, arrayE, lengthE,
							array[j].serie);

					marca_descripcionPorId(descMarca, arrayM, lengthM, idMarca);

					servicio_descripcionPorId(descServicio, arrayS, lengthS,
							array[j].idServicio);

					servicio_precioPorId(&precio, arrayS, lengthS,
							array[j].idServicio);

					reparacion_nombreClientePorId(nombre, arrayC, lengthC,
							array[j].idCliente);
					reparacion_apellidoClientePorId(apellido, arrayC, lengthC,
							array[j].idCliente);

					reparacion_imprimir(&array[j], descMarca, descServicio,
							nombre, apellido, precio);

					cont++;

				}
			}

			printf(
					"-----------------------------------------------------------------------------------------------------------------------------------------\n");
			printf("Cantidad: %d \n", cont);

			printf(
					"------------------------------------------------------------------------------------------------------------------------------------------\n");

			cont = 0;

		}

		ret = 0;

	}
	return ret;
}

int informarCantidadPorServicio(Reparacion *array, int lengthR,
		Electrodomestico *arrayE, int lengthE, Marca *arrayM, int lengthM,
		Servicio *arrayS, int lengthS, Cliente *arrayC, int lengthC) {

	int ret = -1;

	int idMarca;

	char descMarca[MAX_DESC_MARCA];

	char descServicio[MAX_DESC_SERV];

	char nombre[MAX_NOMRBRE];

	char apellido[MAX_APELLIDO];

	float precio;

	int flag = 0;

	int cont = 0;

	if (array != NULL && lengthR > 0) {

		servicio_imprimirArray(arrayS, lengthS);

		if (utn_getTexto(descServicio,
				"Ingrese la descripcion del SERVICIO a Informar \n",
				"Ingreso inválido \n", 1, MAX_DESC_SERV, 2) == 0) {

			reparacion_ordenarPorServicio(array, lengthR);

			for (int i = 0; i < lengthS; i++) {

				if (strcmp(descServicio, arrayS[i].descripcion) == 0) {

					printf("Servicio: %s  \n", descServicio);

					printf(
							"------------------------------------------------------------------------------------------------------------------------------------------\n");

					printf("%5s  %20s  %15s   %10s  %15s   %10s  %20s \n", "ID",
							"CLIENTE", "SERVICIO", "MARCA", "SERIE", "PRECIO",
							"FECHA");

					for (int j = 0; j < lengthR; j++) {

						if (array[j].isEmpty == 0
								&& array[j].idServicio == arrayS[i].id) {

							electro_marcaPorSerie(&idMarca, arrayE, lengthE,
									array[j].serie);

							marca_descripcionPorId(descMarca, arrayM, lengthM,
									idMarca);

							servicio_descripcionPorId(descServicio, arrayS,
									lengthS, array[j].idServicio);

							servicio_precioPorId(&precio, arrayS, lengthS,
									array[j].idServicio);

							reparacion_nombreClientePorId(nombre, arrayC,
									lengthC, array[j].idCliente);
							reparacion_apellidoClientePorId(apellido, arrayC,
									lengthC, array[j].idCliente);

							reparacion_imprimir(&array[j], descMarca,
									descServicio, nombre, apellido, precio);

							cont++;

							flag = 1;

						}
					}

					printf(
							"-----------------------------------------------------------------------------------------------------------------------------------------\n");
					printf("Cantidad: %d \n", cont);

					printf(
							"------------------------------------------------------------------------------------------------------------------------------------------\n");

					cont = 0;

				}
			}

		}

		if (flag!=0){

			ret = 0;
		}

		else {
			printf("No se registran cargas del servicio elegido \n");
		}

	}
	return ret;
}

int informarPorMarca(Electrodomestico *array, int length, Marca *arrayM,
		int lengthM) {

	int ret = -1;

	int idMarca;

	char descripcion[MAX_DESC_MARCA];

	int flag = 0;

	if (array != NULL && length > 0) {

		marca_imprimirArray(arrayM, lengthM);

		if (utn_getNumero(&idMarca, "Ingrese el ID de la Marca a informar \n",
				"Ingreso inválido \n", MIN_IDMARCA, MAX_IDMARCA, 2) == 0) {

			printf(
					"---------------------------------------------------------------------------------------------\n");

			printf("%10s  %20s   %20s  %20s  \n", "ID", "SERIE", "MARCA",
					"MODELO");

			for (int i = 0; i < length; i++) {

				if (array[i].isEmpty == 0 && array[i].idMarca == idMarca) {

					marca_descripcionPorId(descripcion, arrayM, lengthM,
							array[i].idMarca);

					electro_imprimir(&array[i], descripcion);

					flag = 1;
				}

			}

			printf(
					"---------------------------------------------------------------------------------------------\n");
		}

		if (flag != 0) {

			ret = 0;

		} else {

			printf("No se registran cargas relacionadas a la Marca elegida \n");
		}

	}
	return ret;
}
