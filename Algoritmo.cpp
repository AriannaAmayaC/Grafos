#include "Algoritmo.h"

void MGE::reportar() {

    for(auto i : caminosCerrados){
        if (i.verticePartida==i.verticeDestino)
            cout << "<" << grafo->vertices[i.verticePartida]->nombre << ">"<<endl;
        else
            cout << "<" << grafo->vertices[i.verticePartida]->nombre << ","
            << grafo->aristas[i.Arista]->nombre << "," <<
            grafo->vertices[i.verticeDestino]->nombre << ">\n"<< endl;
    }
    cout << "Finalizado ..\n"   << endl;
    };

void MGE::calcularAtributos()
    {

    };

void MGE::escogerCaminoAbierto(Camino &aux)
    {

    };

void MGE::eliminarCaminos()
    {

    };

void MGE:: ejecutar(int v){

    s = grafo->vertices[v];  // Debe existir el vértice !!!
    cout << "Ejecutando ..."    << endl;

//  (0) Caminos abiertos, cerrados y nuevos vacíos

    Camino inicial, actual;
    int vj;
    Camino Ck;

   //  Colocar <s> en caminosAbiertos
    s->visitado=true;
    inicial.verticePartida=s->getID();
    inicial.verticeDestino=s->getID();
    caminosAbiertos.push_back(inicial);

   // (1) mientras CamAb no vacía hacer
    while (!caminosAbiertos.empty()){

        //(1.1) Escoger camino de CamAb
        escogerCaminoAbierto(actual);

        //(1.2) Cerrarlo (pasarlo a CamCer)
        vj=actual.verticeDestino;
        grafo->vertices[vj]->visitado=true;
        caminosCerrados.push_back(actual);

       /* (1.3) Obtener sucesores Cj = <...vj>
        (1.4) Construir caminos nuevos Ck = <vj..wk>*/
        Ck.verticePartida=vj;
        for(auto i: grafo->vertices[vj]->Adyacentes){
            Ck.Arista = i;
            Ck.verticeDestino=grafo->aristas[i]->extremo[FIN]->getID();
            caminosNuevos.push_back(Ck);
        }
           // (1.5) Calcular atributos de cada Ck
        calcularAtributos();
       /* (1.6) Para todo camino nuevo hacer
            (1.1.1) Aplicar Eliminación de caminos*/
        eliminarCaminos();
    }
   // (2) Reportar lista de caminos (arcos) Cerrados
    reportar();

    }


void DFS :: DFSCompleto(int v){
    for (auto i: grafo->vertices)
        i->visitado = false;
    ejecutar(v);
    for (auto i: grafo->vertices){
        if( !i->visitado)
            ejecutar(i->getID());
    }
}

void DFS ::escogerCaminoAbierto(Camino &aux ){
        aux=caminosAbiertos.back();
        caminosAbiertos.pop_back();

    }


int DFS::ExistenCA(int Vi){
        size_t i;
        for(i=0; i<caminosAbiertos.size(); i++)
            if(Vi==caminosAbiertos[i].verticeDestino)
                return i;
        return -1;
    }

int DFS::ExistenCC(int Vi){
        size_t i;
        for(i=0; i<caminosCerrados.size(); i++)
                if(Vi==caminosCerrados[i].verticeDestino)
                    return i;
        return -1;
    }

void DFS::eliminarCaminos()
    {
    int CA, CC;
    for(auto k: caminosNuevos){
        CA = ExistenCA(k.verticeDestino);
        CC = ExistenCC(k.verticeDestino);
            if ((CA==-1)&&(CC==-1))
                caminosAbiertos.push_back(k);
            else if(CA!=-1){
                caminosAbiertos.erase(caminosAbiertos.begin()+CA);
                caminosAbiertos.push_back(k);
        }
    }
        caminosNuevos.clear();

    }

void DFS :: limpiarListas(){

    caminosNuevos.clear();
    caminosAbiertos.clear();
    caminosCerrados.clear();

}

int Dijkstra:: VerticeA_MenorCosto(){
    int minimo = -1;
    float c = std::numeric_limits<double>::infinity();
    for (auto i: grafo->vertices){
        if((i->abierto) && (i->costoA < c)){
            minimo = i->getID();
            c= i->costoA;
        }
    }
    return minimo;
}

void Dijkstra :: imprimircamino(int v) {
    Arista *a;
    if (grafo->vertices[v]->Antecesor ==-1){
        cout << "<" <<grafo->vertices[v]->nombre;
    } else {
        imprimircamino(grafo->vertices[v]->Antecesor);
        for (auto i: grafo->vertices[grafo->vertices[v]->Antecesor]->Adyacentes) {
            a = grafo->aristas[i];
            if (a->extremo[FIN]->getID() == v)
                break;
        }
        cout << ", " << a->nombre;
        cout << ", " << grafo->vertices[v]->nombre;
    }
}

void Dijkstra :: reportar (){
    for (auto k: grafo->vertices){
        imprimircamino (k->getID());
        cout << ">" << endl;
    }
}

void Dijkstra :: ejecutar (int v){

    s=grafo->vertices[v];
    int vertice;
    Vertice* sucesor;
    float c;
    for (auto k: grafo->vertices){
        if (k==s)
            k->costoA= 0;
        else
            k->costoA= std::numeric_limits<double>::infinity();

        k->Antecesor = -1;
        k->abierto= true;
    }

    while ((vertice = VerticeA_MenorCosto())!=-1)
    {
        grafo->vertices[vertice]->abierto = false;
        c= grafo->vertices[vertice]->costoA;
        for( auto k: grafo->vertices[vertice]->Adyacentes){
            sucesor = grafo->aristas[k]->extremo[FIN];
            if (sucesor->abierto){
                if ((c + grafo->aristas[k]->costo) < sucesor->costoA){
                    sucesor->Antecesor = vertice;
                    sucesor->costoA = c + grafo->aristas[k]->costo;
                }
            }
        }

    }

}

