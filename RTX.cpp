#include "RTX.h"
#include <iostream>
#include <cmath>

Rtx::Rtx()
{
    for (int i = 0; i < 60; i++)
    {
        for (int k = 0; k < 60; k++)
        {
            screen[i][k] = false;
        }
    }
}

void Rtx::Draw()
{
    for (int i = 0; i < 60; i++)
    {
        for (int k = 0; k < 60; k++)
        {
            if (screen[i][k])
                std::cout << "0 ";
            else
                std::cout << ". ";
        }
        std::cout << "\n";
    }
}

struct Ray {
    Wektory3D origin;
    Wektory3D direction;
    Wektory3D temp;

    Ray(const Wektory3D& o, const Wektory3D& d) {
        origin = o; 
        temp = d;
        direction = temp.normalizacja(); 
    }
};


bool IntersectAABB(const Ray& ray)
{
    Wektory3D boxMin(-1, -1, -1);
    Wektory3D boxMax(1, 1, 1);

    Wektory3D invDir(1.0 / ray.direction.get_x(),
        1.0 / ray.direction.get_y(),
        1.0 / ray.direction.get_z());

    double t1 = (boxMin.get_x() - ray.origin.get_x()) * invDir.get_x();
    double t2 = (boxMax.get_x() - ray.origin.get_x()) * invDir.get_x();
    double t3 = (boxMin.get_y() - ray.origin.get_y()) * invDir.get_y();
    double t4 = (boxMax.get_y() - ray.origin.get_y()) * invDir.get_y();
    double t5 = (boxMin.get_z() - ray.origin.get_z()) * invDir.get_z();
    double t6 = (boxMax.get_z() - ray.origin.get_z()) * invDir.get_z();

    double tMin = std::max(std::max(std::min(t1, t2), std::min(t3, t4)), std::min(t5, t6));
    double tMax = std::min(std::min(std::max(t1, t2), std::max(t3, t4)), std::max(t5, t6));

    return tMax >= std::max(tMin, 0.0);
}

void Rtx::RayCast(const Wektory3D& cameraPosition, const Wektory3D& cameraDirection)
{
    float pixelSize = 4.0f / 60.0f;
    float screenDistance = 1.0f;

    Wektory3D screenCenter = cameraPosition;
    Wektory3D temp = cameraDirection;
    screenCenter = screenCenter + (temp.normalizacja() * screenDistance);
    Wektory3D worldUp(0, 0, 1);

    // Kierunki lewo i dó³ dla ekranu
    Wektory3D screenLeft = cameraDirection;
    screenLeft.iloczyn_wektorowy(worldUp).normalizacja();
    Wektory3D screenDown = screenLeft.iloczyn_wektorowy(cameraDirection).normalizacja();

    for (int i = 0; i < 60; i++)
    {
        for (int k = 0; k < 60; k++)
        {
            // Pozycja piksela na ekranie
            Wektory3D pixelOffset = screenLeft * ((k - 30) * pixelSize) + screenDown * ((i - 30) * pixelSize);
            Wektory3D pixelPosition = screenCenter + pixelOffset;

            // Tworzymy promieñ od pozycji kamery do piksela
            Ray ray(cameraPosition, pixelPosition - cameraPosition);

            // Sprawdzamy przeciêcie z jednostkowym szeœcianem
            screen[i][k] = IntersectAABB(ray);
        }
    }
}
