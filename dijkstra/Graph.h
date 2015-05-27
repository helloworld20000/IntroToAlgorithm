//Graph.h
#ifndef GRAPH_H
#define GRAPH_H
 
#include "Vertex.h"
#include "Edge.h"
#include <vector>
#include <list>
#include <limits.h>
#include <set>
#include <map>
using namespace std;
 
class Graph
{
private:
  vector<Vertex> *vs;
  vector<Edge> *es;
public:
  Graph();
  Graph& addVertex(Vertex &v);
  Graph& addEdge(Edge &e);
  Vertex& rmVertex(Vertex &v);
  Edge& rmEdge(Edge &e);
 
  bool dijkstra(Vertex &v);
  bool getEdgeEnd(Vertex &v, map<int, int> &edgeEnds);
  void printS(set<int> &s);
  void printCandidate(set<int> &candidate);
  bool printEdgeEnds(map<int, int> &ends);
  bool obtainCandidate(set<int> &s, set<int> &candidate);
  bool calcShortestPath(Vertex &v, vector<int> &currentShortest, vector<int> &result);
  int selectU(set<int> &candidate, vector<int> &currentDist);
  unsigned int retrieveVertexById(int id);
  bool printDist(vector<vector<int> > &dist);
 
  friend ostream& operator<<(ostream &out, Graph &graph);
  ~Graph();
};
#endif
 

