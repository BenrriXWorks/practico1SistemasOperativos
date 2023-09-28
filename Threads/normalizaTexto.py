import os
import unicodedata
import sys

def remove_accents(text):
    return ''.join(c for c in unicodedata.normalize('NFD', text) if unicodedata.category(c) != 'Mn').lower()

def process(paths):
    # Crear la carpeta "processed" si no existe
    carpeta = "Processed"
    os.makedirs(carpeta, exist_ok=True)

    for path in paths:
        try:
            with open(path, 'r', encoding='utf-8') as file:
                text = file.read()
            
                textoNuevo = remove_accents(text)
    
                textoNuevo = ''.join((char," ")[char=="\n"] for char in textoNuevo if char.islower() or char.isspace())
                
                nombreArchivo = os.path.basename(path)
            
                output_file_path = os.path.join(carpeta, nombreArchivo)
                
                with open(output_file_path, 'w', encoding='utf-8') as output_file:
                    output_file.write(textoNuevo)
        except Exception as e:
            print(f'Error al procesar el archivo {path}')

if __name__ == "__main__":
    archivos = sys.argv[1:]
    process(archivos)
