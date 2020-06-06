#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "vector3.h"

struct triangleIK
{
    Vector3 *Target;
    Vector3 *Origin;

    float bow1Length;
    float bow2Length;

    triangleIK(Vector3 *t = Vector3::One())
    {
        this->Origin = Vector3::Zero();
        this->Target = t;
    }

    float MinLength()
    {
        return fabs(
            this->bow2Length -
            this->bow1Length);
    };
    float MaxLength()
    {
        return bow2Length + bow1Length;
    };

    float XLength()
    {
        return Target->X - Origin->X;
    };

    float YLength()
    {
        return Target->Z - Origin->Z;
    };

    float TargetHeight()
    {
        return Target->Y - Origin->Y;
    };

    float EdgeLength()
    {
        return sqrtf(
            this->XLength() * this->XLength() +
            this->YLength() * this->YLength());
    };

    float rotationY()
    {
        return atan2(
                   this->Target->X - this->Origin->X,
                   this->Target->Z - this->Origin->Z) /
               M_PI * 180.0;
    }

    float rotationX()
    {
        return atan2(
                   this->EdgeLength(),
                   this->TargetHeight()) /
               M_PI * 180;
    };

    float TargetDistance()
    {
        return Vector3::Distance(this->Origin, this->Target);
    };
    /*三角形の辺の長さ*/
    float TriangleEdgeLength()
    {
        return fmin(
            this->MaxLength(),
            fmax(this->TargetDistance(),
                 this->MinLength()));
    };
    float Tilt()
    {
        return 90.0 - this->rotationX();
    };

    //先端の位置

    /*
    Vector3 Tip()
    {
        return this->Origin + (bow1.rotation * Vector3.up * bow1Length) + (bow2.rotation * Vector3.up * bow2Length);
    }
    */

    void dump()
    {
        printf("triangleIK:\n");
        printf("Edge= %4.2f \n", this->EdgeLength());
        printf("Pan= %4.2f \n", this->rotationY());
        printf("Tilt= %4.2f \n", this->rotationX());
    }
};
