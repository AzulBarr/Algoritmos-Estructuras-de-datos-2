#ifndef ALGO2_LABO_CLASE5_ALGORITMOS_H
#define ALGO2_LABO_CLASE5_ALGORITMOS_H

#include <utility>
#include <iterator>
#include <vector>
#include <iostream>

using namespace std;

//Ej 1
//Asumo que la colección no es vacía, que existen los métodos:
//bool operator<(const Contenedor::value_type&, const Contenedor::value_type&)
//Contenedor::const_iterator Contenedor::begin() const
//Contenedor::const_iterator Contenedor::end() const

template<class Contenedor>
typename Contenedor::value_type minimo(const Contenedor& c){
    auto min = c.begin();
    auto elemActual = c.begin();
    while(elemActual != c.end()){
        if (*elemActual < *min) min = elemActual;
        elemActual++;
    }
    return *min;
}

//Ej 2
//Asumo que existen los métodos: Contenedor::const_iterator Contenedor::begin() const
//Contenedor::const_iterator Contenedor::end() const
//y que Contenedor::value_type es un tipo numérico

template<class Contenedor>
typename Contenedor::value_type promedio(const Contenedor& c){
    typename Contenedor::value_type suma = 0;
    int cantidad = 0;
    for (auto& x : c) {
        suma += x;
        cantidad++;
    }
    return suma/cantidad;

}

//Ej 3
template<class Iterator>
typename Iterator::value_type minimoIter(const Iterator& desde, const Iterator& hasta){
    Iterator min = desde;
    Iterator elemActual = desde;
    while(elemActual != hasta){
        if (*elemActual < *min) min = elemActual;
        elemActual++;
    }
    return *min;
}

template<class Iterator>
typename Iterator::value_type promedioIter(const Iterator& desde, const Iterator& hasta){
    typename Iterator::value_type suma = 0;
    Iterator elemActual = desde;
    int cantidad = 0;
    while(elemActual != hasta) {
        suma += *elemActual;
        elemActual++;
        cantidad++;
    }
    return suma/cantidad;
}

//Ej 4
//Asumo las siguientes funciones del contenedor y su iterador:
//Contenedor::iterator Contenedor::begin()
//Contenedor::iterator Contenedor::end()
//Contenedor::iterator Contenedor::erase(Contenedor::iterator)
//bool operator==(const Contenedor::value_type&, const Contenedor::value_type&)
template<class Contenedor>
void filtrar(Contenedor &c, const typename Contenedor::value_type& elem){
    auto it = c.begin();
    while (it != c.end()){
        if (*it == elem) it = c.erase(it);
        else it++;
    }
}

//Ej 5
//Asumo que la colección no es vacía y que existen los métodos:
//bool operator<(const Contenedor::value_type&, const Contenedor::value_type&)
//Contenedor::const_iterator Contenedor::begin() const
//Contenedor::const_iterator Contenedor::end() const
template<class Contenedor>
bool ordenado(Contenedor &c) {
    for (auto it = c.begin(); it != c.end(); ++it) {
        if (it != c.begin()){
            auto anterior = it;
            anterior--;
            if (*it < *anterior) return false;
        }

    }
    return true;
}

//Ej 6
//Asumo que existen los métodos: bool operator<(const Contenedor::value_type&, const Contenedor::value_type&)
//Contenedor::const_iterator Contenedor::begin() const
//Contenedor::const_iterator Contenedor::end() const
//Contenedor::iterator Contenedor::insert(const Contenedor::const_iterator&, const Contenedor::value_type&) const

template<class Contenedor>
pair<Contenedor, Contenedor> split(const Contenedor& c, const typename Contenedor::value_type& elem){
    Contenedor menores;
    Contenedor mayoresIguales;
    for (auto it = c.begin(); it != c.end(); ++it) {
        if (*it < elem) menores.insert(menores.end(), *it);
        else mayoresIguales.insert(mayoresIguales.end(), *it);
    }
    return make_pair(menores, mayoresIguales);
}

//Ej 7
//Asumo que los elementos de c1 y c2 se encuentran ordenados de manera creciente (no necesariamente estricta),
//y que existen los métodos: bool operator<(const Contenedor::value_type&, const Contenedor::value_type&)
//Contenedor::const_iterator Contenedor::begin() const
//Contenedor::const_iterator Contenedor::end() const
//Contenedor::iterator Contenedor::insert(const Contenedor::const_iterator&, const Contenedor::value_type&) const

template <class Contenedor>
void merge(const Contenedor& c1, const Contenedor & c2, Contenedor & res) {
    auto it1 = c1.begin();
    auto it2 = c2.begin();
    while (it1 != c1.end() && it2 != c2.end()) {
        if(*it1 < *it2){ //res.end()
            res.insert(res.end(), *it1);
            it1++;
        }
        else{
            res.insert(res.end(), *it2);
            it2++;
        }
    }
    if (it1 != c1.end()){
        while (it1 != c1.end()){
            res.insert(res.end(), *it1);
            it1++;
        }
    }
    else if (it2 != c2.end()) {
        while (it2 != c2.end()) {
            res.insert(res.end(), *it2);
            it2++;
        }
    }
}


#endif //ALGO2_LABO_CLASE5_ALGORITMOS_H
