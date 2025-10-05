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

#include "comentarios.h"

/**
 * @brief Metodo que almacena los comentarios encontrados en un fichero
 * @param comentario Cadena que contiene los comnetarios encontrados en el fichero
 * @param numero_liena Entero que contiene el numero de linea en la que se encuentra el comentario
*/
void Comentario::setComentarios(std::string comentario, int numero_linea) {
  comentarios_.push_back(comentario); 
  linea_comentarios_.push_back(numero_linea);
}
