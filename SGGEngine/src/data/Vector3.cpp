#include "pch.h"


#include "data/Vector3.h"

namespace SG
{
	Vector3::Vector3()
		: X(0), Y(0), Z(0)
	{
	}

	Vector3::Vector3(int xy) : X(xy), Y(xy), Z(0)
	{
	}

	Vector3::Vector3(int x, int y, int z) : X(x), Y(y), Z(z)
	{
	}

}
