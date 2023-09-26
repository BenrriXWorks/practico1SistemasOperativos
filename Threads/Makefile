# Directorios de origen y destino
SRC_DIR = src
INCLUDE_DIR = include
COMPILED_DIR = compiled

# Nombre del ejecutable
EXECUTABLE = main

# Compilador y opciones de compilación
CXX = g++
CXXFLAGS = -std=c++17 -Wall -I$(INCLUDE_DIR)

# Obtener la lista de archivos fuente
SOURCES = $(wildcard $(SRC_DIR)/**/*.cpp) main.cpp

# Objetos generados
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(COMPILED_DIR)/%.o,$(SOURCES))

# Regla principal para compilar el ejecutable
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

# Regla para compilar los objetos
$(COMPILED_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Limpieza de archivos compilados
clean:
	rm -rf $(COMPILED_DIR)/*.o $(EXECUTABLE)

.PHONY: all clean
