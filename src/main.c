/*
 ============================================================================
 Name        : parcial1laboratorio1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_inputs.h"
#include "Electrodomestico.h"
#include "Reparacion.h"

/**
 * Imprime mensaje error
 */
void mensajeError();

/**
 * Imprime mensaje de operación exitosa
 */
void mensajeExito();

/**
 * Imprime mensaje de array vacío
 */
void arrayVacio();

/**
 * Imprime mensaje de array completo
 */

void arrayCompleto();

int main(void) {

	Electrodomestico arrayElectro[QTY_ELECTRODOMESTICOS];

	Marca arrayMarcas[QTY_MARCAS];

	Reparacion arrayReparaciones[QTY_REPARACIONES];

	Servicio arrayServicios[QTY_SERVICIOS];

	Fecha arrayFechas[QTY_FECHAS];

	int idElectro = MIN_ID;
	int idMarca = MIN_IDMARCA;
	int idRepa = MIN_ID;
	int idServ = MIN_IDSERV;
	int opcion;
	int ret;
	int idAux;
	int indiceAux;
	int idServAux;
	int serieAux;

	Fecha fechaAux;

	if (electro_iniciar(arrayElectro, QTY_ELECTRODOMESTICOS) == 0) {
		printf("Electrodomesticos se inició correctamente \n");
	}

	if (marca_iniciar(arrayMarcas, QTY_MARCAS) == 0) {
		printf("Marcas se inició correctamente \n");
	}

	if (reparacion_iniciar(arrayReparaciones, QTY_REPARACIONES) == 0) {
		printf("Reparaciones se inició correctamente \n");
	}

	if (servicio_iniciar(arrayServicios, QTY_SERVICIOS) == 0) {
		printf("Servicio se inició correctamente \n");
	}

	if (fecha_iniciar(arrayFechas, QTY_FECHAS) == 0) {
		printf("Fecha se inició correctamente \n");
	}

	electro_altaForzada(arrayElectro, QTY_ELECTRODOMESTICOS, &idElectro, 124325,
			2005, 1001);
	electro_altaForzada(arrayElectro, QTY_ELECTRODOMESTICOS, &idElectro, 200214,
			1990, 1002);

	marca_altaForzada(arrayMarcas, QTY_MARCAS, &idMarca, "Whirpool");
	marca_altaForzada(arrayMarcas, QTY_MARCAS, &idMarca, "Sony");
	marca_altaForzada(arrayMarcas, QTY_MARCAS, &idMarca, "Liliana");
	marca_altaForzada(arrayMarcas, QTY_MARCAS, &idMarca, "Gafa");
	marca_altaForzada(arrayMarcas, QTY_MARCAS, &idMarca, "Philips");


	servicio_altaForzada(arrayServicios,QTY_SERVICIOS,"Garantía",250,&idServ);
	servicio_altaForzada(arrayServicios,QTY_SERVICIOS,"Mantenimiento",500,&idServ);
	servicio_altaForzada(arrayServicios,QTY_SERVICIOS,"Repuestos",400,&idServ);
	servicio_altaForzada(arrayServicios,QTY_SERVICIOS,"Refaccion",600,&idServ);

	/* reparacion_altaForzada(arrayReparaciones, QTY_REPARACIONES, &idRepa,
	 "A5453", 1040, 200000); */

	do {

		ret = utn_getNumero(&opcion, "Seleccione una opción \n "
				"1- Alta Electrodomestico \n "
				"2- Modificar Electrodomestico \n "
				"3- Baja Electrodomestico \n "
				"4- Imprimir Listado Electrodomesticos \n "
				"5- Imprimir Listado Marcas \n"
				"6- Imprimir Listado Servicios \n"
				"7- Alta Reparacion \n"
				"8- Imprimir Listado Reparaciones \n"
				"9- Salir \n", "Opción no válida  \n", 1, 10, 2);

		if (ret == 0) {

			switch (opcion) {

			case 1:

				marca_imprimirArray(arrayMarcas, QTY_MARCAS);

				if (marca_validarId(arrayMarcas, QTY_MARCAS, &idAux) == 0) {

					if (electro_alta(arrayElectro, QTY_ELECTRODOMESTICOS,
							&idElectro, idAux) == 0) {
						mensajeExito();
					} else {
						mensajeError();
					}
				}

				else {

					printf("No existe el ID seleccionado \n");
				}
				break;

			case 2:

				electro_imprimirArray(arrayElectro,QTY_ELECTRODOMESTICOS);

				if (electro_modificar(arrayElectro, QTY_ELECTRODOMESTICOS)
						== 0) {

					mensajeExito();
				}

				else {

					mensajeError();
				}

				break;

			case 3:

				if (electro_baja(arrayElectro, QTY_ELECTRODOMESTICOS) == 0) {

					mensajeExito();
				}

				else {

					mensajeError();
				}
				break;

			case 4:

				if (electro_imprimirArray(arrayElectro,
				QTY_ELECTRODOMESTICOS) == 0) { //

					mensajeExito();
				}

				else {

					mensajeError();
				}

				break;

			case 5:

				marca_imprimirArray(arrayMarcas, QTY_MARCAS);

				break;

			case 6:


				servicio_imprimirArray(arrayServicios,QTY_SERVICIOS);


				break;



			case 7:

				servicio_imprimirArray(arrayServicios,QTY_SERVICIOS);

				utn_getNumero(&idServAux,"Seleccione ID de servicio \n","Ingreso Inválido \n",MIN_IDSERV,MAX_IDSERV,2);

				servicio_buscarId(arrayServicios,QTY_SERVICIOS,idServAux,&indiceAux);

				electro_imprimirArray(arrayElectro,QTY_ELECTRODOMESTICOS);

				electro_validarSerie(arrayElectro,QTY_ELECTRODOMESTICOS,&serieAux);

				if (fecha_alta(arrayFechas, QTY_FECHAS, &fechaAux) == 0) {

					reparacion_alta(arrayReparaciones,QTY_REPARACIONES,&idRepa,idServAux,serieAux,fechaAux);
				} else {
					mensajeError();
				}

				break;

			case 8:

				if (reparacion_imprimirArray(arrayReparaciones,
				QTY_REPARACIONES) == 0) {
					mensajeExito();
				} else {
					mensajeError();
				}
				break;

			case 9:
				printf("Saliendo del programa");
			}

		} else {
			mensajeError();
		}

	} while (opcion != 10);

	return EXIT_SUCCESS;

}

void mensajeError() {

	char mensaje[] = "Se produjo un error. Se redigirá al menú \n";

	printf("%s", mensaje);

}

void mensajeExito() {

	char mensaje[] = "Operación exitosa \n";

	printf("%s", mensaje);

}

void arrayVacio() {

	char mensaje[] = "No se registra ninguna carga \n";

	printf("%s", mensaje);

}

void arrayCompleto() {

	char mensaje[] = "No hay mas lugar para realizar una carga \n";

	printf("%s", mensaje);

}
