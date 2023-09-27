#include <vector>
#include <stdexcept>
#pragma once

template<typename I,typename O>
class Flatmap
{
protected:
    std::vector<std::pair<I,O>> map;
    void quickSort(int low, int high);
    int partition(int low, int high);
    int flatSearch(I input);
public:
    Flatmap(){};
    Flatmap(std::vector<std::pair<I, O>> pairs);
    Flatmap(std::vector<I> keys, std::vector<O> values);
    static Flatmap fromOrderedUnique(std::vector<I> orderedIn,std::vector<O> orderedOut);
    static Flatmap fromOrderedUnique(std::vector<std::pair<I,O>> pairKeyvalue);
    bool add(std::pair<I,O> p);
    inline bool add(I key, O value) {return add(std::make_pair(key,value));};
    bool remove(I input);
    O at(I input);
    std::pair<O,bool> try_at(I input);
    inline std::vector<std::pair<I,O>> getAll() {return map;};
    std::vector<I> keys();
    std::vector<O> values();
    
};
