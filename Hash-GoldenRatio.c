/*Introduction to Algorithm Second Edtion Chapter 11.3
 *As an example, suppose we have k = 123456, p = 14, m = 16384, and w = 32 
 */

#include <stdio.h>
#include <stdlib.h>
typedef unsigned int u32;

#define MIDDLE 16384
#define MAX    30000
#define MIN     8000

u32 T[16384];

u32 hash(u32 key)
{
  u32  s = 2654435769;
  u32  r0 = key * s;
  u32  hash = r0 >> 18;

  return hash;
}

void performance(u32 len, u32 u)
{
  u32 i = 0;
  u32 random = 0;
  u32 count = 0;
  srand(time(NULL));
  for(i = 0; i < u; i++){
    random = rand();
    T[hash(random)]++;
  }

  printf("when len is %u, univeral is %u\n", len, u);
  printf("collided one time: ");
  for(i = 0; i < len; i++){
    if(T[i] == 2)
      count++;
  }
  printf("%d\n", count);

  printf("collided two times: ");
  for(i = 0; i < len; i++){
    if(T[i] == 3)
      count++;
  }
  printf("%d\n", count);
  
  printf("collided bigger than three times: ");
  for(i = 0; i < len; i++){
    if(T[i] > 3)
      count++;
  }
  printf("%d\n", count);
 
  printf("collied ratio: %u / %u = %f \n\n", count, len, count/(double)len);
}

int main()
{
   u32 i = 0;
   printf("hash(123456) = %u \n", hash(123456));

   for(i = 0; i < 16384; i++)
     T[i] = 0;

   performance(16384, MIN);
   performance(16384, MIDDLE);
   performance(16384, MAX);

   return 0;
}
