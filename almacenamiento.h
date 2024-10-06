// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expreciones regulares
// Autor: Joshua Gomez Marrero
// Correo: alu0101477398@ull.edu.es
// Fecha: 17/09/2024
// Archivo almacenamiento.h: definicion de la clase almacenamiento
// Contiene la definicion de la clase almacenamiento
// para ... (indicar brevemente el objetivo)
// Referencias:
// Enlaces de interes
// Historial de revisiones
// 17/09/2024 - Creacion (primera version) del codigo 

#ifndef ALMACENAMIENTO_H
#define ALMACENAMIENTO_H

#include <iostream>
#include <string>
#include <vector>


class Almacenamiento {
  public:
    //Constructor por defecto
    Almacenamiento() {}

    //Destructor
    ~Almacenamiento() {}

    //Metodos
    void setVariables(std::string, int);
    void setBucles(std::string, int);
    void setMain(bool);
    void setComentarios(std::string, int);

    //sobrecarga de operadores
    friend std::ostream& operator<<(std::ostream& salida, const Almacenamiento almacen);

  private:
    std::vector<std::string> variables_;
    std::vector<int> linea_variables_;
    std::vector<std::string> bucles_;
    std::vector<int> linea_bucles_;
    bool main_{false};
    std::vector<std::string> comentarios_;
    std::vector<int> linea_comentarios_;
};


#endif