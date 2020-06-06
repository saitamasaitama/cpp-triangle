#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "triangle.h"
#include "vector3.h"

struct triangleIK
{
    Vector3 *Target;
    Vector3 *Origin;

    float bow1Length = 1;
    float bow2Length = 1;

    triangleIK(
        float bow1Length,
        float bow2Length,
        Vector3 *t = Vector3::One()
        )
    {
        this->Origin = Vector3::Zero();
        this->bow1Length=bow1Length;
        this->bow2Length=bow2Length;
        this->Target = t;
    }

    Triangle *triangle()
    {
        return Triangle::from3edges(
            bow1Length,
            bow2Length,
            this->TriangleEdgeLength());
    }

    float bow1Angle()
    {
        Triangle *triangle = this->triangle();
        Angle *angle = triangle->angleB;
        float result = 90.0 - angle->Degree() - this->Tilt();

        delete triangle;
        return result;
    };
    float bow2Angle()
    {
        Triangle *triangle = this->triangle();
        Angle *angle = triangle->angleC;
        float result = 180 - angle->Degree();

        delete triangle;
        return result;
    };

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
        printf(
            "EdgeLength: X=%4.2f Y=%4.2f ",
            this->XLength(),
            this->YLength());
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
        printf("Length: %4.2f ～ %4.2f \n", this->MinLength(), this->MaxLength());
        printf("Edge= %4.2f \n", this->EdgeLength());

        printf(
            "ARMS:\n"
            "\tBack = %4.2f ANGLE= %4.2f \n"
            "\tForward = %4.2f ANGLE= %4.2f \n",
            this->bow1Length, this->bow1Angle(),
            this->bow2Length, this->bow2Angle());

        printf("Pan= %4.2f \n", this->rotationY());
        printf("Tilt= %4.2f \n", this->rotationX());
    }
};
