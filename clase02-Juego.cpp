#include <utility>
#include <list>

using namespace std;
using uint = unsigned int;

// Taller 1 - Juego

using Pos = pair<int, int>;

char ARRIBA = '^';
char ABAJO = 'v'; 
char DERECHA = '<';
char IZQUIERDA = '>';

class Pocion {
public:
    Pocion(uint movimientos, uint turnos);
    uint cuantosMovimientos();
    uint cuantosTurnos();
    void seGastoUnTurno();
private:
    uint _movimientos;
    uint _turnos;
};

class Juego {
public:
    Juego(uint casilleros, Pos pos_inicial);
    Pos posicion_jugador();
    uint turno_actual();
    void mover_jugador(char dir);
    void ingerir_pocion(uint movimientos, uint turnos);
private:
    Pos _posicion;
    uint _turno;
    uint _casilleros;
    list<Pocion> _pociones;
};

Pocion::Pocion(uint movimientos, uint turnos): _movimientos(movimientos), _turnos(turnos) {}

uint Pocion::cuantosMovimientos() { return _movimientos; }

uint Pocion::cuantosTurnos() { return _turnos; }

void Pocion::seGastoUnTurno() { _turnos--; }

Juego::Juego(uint casilleros, Pos pos_inicial): _casilleros(casilleros), _posicion(pos_inicial), _turno(0){}

uint Juego::turno_actual() { return _turno; }

Pos Juego::posicion_jugador() { return _posicion; }

void Juego::mover_jugador(char dir) {
    if (dir == ARRIBA && _posicion.first != 0){
        _posicion.first--;
    } else if (dir == ABAJO && _posicion.first != _casilleros){
        _posicion.first++;
    } else if (dir == DERECHA && _posicion.second != _casilleros){
        _posicion.second++;
    } else if (dir == IZQUIERDA && _posicion.second != 0){
        _posicion.second--;
    }
    _turno++;
    for (Pocion pocion:_pociones){
        pocion.seGastoUnTurno();
    }

}

void Juego::ingerir_pocion(uint movimientos, uint turnos) {
    _pociones.push_back(Pocion(movimientos, turnos));
}
