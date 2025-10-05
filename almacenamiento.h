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


#ifndef ALMACENAMIENTO_H
#define ALMACENAMIENTO_H

#include <iostream>
#include <string>
#include <vector>

#include "comentarios.h"
#include "bucle.h"
#include "variables.h"

class Almacenamiento {
  public:
    //Constructor por defecto
    Almacenamiento() {}

    //Destructor
    ~Almacenamiento() {}

    //Getters y setters
    void setNombre(std::string);
    void setMain(bool);
    std::string getNombre(void) { return nombre_fichero_; }
    bool getMain(void) { return main_; }
    Comentario getComentarios(void) { return comentarios_; }
    Variables getVariables(void) { return variables_; }
    Bucle getBucle(void) { return bucles_; }
    void setComentarios(Comentario comentarios) { comentarios_ = comentarios; }
    void setVariables(Variables variables) { variables_ = variables; }
    void setBulces(Bucle bucles) { bucles_ = bucles; }

    //sobrecarga de operadores
    friend std::ostream& operator<<(std::ostream& salida, const Almacenamiento almacen);

  private:
    std::string nombre_fichero_;
    bool main_{false};
    Comentario comentarios_; 
    Variables variables_;
    Bucle bucles_;

};


#endif