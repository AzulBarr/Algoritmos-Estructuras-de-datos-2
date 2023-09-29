#ifndef MULTICONJUNTO_HPP
#define MULTICONJUNTO_HPP

#include "Diccionario.hpp"
//Ej 7
template<class T>
class Multiconjunto {
public:
    Multiconjunto();
    void agregar(T x);
    int ocurrencias(T x) const;
    bool operator<=(Multiconjunto<T> otro) const;

private:
    Diccionario<T, int> _multiconj;
};

template<class T>
Multiconjunto<T>::Multiconjunto(): _multiconj(){}

template<class T>
void Multiconjunto<T>::agregar(T x){
    int cantidad = 0;
    if (_multiconj.def(x)){
        cantidad = ocurrencias(x) + 1;
    }
    else cantidad = 1;
    _multiconj.definir(x, cantidad);
}

template<class T>
int Multiconjunto<T>::ocurrencias(T x) const{
    int cantidad;
    if (!_multiconj.def(x)) cantidad = 0;
    else cantidad = _multiconj.obtener(x);
    return cantidad;
}

template<class T>
bool Multiconjunto<T>::operator<=(Multiconjunto<T> otro) const{
    for (T clave : _multiconj.claves()) {
        if (ocurrencias(clave) > otro.ocurrencias(clave))
            return false;
    }
    return true;

}
#endif