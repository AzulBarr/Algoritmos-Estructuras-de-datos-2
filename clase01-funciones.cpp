#include <vector>
#include "algobot.h"

using namespace std;

set<int> pasarASet(vector<int> s) {
    set<int> set_a;
    for (int n : s) {
        set_a.insert(n);
    }
    return set_a;
}

vector<int> pasarAVector(set<int> a){
    vector<int> res;
    for (int i : a) res.push_back(i);
}

// Ejercicio 1
vector<int> quitar_repetidos(vector<int> s) {
    set<int> set_a;
    for (int n : s) {
        set_a.insert(n);
    }
    vector<int> res;
    for (int i : set_a) {
        res.push_back(i);
    }
    return res;
}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    vector<int> res = quitar_repetidos(s);
    return res;
}

// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {
    set<int> s = pasarASet(a), t = pasarASet(b);
    return s == t;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    return mismos_elementos(a,b);
}

// Ejercicio 5

int cantidadApariciones(vector<int> v, int x){
    int count = 0;
    for (int i : v){
        if (i == x) count++;
    }
    return count;
}
map<int, int> contar_apariciones(vector<int> s) {
    set<int> set_a = pasarASet(s);
    map<int, int> diccApariciones;
    for (int i : set_a){
        diccApariciones[i] = cantidadApariciones(s, i);
    }
    return diccApariciones;
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    vector<int> res(0);
    for (int i : s){
        if (cantidadApariciones(s, i) == 1) res.push_back(i);
    }
    return res;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    set<int> interseccion;
    for(int i : a){
        if (b.count(i) == 1) interseccion.insert(i);
    }
    return interseccion;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) { //secu sin repetidos.
    map<int, set<int>> res;

    for (int x:s){
        res[x % 10].insert(x);

    }
    return res;
}

// Ejercicio 9

int indiceCambio(vector<pair<char, char>> tr, char x){
    int res = -1;
    for (int i = 0; i < tr.size() && res == -1; i++){
        if (tr[i].first == x)
            res = i;
    }
    return res;
}
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    vector<char> res(0);
    for (char x:str){
        int i = indiceCambio(tr, x);
        if (i == -1) res.push_back(x);
        else res.push_back(tr[i].second);
    }
    return res;
}

// Ejercicio 10

bool SeRepitenItegrantesEnGruposDistintos(set<LU> libr, LU lu, set<set<LU>> todasLasLibretas){
    bool res = false;
    for (set<LU> libr2 : todasLasLibretas){
        for (LU lu2 : libr2) {
            res = lu2 == lu && libr2 != libr;
            if (res) return true;
        }
    }
    return false;
}

bool integrantes_repetidos(vector<Mail> s) {
    set<set<LU>> todasLasLibretas;
    bool res = false;
    for (Mail m : s){
        todasLasLibretas.insert(m.libretas());
    }
    for (set<LU> libr : todasLasLibretas){
        for (LU lu : libr){
            res = SeRepitenItegrantesEnGruposDistintos(libr, lu, todasLasLibretas);
            if (res) return true;
        }
    }
    return false;
}

// Ejercicio 11


map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
    map<set<LU>, Mail> res;
    for (Mail m: s) {
        if (m.adjunto() && m.fecha() > res[m.libretas()].fecha()) {
            res[m.libretas()] = m;
        }
    }
    return res;
}
