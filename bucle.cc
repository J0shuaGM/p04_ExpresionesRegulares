// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expreciones regulares
// Autor: Joshua Gomez Marrero
// Correo: alu0101477398@ull.edu.es
// Fecha: 5/10/2025
// Archivo almacenamiento.cc: declaracion de la clase almacenamiento
// Contiene la declaracion de la clase almacenamiento

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "bucle.h"

/**
 * @brief Metodo que almacena los bucles encontrados en el fichero
 * @param bucle Cadena que contiene el tipo de bucle
 * @param numero_linea Eneto que contiene el numero de linea en la que se encuentra el bucle
*/
void Bucle::setBucles(std::string bucle, int numero_linea) {
  bucles_.push_back(bucle);
  linea_bucles_.push_back(numero_linea);
}
