#include "graph.h"
#include <glut.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>



int main(int argc, char* argv[])
{
	//setlocale(LC_ALL, "RUS");

	glutInit(&argc, argv);
	cout << "Your attention is presented to the Traveling Salesman Problem. \nFor the program to work correctly, enter no more than 15 different cities through which you need to build a route. \nFor ease of filling, write down each city according to its serial number. \n\n\n";
	graph = Create_Graph();
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	// Setting interface window options
	glutInitWindowSize(1350, 730);
	glutCreateWindow("Traveling salesman");
	WinW = glutGet(GLUT_WINDOW_WIDTH);
	WinH = glutGet(GLUT_WINDOW_HEIGHT);

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutMouseFunc(mouseClick);

	glutMainLoop();



	return 0;
}