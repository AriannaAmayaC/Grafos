#include "Grafo.h"

int Entidad::numSecuencia = 0;

Entidad::Entidad()
{
    //constructor
}

Entidad::Entidad(const int id)
{
    secID = Entidad::numSecuencia++;
    ID = id;
    nombre.assign("*");
}

Entidad::Entidad(const int id, const char *nom)
{
    nombre.assign(nom);
    secID = Entidad::numSecuencia++;
    ID = id;
}

Entidad::Entidad(const int id, const string nom)
{
    nombre = nom;
    secID = Entidad::numSecuencia++;
    ID = id;
}

Entidad::~Entidad()
{
    //destructor
}

Entidad::Entidad(const Entidad& other)
{
    //copia constructor
}

Entidad& Entidad::operator=(const Entidad& rhs)
{
    if (this == &rhs)
        return *this; // considerar autoasignación
    // operador asignación
    return *this;
}

Arista::~Arista()
{
    //destructor
}

Lado::~Lado()
{
    //destructor
}

Arco::~Arco()
{
    //destructor
}

Vertice::~Vertice()
{
    //destructor
}

Grafo::Grafo(const int id) : Entidad(id, "SAMPLE")
{
    //constructor
}

Grafo::~Grafo()
{
    //destructor
}

/* Crear Nueva Adyacencia */
Vertice* Grafo::anyadirVertice(int i, char* nom = "_")
{
    if (not vertices[i])    // vertices[i] == NULL
        vertices[i] = new Vertice(i, nom);
    return vertices[i];
}

/* Añadir Arco nueva al Grafo */
Arista* Grafo::anyadirArista(int k, char* nom, int nvi, int nvf)
{
    if (not aristas[k]) {
        Vertice* vIni = anyadirVertice(nvi);
        Vertice* vFin = anyadirVertice(nvf);

        if (dirigido)
            aristas[k] = new Arco(k, nom);
        else
            aristas[k] = new Lado(k, nom);

        aristas[k]->extremo[INI] = vIni;
        aristas[k]->extremo[FIN] = vFin;

        vIni->Adyacentes.push_back(k);
        vFin->Incidentes.push_back(k);
        if (not dirigido)
            vFin->Adyacentes.push_back(k);
    }

    return aristas[k];
}

Arista* Grafo::anyadirArista(int k, char* nom, int nvi, int nvf, float costo)
{
    if (not aristas[k]) {
        Vertice* vIni = anyadirVertice(nvi);
        Vertice* vFin = anyadirVertice(nvf);

        if (dirigido)
            aristas[k] = new Arco(k, nom, costo);
        else
            aristas[k] = new Lado(k, nom, costo);

        aristas[k]->extremo[INI] = vIni;
        aristas[k]->extremo[FIN] = vFin;

        vIni->Adyacentes.push_back(k);
        vFin->Incidentes.push_back(k);
        if (not dirigido)
            vFin->Adyacentes.push_back(k);
    }

    return aristas[k];
}
