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

#include "almacenamiento.h"
#include "comentarios.h"
#include "bucle.h"
#include "variables.h"


/**
 * @brief Metoodo que almacena el nombre del fichero
 * @param nombre_fichero Nombre del fichero
*/
void Almacenamiento::setNombre(std::string nombre_fichero) {
  nombre_fichero_ = nombre_fichero;
}



/**
 * @brief Metodo que declara si existe o no una función main en el fichero
 * @param main Variable booleana que define si existe una funcion main en el fichero
*/
void Almacenamiento::setMain(bool main) {
  main_ = main;
}



/**
 * @brief Sobrecarga del operador de insercion
 * @param salida variable que contiene la salida de la escritura
 * @param almacen variable a ser escrita
*/
std::ostream& operator<<(std::ostream& salida, Almacenamiento almacen) {
  Comentario comentarios = almacen.getComentarios();
  Variables variables = almacen.getVariables();
  Bucle bucles = almacen.getBucle();

  salida << "PROGRAM: " << almacen.nombre_fichero_ << std::endl;
  salida << "DESCRIPTION: \n";
  if (!comentarios.getComentarios().empty()) {
    salida << comentarios.getComentarios()[0] << std::endl;
  }
  salida << "VARIABLES: \n";
  for(auto i = 0; i < variables.getVariables().size(); ++i) {
    salida << "[Line " << variables.getLineaVariables()[i] << "] ";
    std::istringstream stream(variables.getVariables()[i]);
    std::string tipo, nombre, declaracion;
    stream >> tipo >> nombre; 
    std::getline(stream, declaracion);
    if (!declaracion.empty() && declaracion.back() == ';') declaracion.pop_back();
    std::transform(tipo.begin(), tipo.end(), tipo.begin(), ::toupper);
    salida << tipo << ": " << nombre << declaracion << std::endl;
  }
  salida << std::endl;
  salida << "STATEMENTS: \n";
  for(auto i = 0; i < bucles.getNombreBucles().size(); ++i) {
    salida << "[Line " << bucles.getLineaBucles()[i] << "] LOOP: " << bucles.getNombreBucles()[i] << "\n";
  }
  salida << std::endl;
  salida << "MAIN: \n";
  if(almacen.main_ == true) {
    salida << "TRUE \n";
  } else {
    salida << "FALSE \n";
  }
  salida << std::endl;
  salida << "COMMENTS: \n";
  for(auto i = 0; i < comentarios.getLineaComentarios().size(); ++i) {
    if (i == 0) {
      salida << "[Line 1-" << comentarios.getLineaComentarios()[i] << "] DESCRIPTION \n";
    } else {
      // Imprimir el texto del comentario en vez del número de línea dos veces
      if (i < comentarios.getComentarios().size()) {
        salida << "[Line " << comentarios.getLineaComentarios()[i] << "] " << comentarios.getComentarios()[i] << "\n";
      }
    }
  }
  return salida;
}