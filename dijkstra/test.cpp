//test.cpp
#include <iostream>
#include "Vertex.h"
#include "Edge.h"
#include "Graph.h"
using namespace std;
 
int main()
{
  Vertex *v1 = new Vertex(1);
  Vertex *v2 = new Vertex(2);
  Vertex *v3 = new Vertex(3);
  Vertex *v4 = new Vertex(4);
  Vertex *v5 = new Vertex(5);
 
  Edge *e1 = new Edge(1, 2, 10);
  Edge *e2 = new Edge(1, 5, 100);
  Edge *e3 = new Edge(1, 4, 30);
  Edge *e4 = new Edge(2, 3, 50);
  Edge *e5 = new Edge(3, 5, 10);
  Edge *e6 = new Edge(4, 5, 60);
  Edge *e7 = new Edge(4, 3, 20);
 
  Graph *g = new Graph();
  g->addVertex(*v1).addVertex(*v2).addVertex(*v3).addVertex(*v4);
  g->addVertex(*v5);
 
  g->addEdge(*e1).addEdge(*e2).addEdge(*e3).addEdge(*e4);
  g->addEdge(*e5).addEdge(*e6).addEdge(*e7);
 
  cout << "graph: \n" << *g << endl;
  
  g->dijkstra(*v2);
 
  return 0;
}