void RutaCritica::imprimirCamino(int v) {
    Arista *a;
    if (grafo->vertices[v]->Antecesor ==-1){
        cout << "<" <<grafo->vertices[v]->nombre;
    } else {
        imprimirCamino(grafo->vertices[v]->Antecesor);
        for (auto i: grafo->vertices[grafo->vertices[v]->Antecesor]->Adyacentes) {
            a = grafo->aristas[i];
            if (a->extremo[FIN]->getID() == v)
                break;
        }
        cout << ", " << a->nombre;
        cout << ", " << grafo->vertices[v]->nombre;
    }
}

void RutaCritica::reportar() {
    cout << "Caminos maximos segun el algoritmo de Bellman:" << endl;
    for (auto k: grafo->vertices) {
        cout << "Camino: ";
        imprimirCamino(k->getID());
        cout << ">, Costo: " << k->costoA << endl;
    }

    string separador = "+----------+----------+----------+----------+";
    cout << endl <<"TEC, TAC y holgura de cada vertice:" << endl;
    cout << separador << endl;
    cout << '|' << setw(10) << left << "Vertice" << '|' << setw(10) << "TEC" << '|';
    cout << setw(10) << "TAC" << '|' << setw(10) << "Holgura" << '|' << endl;
    cout << separador << endl;
    for (auto k: grafo->vertices){
    cout << '|' << setw(10) << k->nombre << '|' << setw(10) << k->costoA << '|';
    cout << setw(10) << k->tac << '|' << setw(10) << k->tac - k->costoA << '|' << endl;
    cout << separador << endl;
    }

    cout << endl << "Camino critico: " << endl;
    Vertice *mayorCosto = grafo->vertices[0];
    for (auto k: grafo->vertices){
        if (k->costoA > mayorCosto->costoA) {
            mayorCosto = k;
        }
    }
    imprimirCamino(mayorCosto->getID());
    cout << '>' << endl;
    cout << "Costo acumulado: " << mayorCosto->costoA << endl;
}

void RutaCritica::bellmanModificado(int v){
    set<int> conjunto;
    int id_vertice, grad;
    Vertice *actual, *adyacente;
    Arista *arisAdyacente;

    actual = grafo->vertices[v];
    actual->costoA = 0;
    actual->Antecesor = -1;
    conjunto.insert(v);
    for (auto k: grafo->vertices) {
        grad = 0;
        for (auto q: k->Incidentes)
            grad++;
        k->grado = grad;
        if (k->getID()!= v) {
            k->costoA = std::numeric_limits<float>::infinity();
        }
    }

    while (!conjunto.empty()){
        id_vertice = *conjunto.begin();
        conjunto.erase(id_vertice);
        actual = grafo->vertices[id_vertice];
        for (auto k: actual->Adyacentes) {
            arisAdyacente = grafo->aristas[k];
            adyacente = arisAdyacente->extremo[FIN];
            adyacente->grado = adyacente->grado - 1;
            if (adyacente->grado == 0) {
                conjunto.insert(adyacente->getID());
            }
            if (adyacente->costoA > actual->costoA - arisAdyacente->costo) {
                // los costos se toman negativos para hallar caminos máximos
                adyacente->costoA = actual->costoA - arisAdyacente->costo;
                adyacente->Antecesor = actual->getID();
            }
        }
    }

    for (auto k: grafo->vertices)
        k->costoA *= -1;
        // se regresan los costos a positivo
}

void RutaCritica::visitaDFS(int v, vector<int> &ordenamiento) {
    Vertice * actual, *adyacente;
    actual = grafo->vertices[v];
    actual->visitado = true;
    for (auto k: actual->Adyacentes){
        adyacente = grafo->aristas[k]->extremo[FIN];
        if (!adyacente->visitado) {
            visitaDFS(adyacente->getID(), ordenamiento);
        }
    }
    ordenamiento.push_back(actual->getID());
}

vector<int> RutaCritica::ordenTopologico(int v) {
    vector<int> ordenamiento;
    for (auto k: grafo->vertices)
        k->visitado = false;
    ordenamiento.reserve(grafo->vertices.size());
    visitaDFS(v, ordenamiento);
    return ordenamiento;
}

void RutaCritica::calcularTAC(int v) {
    Vertice *actual, *adyacente;
    vector<int> ordenamiento = ordenTopologico(v);
    actual = grafo->vertices[ordenamiento[0]];
    actual->tac = actual->costoA;
    for (auto i: ordenamiento) {
        actual = grafo->vertices[i];
        if (i != ordenamiento[0])
            actual->tac = std::numeric_limits<float>::infinity();
        for (auto j: actual->Adyacentes) {
            adyacente = grafo->aristas[j]->extremo[FIN];
            if (actual->tac > adyacente->tac - grafo->aristas[j]->costo) {
                actual->tac = adyacente->tac - grafo->aristas[j]->costo;
            }
        }
    }
}

void RutaCritica::ejecutar(int v) {
    bellmanModificado(v);
    calcularTAC(v);
    // el camino crítico se busca en reportar()
}
