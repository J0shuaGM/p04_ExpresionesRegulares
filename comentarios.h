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


#ifndef COMENTARIOS_H
#define COMENTARIOS_H

#include <iostream>
#include <string>
#include <vector>


class Comentario{
  public:
    //Constructor por defecto
    Comentario() {}

    //Destructor
    ~Comentario() {}

    //Metodos
    void setComentarios(std::string, int);
    std::vector<std::string> getComentarios(void) { return comentarios_; }
    std::vector<int> getLineaComentarios(void) { return linea_comentarios_; }

  private:
    std::vector<std::string> comentarios_;
    std::vector<int> linea_comentarios_;
};

#endif