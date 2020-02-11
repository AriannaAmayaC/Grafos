#pragma once

#ifndef ALGORITMO_H
#define ALGORITMO_H

#include <iostream>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <limits>

#include "Grafo.h"

using namespace std;

class Algoritmo {
    public:
    Algoritmo() {};
    virtual ~Algoritmo() {};

    virtual void ejecutar() {};
    virtual void reportar (){};

    virtual void unistantiable() = 0;
};
class Camino {
    public:
    int verticePartida;
    int Arista;
    int verticeDestino;
    Camino() {};
    ~Camino() {};
    void unistantiable() {};
};

class MGE : public Algoritmo {
    public:
        Grafo* grafo;
        Vertice* s;

        std::vector<Camino> caminosAbiertos;
        std::vector<Camino> caminosCerrados;
        std::vector<Camino> caminosNuevos;

    MGE(Grafo* g) {
        grafo = g;
        cout << "Inicializando ..." << endl;
    };
    virtual ~MGE() {};

    virtual void preparar (Grafo* g) {
        grafo = g;
        cout << "Inicializando ..." << endl;
    };

    void reportar();

    virtual void ejecutar(int v);

    virtual void calcularAtributos();
    virtual void escogerCaminoAbierto(Camino &aux);
    virtual void eliminarCaminos();

    void unistantiable() {};
};

class DFS : public MGE {
    public:
        DFS(Grafo *g) : MGE(g) {};
        ~DFS() {};
        void DFSCompleto(int v);
        void escogerCaminoAbierto(Camino &aux);
        void eliminarCaminos();
        void limpiarListas();

    private:
        int ExistenCC(int Vi);
        int ExistenCA(int Vi);

    void unistantiable() {};
};

class Dijkstra: public Algoritmo {
    public :
        Grafo* grafo;
        Vertice* s;
        Dijkstra (Grafo *g): Algoritmo(){
        grafo = g;
        };
        ~Dijkstra() {};
        void ejecutar(int vertice);
        void reportar();

    private:
        int VerticeA_MenorCosto();
        void imprimircamino (int v);

    void unistantiable() {};
};

class RutaCritica: public Algoritmo {
    public:
        Grafo* grafo;
        Vertice* s;
        RutaCritica(Grafo *g): Algoritmo(){
        grafo = g;
        };
        ~RutaCritica() {};
        void ejecutar(int v);
        void reportar();

    private:
        void visitaDFS(int v, vector<int> &ordenamiento);
        void imprimirCamino(int v);
        void bellmanModificado(int v);
        void calcularTAC(int v);
        vector<int> ordenTopologico(int v);
    void unistantiable() {};
};

#endif // ALGORITMO_H
