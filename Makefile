CC = g++
CFLAGS = -O4 -Wall -I./include

# Carpeta donde se guardarán los archivos objeto
OBJ_DIR = ./compiled

# Enumera los archivos fuente en cada carpeta (AGREGAR AQUI NUEVAS CARPETAS)
GENERAL_SRCS = $(wildcard src/General/*.cpp)
USER_CLASSES_SRCS = $(wildcard src/UserModule/UserClasses/*.cpp)
USER_OTHER_SRC = $(wildcard src/UserModule/*.cpp)
FILEHANDLERS_SRCS = $(wildcard src/FileHandlers/*.cpp)
ENVLOADER_SRCS = $(wildcard src/EnvLoader/*.cpp)
ARGUMENTSLOADER_SRCS = $(wildcard src/ArgumentsLoader/*.cpp)

# Concatena todas las fuentes en una sola lista (AGREGAR AQUI NUEVAS CARPETAS)
SOURCES = $(GENERAL_SRCS) $(USER_CLASSES_SRCS) $(USER_OTHER_SRC) $(FILEHANDLERS_SRCS) $(ENVLOADER_SRCS) $(ARGUMENTSLOADER_SRCS) 

# Nombres de los archivos objeto en las subcarpetas (AGREGAR AQUI NUEVAS CARPETAS)
GENERAL_OBJS = $(patsubst src/General/%.cpp, $(OBJ_DIR)/%.o, $(GENERAL_SRCS))
USER_CLASSES_OBJS = $(patsubst src/UserModule/UserClasses/%.cpp, $(OBJ_DIR)/%.o, $(USER_CLASSES_SRCS))
USER_OTHER_OBJS = $(patsubst src/UserModule/%.cpp, $(OBJ_DIR)/%.o, $(USER_OTHER_SRC))
FILEHANDLERS_OBJS = $(patsubst src/FileHandlers/%.cpp, $(OBJ_DIR)/%.o, $(FILEHANDLERS_SRCS))
ENVLOADER_OBJS = $(patsubst src/EnvLoader/%.cpp, $(OBJ_DIR)/%.o, $(ENVLOADER_SRCS))
ARGUMENTSLOADER_OBJS = $(patsubst src/ArgumentsLoader/%.cpp, $(OBJ_DIR)/%.o, $(ARGUMENTSLOADER_SRCS))

# Agregar a esta lista los nuevos objetos
OBJECTS = $(GENERAL_OBJS) $(USER_CLASSES_OBJS) $(USER_OTHER_OBJS) $(FILEHANDLERS_OBJS) $(ENVLOADER_OBJS) $(ARGUMENTSLOADER_OBJS)
MAIN = main.cpp

EXECUTABLE = main

.PHONY: all clean

all: clean $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(MAIN) $^ -o $@

$(OBJ_DIR)/%.o: src/General/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: src/UserModule/UserClasses/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: src/UserModule/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: src/FileHandlers/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	
$(OBJ_DIR)/%.o: src/EnvLoader/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: src/ArgumentsLoader/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# AGREGAR AQUI NUEVAS CARPETAS COMO EL EJEMPLO DE ARRIBA

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
