# Universidad de La Laguna
# Escuela Superior de Ingenieria y Tecnologia
# Grado en Ingenieria Informatica
# Asignatura: Computabilidad y Algoritmia
# Curso: 2º
# Practica 2: Exprexiones regulares
# Autor: Joshua Gomez Marrero
# Correo: alu0101477398@ull.edu.es
# Fecha: 24/10/2023
# Archivo: Makefile

# Nombre del archivo de salida
TARGET = Expresiones

# Lista de archivos fuente(.cc)
SOURCES = almacenamiento.cc cliente_almacenamiento.cc tools.cc lectura_escritura.cc

# Dependencias de los archivos fuente 
DEPENDENCIES = tools.h almacenamiento.h lectura_escritura.h

# Opciones de compilación
CXX = g++
CXXFLAGS = -std=c++11

# Regla para compilar el programa
$(TARGET): $(SOURCES) $(DEPENDENCIES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

# Regla para limpiar los archivos generados
clean:
	rm -f $(TARGET) *.o

# Regla por defecto
default: $(TARGET)