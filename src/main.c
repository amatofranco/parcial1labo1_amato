/*
 ============================================================================
 Name        : PARCIAL LABORATORIO 1
 Author      : FRANCO AMATO
 Version     : 1.0
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_inputs.h"
#include "Electrodomestico.h"
#include "Reparacion.h"
#include "Cliente.h"
#include "Informes.h"

// Imprime mensaje error

void mensajeError();

// Imprime mensaje de operación exitosa

void mensajeExito();

// Imprime mensaje de array vacío
void emptyArray();

int main(void) {

	Electrodomestico arrayElectro[QTY_ELECTRODOMESTICOS];
	Marca arrayMarcas[QTY_MARCAS];
	Reparacion arrayReparaciones[QTY_REPARACIONES];
	Servicio arrayServicios[QTY_SERVICIOS];
	Cliente arrayClientes[QTY_CLIENTES];

	int idMarca = MIN_IDMARCA;
	int idRepa = MIN_ID;
	int idServ = MIN_IDSERV;
	int idCliente = MIN_ID_CLIENTE;
	int opcion;
	int ret;

	electro_iniciar(arrayElectro, QTY_ELECTRODOMESTICOS);
	marca_iniciar(arrayMarcas, QTY_MARCAS);
	servicio_iniciar(arrayServicios, QTY_SERVICIOS);
	cliente_iniciar(arrayClientes, QTY_CLIENTES);
	reparacion_iniciar(arrayReparaciones, QTY_REPARACIONES);

	marca_hardcodeo(arrayMarcas, QTY_MARCAS, &idMarca);
	servicio_hardcodeo(arrayServicios, QTY_SERVICIOS, &idServ);
	cliente_hardcodeo(arrayClientes, QTY_CLIENTES, &idCliente);

	electro_altaForzada(arrayElectro, QTY_ELECTRODOMESTICOS);
	reparacion_altaForzada(arrayReparaciones, QTY_REPARACIONES, &idRepa);

	do {

		ret = utn_getNumero(&opcion, "Seleccione una opción: \n"
				"1- Alta Electrodomestico \n"
				"2- Modificar Electrodomestico \n"
				"3- Baja Electrodomestico \n"
				"4- Imprimir Listado Electrodomesticos \n"
				"5- Imprimir Listado Marcas \n"
				"6- Imprimir Listado Servicios \n"
				"7- Imprimir Listado Clientes \n"
				"8- Alta Reparacion \n"
				"9- Imprimir Listado Reparaciones \n"
				"10- Informar Electrodomésticos por Marca \n"
				"11- Informar Reparaciones por Servicio \n"
				"12 -Informar Cantidad por Servicio \n"
				"13- Informar Cantidad Total por Servicio \n"
				"14- Salir \n", "Opción no válida  \n", 1, 14, 2);

		if (ret == 0) {

			switch (opcion) {

			case 1:

				marca_imprimirArray(arrayMarcas, QTY_MARCAS);

				if (electro_alta(arrayElectro, QTY_ELECTRODOMESTICOS,
						arrayMarcas, QTY_MARCAS) == 0) {
					mensajeExito();
				} else {
					mensajeError();
				}
				break;

			case 2:

				if (!electro_emptyArray(arrayElectro, QTY_ELECTRODOMESTICOS)) {

					electro_imprimirArray(arrayElectro, QTY_ELECTRODOMESTICOS,
							arrayMarcas, QTY_MARCAS);

					if (electro_modificar(arrayElectro, QTY_ELECTRODOMESTICOS,
							arrayMarcas, QTY_MARCAS) == 0) {

						mensajeExito();
					}

					else {

						mensajeError();
					}
				}

				else {

					emptyArray();
				}

				break;

			case 3:

				if (!electro_emptyArray(arrayElectro, QTY_ELECTRODOMESTICOS)) {

					electro_imprimirArray(arrayElectro, QTY_ELECTRODOMESTICOS,
							arrayMarcas, QTY_MARCAS);

					if (electro_baja(arrayElectro, QTY_ELECTRODOMESTICOS,
							arrayMarcas, QTY_MARCAS) == 0) {

						mensajeExito();
					}

					else {

						mensajeError();
					}
				}

				else {
					emptyArray();
				}

				break;

			case 4:

				if (!electro_emptyArray(arrayElectro, QTY_ELECTRODOMESTICOS)) {

					electro_ordenar(arrayElectro, QTY_ELECTRODOMESTICOS);

					if (electro_imprimirArray(arrayElectro,
					QTY_ELECTRODOMESTICOS, arrayMarcas, QTY_MARCAS) == 0) { //

						mensajeExito();
					}

					else {

						mensajeError();
					}
				}

				else {
					emptyArray();
				}
				break;

			case 5:

				marca_imprimirArray(arrayMarcas, QTY_MARCAS);

				break;

			case 6:

				servicio_imprimirArray(arrayServicios, QTY_SERVICIOS);

				break;

			case 7:

				cliente_imprimirArray(arrayClientes, QTY_CLIENTES);
				break;

			case 8:

				if (!electro_emptyArray(arrayElectro, QTY_ELECTRODOMESTICOS)) {

					if (reparacion_alta(arrayReparaciones, QTY_REPARACIONES,
							arrayClientes, QTY_CLIENTES, arrayServicios,
							QTY_SERVICIOS, arrayElectro, QTY_ELECTRODOMESTICOS,
							arrayMarcas, QTY_MARCAS, &idRepa) == 0) {

						mensajeExito();

					}

					else {
						mensajeError();
					}
				}

				else{

				printf("Aún no se registran cargas de Electrodomésticos para dar de alta una Reparación. \n");
				}

				break;

			case 9:

				if (!reparacion_emptyArray(arrayReparaciones,
				QTY_REPARACIONES)) {

					if (reparacion_imprimirArray(arrayReparaciones,
							QTY_REPARACIONES, arrayElectro,
							QTY_ELECTRODOMESTICOS, arrayMarcas, QTY_MARCAS,
							arrayServicios, QTY_SERVICIOS, arrayClientes,
							QTY_CLIENTES) == 0) {
						mensajeExito();
					} else {
						mensajeError();
					}
				}

				else {

					emptyArray();
				}
				break;

			case 10:

				if (informarPorMarca(arrayElectro, QTY_ELECTRODOMESTICOS,
						arrayMarcas, QTY_MARCAS) == 0) {

					mensajeExito();
				} else {
					mensajeError();

				}

				break;

			case 11:
				if (informarPorServicio(arrayReparaciones, QTY_REPARACIONES,
						arrayElectro, QTY_ELECTRODOMESTICOS, arrayMarcas,
						QTY_MARCAS, arrayServicios, QTY_SERVICIOS,
						arrayClientes, QTY_CLIENTES) == 0) {
					mensajeExito();
				} else {
					mensajeError();
				}
				break;

			case 12:

				if (informarCantidadPorServicio(arrayReparaciones,
						QTY_REPARACIONES, arrayElectro, QTY_ELECTRODOMESTICOS,
						arrayMarcas,
						QTY_MARCAS, arrayServicios, QTY_SERVICIOS,
						arrayClientes, QTY_CLIENTES) == 0) {
					mensajeExito();
				} else {
					mensajeError();
				}
				break;

			case 13:

				if (informarCantidadServicios(arrayReparaciones,
						QTY_REPARACIONES, arrayElectro, QTY_ELECTRODOMESTICOS,
						arrayMarcas,
						QTY_MARCAS, arrayServicios, QTY_SERVICIOS,
						arrayClientes, QTY_CLIENTES) == 0) {
					mensajeExito();
				} else {
					mensajeError();
				}
				break;

			case 14:
				printf("Saliendo del programa \n");
			}

		} else {
			mensajeError();
		}

	} while (opcion != 14);

	return EXIT_SUCCESS;

}

void mensajeError() {

	char mensaje[] = "No se pudo completar la operación. Se redigirá al menú \n";

	printf("%s", mensaje);

}

void mensajeExito() {

	char mensaje[] = "Operación exitosa \n";

	printf("%s", mensaje);

}

void emptyArray() {

	char mensaje[] = "No se registran cargas. Se redigirá al menú. \n";

	printf("%s", mensaje);

}

