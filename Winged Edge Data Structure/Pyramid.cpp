#include "Pyramid.h"
#include <string>
using namespace std;

Pyramid::Pyramid()
{
}

void Pyramid::setup(vector<Point*> VOP)
{
	int s = (int)VOP.size();
	for (int i = 0; i < s; i++)
	{
		Vertex *tempV = new Vertex(VOP[i]);
		VOV.push_back(tempV);
	}
}

void Pyramid::setRotation(float addRotX, float addRotY)
{
	rotX += addRotX;
	rotY += addRotY;
}

void Pyramid::createConnections(Point *p1, Point *p2, Point *p3, Point *p4, Point *p5)
{

	Vertex* v1 = new Vertex(p1); VOV.push_back(v1);
	Vertex* v2 = new Vertex(p2); VOV.push_back(v2);
	Vertex* v3 = new Vertex(p3); VOV.push_back(v3);
	Vertex* v4 = new Vertex(p4); VOV.push_back(v4);
	Vertex* v5 = new Vertex(p5); VOV.push_back(v5);

	Edge* e1 = new Edge(v3, v2); VOE.push_back(e1);
	Edge* e2 = new Edge(v3, v4); VOE.push_back(e2);
	Edge* e3 = new Edge(v4, v5); VOE.push_back(e3);
	Edge* e4 = new Edge(v5, v2); VOE.push_back(e4);
	Edge* e5 = new Edge(v1, v2); VOE.push_back(e5);
	Edge* e6 = new Edge(v3, v1); VOE.push_back(e6);
	Edge* e7 = new Edge(v4, v1); VOE.push_back(e7);
	Edge* e8 = new Edge(v5, v1); VOE.push_back(e8);
	Edge* e9 = new Edge(v2, v4); VOE.push_back(e9);

	Face* f1 = new Face(e6); VOF.push_back(f1);
	Face* f2 = new Face(e2); VOF.push_back(f2);
	Face* f3 = new Face(e3); VOF.push_back(f3);
	Face* f4 = new Face(e8); VOF.push_back(f4);
	Face* f5 = new Face(e9); VOF.push_back(f5);
	Face* f6 = new Face(e1); VOF.push_back(f6);

	//Ligações
	e1->setFaceLeftRigh(f1, f6); e1->setLeftTraverse(e5, e6); e1->setRightTraverse(e2, e9);
	e2->setFaceLeftRigh(f6, f2); e2->setLeftTraverse(e9, e1); e2->setRightTraverse(e6, e7);
	e3->setFaceLeftRigh(f5, f3); e3->setLeftTraverse(e4, e9); e3->setRightTraverse(e7, e8);
	e4->setFaceLeftRigh(f5, f4); e4->setLeftTraverse(e9, e3); e4->setRightTraverse(e8, e5);
	e5->setFaceLeftRigh(f4, f1); e5->setLeftTraverse(e4, e8); e5->setRightTraverse(e6, e1);
	e6->setFaceLeftRigh(f2, f1); e6->setLeftTraverse(e7, e2); e6->setRightTraverse(e1, e5);
	e7->setFaceLeftRigh(f3, f2); e7->setLeftTraverse(e3, e8); e7->setRightTraverse(e2, e6);
	e8->setFaceLeftRigh(f3, f4); e8->setLeftTraverse(e3, e7); e8->setRightTraverse(e5, e4);
	e9->setFaceLeftRigh(f6, f5); e9->setLeftTraverse(e2, e1); e9->setRightTraverse(e3, e6);

	int s = (int)VOF.size();
	for(int i=0; i < s;i++){
		cout << "Face " << i << ": ";
		cout << std::to_string(VOF[i]->e->v_origin->p->x) << ", " << std::to_string(VOF[i]->e->v_origin->p->y) << ", " << std::to_string(VOF[i]->e->v_origin->p->z) << "\n ";
		cout << std::to_string(VOF[i]->e->e_r_cw->v_dest->p->x) << ", " << std::to_string(VOF[i]->e->e_r_cw->v_dest->p->y) << ", " << std::to_string(VOF[i]->e->e_r_cw->v_dest->p->z) << "\n ";
		cout << std::to_string(VOF[i]->e->v_dest->p->x) << ", " << std::to_string(VOF[i]->e->v_dest->p->z) << ", " << std::to_string(VOF[i]->e->v_dest->p->z) << "\n ";
	}
}

void Pyramid::draw()
{
	// Move left and into the screen
	glRotatef(rotY, 0.0, 1.0, 0.0);
	glRotatef(rotX, 1.0, 0.0, 0.0);

	glBegin(GL_TRIANGLES);

	int s = (int)VOF.size();
	Point *p1, *p2, *p3;
	for (int i = 0; i < s; i++)
	{
		p1 = VOF[i]->e->v_origin->p;
		p2 = VOF[i]->e->v_dest->p;
		p3 = VOF[i]->e->e_r_cw->v_dest->p;

		glColor3f(1.0f, 0.0f, 0.0f);     // Red
		glVertex3f(p1->x, p1->y, p1->z);
		glColor3f(1.0f, 1.0f, 0.0f);     // Green
		glVertex3f(p2->x, p2->y, p2->z);
		glColor3f(0.0f, 0.0f, 1.0f);     // Blue
		glVertex3f(p3->x, p3->y, p3->z);
	}
}
