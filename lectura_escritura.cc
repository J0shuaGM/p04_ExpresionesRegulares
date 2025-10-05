// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expreciones regulares
// Autor: Joshua Gomez Marrero
// Correo: alu0101477398@ull.edu.es
// Fecha: 5/10/2025
// Archivo lectura.cc: declaracion de las funciones 
// Contiene la declaracion de las funciones usadas para leer y escribir en los ficheros de texto

#include <iostream>
#include <string> 
#include <fstream>
#include <regex>

#include "lectura_escritura.h"
#include "almacenamiento.h"
#include "comentarios.h"
#include "bucle.h"
#include "variables.h"



/**
 * @brief Función que lee y clasifica la informacion contenida en un fichero
 * @param fichero_entrada Cadena que contiene el nombre del fichero que sera analizado
 * @param fichero_salida Cadena que contiene el nombre del fichero de salida
*/
Almacenamiento lectura(std::string fichero_entrada, std::string fichero_salida) {

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
  std::regex variables("\\s+int|double\\s+[a-zA-Z0-9]+\\s*;"); // Detectar las diferentes variables
  std::regex buclesfor("\\bfor\\s*\\(.*\\)"); // Detectar los bucles for
  std::regex bucleswhile("\\bwhile\\s*\\(.*\\)"); // Detectar los bucles while
  std::regex main("int main"); //Detectar si existe una función mainxº

  std::smatch coincidencias;
  Almacenamiento almacen;
  Comentario comentario; 
  Variables variable;
  Bucle bucles;

  almacen.setNombre(fichero_entrada);

  while(std::getline(input, linea)) {
    ++contador;

    //Busqueda de comentarios multilinea
    if(dentro_de_comentario) {
      comentarios_encontrados += linea + "\n";
      if(std::regex_search(linea, fin_comentario)) {
        dentro_de_comentario = false; 
        comentario.setComentarios(comentarios_encontrados, contador);
      }
      continue; // Saltar el resto de análisis si estamos dentro de comentario
    }
    //Busqueda de comentarios simples
    if(std::regex_search(linea, comentario_simple)) {
      comentario.setComentarios(linea, contador);
      continue;
    }
    if (std::regex_search(linea, inicio_comentario)) {
      dentro_de_comentario = true;
      comentarios_encontrados = linea + "\n";
      continue;
    }
    if (std::regex_search(linea, variables)) { //Busqueda de variables 
      variable.setVariables(linea, contador);
    } else if (std::regex_search(linea, coincidencias, buclesfor)) {  //Busqueda de bucles for
      bucles.setBucles("for", contador);
    } else if (std::regex_search(linea, coincidencias, bucleswhile)) { //Busqueda de bucles while
      bucles.setBucles("while", contador);
    } else if (std::regex_search(linea, coincidencias, main)) { //Busqueda de funcion main
      almacen.setMain(true);
    } 
  }
  // Guardar los objetos en almacen
  almacen.setVariables(variable); 
  almacen.setBulces(bucles); 
  almacen.setComentarios(comentario);
  return almacen;
}



/**
 * @brief Funcion que escribe en el fichero de salida
 * @param fichero_salida Cadena que contiene el nombre del fichero donde se va a escribir
 * @param almacen Variabel que contiene toda la información a ser escrita
*/
void escritura(std::string ficher_salida, Almacenamiento almacen) {
  std::ofstream out(ficher_salida); 
  if (!out.is_open()) {
    std::cerr << "El fichero de salida no se ha podido abrir" << std::endl;
    exit(EXIT_FAILURE);
  } 
  out << almacen;
}