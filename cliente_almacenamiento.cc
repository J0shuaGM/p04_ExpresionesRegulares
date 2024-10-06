// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Expreciones regulares
// Autor: Joshua Gomez Marrero
// Correo: alu0101477398@ull.edu.es
// Fecha: 17/09/2024
// Archivo cliente_almacenamientocch: programa cliente.
// Contiene la definicion del cliente
// para ... (indicar brevemente el objetivo)
// Referencias:
// Enlaces de interes
// Historial de revisiones
// 17/09/2024 - Creacion (primera version) del codigo 

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
  lectura(fichero_entrada, fichero_salida);
  return 0;
}