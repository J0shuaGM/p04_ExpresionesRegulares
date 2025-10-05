// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Expreciones regulares
// Autor: Joshua Gomez Marrero
// Correo: alu0101477398@ull.edu.es
// Fecha: 5/10/2025
// Archivo cliente_almacenamientocch: programa cliente.
// Contiene la definicion del cliente


#include <iostream>
#include <fstream>
#include <string>

#include "tools.h"
#include "almacenamiento.h"
#include "lectura_escritura.h"

int main(int argc, char * argv[]) {
  Usage(argc, argv);
  std::string fichero_entrada = argv[1];
  std::string fichero_salida = argv[2];
  Almacenamiento almacen = lectura(fichero_entrada, fichero_salida);
  escritura(fichero_salida, almacen);
  return 0;
}