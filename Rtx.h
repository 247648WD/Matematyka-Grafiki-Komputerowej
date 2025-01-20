#pragma once

#include "Wektory3D.h"
#include <conio.h>

#define M_PI 3.14159265358979323846 

class Rtx
{
public:
	Rtx();

	void Draw();
	void RayCast(Wektory3D cameraPosition, Wektory3D cameraDirection);
	void CameraUpdate(float pitch, float yaw, float radius, Wektory3D cameraPos);

private:
	bool screen[60][60] = { {false} };
};

