#include "../../include/Flatmap.h"
using namespace std;

template<typename I, typename O>
void Flatmap<I, O>::quickSort(int low, int high) {
    if (low < high) {
        int pivot = partition(low, high);
        quickSort(low, pivot - 1);
        quickSort(pivot + 1, high);
    }
}

template<typename I, typename O>
int Flatmap<I, O>::partition(int low, int high) {
    pair<I, O> pivot = map[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (map[j].first < pivot.first || 
            (map[j].first == pivot.first && map[j].second < pivot.second)) {
            i++;
            swap(map[i], map[j]);
        }
    }

    swap(map[i + 1], map[high]);
    return (i + 1);
}

template<typename I, typename O>
Flatmap<I, O>::Flatmap(vector<pair<I, O>> pairs) {
    map = pairs; // Copia el vector de pares

    // Ordena el vector utilizando Quicksort
    quickSort(0, map.size() - 1);
}

template<typename I, typename O>
Flatmap<I, O>::Flatmap(vector<I> keys, vector<O> values){
    if (keys.size() != values.size())
        throw runtime_error("Flatmap (constructor): Los pares clave valor no tienen el mismo largo.");
    for (size_t i = 0; i < keys.size(); i++)
        map.push_back(std::make_pair(keys[i], values[i]));
    quickSort(0, map.size() - 1); 
}


template<typename I, typename O>
int Flatmap<I, O>::flatSearch(I input){
    // Suponemos que el vector map está ordenado por la clave I.
    int left = 0;
    int right = map.size() - 1;

    while (left <= right){
        int middle = left + (right - left) / 2;
        if (map[middle].first == input)
            return middle; // Devuelve el índice donde se encontró el elemento input
        else if (map[middle].first < input)
            left = middle + 1;
        else
            right = middle - 1; 
    }

    // Si el elemento no se encuentra, puedes devolver un valor especial, como -1, para indicar que no se encontró.
    return -1;
}

template<typename I, typename O>
Flatmap<I, O> Flatmap<I, O>::fromOrderedUnique(vector<pair<I,O>> pairsKeyValue) {

    Flatmap<I, O> flatmap;

    for (const auto &p : pairsKeyValue)
        flatmap.map.emplace_back(p);
    return flatmap;
}

template<typename I, typename O>
Flatmap<I, O> Flatmap<I, O>::fromOrderedUnique(vector<I> orderedIn, vector<O> orderedOut) {
    if (orderedIn.size() != orderedOut.size()) {
        throw runtime_error("Flatmap: El tamaño de los vectores I y O no coincide.");
    }
    Flatmap<I, O> flatmap;
    for (size_t i = 0; i < orderedIn.size(); i++) 
        flatmap.map.emplace_back(orderedIn[i], orderedOut[i]);
    return flatmap;
}

template<typename I, typename O>
bool Flatmap<I, O>::add(pair<I, O> p) {
    int index = flatSearch(p.first);

    if (index != -1 && map[index].first == p.first) {
        return false; // El elemento ya existe en el mapa
    }

    map.insert(map.begin() + index + 1, p);
    return true;
}

template<typename I, typename O>
bool Flatmap<I, O>::remove(I input)
{
    // Realizar una búsqueda binaria para encontrar el elemento
    int index = flatSearch(input);

    // Verificar si el elemento existe en el mapa
    if (index != -1 && map[index].first == input){
        // Eliminar el elemento del mapa en la posición encontrada
        map.erase(map.begin() + index);
        return true; // Elemento eliminado exitosamente
    }

    return false; // Elemento no encontrado o no eliminado
}

template<typename I, typename O>
O Flatmap<I, O>::at(I input) {
    int pos = flatSearch(input);

    if (pos == -1) {
        throw out_of_range("Flatmap: No se encontró el elemento requerido");
    }

    return map[pos].second;
}

template<typename I, typename O>
pair<O, bool> Flatmap<I, O>::try_at(I input) {
    int pos = flatSearch(input);

    if (pos == -1) {
        return make_pair(O(), false);
    }

    return make_pair(map[pos].second, true);
}

template<typename I, typename O>
std::vector<I> Flatmap<I, O>::keys(){
    vector<I> k;
    for (const auto & obj : map)
        k.push_back(obj.first);
    return k;
}

template<typename I, typename O>
std::vector<O> Flatmap<I, O>::values(){
    vector<O> k;
    for (const auto & obj : map)
        k.push_back(obj.second);
    return k;
}
