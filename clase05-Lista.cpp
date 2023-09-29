#include "Lista.h"
#include <cassert>

Lista::Lista(): _primero(nullptr), _ultimo(nullptr), _size(0) {}

Lista::Lista(const Lista& l) : Lista() {
    *this = l;
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
}

Lista::~Lista() {
    while (_size != 0)
        eliminar(0);
}

Lista& Lista::operator=(const Lista& aCopiar) {
    while (_size != 0)
        eliminar(0);
    for (int i=0;i<aCopiar._size;i++){
        this->agregarAtras(aCopiar.iesimo(i));
    }
    return *this;
}

void Lista::agregarAdelante(const int& elem) {
    Nodo* nuevo = new Nodo(elem);

    if (_size == 0)
        _ultimo = nuevo;
    else{
        _primero->ant = nuevo;
        nuevo->sig = _primero;
    }

    _primero = nuevo;
    _size++;
}

void Lista::agregarAtras(const int& elem) {
    Nodo* nuevo = new Nodo(elem);
    if (_size == 0)
        _primero = nuevo;
    else{
        _ultimo->sig = nuevo;
        nuevo->ant = _ultimo;
    }

    _ultimo = nuevo;
    _size++;
}

void Lista::eliminar(Nat i) {
    _size--;
    Nodo* actual = _primero;
    for (int j = 0; j < i; j++) {
        actual = actual->sig;
    }
    if (i > 0){
        actual->ant->sig = actual->sig;
    }
    else
        _primero = actual->sig;
    delete actual;
}

int Lista::longitud() const {
    return _size;
}

const int& Lista::iesimo(Nat i) const {
    Nodo* actual = _primero;
    for (int j = 0; j < i; j++) {
        actual = actual->sig;
    }
    return actual->valor;
}

int& Lista::iesimo(Nat i) {
    Nodo* actual = _primero;
    for (int j = 0; j < i; j++) {
        actual = actual->sig;
    }
    return actual->valor;
}

void Lista::mostrar(ostream& o) {
    for (int i = 0; i < _size-1; i++) {
        o << "[" << this->iesimo(i) << ", ";
    }
    o << this->_ultimo->valor << "]" << endl;
}
