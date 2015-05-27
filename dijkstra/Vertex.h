//Vertex.h
//http://liuxinzhangyin.cn/58.html
#ifndef VERTEX_H
#define VERTEX_H
#include <fstream>
#include <iostream>
 
using namespace std;
 
class Vertex
{
private:
   int nodeId;
 
public:
   Vertex(int nodeId);
   void setNodeId(int nodeId);
   int getNodeId(void);
 
   friend ostream& operator<<(ostream &out, Vertex &v);
};
 
#endif
