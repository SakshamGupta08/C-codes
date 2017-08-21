#include "Graph.h"

int main() {
    Graph g;


    char a[] = "A";
    char b[] = "B";
    g.addVertex(a);
    g.addVertex(b);
    g.addVertex("C");
    g.addVertex("D");
    g.addVertex("E");

    g.addEdge(a, b);
    g.addEdge("A", "C");
    g.addEdge("C", "D");
    g.addEdge("C", "E");
    g.addEdge("D", "E");


    g.print();

    g.getPath(a,b);
    cout<<g.connectedcomponents()<<endl;

}
