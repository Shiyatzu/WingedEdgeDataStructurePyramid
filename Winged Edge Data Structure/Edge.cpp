#include "Edge.h"

Edge::Edge()
{
}

Edge::Edge(Vertex *_v_origin, Vertex *_v_dest)
{
	v_origin = _v_origin;
	v_dest = _v_dest;
}

void Edge::setFaceLeft(Face *_f_left)
{
	f_left = _f_left;
}

void Edge::setFaceRight(Face *_f_right)
{
	f_right = _f_right;
}

void Edge::setFaceLeftRigh(Face *_f_left, Face *_f_right)
{
	f_left = _f_left;
	f_right = _f_right;
}

void Edge::setLeftTraverse(Edge *_e_l_cw, Edge *_e_l_ccw)
{
	e_l_cw = _e_l_cw;
	e_l_ccw = _e_l_ccw;
}

void Edge::setRightTraverse(Edge *_e_r_cw, Edge *_e_r_ccw)
{
	e_r_cw = _e_r_cw;
	e_r_ccw = _e_r_ccw;
}