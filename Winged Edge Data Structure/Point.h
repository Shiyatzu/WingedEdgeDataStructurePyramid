#pragma once
#ifndef POINT_H
#define POINT_H
class Point
{
public:
	float x, y, z;
	Point(float _x, float _y, float _z) {
		x = _x;
		y = _y;
		z = _z;
	}
};
#endif