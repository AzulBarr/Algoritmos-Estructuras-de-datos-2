#include <iostream>
#include <list>

using namespace std;

using uint = unsigned int;

// Pre: 0 <= mes < 12
uint dias_en_mes(uint mes) {
    uint dias[] = {
        // ene, feb, mar, abr, may, jun
        31, 28, 31, 30, 31, 30,
        // jul, ago, sep, oct, nov, dic
        31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}

// Ejercicio 7, 8, 9 y 10

// Clase Fecha
class Fecha {
  public:
    // Completar declaraciones funciones
    Fecha(int mes, int dia);
    int mes();
    int dia();
    bool operator==(Fecha f);
    void incrementar_dia();


  private:
    //Completar miembros internos
    int _mes;
    int _dia;
};

Fecha::Fecha(int mes, int dia): _mes(mes), _dia(dia) {}

int Fecha::mes() { return _mes; }

int Fecha::dia() { return _dia; }

bool Fecha::operator==(Fecha f) {
    bool igual_dia = this->dia() == f.dia();
    bool igual_mes = this->mes() == f.mes();
    return igual_dia && igual_mes;
}

ostream& operator<<(ostream& os, Fecha f) {
    os << f.dia() << "/" << f.mes();
    return os;
}

void Fecha::incrementar_dia() {
    _dia++;
    if (_dia > dias_en_mes(_mes)) {
        _dia = 1;
        _mes++;
        if (_mes > 12) _mes = 1;
    }
}

// Ejercicio 11, 12
// Clase Horario

class Horario {
public:
    Horario(uint hora, uint min);
    uint hora();
    uint min();
    bool operator==(Horario h);
    bool operator<(Horario h);
private:
    uint _hora;
    uint _min;
};

Horario::Horario(uint hora, uint min): _hora(hora), _min(min) {}

uint Horario::hora() { return _hora; }

uint Horario::min() { return _min; }

ostream& operator<<(ostream& os, Horario h) {
    os << h.hora() << ":" << h.min();
    return os;
}

bool Horario::operator==(Horario h) {
    bool igual_hora = this->hora() == h.hora();
    bool igual_min = this->min() == h.min();
    return igual_hora && igual_min;
}

bool Horario::operator<(Horario h) {
    if (this->hora() == h.hora()) return this->min() < h.min();
    else return this->hora() < h.hora();
}

// Ejercicio 13
// Clase Recordatorio

class Recordatorio {
public:
    Recordatorio(Fecha fecha, Horario horario, string mensaje);
    string mensaje();
    Fecha fecha();
    Horario horario();
private:
    string _mensaje;
    Fecha _fecha;
    Horario _horario;
};

Recordatorio::Recordatorio(Fecha fecha, Horario horario, string mensaje):
_mensaje(mensaje), _fecha(fecha.mes(), fecha.dia()), _horario(horario) {}

string Recordatorio::mensaje(){ return _mensaje; }

Fecha Recordatorio::fecha() { return _fecha; }

Horario Recordatorio::horario() { return _horario; }

ostream& operator<<(ostream& os, Recordatorio r) {
    os << r.mensaje() << " @ " << r.fecha() << " " << r.horario(); //Cumple March @ 10/6 9:45*/
    return os;
}
// Ejercicio 14
// Clase Agenda

class Agenda {
public:
    Agenda(Fecha fecha_inicial);
    void agregar_recordatorio(Recordatorio rec);
    void incrementar_dia();
    list<Recordatorio> recordatorios_de_hoy();
    Fecha hoy();

private:
    Fecha _hoy;
    list<Recordatorio> _recordatorios;

};

Agenda::Agenda(Fecha fecha_inicial): _hoy(fecha_inicial.mes(), fecha_inicial.dia()) {}

void Agenda::agregar_recordatorio(Recordatorio rec) {
    _recordatorios.push_back(rec);
}

void Agenda::incrementar_dia() {
    _hoy.incrementar_dia();
}

bool comparar_recordatorio(Recordatorio rec1, Recordatorio rec2){
    return rec1.horario() < rec2.horario();
}

list<Recordatorio> Agenda::recordatorios_de_hoy() {
    list<Recordatorio> recordatorios_hoy;
    for (Recordatorio rec : _recordatorios)
        if (rec.fecha() == _hoy) recordatorios_hoy.push_back(rec);
    recordatorios_hoy.sort(comparar_recordatorio);
    return recordatorios_hoy;
}

Fecha Agenda::hoy() { return _hoy; }

ostream& operator<<(ostream& os, Agenda a) {
    os << a.hoy() << endl << "=====" << endl;
    for (Recordatorio rec : a.recordatorios_de_hoy()) {
        os << rec << endl;
    }
    return os;
}
