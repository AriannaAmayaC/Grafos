/*
Sartenejas, 26 de Junio de 20015.
Universidad Simón Bolívar
CI3621 - Grafos y Flujo en Redes.
Trimestre: Abril-Julio2015

Realizado por:
    Arianna Amaya, 12-11115
                                Asignación III: Ruta Crítica

*/



#include <iostream>
#include "Grafo.h"
#include "Algoritmo.h"

using namespace std;

int main()
{
    cout << "comienzo" << endl << flush;
    Grafo* miGrafo = new Grafo(71, "Grafo1", 5, 7, NODIRIGIDO);

    cout << "miGrafo creado" << endl << flush;
    miGrafo->anyadirVertice(0, "AA");
    miGrafo->anyadirVertice(1, "BB");
    miGrafo->anyadirVertice(2, "CC");
    miGrafo->anyadirVertice(3, "DD");
    miGrafo->anyadirVertice(4, "EE");

    miGrafo->anyadirArista(0, "a", 0, 1);
    miGrafo->anyadirArista(1, "b", 0, 4);
    miGrafo->anyadirArista(2, "c", 1, 2);
    miGrafo->anyadirArista(3, "d", 1, 3);
    miGrafo->anyadirArista(4, "e", 1, 4);
    miGrafo->anyadirArista(5, "f", 2, 3);
    miGrafo->anyadirArista(6, "g", 3, 4);

    // imprime Grafo miGrafo;
    std::cout << *miGrafo << std::endl;

    Grafo* G = new Grafo(37, "Grafo2", 5, 7, DIRIGIDO);
    G->anyadirVertice(0, "CAR");
    G->anyadirVertice(1, "MAR");
    G->anyadirVertice(2, "VAL");
    G->anyadirVertice(3, "BAR");
    G->anyadirVertice(4, "COR");

    G->anyadirArista(0, "a", 0, 1);
    G->anyadirArista(1, "b", 0, 4);
    G->anyadirArista(2, "c", 1, 2);
    G->anyadirArista(3, "d", 1, 3);
    G->anyadirArista(4, "e", 1, 4);
    G->anyadirArista(5, "f", 2, 3);
    G->anyadirArista(6, "g", 3, 4);

//    // imprime Grafo G;
    cout << *G << endl;
//
    Grafo* W = new Grafo(45, "Ejemplo de Clase", 8, 12, DIRIGIDO);
    W->anyadirVertice(0, "0");
    W->anyadirVertice(1, "1");
    W->anyadirVertice(2, "2");
    W->anyadirVertice(3, "3");
    W->anyadirVertice(4, "4");
    W->anyadirVertice(5, "5");
    W->anyadirVertice(6, "6");
    W->anyadirVertice(7, "7");

    W->anyadirArista( 0, "a", 0, 1);
    W->anyadirArista( 1, "b", 0, 2);
    W->anyadirArista( 2, "c", 0, 3);
    W->anyadirArista( 3, "d", 1, 4);
    W->anyadirArista( 4, "e", 1, 5);
    W->anyadirArista( 5, "f", 2, 1);
    W->anyadirArista( 6, "g", 3, 5);
    W->anyadirArista( 7, "h", 4, 2);
    W->anyadirArista( 8, "i", 6, 2);
    W->anyadirArista( 9, "j", 6, 7);
    W->anyadirArista(10, "k", 7, 4);
    W->anyadirArista(11, "l", 7, 6);
//    // imprime Grafo W;
    cout << *W << endl;

    Grafo* F = new Grafo(12, "Tricky", 6, 12, DIRIGIDO);
    F->anyadirVertice(0, "0");
    F->anyadirVertice(1, "1");
    F->anyadirVertice(2, "2");
    F->anyadirVertice(3, "3");
    F->anyadirVertice(4, "4");
    F->anyadirVertice(5, "5");

    F->anyadirArista( 0, "0-1", 0, 1);
    F->anyadirArista( 1, "0-3", 0, 3);
    F->anyadirArista( 2, "1-2", 1, 2);
    F->anyadirArista( 3, "1-5", 1, 5);
    F->anyadirArista( 4, "2-0", 2, 0);
    F->anyadirArista( 5, "2-4", 2, 4);
    F->anyadirArista( 6, "3-1", 3, 1);
    F->anyadirArista( 7, "3-4", 3, 4);
    F->anyadirArista( 8, "4-0", 4, 0);
    F->anyadirArista( 9, "4-5", 4, 5);
    F->anyadirArista(10, "5-2", 5, 2);
    F->anyadirArista(11, "5-3", 5, 3);

    // imprime Grafo F;
    cout << *F << endl;


    cout << "\nDFS a partir de los vertices pedidos\n" << endl;
    DFS *miDFS = new DFS(G);
    cout <<"DFS de G a partir del vertice 0\n"<< endl;
    miDFS->ejecutar(0);
    miDFS->limpiarListas();
    cout <<"DFS de G a partir del vertice 4\n"<< endl;
    miDFS->ejecutar(4);
    miDFS->limpiarListas();
    delete(miDFS);

    miDFS = new DFS (W);
    cout <<"DFS de W a partir del vertice 0\n"<< endl;
    miDFS->ejecutar(0);
    miDFS->limpiarListas();
    cout <<"DFS de W a partir del vertice 1\n"<< endl;
    miDFS->ejecutar(1);
    miDFS->limpiarListas();
    cout <<"DFS de W a partir del vertice 6\n"<< endl;
    miDFS->ejecutar(6);
    miDFS->limpiarListas();
    delete(miDFS);

    miDFS = new DFS (F);
    cout <<"DFS de F a partir del vertice 1\n"<< endl;
    miDFS->ejecutar(1);
    miDFS->limpiarListas();
    cout <<"DFS de F a partir del vertice 4\n"<< endl;
    miDFS->ejecutar(4);
    miDFS->limpiarListas();
    delete(miDFS);

//Algoritmo de Dijkstra

    Grafo* A = new Grafo(4, "grafo de la pregunta 7 del Problemario I", 9, 15, DIRIGIDO);
    A->anyadirVertice(0, "1");
    A->anyadirVertice(1, "a");
    A->anyadirVertice(2, "b");
    A->anyadirVertice(3, "c");
    A->anyadirVertice(4, "d");
    A->anyadirVertice(5, "e");
    A->anyadirVertice(6, "g");
    A->anyadirVertice(7, "h");
    A->anyadirVertice(8, "f");
    A->anyadirArista( 0, "1-a", 0, 1, 7);
    A->anyadirArista( 1, "1-c", 0, 3, 3);
    A->anyadirArista( 2, "a-b", 1, 2, 4);
    A->anyadirArista( 3, "a-d", 1, 4, 6);
    A->anyadirArista( 4, "a-e", 1, 5, 5);
    A->anyadirArista( 5, "b-d", 2, 4, 8);
    A->anyadirArista( 6, "b-g", 2, 6, 4);
    A->anyadirArista( 7, "c-b", 3, 2, 2);
    A->anyadirArista( 8, "c-g", 3, 6, 3);
    A->anyadirArista( 9, "d-e", 4, 5, 5);
    A->anyadirArista( 10, "d-f", 4, 8, 7);
    A->anyadirArista(11, "e-f", 5, 8, 4);
    A->anyadirArista(12, "g-d", 6, 4, 6);
    A->anyadirArista(13, "g-h", 6, 7, 8);
    A->anyadirArista(14, "f-h", 8, 7, 4);


    Grafo* B = new Grafo(5, "grafo de prueba", 12, 21, DIRIGIDO);
    B->anyadirVertice(0, "a");
    B->anyadirVertice(1, "b");
    B->anyadirVertice(2, "c");
    B->anyadirVertice(3, "d");
    B->anyadirVertice(4, "e");
    B->anyadirVertice(5, "f");
    B->anyadirVertice(6, "g");
    B->anyadirVertice(7, "h");
    B->anyadirVertice(8, "i");
    B->anyadirVertice(9, "j");
    B->anyadirVertice(10, "k");
    B->anyadirVertice(11, "l");

    B->anyadirArista( 0, "a-b", 0, 1, 2);
    B->anyadirArista( 1, "a-c", 0, 2, 1);
    B->anyadirArista( 2, "a-d", 0, 3, 2.5);
    B->anyadirArista( 3, "b-f", 1, 5, 0.7);
    B->anyadirArista( 4, "c-f", 2, 5, 0.5);
    B->anyadirArista( 5, "c-i", 2, 8, 1.5);
    B->anyadirArista( 6, "d-e", 3, 4, 0.3);
    B->anyadirArista( 7, "d-g", 3, 6, 1);
    B->anyadirArista( 8, "e-b", 4, 1, 1);
    B->anyadirArista( 9, "e-j", 4, 9, 2.3);
    B->anyadirArista(10, "e-h", 4, 7, 1);
    B->anyadirArista(11, "f-e", 5, 4, 1);
    B->anyadirArista(12, "f-j", 5, 9, 0.3);
    B->anyadirArista(13, "f-k", 5, 10, 0.25);
    B->anyadirArista(14, "g-h", 6, 7, 1.5);
    B->anyadirArista(15, "h-l", 7, 11, 1);
    B->anyadirArista(16, "i-k", 8, 10, 0.3);
    B->anyadirArista(17, "j-h", 9, 7, 0.2);
    B->anyadirArista(18, "k-j", 10, 9, 0.1);
    B->anyadirArista(19, "k-l", 10, 11, 0.2);
    B->anyadirArista(20, "l-j", 11, 9, 0.1);

    // imprime Grafo A;
    cout << *A << endl;

    cout << "Prueba I de algoritmo de Dijkstra" << endl;
    Dijkstra *miDijk = new Dijkstra (A);
    miDijk->ejecutar(0);
    miDijk->reportar();
    delete(miDijk);

     // imprime Grafo B;
    cout << *B << endl;

    cout << "Prueba II de algoritmo de Dijkstra" << endl;
    miDijk = new Dijkstra (B);
    miDijk->ejecutar(0);
    miDijk->reportar();
    delete(miDijk);

    Grafo *E = new Grafo(6,"Grafo de precedencia", 12, 21, DIRIGIDO);

    E->anyadirVertice(0, "a");
    E->anyadirVertice(1, "b");
    E->anyadirVertice(2, "c");
    E->anyadirVertice(3, "d");
    E->anyadirVertice(4, "e");
    E->anyadirVertice(5, "f");
    E->anyadirVertice(6, "g");
    E->anyadirVertice(7, "h");
    E->anyadirVertice(8, "i");
    E->anyadirVertice(9, "j");
    E->anyadirVertice(10, "k");
    E->anyadirVertice(11, "l");

    E->anyadirArista( 0, "a-b", 0, 1, 2);
    E->anyadirArista( 1, "a-c", 0, 2, 1);
    E->anyadirArista( 2, "a-d", 0, 3, 2.5);
    E->anyadirArista( 3, "b-e", 1, 4, 1);
    E->anyadirArista( 4, "b-f", 1, 5, 0.7);
    E->anyadirArista( 5, "c-f", 2, 5, 0.5);
    E->anyadirArista( 6, "c-i", 2, 8, 1.5);
    E->anyadirArista( 7, "d-e", 3, 4, 0.3);
    E->anyadirArista( 8, "d-g", 3, 6, 1);
    E->anyadirArista( 9, "e-j", 4, 9, 2.3);
    E->anyadirArista(10, "e-h", 4, 7, 1);
    E->anyadirArista(11, "f-e", 5, 4, 1);
    E->anyadirArista(12, "f-j", 5, 9, 0.3);
    E->anyadirArista(13, "f-k", 5, 10, 0.25);
    E->anyadirArista(14, "g-h", 6, 7, 1.5);
    E->anyadirArista(15, "h-l", 7, 11, 1);
    E->anyadirArista(16, "i-k", 8, 10, 0.3);
    E->anyadirArista(17, "j-h", 9, 7, 0.2);
    E->anyadirArista(18, "j-l", 9, 11, 0.1);
    E->anyadirArista(19, "k-j", 10, 9, 0.1);
    E->anyadirArista(20, "k-l", 10, 11, 0.2);

    cout << endl;
    cout << *E << endl;

    cout << "Prueba del algoritmo para hallar la ruta critica" << endl;

    RutaCritica *ruta = new RutaCritica(E);
    ruta->ejecutar(0);
    ruta->reportar();

    delete(ruta);

    return 0;
}
