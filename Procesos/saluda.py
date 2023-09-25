import sys
import os

def main():
    args = sys.argv
    if len(args) != 2:
        print("saluda.py: Cantidad inesperada de argumentos, debe ser solo usuario")
        print("Entregado: ", args)
        return False

    print("HOLA COMO ESTAS " + args[1], os.getpid())

    return 0

if __name__ == "__main__":
    main()
