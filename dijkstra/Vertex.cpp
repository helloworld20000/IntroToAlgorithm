//Vertex.cpp
//http://liuxinzhangyin.cn/58.html
#include "Vertex.h"
 
Vertex::Vertex(int nodeId)
{
   this->nodeId = nodeId;
}
 
void Vertex::setNodeId(int nodeId)
{
   this->nodeId = nodeId;
}
 
int Vertex::getNodeId(void)
{
   return this->nodeId;
}
 
ostream& operator<<(ostream &out, Vertex &v)
{
   out << "Vertex num: " << v.nodeId;
   return out;
}
