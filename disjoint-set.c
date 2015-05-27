/* http://liuxinzhangyin.cn/62.html
MAKE-SET(X)

UNION(X, Y)

FIND-SET(X)

CONNECTED_COMPONENTS(G)
for each vertex v in G.V
  MAKE-SET(v)
for each edge(u, v) in G.E
  if FIND-SET(u) != FIND-SET(v)
     UNION(u, v)

SAME-COMPONENT(u, v)
  if FIND-SET(u) == FIND-SET(v)
     return TRUE
  else return FALSE
*/

#include <stdio.h>
#include <stdlib.h>

struct Member
{
  char id;
  struct Member *next;
  struct Set *set;
};

struct Set
{
  struct Member *head;
  struct Member *tail;
};

int addMember(struct Set* S, struct Member* m)
{
  if(0 == S->head){
    S->head = m;
    S->tail = m;
    m->next = 0;
    m->set = S;
    return 0;
  }

  m->next = 0;
  m->set = S;
  S->tail->next = m;
  S->tail = m;
  return 0;
}

void printSet(const struct Set* S)
{
  struct Member *m = S->head;
  while(0 != m){
    printf(" %c ", m->id);
    m = m->next;
  }
}

int UNION(struct Set* S1, struct Set* S2)
{
  struct Member *m = S2->head;
  struct Member *next = 0;
  while(0 != m){
    next = m->next;
    addMember(S1, m);
    m = next;
  }
  free(S2);
  return 0;
}

int main()
{
  struct Set *S1 = (struct Set*)malloc(sizeof(struct Set));
  struct Set *S2 = (struct Set*)malloc(sizeof(struct Set));

  struct Member *f = (struct Member*)malloc(sizeof(struct Member)); 
  struct Member *g = (struct Member*)malloc(sizeof(struct Member));
  struct Member *d = (struct Member*)malloc(sizeof(struct Member)); 
  struct Member *c = (struct Member*)malloc(sizeof(struct Member));
  struct Member *h = (struct Member*)malloc(sizeof(struct Member)); 
  struct Member *e = (struct Member*)malloc(sizeof(struct Member)); 
  struct Member *b = (struct Member*)malloc(sizeof(struct Member));

  S1->head = 0; S1->tail = 0; S2->head = 0; S2->tail = 0;
  f->id = 'f'; g->id = 'g'; d->id = 'd';
  addMember(S1, f); addMember(S1, g); addMember(S1, d);

  c->id = 'c'; h->id = 'h'; e->id = 'e'; b->id = 'b';
  addMember(S2, c); addMember(S2, h); addMember(S2, e); addMember(S2, b);

  printSet(S1); printf("\n"); printSet(S2); printf("\n");

  UNION(S1, S2); printSet(S1); printf("\n");

  return 0;
}
