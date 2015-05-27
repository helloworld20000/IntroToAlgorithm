//http://liuxinzhangyin.cn/58.html
//edge.h
#ifndef EDGE_H
#define EDGE_H
 
#include <iostream>
#include <fstream>
using namespace std;
 
class Edge
{
private:
  int src;
  int dst;
  int weight;
public:
  Edge(int src, int dst, int weight);
  void setSrc(int src);
  void setDst(int dst);
  void setWeight(int weight);
  int getSrc(void);
  int getDst(void);
  int getWeight(void);
  friend ostream &operator<<(ostream &out, Edge &e);
};
 
#endif
