#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

//Ej 1
template<class T>
T cuadrado(T x) {
    return x * x;
}

//Ej 2
// Asumo que se encuentran definidos los métodos Elem Contenedor::operador[](int) const, y Contenedor::size() const
template<class Contenedor, class Elem>
bool contiene(Contenedor s, Elem c) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == c) {
            return true;
        }
    }
    return false;
}

//Ej 3
//Asumo que se encuentran definidos los métodos int Contenedor::size() const, y Elem Contenedor::operator[](int) const
template<class Contenedor>
bool esPrefijo(Contenedor a, Contenedor b){
    if (a.size() > b.size())
        return false;

    else {
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i])
                return false;
        }
    }
    return true;

}

//Ej 4
//Asumo que c tiene al menos un elemento y que se encuentran definidos los métodos int Contenedor::size() const,
//Elem Contenedor::operator[](int) const, y bool operator<(Elem, Elem)
template<class Contenedor, class Elem>
Elem maximo(Contenedor c){
    if (c.size()==1) return c[0];
    Elem max = c[0];
    for (Elem x : c){
        if (max < x){
            max = x;
        }
    }
    return max;
}

#endif