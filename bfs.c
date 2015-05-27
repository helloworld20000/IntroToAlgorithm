//http://liuxinzhangyin.cn/60.html
#include <stdio.h>
#include <stdlib.h>
#define NUM 5
enum colors {white, gray, black};
const char const * color_name[3] = {"white", "gray", "black"};
enum colors flag[NUM] = {white, white, white, white, white};
int dist[NUM] = {0};
 
struct node
{
  int no;
  enum colors color;
  int distance;
  struct node *next;
};
 
void printAdjList(struct node adjList[], size_t size)
{
  int i = 0;
  struct node *current = 0;
  printf("The adjacent List:\n");
  for(i = 0; i < size; i++)
  {
     current = adjList + i;
     while(current != 0)
     {
        printf(" (%d, %s, %d) ", current->no, color_name[current->color],
                                current->distance);
        current = current->next;
     }
     printf("\n");
  }
}
 
int fifoInsertByNo(struct node *head, int no)
{
  struct node *p = head;
  struct node *new = (struct node*)malloc(sizeof(struct node));
  new->no = no;
  new->next = 0;
  new->color = white;
  new->distance = 0;
 
  while(p->next != 0)
    p = p->next;
  p->next = new;
  
  return 0;
}
 
int fifoInsertByNode(struct node *head, struct node *n)
{
  struct node *p = head;
  struct node *new = (struct node*)malloc(sizeof(struct node));
  new->no = n->no;
  new->next = 0;
  new->color = n->color;
  new->distance = n->distance;
 
  while(p->next != 0)
    p = p->next;
  p->next = new;
  
  return 0;
}
 
int fifoDelete(struct node *head)
{
  struct node *p = 0;
  int no = -1;
  if(0 == head->next)
     return 0;
 
  p = head->next;
  head->next = head->next->next;
  no = p->no;
  p->next = 0;
  
  free(p);
  return no;
}
 
int bfs(struct node *graph, int source) //source start by 0
{
   int del = 0;
   struct node *pGraph;
   struct node *head = (struct node*)malloc(sizeof(struct node));
   head->no = -1;
   head->next = 0;
 
   flag[source] = black;
   dist[source] = 0;
   fifoInsertByNode(head, (graph+source));
   while(0 != head->next)
   {
      del = fifoDelete(head);
      pGraph = graph + del -1;
      pGraph = pGraph->next;
      while(0 != pGraph)
      {
         if(white == flag[pGraph->no -1])
         {
            dist[pGraph->no -1] = dist[del -1] + 1;
            flag[pGraph->no -1] = gray;
            fifoInsertByNode(head, pGraph);
         }
      
         pGraph = pGraph->next;
       }
       flag[del - 1] = black;
       printf(" (%d, %d) \n", del, dist[del -1]);
    }
    return 0;
}
 
int main()
{
  struct node adjList[5];
  int i = 0;
  for(i = 0; i < 5; i++)
  {
     adjList[i].no = i + 1;
     adjList[i].next = 0;
     adjList[i].color = white;
     adjList[i].distance = 0;
  }
 
  fifoInsertByNo(adjList, 2); fifoInsertByNo(adjList, 5);
  fifoInsertByNo(adjList + 1, 1); fifoInsertByNo(adjList + 1, 5);
  fifoInsertByNo(adjList + 1, 3); fifoInsertByNo(adjList + 1, 4);
  fifoInsertByNo(adjList + 2, 2); fifoInsertByNo(adjList + 2, 4);
  fifoInsertByNo(adjList + 3, 2); fifoInsertByNo(adjList + 3, 5);
  fifoInsertByNo(adjList + 3, 3); fifoInsertByNo(adjList + 4, 4);
  fifoInsertByNo(adjList + 4, 1); fifoInsertByNo(adjList + 4, 2);
  printAdjList(adjList, 5);
 
  printf("after bfs(): \n");
  bfs(adjList, 2); //source start by 0
 
  return 0;
}
