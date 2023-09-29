using namespace std;
#include "string_map.h"
#include <string>
#include <vector>
template <typename T>
bool string_map<T>::sonIguales(const string& s1, const string& s2){
    bool verdad = true;
    if (s1.size() != s2.size()){
        verdad = false;
    }
    else{
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) verdad = false;
        }
    }
    return verdad;
}

template <typename T>
string_map<T>::string_map(): _size(0), _raiz(nullptr), _claves(vector<string>(0)){}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; }
// Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
     // usar la funcion borrartodosNodos que voy a poner en el destructor
    while (_claves.size() != 0){
        erase(_claves[0]);
    }
    for (int i = 0; i < d._claves.size(); ++i) {
        T* def = new T(d.at((d._claves)[i]));
        insert(make_pair((d._claves)[i], *def));
        delete def;
    }

}

template <typename T>
string_map<T>::~string_map(){
    while (_claves.size() != 0){
        erase(_claves[0]);
    }
}


template <typename T>
int string_map<T>::count(const string& clave) const{
    /*if (empty() || clave.size() == 0) return 0;
    else {
        Nodo* actual = _raiz;
        int posClave = 0;
        while (posClave < clave.size() && actual->siguientes[clave[posClave]] != nullptr){
            actual = actual->siguientes[clave[posClave]];
            posClave++;
        }
        if (posClave == clave.size() && actual->definicion != nullptr)  return 1;
        else    return 0;
    }*/
    for (int i = 0; i < _claves.size(); i++){
        if (_claves[i] == clave){
            return 1;
        }
    }
    return 0;
}

template <typename T>
void string_map<T>::insert(const pair<string, T>& p) {
    if (empty())    _raiz = new Nodo();

    Nodo* actual = _raiz;
    int posClave = 0;
    int posVector = 0;
    while (posClave < (p.first).size()){
        posVector = int((p.first)[posClave]);
        if ((actual->siguientes)[posVector] == nullptr){
            (actual->siguientes)[posVector] = new Nodo();
        }
        actual = (actual->siguientes)[posVector];
        posClave++;
    }
    delete actual->definicion;
    actual->definicion = new T(p.second);
    _claves.push_back(p.first);
    _size++;
}

template <typename T>
const T& string_map<T>::at(const string& clave) const {
    Nodo* actual = _raiz;
    int posClave = 0;
    int posVector = 0;
    while (posClave < clave.size()){
        posVector = int(clave[posClave]);
        actual = actual->siguientes[posVector];
        posClave++;
    }
    return *(actual->definicion);

}

template <typename T>
T& string_map<T>::at(const string& clave) {
    Nodo* actual = _raiz;
    int posClave = 0;
    int posVector = 0;
    while (posClave < clave.size()){
        posVector = int(clave[posClave]);
        actual = actual->siguientes[posVector];
        posClave++;
    }
    return *(actual->definicion);
}

template <typename T>
unsigned int string_map<T>::cantidadDeHijos(const Nodo* n) {
    unsigned int count = 0;
    for (int i = 0; i < 256; i++){
        if ((n->siguientes)[i] != nullptr)  count++;
    }
    return count;
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    Nodo* actual = _raiz;
    Nodo* ultimoNoBorrar = _raiz;
    int posClave = 0;
    int ultimaPos = 0;
    int posVector = 0;
    while (posClave < clave.size()){
        posVector = int(clave[posClave]);
        actual = actual->siguientes[posVector];
        if (cantidadDeHijos(actual) > 1 || (actual->definicion != nullptr && posClave != clave.size()-1)){  //*(actual->definicion) != at(clave))
            ultimoNoBorrar =  actual;
            ultimaPos = posClave;

        }
        posClave++;
    }
    delete actual->definicion;
    actual->definicion = nullptr; //actual != ultimoNoBorrar &&
    if ( cantidadDeHijos(actual) == 0){
        borrarLoInnecesarioDesde(ultimoNoBorrar, clave, ultimaPos);
    }
    vector<string> clavesRefedinidas(0);
    for (int i = 0; i < _claves.size(); i++){
        if (!sonIguales(_claves[i], clave)){
            clavesRefedinidas.push_back(_claves[i]);
        }
    }
    _claves = clavesRefedinidas;
    _size--;
}

template <typename T>
void string_map<T>::borrarLoInnecesarioDesde(Nodo*& desde, const string& clave, int pos){
    int posClave = 0;
    Nodo* siguiente = desde;
    vector<Nodo *> nodosInnecesarios(0);
    if (desde == _raiz){
        posClave = pos;
    }
    else {
        posClave = pos + 1;
    }
    while(posClave < clave.size()){
        siguiente = (siguiente->siguientes)[int(clave[posClave])];
        nodosInnecesarios.push_back(siguiente);
        posClave++;
    }
    for (int i = 0; i < nodosInnecesarios.size(); i++){
        delete nodosInnecesarios[i];
        //(nodosInnecesarios[i])->siguientes = vector<Nodo*>(256, nullptr);
        //(nodosInnecesarios[i])->definicion = nullptr;
    }
    if (desde == _raiz){
        //delete (desde->siguientes)[int(clave[pos])];
        (desde->siguientes)[int(clave[pos])] = nullptr;
    }
    else{
        //delete (desde->siguientes)[int(clave[pos+1])];
        (desde->siguientes)[int(clave[pos+1])] = nullptr;
    }
    if (_claves.size() == 1){
        delete _raiz;
    }

}

template <typename T>
int string_map<T>::size() const{
    return _size;
}

template <typename T>
bool string_map<T>::empty() const{
    if (_size == 0)     return true;
    else    return false;
}