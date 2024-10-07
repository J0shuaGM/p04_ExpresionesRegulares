// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expreciones regulares
// Autor: Joshua Gomez Marrero
// Correo: alu0101477398@ull.edu.es
// Fecha: 17/09/2024
// Archivo tools.cc: delcaracion de funciones
// Contiene la implementacion de las fundciones que no pertenecen a metodos
// para ... (indicar brevemente el objetivo)
// Referencias:
// Enlaces de interes
// Historial de revisiones
// 17/09/2024 - Creacion (primera version) del codigo

#include <iostream>
#include <string>

#include "tools.h"



/**
 * @brief Funcion que explica como usar este programa 
 * @param argc Numero de argumentos pasados por linea de comandos
 * @param agrv Las cadenas que han sido pasadas por linea de comandos
*/
void Usage(int argc, char *argv[]) {
  switch (argc)
  {
  case 1:
    std::cerr << argv[0] << " Modo de empleo: ./Expresiones Entrada.cc Salida.txt" << std::endl;
    std::cerr << "Use: " << argv[0] << " --help para mas información" << std::endl;
    break;
  
  case 2: 
    std::string parametro = argv[1];
    if (parametro == "--help") {
      std::cout << "Este programa analiza un fichero en c++ y escribe sus caracteristicas en un fichero detexto" << std::endl;
      std::cout << "Se necesita un fichero .cc de entrada y un fichero .txt de salida para poder ser ejecutado" << std::endl;
    }
    else {
    std::cerr << argv[0] << " Modo de empleo: ./Expreciones Entrada.cc Salida.txt" << std::endl;
    std::cerr << "Use: " << argv[0] << " --help para mas información" << std::endl;
    }
    break;
  }
}