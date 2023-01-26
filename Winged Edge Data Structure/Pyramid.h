#ifndef PYRAMID_H
#define PYRAMID_H
#include <iostream>
#include <vector>
using namespace std;
#include <..\freeglut\include\GL\freeglut.h>
#include "Edge.h"
#include "Face.h"
#include "Vertex.h"
#include "Point.h"

class Edge;
class Vertex;
class Edge;
class Face;
class Point;

class Pyramid
{
public:
	float rotX = 0.0;
	float rotY = 140.0;
	vector<Vertex*>VOV;
	vector<Edge*>VOE;
	vector<Face*>VOF;

	Pyramid();
	void setup(Point*, Point*, Point*, Point*, Point*);
	void setup(vector <Point*>);
	void setRotation(float, float);
	void createConnections(Point *, Point *, Point *, Point *, Point *);
	void draw();
};
#endif
