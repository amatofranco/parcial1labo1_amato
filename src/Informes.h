/*
 * Informes.h
 *
 *  Created on: Oct 20, 2020
 *      Author: francoamato
 */

#ifndef INFORMES_H_
#define INFORMES_H_

int informar_electro2020(Electrodomestico *array, int length, Marca *arrayM,int lengthM);

int informar_electroPorMarca(Electrodomestico *array, int length, Marca *arrayM,int lengthM);


int informar_repaPorElectro(Reparacion *array, int lengthR, Electrodomestico *arrayE, int lengthE, Marca *arrayM, int lengthM,
Servicio *arrayS, int lengthS, Cliente *arrayC, int lengthC);

int informar_electroSinRepa(Reparacion *array, int lengthR,Electrodomestico *arrayE, int lengthE, Marca *arrayM, int lengthM);

int informar_importePorElectro(Reparacion *array, int lengthR, Electrodomestico *arrayE, int lengthE, Marca *arrayM, int lengthM, Servicio *arrayS, int lengthS, Cliente *arrayC, int lengthC);

int informar_cantidadServicios(Reparacion *array, int lengthR,Electrodomestico *arrayE, int lengthE, Marca *arrayM, int lengthM,
Servicio *arrayS, int lengthS, Cliente *arrayC, int lengthC);
//////////////////////////////////////////////////////////////////////////
int idServicioPorDescripcion(char *descripcion, Servicio *array, int len,
		int *idServicio);

int informarPorServicio(Reparacion *array, int lengthR,
		Electrodomestico *arrayE, int lengthE, Marca *arrayM, int lengthM,
		Servicio *arrayS, int lengthS, Cliente *arrayC, int lengthC);



int cargarDescripcionServicioPorId(int idServicio, Servicio *array, int length,
		char *descripcion);



int informarCantidadPorServicio(Reparacion *array, int lengthR,
		Electrodomestico *arrayE, int lengthE, Marca *arrayM, int lengthM,
		Servicio *arrayS, int lengthS, Cliente *arrayC, int lengthC);




#endif /* INFORMES_H_ */
