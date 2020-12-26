#include "pch.h"


#include  "Vector3.h"

namespace SG
{
	Vector3::Vector3()
		: X(0), Y(0), Z(0)
	{
	}

	Vector3::Vector3(float xy) : X(xy), Y(xy), Z(0)
	{
	}

	Vector3::Vector3(float x, float y, float z) : X(x), Y(y), Z(z)
	{
	}

}
