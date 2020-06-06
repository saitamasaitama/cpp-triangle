#include <math.h>

struct Vector3
{
    float X;
    float Y;
    float Z;

    Vector3()
    {
        this->X = 0;
        this->Y = 0;
        this->Z = 0;
    }

    Vector3(float x, float y, float z)
    {
        this->X = x;
        this->Y = y;
        this->Z = z;
    }

    static Vector3 *Zero()
    {
        Vector3 *result = new Vector3();
        result->X = 0;
        result->Y = 0;
        result->Z = 0;
        return result;
    }
    static Vector3 *One()
    {
        Vector3 *result = new Vector3();
        result->X = 1;
        result->Y = 1;
        result->Z = 1;
        return result;
    }

    static float Distance(Vector3 *from, Vector3 *to)
    {
        return sqrt(
            (to->X - from->X) * (to->X - from->X) + (to->Y - from->Y) * (to->Y - from->Y) + (to->Z - from->Z) * (to->Z - from->Z));
    };
};

struct Quaternion
{
    float X;
    float Y;
    float Z;
    float W;
};
