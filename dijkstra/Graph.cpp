//Graph.cpp
#include "Graph.h"
 
Graph::Graph()
{
  vs = new vector<Vertex>();
  es = new vector<Edge>();
}
 
Graph& Graph::addVertex(Vertex &v)
{
  vs->push_back(v);
  return *this;
}
 
Graph& Graph::addEdge(Edge &e)
{
  es->push_back(e);
  return *this;
}
 
Vertex& Graph::rmVertex(Vertex &v)
{
  return v;
}
 
Edge& Graph::rmEdge(Edge &e)
{
  return e;
}
 
ostream& operator<<(ostream &out, Graph &graph)
{
  vector<Edge>::iterator iterE;
  for(iterE = graph.es->begin(); iterE != graph.es->end(); iterE++)
    out << *iterE << endl;
 
  vector<Vertex>::iterator iterV;
  for(iterV = graph.vs->begin(); iterV != graph.vs->end(); iterV++)
    out << *iterV << endl;
 
  return out;
}
 
bool Graph::dijkstra(Vertex &v)
{
  if(vs->size() < 1)
    return false;
 
  set<int> *S = new set<int>();
  S->insert(v.getNodeId());
 
  set<int> *candidate = new set<int>();
  obtainCandidate(*S, *candidate);
  printS(*S);
  printCandidate(*candidate);
 
  vector<vector<int> > *dist = new vector<vector<int> >();
  int u = v.getNodeId();
  vector<int> *vec = new vector<int>(vs->size());
  for(unsigned int i = 0; i < vs->size(); i++)
    vec->at(i) = INT_MAX;
  vec->at(retrieveVertexById(u)) = 0;
  calcShortestPath(vs->at(retrieveVertexById(u)), *vec, *vec);
  dist->push_back(*vec);
 
  printDist(*dist);
 
  for(unsigned int i = 0; i < vs->size() -1; i++)
  {
    vector<int> *vec = new vector<int>();
    bool nextNode = calcShortestPath(vs->at(retrieveVertexById(u)), dist->at(i), *vec);
    if(false == nextNode) // no neighbour node, finish
       return true;
 
    dist->push_back(*vec);
    
    u = selectU(*candidate, *vec);
    S->insert(u);
    printS(*S);
    obtainCandidate(*S, *candidate);
    printDist(*dist);
  }
 
  return true;
}
 
bool Graph::calcShortestPath(Vertex &v, vector<int> &currentShortest, vector<int> &result)
{
   if(currentShortest != result)
   {
      vector<int>::iterator it = currentShortest.begin();
      for(; it != currentShortest.end(); it++)
         result.push_back(*it);
   }
 
   map<int, int> *edgeEnds = new map<int, int>();
   cout << "in calcShortestPath: v = " << v << endl;
   getEdgeEnd(v, *edgeEnds);
 
   if(edgeEnds->size() == 0) // no neighbour node
      return false;
 
   printEdgeEnds(*edgeEnds);
   map<int, int>::iterator iter = edgeEnds->begin();
   int weightToOrigin = currentShortest.at(retrieveVertexById(v.getNodeId()));
 
   for(; iter != edgeEnds->end(); iter++)
   {
     int weightCurrentToOrigin = currentShortest.at(retrieveVertexById(iter->first));
     if(weightToOrigin + iter->second < weightCurrentToOrigin)
     {
        result.at(retrieveVertexById(iter->first)) = weightToOrigin + iter->second;
     }
   }
   return true;
}
 
bool  Graph::getEdgeEnd(Vertex &v, map<int, int> &edgeEnds)
{
   vector<Edge>::iterator iter = es->begin();
   for(; iter != es->end(); iter++)
   {
      if(iter->getSrc() == v.getNodeId())
         edgeEnds.insert(pair<int, int>(iter->getDst(), iter->getWeight()) );
   }
   return true;
}
 
void Graph::printS(set<int> &s)
{
  cout << "S: ";
  set<int>::iterator it;
  for(it = s.begin(); it != s.end(); it++)
    cout << *it << " ";
  cout << endl;
}
 
void Graph::printCandidate(set<int> &candidate)
{
  cout << "candidate: " ;
  set<int>::iterator it;
  for(it = candidate.begin(); it != candidate.end(); it++)
    cout << *it << " ";
  cout <<endl;
}
 
bool Graph::printEdgeEnds(map<int, int> &ends)
{
  map<int, int>::iterator m = ends.begin();
  for(; m!= ends.end(); m++)
    cout << "vertex: " << m->first << " weight: " << m->second << endl;
 
  return true;
}
 
bool Graph::obtainCandidate(set<int> &s, set<int> &candidate)
{
  for(vector<Vertex>::iterator iter = vs->begin();
             iter != vs->end(); iter++)
      candidate.insert(iter->getNodeId());
 
  for(set<int>::iterator iter = s.begin(); 
             iter != s.end(); iter++)
     candidate.erase(*iter);
 
  return true;
}
 
unsigned int Graph::retrieveVertexById(int id)
{
  vector<Vertex>::iterator iter = vs->begin();
  for(unsigned int i = 0; iter != vs->end(); iter++, i++)
    if(id == iter->getNodeId())
       return i;
 
  return 0;
}
 
int Graph::selectU(set<int> &candidate, vector<int> &currentDist)
{
  int u = 0, minDist = INT_MAX;
  set<int>::iterator iter = candidate.begin();
  for(; iter != candidate.end(); iter++)
    if(currentDist.at(retrieveVertexById(*iter)) < minDist)
    {
      minDist = currentDist.at(retrieveVertexById(*iter));
      u = *iter;
    }
 
  return u;
}
 
bool Graph::printDist(vector<vector<int> > &dist)
{
  cout << "dist " << endl;
  for(vector<vector<int> >::iterator i1 = dist.begin();
         i1 != dist.end(); i1++)
  {
     for(vector<int>::iterator i2 = i1->begin(); i2 != i1->end(); i2++)
        cout <<*i2 << " ";
     cout << endl;
  }
  return true;
}
