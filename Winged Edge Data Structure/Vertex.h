#ifndef VERTEX_H
#define VERTEX_H


class Edge;
class Point;

class Vertex
{
public:
	Point *p;
	Edge *e;
	Vertex();
	Vertex(Point *_p) {
		p = _p;
	};
	void setEdge(Edge*);
};
#endif