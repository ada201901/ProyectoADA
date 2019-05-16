#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QGeoRoute>
#include <QGeoCoordinate>
#include <QQmlComponent>
#include "Grafo/read.h"
#include "Grafo/graph.h"
#include <set>
#define nNodos 5
#define distMax 100000

int main(int argc, char *argv[])
{
    graph g1;
    rd gg;
    gg.getGraph(&g1);
    auto nodos = g1.getNodes();
    unsigned long numNodos = g1.total_nodos();
    srand (time(nullptr));

    vector <string> loquemevanadarlasfunciones;
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    QQmlComponent component(&engine,QUrl::fromLocalFile("qrc:/misListas.qml"));
    vector<QObject*> misListas;
    //TODO
    //acuerdate, a qt le vas a pasar SOLO COORDENADAS, i =2n, n siendo el numero del nodo
    auto idNodoi = nodos.begin();
    auto idNodoj = nodos.begin() ;
    std::set<int> ids;
    vector<int> idsParafind;

    //encuentra n nodos diferentes
    for (int x = 0;x <= nNodos; x++) {
        int currRand = rand()%numNodos ;
        while(!(ids.insert(currRand)).second)currRand= rand() %numNodos;
        //Tenemos los i's de los nodos a ser usados
    }
    for (int i =0;i < numNodos; i++) {
        if (i == (*ids.find(i)) ) {
        misListas.push_back(component.create());
        //placeholders, esto es lima


        misListas[i]->setProperty("centerLong","-12.1348806");
        misListas[i]->setProperty("centerLat","-77.02212709999999");


        for (unsigned long j =0;j <= loquemevanadarlasfunciones.size(); j++) {
            vector<string> toSetCoords;
            toSetCoords.push_back(loquemevanadarlasfunciones[j]);

            if (j == loquemevanadarlasfunciones.size()){
                QVariant buffer;
                buffer.setValue(toSetCoords);
                misListas[i]->setProperty("vectorCoords",buffer);
            }
        }

    }idNodoi++;
    }
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
