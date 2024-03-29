#include <iostream>

using namespace std;

using uint = unsigned int;

// Ejercicio 1

class Rectangulo {
    public:
        Rectangulo(uint alto, uint ancho);
        uint alto();
        uint ancho();
        float area();

    private:
        int alto_;
        int ancho_;

};

Rectangulo::Rectangulo(uint alto, uint ancho) : alto_(alto), ancho_(ancho) {};

uint Rectangulo::alto() {
    return alto_;
}

// Completar definición: ancho
uint Rectangulo::ancho() {
    return ancho_;
}

// Completar definición: area
float Rectangulo::area(){
    return alto_ * ancho_;
}

// Ejercicio 2
// Clase Elipse

float PI = 3.14;
class Elipse {
    public:
        Elipse(uint a, uint b);
        uint r_a();
        uint r_b();
        float area();

    private:
    uint r_a_;
    uint r_b_;

};

Elipse::Elipse(uint r_a, uint r_b): r_a_(r_a), r_b_(r_b) {};

uint Elipse::r_a(){ return r_a_; }

uint Elipse::r_b() { return r_b_; }

float Elipse::area() { return PI * r_b_ * r_a_; }

// Ejercicio 3

class Cuadrado {
    public:
        Cuadrado(uint lado);
        uint lado();
        float area();

    private:
        Rectangulo r_;
};

Cuadrado::Cuadrado(uint lado): r_(lado, lado) {}

uint Cuadrado::lado() { return r_.ancho(); }

float Cuadrado::area() { return r_.area(); }

// Ejercicio 4
// Clase Circulo

class Circulo {
public:
    Circulo(uint radio);
    uint radio();
    float area();

private:
    Elipse e_;

};

Circulo::Circulo(uint radio): e_(radio, radio) {}

uint Circulo::radio() { return e_.r_a(); }

float Circulo::area() { return e_.area(); }

// Ejercicio 5

ostream& operator<<(ostream& os, Rectangulo r) {
    os << "Rect(" << r.alto() << ", " << r.ancho() << ")";
    return os;
}
// ostream Elipse

ostream& operator<<(ostream& os, Elipse e) {
    os << "Elipse(" << e.r_a() << ", " << e.r_b() << ")";
    return os;
}

// Ejercicio 6
ostream& operator<<(ostream& os, Cuadrado cu) {
    os << "Cuad(" << cu.lado() << ")";
    return os;
}

ostream& operator<<(ostream& os, Circulo ci) {
    os << "Circ(" << ci.radio() << ")";
    return os;
}
