#include "SistemaDeMensajes.h"
using namespace std;

SistemaDeMensajes::SistemaDeMensajes(): _conns(), _proxys() {}

SistemaDeMensajes::~SistemaDeMensajes() {
    for (int j=0; j<4; j++) {
        delete _conns[j];
    }
    for (int h=0; h<_proxys.size(); h++){
        delete _proxys[h];
    }
}

void SistemaDeMensajes::registrarJugador(int id, string ip){
    if (_conns[id] != nullptr)
        desregistrarJugador(id);
    _conns[id] = new ConexionJugador(ip);
}

void SistemaDeMensajes::desregistrarJugador(int id){
    _conns[id] = nullptr;
}

void SistemaDeMensajes::enviarMensaje(int id, string mensaje){
    _conns[id]->enviarMensaje(mensaje);
}

bool SistemaDeMensajes::registrado(int id) const {
    return _conns[id] != nullptr;
}

string SistemaDeMensajes::ipJugador(int id) const {
    return _conns[id]->ip();
}

Proxy* SistemaDeMensajes::obtenerProxy(int id){
    Proxy* prox = new Proxy(_conns[id]);
    _proxys.push_back(prox);
    return prox;
}
//dado un id de jugador cree un proxy para este jugador y devuelva un puntero al mismo.