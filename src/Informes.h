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

int informar_importePorFecha(Reparacion *array, int lengthR,
		Electrodomestico *arrayE, int lengthE, Marca *arrayM, int lengthM,
		Servicio *arrayS, int lengthS, Cliente *arrayC, int lengthC);



int informar_electroGarantia (Reparacion *array, int lengthR,
		Electrodomestico *arrayE, int lengthE, Marca *arrayM, int lengthM,
		Servicio *arrayS, int lengthS, Cliente *arrayC, int lengthC);

int informar_repaElectro2018(Reparacion *array, int lengthR,
		Electrodomestico *arrayE, int lengthE, Marca *arrayM, int lengthM,
		Servicio *arrayS, int lengthS, Cliente *arrayC, int lengthC);

int informar_importePorMantenimiento(Reparacion *array, int lengthR,
		Electrodomestico *arrayE, int lengthE, Marca *arrayM, int lengthM,
		Servicio *arrayS, int lengthS, Cliente *arrayC, int lengthC);

int informar_cantidadRefacciones(Reparacion *array, int lengthR,
		Electrodomestico *arrayE, int lengthE, Marca *arrayM, int lengthM,
		Servicio *arrayS, int lengthS, Cliente *arrayC, int lengthC);
//////////////////////////////////////////////////////////////////////////


#endif /* INFORMES_H_ */
