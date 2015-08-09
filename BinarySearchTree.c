/*The search tree data structure supports many dynamic-set operations,
 *including SEARCH, MINIMUM, MAXIMUM, PREDECESSOR, SUCCUESSOR, INSERT,
 *and DELETE. Thus, we can use a search tree both as a dictionary and
 *as a priority queue.
 */

#include <stdlib.h>
#include <stdio.h>

#define NIL 0

struct node {
  struct node *p;
  struct node *l;
  struct node *r;
  int key;
};

struct tree {
  struct node *root;
};

struct node* init(int k)
{
  struct node *n = (struct node*)malloc(sizeof(struct node));
  n->p = NIL;
  n->l = NIL;
  n->r = NIL;
  n->key = k;
  
  return n;
}

struct node* search(struct node *x, int k)
{
  if(x == NIL || k == x->key)
    return x;
  if(k < x->key)
    return search(x->l, k);
  else
    return search(x->r, k);
}

struct node* minimum(struct node *x)
{
  while(x->l != NIL)
   x = x->l;
  return x;
}

struct node* maximum(struct node *x)
{
  while(x->r != NIL)
   x = x->r;
  return x;
}

//predecesor()

struct node* successor(struct node *x)
{
  if(x->r != NIL)
    return minimum(x->r);
  struct node *y = x->p;
  while(y != NIL && x == y->r){
    x = y;
    y = y->p;
  }
  return y;
}

void insert(struct tree *T, struct node *z)
{
  struct node *y = NIL;
  struct node *x = T->root;
  while(x != NIL){
    y = x;
    if(z->key < x->key)
      x = x->l;
    else
      x = x->r;
  }
  z->p = y;
  if(y == NIL)
    T->root = z; // tree T was empty
  else if(z->key < y->key)
    y->l = z;
  else
    y->r = z;
}

void transplant(struct tree *T, struct node *u, struct node *v)
{
  if(u->p == NIL)
    T->root = v;
  else if(u == u->p->l)
    u->p->l = v;
  else
    u->p->r = v;
  if(v != NIL)
    v->p = u->p;
}

void delete(struct tree *T, struct node *z)
{
  struct node *y = NIL;
  if(z->l == NIL)
    transplant(T, z, z->r);
  else if(z->r == NIL)
    transplant(T, z, z->l);
  else {
    y = minimum(z->r);
    if(y->p != z){
      transplant(T, y, y->r);
      y->r = z->r;
      y->r->p = y;
    }
    transplant(T, z, y);
    y->l = z->l;
    y->l->p = y;
  }
}

void printTreeInOrder(struct node *x)
{
  if(x != NIL){
    printTreeInOrder(x->l);
    printf(" %d ", x->key);
    printTreeInOrder(x->r);
  }
}

void printTreePreOrder(struct node *x)
{
  if(x != NIL){
    printf(" %d ", x->key);
    printTreePreOrder(x->l);
    printTreePreOrder(x->r);
  }
}

int main()
{
   struct tree *T = (struct tree*)malloc(sizeof(struct tree));
   T->root = NIL;
   struct node *n = NIL;
   int keys[11] = {15,6,18,3,7,2,4,13,9,17,20};
   int i = 0;
   for(; i < 11; i++){
     n = init(keys[i]);
     insert(T, n);
     printf("After inserting %d inorder: ", keys[i]);
     printTreeInOrder(T->root);
     printf("\nPreOrder: ");
     printTreePreOrder(T->root);
     printf("\n");
   }
   printf("Minimum=%d, Maxmum=%d\n",minimum(T->root)->key, maximum(T->root)->key);

  printf("Print Tree in PreOrder: ");
  printTreePreOrder(T->root);
  
  printf("\nAfter deleting 3: ");
  delete(T, search(T->root, 3));
  printTreeInOrder(T->root);

  printf("\n15 successor is %d\n",successor(search(T->root, 15))->key );
  return 0;
}


