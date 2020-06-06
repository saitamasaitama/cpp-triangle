#include <stdio.h>
#include "triangle.h"
#include "triangleIK.h"

int main()
{
  printf("OK OK\n");
  Angle *a = Angle::FromDegree(90);
  printf("ANGLE (RAD=%4.2f DEG=%4.2f )\n", a->Radian(), a->Degree());
  a->dump();

  Triangle *tri = Triangle::from3edges(3, 4, 5);

  triangleIK *ik = new triangleIK();
  tri->dump();
  ik->dump();
  return 0;
}
