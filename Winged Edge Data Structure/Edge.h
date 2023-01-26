#ifndef EDGE_H
#define EDGE_H

class Vertex;
class Face;

class Edge {
public:
	Vertex  *v_origin, *v_dest;
	Face *f_left, *f_right;
	Edge *e_l_cw, *e_l_ccw, *e_r_cw, *e_r_ccw;

	Edge();
	Edge(Vertex *, Vertex*);
	void setFaceLeft(Face*);
	void setFaceRight(Face*);
	void setFaceLeftRigh(Face*, Face*);
	void setLeftTraverse(Edge*, Edge*);
	void setRightTraverse(Edge*, Edge*);
};
#endif
