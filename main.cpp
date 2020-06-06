#include <stdio.h>

#include "triangleIK.h"

int main()
{
  printf("OK OK\n");
  Angle *a = Angle::FromDegree(90);
  printf("ANGLE (RAD=%4.2f DEG=%4.2f )\n", a->Radian(), a->Degree());
  a->dump();

  triangleIK *ik = new triangleIK(
      new Vector3(1, 1, 1));

  ik->dump();
  ik->dump();
  return 0;
}
