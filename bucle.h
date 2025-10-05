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


#ifndef BUCLE_H
#define BUCLE_H

#include <iostream>
#include <string>
#include <vector>


class Bucle {
  public:
    //Constructor por defecto
    Bucle() {}

    //Destructor
    ~Bucle() {}

    //Metodos
    void setBucles(std::string, int);
    std::vector<std::string> getNombreBucles(void) { return bucles_; }
    std::vector<int> getLineaBucles(void) { return linea_bucles_; }


  private:
    std::vector<std::string> bucles_;
    std::vector<int> linea_bucles_;
};

#endif