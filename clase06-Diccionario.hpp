#ifndef DICCIONARIO_HPP
#define DICCIONARIO_HPP
#include <vector>
using namespace std;

//Ej 5
template<class Clave, class Valor>
class Diccionario {
public:
    Diccionario();
    void definir(Clave k, Valor v);
    bool def(Clave k) const;
    Valor obtener(Clave k) const;
    vector<Clave> claves() const;
private:

    struct Asociacion {
        Asociacion(Clave k, Valor v);
        Clave clave;
        Valor valor;
    };
    std::vector<Asociacion> _asociaciones;
};

template<class Clave, class Valor>
Diccionario<Clave, Valor>::Diccionario() {}

template<class Clave, class Valor>
Diccionario<Clave, Valor>::Asociacion::Asociacion(Clave k, Valor v) : clave(k), valor(v) {
}

template<class Clave, class Valor>
void Diccionario<Clave, Valor>::definir(Clave k, Valor v) {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            _asociaciones[i].valor = v;
            return;
        }
    }
    _asociaciones.push_back(Asociacion(k, v));
}

template<class Clave, class Valor>
bool Diccionario<Clave, Valor>::def(Clave k) const {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            return true;
        }
    }
    return false;
}

template<class Clave, class Valor>
Valor Diccionario<Clave, Valor>::obtener(Clave k) const {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            return _asociaciones[i].valor;
        }
    }
    assert(false);
}

template<class Clave>
Clave minimo(vector<Clave>& v){
    Clave min = v[0];
    for (int i = 0; i < v.size(); ++i) {
        if (min > v[i]){
            min = v[i];
        }
    }
    return min;
}

template<class Clave>
vector<Clave> borrar(vector<Clave> v, Clave x){
    vector<Clave> res(0);
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] != x){
            res.push_back(v[i]);
        }
    }
    return res;
}

template<class Clave, class Valor>
vector<Clave> Diccionario<Clave,Valor>::claves() const {
    vector<Clave> clavesDesordenadas(0);
    for (int i = 0; i < _asociaciones.size(); ++i) {
        clavesDesordenadas.push_back(_asociaciones[i].clave);
    }
    vector<Clave> clavesOrdenadas(0);
    while (clavesDesordenadas.size() != 0){
        Clave min = minimo(clavesDesordenadas);
        clavesOrdenadas.push_back(min);
        clavesDesordenadas = borrar(clavesDesordenadas,min);
    }
    return clavesOrdenadas;

}

#endif