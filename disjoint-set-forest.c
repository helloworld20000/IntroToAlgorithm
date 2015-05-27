/* http://liuxinzhangyin.cn/63.html
MAKE-SET(X)

UNION(X, Y)

FIND-SET(X)

MAKE-SET(X)
 X.p = X
 X.rank = 0

UNION(X, Y)
 LINK(FIND-SET(X), FIND-SET(Y))

LINK(X, Y)
 if x.rank > y.rank
    y.p=x
 else  x.p = y
   if x.rank = y.rank
      y.rank = y. rank + 1

 FIND-SET(X)
  if x ! = x.p
    x.p = FIND-SET(x.p)
  return x.p

*/

//
//
//
#include <stdio.h>
#include <stdlib.h>

struct Node
{
   char id;
   struct Node *parent;
   struct Node *lchild;
   struct Node *rchild;
   int rank;
};

void MAKE_SET(struct Node *n, char id)
{
   n->parent = n;
   n->rank = 0;
   n->id = id;
   n->lchild = 0;
   n->rchild = 0;
}

struct Node* FIND_SET(struct Node *n)
{
   if(n->id != n->parent->id)
     n->parent = FIND_SET(n->parent);
   return n->parent;
}

struct Node* MERGE(struct Node *x, struct Node *y) //Merge x to y
{
   struct Node *p = y;
   struct Node *pChild = y->lchild;
   while(0 != pChild){
      p = pChild;
      pChild = pChild->lchild;
   }
   p->lchild = x;
   return y;
}

struct Node* LINK(struct Node *x, struct Node *y)
{
   if(x->rank > y->rank){
      y->parent = x;
      return MERGE(y,x);
   }
   else{
      x->parent = y;
      if(x->rank == y->rank)
        y->rank = y->rank + 1;
      return MERGE(x, y);
  }
}

struct Node* UNION(struct Node *x, struct Node *y)
{
  return LINK(FIND_SET(x), FIND_SET(y));
}

int printTree(struct Node *x)
{
  if(0 == x)
    return 0;
  printf(" %c-%d ", x->id, x->rank);
  printTree(x->lchild);
  printTree(x->rchild);
  return 0;
}

int main()
{
  struct Node *p, *q;
  struct Node *c = (struct Node*)malloc(sizeof(struct Node));
  struct Node *h = (struct Node*)malloc(sizeof(struct Node));
  struct Node *e = (struct Node*)malloc(sizeof(struct Node));
  struct Node *b = (struct Node*)malloc(sizeof(struct Node));
  MAKE_SET(c, 'c'); MAKE_SET(h, 'h'); MAKE_SET(e, 'e'); MAKE_SET(b, 'b');
  p = UNION(c, h); p = UNION(p, e); p = UNION(p, b); printTree(p); printf("\n");

  struct Node *f = (struct Node*)malloc(sizeof(struct Node));
  struct Node *d = (struct Node*)malloc(sizeof(struct Node));
  struct Node *g = (struct Node*)malloc(sizeof(struct Node));
  MAKE_SET(f, 'f'); MAKE_SET(d, 'd'); MAKE_SET(g, 'g');
  q = UNION(f, d); q = UNION(q, g); printTree(q); printf("\n");
  p = UNION(p, q); printTree(p); printf("\n");
  return 0;
  
 
}
