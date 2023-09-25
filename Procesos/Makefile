CC = g++
CFLAGS = -O4 -Wall -I./include

# Carpeta donde se guardarán los archivos objeto
OBJ_DIR = ./compiled

# Enumera los archivos fuente en cada carpeta (AGREGAR AQUI NUEVAS CARPETAS)
GENERAL_SRCS = $(wildcard src/General/*.cpp)
FILEHANDLERS_SRCS = $(wildcard src/FileHandlers/*.cpp)
ENVLOADER_SRCS = $(wildcard src/EnvLoader/*.cpp)
ARGUMENTSLOADER_SRCS = $(wildcard src/ArgumentsLoader/*.cpp)
MENU_SRCS = $(wildcard src/Menu/*.cpp)
FUNCIONES_SRCS = $(wildcard src/Funciones/*.cpp)
OPTIONS_SRCS = $(wildcard src/Options/*.cpp)
USER_SRCS = $(wildcard src/User/*.cpp)

# Concatena todas las fuentes en una sola lista (AGREGAR AQUI NUEVAS CARPETAS)
SOURCES = $(GENERAL_SRCS) $(FILEHANDLERS_SRCS) $(ENVLOADER_SRCS) $(ARGUMENTSLOADER_SRCS) $(MENU_SRCS) $(FUNCIONES_SRCS) $(OPTIONS_SRCS) $(USER_SRCS)

# Nombres de los archivos objeto en las subcarpetas (AGREGAR AQUI NUEVAS CARPETAS)
GENERAL_OBJS = $(patsubst src/General/%.cpp, $(OBJ_DIR)/%.o, $(GENERAL_SRCS))
FILEHANDLERS_OBJS = $(patsubst src/FileHandlers/%.cpp, $(OBJ_DIR)/%.o, $(FILEHANDLERS_SRCS))
ENVLOADER_OBJS = $(patsubst src/EnvLoader/%.cpp, $(OBJ_DIR)/%.o, $(ENVLOADER_SRCS))
ARGUMENTSLOADER_OBJS = $(patsubst src/ArgumentsLoader/%.cpp, $(OBJ_DIR)/%.o, $(ARGUMENTSLOADER_SRCS))
MENU_OBJS = $(patsubst src/Menu/%.cpp, $(OBJ_DIR)/%.o, $(MENU_SRCS))
FUNCIONES_OBJS = $(patsubst src/Funciones/%.cpp, $(OBJ_DIR)/%.o, $(FUNCIONES_SRCS))
OPTIONS_OBJS = $(patsubst src/Options/%.cpp, $(OBJ_DIR)/%.o, $(OPTIONS_SRCS))
USER_OBJS = $(patsubst src/User/%.cpp, $(OBJ_DIR)/%.o, $(USER_SRCS))

# Agregar a esta lista los nuevos objetos
OBJECTS = $(GENERAL_OBJS) $(FILEHANDLERS_OBJS) $(ENVLOADER_OBJS) $(ARGUMENTSLOADER_OBJS) $(MENU_OBJS) $(FUNCIONES_OBJS) $(OPTIONS_OBJS) $(USER_OBJS)
MAIN = main.cpp

EXECUTABLE = main

.PHONY: all clean

all: clean $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(MAIN) $^ -o $@

$(OBJ_DIR)/%.o: src/General/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: src/FileHandlers/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	
$(OBJ_DIR)/%.o: src/EnvLoader/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: src/ArgumentsLoader/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	
$(OBJ_DIR)/%.o: src/Menu/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	
$(OBJ_DIR)/%.o: src/Funciones/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: src/Optiones/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	
$(OBJ_DIR)/%.o: src/User/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	
# AGREGAR AQUI NUEVAS CARPETAS COMO EL EJEMPLO DE ARRIBA

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
