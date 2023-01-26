#ifndef FACE_H
#define FACE_H

class Edge;
class Face
{
public:
	Edge *e;
	Face(Edge * _e) {
		e = _e;
	};
};
#endif