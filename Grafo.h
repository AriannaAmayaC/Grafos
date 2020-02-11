
#pragma once

#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

const int NODIRIGIDO = false;
const int DIRIGIDO   = true;

const int INI = 0;
const int FIN = 1;

class Base {
    public:
    friend std::ostream& operator<< (std::ostream& os, const Base& p) {
        return p.imprimir(os);
   };

    protected:
    virtual std::ostream& imprimir(std::ostream& os) const = 0; // pure virtual
};

class Entidad : public Base
{
    protected:
        static int numSecuencia;

    private:
        int secID;

    public:
        int ID;
        std::string nombre;
        bool visitado;

        Entidad();
        Entidad(const int id);
        Entidad(const int id, const char *nom );
        Entidad(const int id, const string nom );
        Entidad(const Entidad& otro);
        Entidad& operator=(const Entidad& otro);
        virtual ~Entidad();

        virtual int getSecID(void) {return secID;};
        virtual int getID(void) {return ID;};

    protected:
        virtual std::ostream& imprimir(std::ostream& os) const {
            os << "[Nombre: " << nombre << ", secID: " << secID
               << ", ID: "    << ID << "]" << std::endl;
            return os;
        }

    virtual void unistantiable() = 0;
};


class Atributos
{
    public:
        float distancia;
};

/* Clase Vertice
*/
class Vertice : public Entidad
{
    public:
        int color;
        vector<int> Adyacentes;
        vector<int> Incidentes;

        float Pi;
        int Antecesor;
        float costoA;
        float tac;
        int grado;
        bool abierto;

        Vertice() : Entidad() { };
        Vertice(const int id) : Entidad(id) {};
        Vertice(const int id, const char *nom) : Entidad(id, nom) {};
        virtual ~Vertice();
        Vertice(const Vertice& otro);
        Vertice& operator=(const Vertice& otro);

    protected:
        virtual std::ostream& imprimir(std::ostream& os) const {
            os << "Vértice [" << ID << "] " << nombre << "," << endl;
        return os;
        }

    virtual void unistantiable() {};
};

/* Clase Lado como lista de nodos (abstracta)
*/

class Arista : public Entidad
{
    public:
        Vertice* extremo[2];
        Arista* opuesto;
        float costo;

        Arista() : Entidad() {
            extremo[INI] = NULL; // Vertice inicial
            extremo[FIN] = NULL; // Vertice final
        };
        Arista(const int id, const char *nom, const float c) : Entidad(id,nom) {
            costo= c;
        };
        Arista(const int id, const char *nom) : Entidad(id,nom) { };
        Arista(const int id, const char *nom,  const int ni, const int nf) : Entidad(id,nom) {};
        Arista(const int id, const char *nom,  const int ni, const int nf, const float c) : Entidad(id,nom) {
            costo =c;
        };
        virtual ~Arista();

        virtual void unistantiable() = 0;
};

class Arco : public Arista
{
    public:

        Arco() : Arista() { };
        Arco(const int id, const char *nom) : Arista(id,nom) { };
        Arco(const int id, const char *nom,  const int ni, const int nf) : Arista(id,nom) { };
        Arco(const int id, const char *nom, const float c) : Arista(id,nom, c) { };
        Arco(const int id, const char *nom,  const int ni, const int nf, const float c) : Arista(id,nom, c) { };
        virtual ~Arco();
        Arco(const Arco& Arco);
        Arco& operator=(const Arco& otro);

    protected:
        virtual std::ostream& imprimir(std::ostream& os) const {
            os << "[" << ID << "] " << nombre << " "
               << "(" << extremo[INI]->ID << ", " << extremo[FIN]->ID << ");  ";
            return os;
        }

        void unistantiable() { };  // hack !!
};

class Lado : public Arista
{
    public:

        Lado() : Arista() { };
        Lado(const int id, const char *nom) : Arista(id,nom) { };
        Lado(const int id, const char *nom, const int ni, const int nf) : Arista(id, nom) { };
        Lado(const int id, const char *nom, const float c) : Arista(id,nom, c) { };
        Lado(const int id, const char *nom, const int ni, const int nf, const float c) : Arista(id, nom, c) { };
        virtual ~Lado();
        Lado(const Lado& Lado);
        Lado& operator=(const Lado& Lado);

    protected:
        virtual std::ostream& imprimir(std::ostream& os) const {
            os << "[" << ID << "] " << nombre << " "
               << "{" << extremo[INI]->ID << ", " << extremo[FIN]->ID << "};  ";
            return os;
        }

    void unistantiable() { };  // hack !!
};

/* Clase Grafo
*/

class Grafo : public Entidad
{
    public:
        bool dirigido;
        std::vector<Vertice*> vertices;
        std::vector<Arista*> aristas;

        Grafo() : Entidad() { };
        Grafo(const int id);
        Grafo(const int id, const char *nom, bool d=NODIRIGIDO) : Entidad(id,nom) {
             dirigido = d;
        };
        Grafo(const Grafo& otro);
        Grafo& operator=(const Grafo& otro);
        virtual ~Grafo();

            // Member operators
        Grafo &operator += ( const Vertice& v)
        {
            std::cout << "Vertice " << v.ID << " aceptado" << std::endl;
            //V.push_back(v);
            return *this;
        }

        Grafo &operator += (const Lado &l)
        {
            std::cout << "Lado " << l.ID << " aceptado" << std::endl;
            return *this;
        }

        Grafo(int id, string nombre, int nv = 0, int na = 0, bool d=NODIRIGIDO) : Entidad(id, nombre) // constructor
        {
            dirigido = d;

            vertices.reserve(nv);
            for (auto k = 0; k<nv; k++)
                vertices.push_back(NULL);

            aristas.reserve(na);
            for (auto k = 0; k<na; k++)
                aristas.push_back(NULL);
        }

        /* Crear Nueva Adyacencia */
        Vertice* anyadirVertice(int NumVertice, char* nom);
        /* Añadir Lado nuevo al Grafo */
        Arista* anyadirArista(int NumArista, char* nom, int vertIni, int vertFin);

        Arista* anyadirArista(int NumArista, char* nom, int vertIni, int vertFin, float costo);

        int getNumVertices() { return vertices.size(); }

        int getNumAristas()  { return aristas.size();  }

    protected:
        virtual std::ostream& imprimir(std::ostream& os) const {
            os <<  endl << endl << "[GRAFO: " << nombre
               << ", ID: "    << ID << "]" << std::endl;

            string s4;

            if (dirigido)
                s4 = "  Arcos: ";
            else
                s4 = "  Lados: ";

            os << endl;
            for (auto v : vertices) {
                if (v) {
                    os << *v << s4;
                    for (auto k : v->Adyacentes)
                        os << *aristas[k];
                    os << endl;
                }
            }
            return os;
        }

    void unistantiable() { };  // hack !!
};


#endif // Grafo_H
