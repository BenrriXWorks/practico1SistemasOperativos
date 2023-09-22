import os
import sys
def main(vectorString):
    # Dividir el string en números usando el separador ";"
    numeros = vectorString.split(";")
    
    # Validar que todos los elementos sean números
    for numero in numeros:
        if not numero.isdigit():
            print("Error: El string contiene caracteres no numéricos.")
            return
    
    # Convertir los números a enteros
    numeros = [int(numero) for numero in numeros]
    
    # Ordenar la lista de números
    numeros_ordenados = sorted(numeros)
    
    # Obtener el PID actual del proceso
    pid = os.getpid()
    
    # Imprimir la lista de números ordenada y el PID
    print("Lista de números ordenada:", numeros_ordenados)
    print("PID del proceso actual:", pid)

if __name__ == "__main__":
    vectorString = sys.argv[1]
    main(vectorString)
