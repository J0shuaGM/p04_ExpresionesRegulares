// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expreciones regulares
// Autor: Joshua Gomez Marrero
// Correo: alu0101477398@ull.edu.es
// Fecha: 5/10/2025
// Archivo almacenamiento.h: definicion de la clase almacenamiento
// Contiene la definicion de la clase almacenamiento


#ifndef VARIABLES_H
#define VARIABLES_H

#include <iostream>
#include <string>
#include <vector>


class Variables {
  public:
    //Constructor por defecto
    Variables() {}

    //Destructor
    ~Variables() {}

    //Metodos
    void setVariables(std::string, int);
    std::vector<std::string> getVariables(void) { return variables_; }
    std::vector<int> getLineaVariables(void) { return linea_variables_; }

  private:
    std::vector<std::string> variables_;
    std::vector<int> linea_variables_;
};

#endif