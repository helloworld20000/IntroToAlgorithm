//http://liuxinzhangyin.cn/61.html
#include <stdlib.h>
#include <stdio.h>
#define NUM 6
enum colors{white, gray, black};

struct node
{
  char name;
  enum colors color;
  int start;
  int end;
  struct node *next;
  struct node *ptr;
};

int time = 1;
enum colors flag[NUM] = {white, white, white, white, white, white};
const char *colors_name[3] = {"white","gray","black"};

struct node *stack_top = 0;
size_t size = 0;

int push(struct node *n)
{
  struct node *element = (struct node*)malloc(sizeof(struct node));
  element->ptr = n;
  element->next = 0;
  if(0 == size) // stack empty
  {
     stack_top = element;
     size++;
  }
  else // more than one element in stack
  {
     element->next = stack_top;
     stack_top = element;
     size++;
  }
  return 0;
}


struct node* pop(void)
{
   struct node *element = 0;
   if(size > 0)
   {
     element = stack_top->ptr;
     stack_top = stack_top->next;
     size--;
   }else
   
   {
     return 0;
   }

   return element;
}



int addNode(struct node *head, char name)
{
     struct node *n = (struct node*)malloc(sizeof(struct node));
     n->name = name;
     n->color = white;
     n->start = 0;
     n->end = 0;
     n->ptr = 0;
     n->next = 0;



     if(head == 0) // head empty,return false
       return -1;


     
     n->next = head->next;
     head->next = n;



     return 0;
}  

     void init(struct node *head)
     {
        int i = 0;


        for(i=0;i<NUM;i++)
        {
           (head+i)->name = 'u' + i;
           (head+i)->color =white;
           (head+i)->start = 0;
           (head+i)->end = 0;
           (head+i)->ptr = 0;
           (head+i)->name = 'u' + i;
           (head+i)->color = white;
           (head+i)->start = 0;
           (head+i)->end = 0;
           (head+i)->ptr = 0;
           (head+i)->next = 0;
         }

         addNode(head,'v'); addNode(head,'x');
         addNode(head+1,'y');
         addNode(head+2,'y');addNode(head+2,'z');
         addNode(head+3,'v');
         addNode(head+4,'x');
         addNode(head+5,'z');
     }


     void print(struct node *head)
     {
         int i = 0;
         struct node *p = head;
         printf("Adjacency Table: \n");
         for(i=0;i<NUM;i++)
         {
            while(0 !=p)
            {
               printf(" %c ",p->name);
               p=p->next;
            }
            printf("\n");
            p = head + i +1;
         }
     }

     struct node* existWhiteChild(struct node *n) // if existed, return it. else return 0 pointer
     {
        struct node *p = n;
        while(0 != p)
        {
            if(white == flag[p->name - 'u'])
              return p;
            p = p->next;
        }
        return 0;
     }

     int dfs(struct node *head)
     {
        struct node *pt = 0;
        int i = 0;
        for(i=0; i < NUM; i++)
        {
            if(white == flag[i])
            {
                flag[i] = gray;
                (head+i)->start = time;
                printf("node %c start: %d color:%s\n", (head+i)->name,
                    (head+i)->start, colors_name[ flag[i] ]);
                time++;
                push(head+i);
                pt = existWhiteChild(head+i);
                while(0 != pt)
                {
                   flag[pt->name-'u'] = gray;
                   (head+pt->name-'u')->start = time;
                   time++;
                   push(pt);
                   printf("node %c start: %d color:%s\n", (head+pt->name -'u')->name,
                    (head+pt->name-'u')->start, colors_name[ flag[pt->name-'u'] ]);
                  
                   pt = existWhiteChild(head+pt->name-'u');
                }
                while(0 != (pt = pop()) )
                {
                   flag[pt->name-'u'] = black;
                   (head+pt->name-'u')->end = time;
                   time++;
                   printf("node %c start: %d end: %d color:%s\n", (head+pt->name -'u')->name,
                    (head+pt->name-'u')->start, (head+pt->name-'u')->end,colors_name[ flag[pt->name-'u'] ]);
                 
                }
            }
        }
     }

     int main()
     {
         struct node *head = (struct node*)malloc(sizeof(struct node)*NUM);
         init(head);
         print(head);
         dfs(head);
         return 0;
     }

