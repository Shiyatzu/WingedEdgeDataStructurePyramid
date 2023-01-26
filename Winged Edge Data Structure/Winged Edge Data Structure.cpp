// Winged Edge Data Structure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "Pyramid.h"
#include "Edge.h"
#include "Point.h"
using namespace std;

Point *a = new Point(0.0f, 2.0f, 0.0f);
Point *b = new Point(1.0f, 0.0f, 1.0f);
Point *c = new Point(-1.0f, 0.0f, 1.0f);
Point *d = new Point(-1.0f, 0.0f, -1.0f);
Point *e = new Point(1.0f, 0.0f, -1.0f);

Pyramid pyramid;

void initGL() { /* Initialize OpenGL Graphics */
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClearDepth(1.0f);                   // Set background depth to farthest
	glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
	glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
	glShadeModel(GL_SMOOTH);   // Enable smooth shading
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections

	pyramid.createConnections(a,b,c,d,e);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
	glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
	// Render a pyramid consists of 4 triangles
	glLoadIdentity();                  // Reset the model-view matrix
	glTranslatef(-1.0f, -0.0f, -6.0f);  // Move left and into the screen

	pyramid.draw();

	glEnd();   // Done drawing the pyramid
	glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)

}

void SpecialKey(int key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_UP:
		pyramid.setRotation(-20,0);
		break;
	case GLUT_KEY_DOWN:
		pyramid.setRotation(+20, 0);
		break;
	case GLUT_KEY_LEFT:
		pyramid.setRotation(0, -20);
		break;
	case GLUT_KEY_RIGHT:
		pyramid.setRotation(0, 20);
		break;
	}
	glutPostRedisplay();
}

/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
	if (height == 0) height = 1; // To prevent divide by 0
	GLfloat aspect = (GLfloat)width / (GLfloat)height;
	glViewport(0, 0, width, height);  // Set the viewport to cover the new window
	// Set the aspect ratio of the clipping volume to match the viewport
	glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
	glLoadIdentity();             // Reset
	// Enable perspective projection with fovy, aspect, zNear and zFar
	gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
	std::cout << "Winged Edge" << std::endl;

	glutInit(&argc, argv);            // Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
	glutInitWindowSize(640, 480);   // Set the window's initial width & height
	glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
	glutCreateWindow("Winged Edge Data Structure Pyramid"); // Create window with the given title
	glutSpecialFunc(SpecialKey);
	glutDisplayFunc(display);       // Register callback handler for window re-paint event
	glutReshapeFunc(reshape);       // Register callback handler for window re-size event
	initGL();                       // Our own OpenGL initialization
	glutMainLoop();                 // Enter the infinite event-processing loop
	return 0;
}
