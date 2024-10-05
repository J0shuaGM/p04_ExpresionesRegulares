// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expreciones regulares
// Autor: Joshua Gomez Marrero
// Correo: alu0101477398@ull.edu.es
// Fecha: 17/09/2024
// Archivo almacenamiento.cc: declaracion de la clase almacenamiento
// Contiene la declaracion de la clase almacenamiento
// para ... (indicar brevemente el objetivo)
// Referencias:
// Enlaces de interes
// Historial de revisiones
// 17/09/2024 - Creacion (primera version) del codigo 

#include <iostream>
#include <string>
#include <fstream>

#include "almacenamiento.h"



void Almacenamiento::setVariables(std::string variables, int numero_linea) {
  variables_.push_back(variables);
  linea_variables_.push_back(numero_linea);
}



void Almacenamiento::setBucles(std::string bucle, int numero_linea) {
  bucles_.push_back(bucle);
  linea_bucles_.push_back(numero_linea);
}



void Almacenamiento::setMain(bool main, int numero_linea) {
  main_ = main;
  linea_main_ = numero_linea;
}



void Almacenamiento::setComentarios(std::string comentario, int numero_linea) {
  comentarios_.push_back(comentario); 
  linea_comentarios_.push_back(numero_linea);
}



std::ostream& operator<<(std::ostream& salida, Almacenamiento almacen) {
  salida << "DESCRIPTION: \n";
  salida << almacen.comentarios_[0];
  salida << "VARIABLES: \n";
  for(auto i = 0; i <= almacen.variables_.size(); ++i) {
    salida << "[Line " << almacen.linea_variables_[i] << "]" << almacen.variables_[i] << "\n";
  }
  salida << "STATEMENTS: \n";
  for(auto i = 0; i <= almacen.bucles_.size(); ++i) {
    salida << "[Line " << almacen.linea_bucles_[i] << "]" << almacen.bucles_[i] << "\n";
  }
  salida << "MAIN: \n";
  if(almacen.main_ == true) {
    salida << "TRUE \n";
  } else {
    salida << "FALSE \n";
  }
  salida << "COMMENTS: \n";
  for(auto i = 0; i <= almacen.linea_comentarios_.size(); ++i) {
    if (i == 0) {
      salida << "[Line 1-" << almacen.linea_comentarios_[i] << "] DESCRIPTION \n";
    } else {
      salida << "[Line " << almacen.linea_comentarios_[i] << "] " << almacen.comentarios_[i] << "\n"; 
    }
  }
  return salida;
}