#include <stdio.h>

#include "triangleIK.h"

int main()
{
  printf("OK OK\n");

  triangleIK *ik = new triangleIK(
      1.1,1.2,
      new Vector3(1, 1, 1))
  ;

  ik->dump();
  
  return 0;
}
