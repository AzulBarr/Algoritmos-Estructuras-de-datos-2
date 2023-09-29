
template <class T>
Conjunto<T>::Conjunto(): _raiz(nullptr), _size(0) {}

template <class T>
Conjunto<T>::~Conjunto() {
    while(_size > 0){
        this->remover(this->minimo());
    }
}

template <class T>
const T& Conjunto<T>::minimoSubarbol(Nodo* nodo) const {
    //Nodo* actual = nodo;
    while(nodo->izq != nullptr) {
        nodo = nodo->izq;
    }
    return nodo->valor;
}


template <class T>
const T& Conjunto<T>::minimo() const {
    return minimoSubarbol(_raiz);
}

template <class T>
const T& Conjunto<T>::maximoSubarbol(Nodo* nodo) const {
    Nodo* actual = nodo;
    while(actual->der != nullptr) {
        actual = actual->der;
    }
    return actual->valor;
}

template <class T>
const T& Conjunto<T>::maximo() const {
    return maximoSubarbol(_raiz);
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    Nodo* actual = _raiz;
    bool esta = false;
    while(actual != nullptr && !esta ){ //) {
        if (actual->valor == clave)     esta = true;//return true;
        else if (actual->valor < clave)     actual = actual->der;
        else    actual = actual->izq;
    }
    //
    if (!esta)  delete actual; //agregue esto
    return esta;//false;
}

template <class T>
void Conjunto<T>::insertar(const T& clave) {
    if (_size == 0){
        _raiz = new Nodo(clave);
        _size++;
        return;
    }

    if (!this->pertenece(clave)){
        Nodo* actual = _raiz;
        Nodo* anterior = _raiz;
        while(actual != nullptr) {
            anterior = actual;
            if (actual->valor < clave) {
                actual = actual->der;
            } else {
                actual = actual->izq;
            }
        }
        if (anterior->valor < clave){
            anterior->der = new Nodo(clave);
        }
        else {
            anterior->izq = new Nodo(clave);
        }
        _size++;
        delete actual; //agregueesto
    }

}

template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    Nodo* actual = _raiz;
//    T valorMayor = actual->valor;
    Nodo* mayor = _raiz;

    while(actual-> valor != clave) {
        if (actual-> valor < clave)     actual = actual->der;
        else{
            mayor = actual;
            actual = actual->izq;
        }
    }

    if (actual->der != nullptr) {
        return minimoSubarbol(actual->der);

    } else {
        return mayor->valor;
    }
}

template <class T>
void Conjunto<T>::remover(const T& clave) {
    if (this->pertenece(clave)){

        Nodo* actual = _raiz;
        Nodo* padre = _raiz;
        while(actual-> valor != clave) {
            padre = actual;
            if (actual-> valor < clave)    actual = actual->der;
            else    actual = actual->izq;
        }

        if (actual->der == nullptr && actual->izq == nullptr){
            if (actual != _raiz) {
                if (padre->valor < clave) padre->der = nullptr;
                else padre->izq = nullptr;

                delete actual;
            }
            else{
                delete actual;
                _raiz = nullptr;
            }
        }

        else if (actual->der != nullptr && actual->izq != nullptr){
            T sucesor = siguiente(actual->valor);
            remover(sucesor);
            _size++;
            actual->valor = sucesor;

        }

        else if (actual->der != nullptr){
            if (actual != _raiz) {
                if (padre->valor < clave) padre->der = actual->der;
                else padre->izq = actual->der;

            }
            else    _raiz = actual->der;
            delete actual; // revisar esto para actual = raiz
        }

        else {
            if (actual != _raiz){
                if (padre->valor < clave)   padre->der = actual->izq;
                else    padre->izq = actual->izq;
            }
            else    _raiz = actual->izq;
            delete actual;

        }


        _size--;
    }


}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    return _size;
}

template <class T>
void Conjunto<T>::mostrar(std::ostream& c) const {}

