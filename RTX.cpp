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

    Ray(Wektory3D o, Wektory3D d) {
        origin = o; 
        temp = d;
        direction = temp.normalizacja(); 
    }


};


bool IntersectAABB(Ray& ray)
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

void Rtx::RayCast(Wektory3D cameraPosition, Wektory3D cameraDirection)
{
    float pixelSize = 4.0f / 60.0f;
    float screenDistance = 1.0f;

    Wektory3D screenCenter = cameraPosition;
    Wektory3D temp = cameraDirection;
    temp = temp.normalizacja();
    screenCenter = cameraPosition + (temp * screenDistance);
    Wektory3D worldUp(0, 0, 1);

    // Kierunki lewo i dó³ dla ekranu
    Wektory3D screenLeft = cameraDirection;
    screenLeft = screenLeft.iloczyn_wektorowy(worldUp);
    screenLeft = screenLeft.normalizacja();
    Wektory3D screenDown = screenLeft.iloczyn_wektorowy(cameraDirection);
    screenDown = screenDown.normalizacja();

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
    system("cls");
    Draw();
}

void Rtx::CameraUpdate(float pitch, float yaw, float radius, Wektory3D cameraPos) {
    float pitchRadians = pitch * M_PI / 180.0f;
    float yawRadians = yaw * M_PI / 180.0f;

    cameraPos.set_x(radius * std::cos(pitchRadians) * std::cos(yawRadians));
    cameraPos.set_y(radius * std::sin(pitchRadians) * std::cos(yawRadians));
    cameraPos.set_z(radius * std::sin(yawRadians));

    double x = cameraPos.get_x() * -1;
    double y = cameraPos.get_y() * -1;
    double z = cameraPos.get_z() * -1;

    Wektory3D cameraDir(x,y,z);
    cameraDir = cameraDir.normalizacja();

    RayCast(cameraPos, cameraDir);
}
