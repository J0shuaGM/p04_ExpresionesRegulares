// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expreciones regulares
// Autor: Joshua Gomez Marrero
// Correo: alu0101477398@ull.edu.es
// Fecha: 17/09/2024
// Archivo lectura.cc: declaracion de las funciones 
// Contiene la declaracion de las funciones usadas para leer y escribir en los ficheros de texto
// para ... (indicar brevemente el objetivo)
// Referencias:
// Enlaces de interes
// Historial de revisiones
// 17/09/2024 - Creacion (primera version) del codigo 

#include <iostream>
#include <string> 
#include <fstream>
#include <regex>

#include "lectura.h"
#include "almacenamiento.h"

void lectura(std::string fichero_entrada) {

  std::ifstream input(fichero_entrada);

  if (!input.is_open()) {
    std::cerr << "El fichero de entrada no se ha podido abrir" << std::endl;
    exit(EXIT_FAILURE);
  }

  std::string linea;
  std::string comentarios_encontrados;
  int contador{0};
  bool dentro_de_comentario = false;  // Flag para comentarios multilinea

  // Expresiones regulares
  std::regex inicio_comentario("/\\*");  // Detectar el inicio de comentario
  std::regex fin_comentario("\\*/");     // Detectar el fin del comentario
  std::regex comentario_simple("//.+"); // Detectar comentarios de una linea
  std::regex variables("\\s*(int|double)\\s+[a-zA-Z_][a-zA-Z0-9_]*\\s*"); 
  std::regex bucles("for|while"); 
  std::regex main("int main");

  std::smatch coincidencias;
  Almacenamiento almacen;

  while(std::getline(input, linea)) {
    //Busqueda de comentarios multilinea
    if(dentro_de_comentario) {
      comentarios_encontrados += linea + "\n";
      ++contador;
      if(std::regex_search(linea, fin_comentario)) {
        dentro_de_comentario = false; 
        almacen.setComentarios(comentarios_encontrados, contador);
      }
    }
    if (std::regex_search(linea, inicio_comentario)) {
      dentro_de_comentario = true;
      comentarios_encontrados = linea + "\n";
    }
    //Busqueda de variables
    if (std::regex_search(linea, coincidencias, variables)) {
      ++contador; 
      almacen.setVariables(linea, contador);
    }
    //Busqueda de bucles
    if (std::regex_search(linea, coincidencias, bucles)) {
      ++contador; 
      almacen.setBucles(linea, contador);
    }
    //Busqueda del main
    if (std::regex_search(linea, coincidencias, main)) {
      ++contador; 
      almacen.setMain(true, contador);
    }
  }
  std::cout << almacen << std::endl;
}
