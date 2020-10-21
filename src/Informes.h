/*
 * Informes.h
 *
 *  Created on: Oct 20, 2020
 *      Author: francoamato
 */

#ifndef INFORMES_H_
#define INFORMES_H_

int idServicioPorDescripcion(char *descripcion, Servicio *array, int len,
		int *idServicio);

int informarPorServicio(Reparacion *array, int lengthR,
		Electrodomestico *arrayE, int lengthE, Marca *arrayM, int lengthM,
		Servicio *arrayS, int lengthS, Cliente *arrayC, int lengthC);

int informarPorMarca(Electrodomestico *array, int length, Marca *arrayM,
		int lengthM);

int cargarDescripcionServicioPorId(int idServicio, Servicio *array, int length,
		char *descripcion);

int informarCantidadServicios(Reparacion *array, int lengthR,
		Electrodomestico *arrayE, int lengthE, Marca *arrayM, int lengthM,
		Servicio *arrayS, int lengthS, Cliente *arrayC, int lengthC);

int informarCantidadPorServicio(Reparacion *array, int lengthR,
		Electrodomestico *arrayE, int lengthE, Marca *arrayM, int lengthM,
		Servicio *arrayS, int lengthS, Cliente *arrayC, int lengthC);


#endif /* INFORMES_H_ */
