#include <math.h>
#include <stdlib.h>
#include <stdio.h>

struct Angle
{
    Angle(){};
    static Angle *FromRadian(float radian)
    {
        Angle *angle = new Angle();
        angle->radian = radian;
        return angle;
    };
    static Angle *FromDegree(float degree)
    {
        Angle *angle = new Angle();
        angle->radian = degree * M_PI / 180.0;
        return angle;
    };

    float Radian()
    {
        return this->radian;
    };
    float Degree()
    {
        return this->radian * (180 / M_PI);
    };
    void dump()
    {
        printf("DEG=%4.2f RAD=%4.2f \n", this->Degree(), this->Radian());
    };

private:
    float radian;
};

struct Triangle
{
    float lengthA;
    float lengthB;
    float lengthC;
    Angle *angleA;
    Angle *angleB;
    Angle *angleC;

    static Triangle *from3edges(float A, float B, float C)
    {
        float cosA = (B * B + C * C - A * A) / (2 * B * C);
        float cosB = (A * A + C * C - B * B) / (2 * A * C);
        float cosC = (A * A + B * B - C * C) / (2 * A * B);

        Triangle *result = new Triangle();

        result->lengthA = A;
        result->lengthB = B;
        result->lengthC = C;

        result->angleA = Angle::FromRadian(acos(cosA));
        result->angleB = Angle::FromRadian(acos(cosB));
        result->angleC = Angle::FromRadian(acos(cosC));

        return result;
    };

    void dump()
    {

        printf("Angles: \n");
        this->angleA->dump();
        this->angleB->dump();
        this->angleC->dump();
        printf("Lengthes: \n");
        printf(
            "A=%4.2f \n"
            "B=%4.2f \n"
            "C=%4.2f \n",
            this->lengthA,
            this->lengthB,
            this->lengthC);
    };
};
