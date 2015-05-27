//Edge.cpp
#include "Edge.h"
 
Edge::Edge(int src, int dst, int weight)
{
  this->src = src;
  this->dst = dst;
  this->weight = weight;
}
 
void Edge::setSrc(int src)
{
  this->src = src;
}
 
void Edge::setDst(int dst)
{
  this->dst = dst;
}
 
void Edge::setWeight(int weight)
{
  this->weight = weight;
}
 
int Edge::getSrc(void)
{
  return this->src;
}
 
int Edge::getDst(void)
{
  return this->dst;
}
 
int Edge::getWeight(void)
{
  return this->weight;
}
 
ostream &operator<<(ostream &out, Edge &e)
{
  out <<"{ src: " << e.src << " dst: " << e.dst << " weight " << e.weight << " }";
  return out;
}
