#pragma once

#include "Wektory3D.h"

class Rtx
{
public:
	Rtx();

	void Draw();
	void RayCast(const Wektory3D& cameraPosition, const Wektory3D& cameraDirection);

private:
	bool screen[60][60] = { {false} };
};

