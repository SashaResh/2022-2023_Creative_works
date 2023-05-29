#pragma once
#include <glut.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// Глобальное объявление переменных, отвечающих за решение задачи
int n;
int** s;
int* way;
int*** Matrix_new; // Матрица смежности
int* path;

// Размеры экрана
int WinW;
int WinH;

int R;

// Structure responsible for storing the coordinates of a particular vertex
struct Node_Coordinatios
{
	int x, y;
};

Node_Coordinatios Node_Coord[15];

template<class T>

class Graph
{
	vector<T> Node_List; //Vector accepting new graph vertices

public:

	int Matrix[15][15]; // Graph Adjacency Matrix

	// Class constructor
	Graph() {
		for (int i = 0; i < 15; i++) {

			for (int j = 0; j < 15; j++) {

				this->Matrix[i][j] = 0;
			}
		}
	}

	// Adding new vertices to the graph
	void Adding_Node(const T& node) {   	// Заполнение графа вершинами

		if (this->Node_List.size() == 15) {

			cout << "\n=======================================";
			cout << "\nUnfortunately, you want to enter more than 15 cities to count, which is contrary to the condition of the specific task.";
			cout << "\n======================================\n";
			return;
		}
		else {

			this->Node_List.push_back(node);
		}
	}

	// Removing the selected vertex of the graph
	void Deleting_Node() {

		if (this->Node_List.size() == 0) {

			cout << "=======================================";
			cout << "\nUnfortunately, there are no more cities in the list: there is nothing to delete.";
			cout << "\n======================================\n";
		}
		else {

			this->Node_List.pop_back();

		}
	}

	// Returning the order number of a graph vertex
	int Number(const T& node) {

		for (int i = 0; i < this->Node_List.size(); i++) {
			if (this->Node_List[i] == node) {

				return i;
			}
		}

		return -1;
	}

	// Adding a new edge between two selected graph vertices
	void Adding_Way(const T& node_fst, const T& node_snd, const int len) {

		int Number_1, Number_2;

		if (this->Number(node_fst) == -1) {

			cout << "\n======================================";
			cout << "\nMistake. Cities with ordinal number " << node_snd << " does not exist.\n";
			cout << "======================================\n";
		}
		else {
			if (this->Number(node_snd) == -1) {

				cout << "\n======================================";
				cout << "\nMistake. Cities with ordinal number " << node_snd << " does not exist.\n";
				cout << "======================================\n";
			}
			else {

				Number_1 = Number(node_fst);
				Number_2 = Number(node_snd);

				if (Matrix[Number_1][Number_2] == 0 && Matrix[Number_2][Number_1] == 0) {

					this->Matrix[Number_1][Number_2] = len;
					this->Matrix[Number_2][Number_1] = len;
				}
				else {
					cout << "======================================\n";
					cout << "\nThere is already a path between these cities.";
					cout << "\nIt is impossible to create a new path, because the roads between cities are unique and the same in length.";
					cout << "\n======================================";
				}
			}

		}
	}

	// Output adjacency matrix to user console
	void Matrix_Output() {

		if ((this->Node_List.size()) == 0) {

			cout << "\n======================================";
			cout << "\nThe list of cities is empty. The adjacency matrix of a graph cannot be deduced.";
			cout << "\n======================================";
		}
		else {

			cout << "\n======================================";
			cout << "\nCity graph adjacency matrix:\n";
			cout << "\t";
			for (int i = 0; i < Node_List.size(); i++) {

				cout << Node_List[i] << "\t|\t";
			}
			cout << "\n\n";


			for (int i = 0; i < Node_List.size(); i++) {

				cout << Node_List[i] << "\t";

				for (int j = 0; j < Node_List.size(); j++) {

					cout << this->Matrix[i][j] << "\t|\t";
				}
				cout << "\n\n";
			}
		}
	}

	// Displaying the final graph on the user's screen
	void Graph_Output();

	// Class destructor
	~Graph() {};
};


int Node_Quantity = 0;
int Way_Quantity = 0;

Graph<int> graph;

// Reduction of rows and columns in the current graph adjacency matrix, in order to find the optimal path
void Finding_Answer(int*** Matrix_new, int n, int** Help_Matrix, int* path) {

	for (int l = 0; l < n; l++) {

		for (int i = 0; i < n; i++) {

			// Finding the smallest value across rows and columns and reduction
			int min = 1000000;
			for (int j = 0; j < n; j++) {

				if (Matrix_new[i][j] && min > *Matrix_new[i][j])

					min = *Matrix_new[i][j];
			}

			for (int j = 0; j < n; j++) {

				if (Matrix_new[i][j])

					*Matrix_new[i][j] -= min;
			}
		}

		for (int j = 0; j < n; j++) {

			int min = 1000000;
			for (int i = 0; i < n; i++) {

				if (Matrix_new[i][j] && min > *Matrix_new[i][j])

					min = *Matrix_new[i][j];
			}

			for (int i = 0; i < n; i++) {

				if (Matrix_new[i][j])

					*Matrix_new[i][j] -= min;
			}
		}

		// Creating an Empty Auxiliary Adjacency Matrix
		for (int i = 0; i < n; i++) {

			for (int j = 0; j < n; j++)

				Help_Matrix[i][j] = 0;
		}

		for (int i = 0; i < n; i++)

			for (int j = 0; j < n; j++) {

				if (Matrix_new[i][j] && !*Matrix_new[i][j]) {

					int col_min = 1000000;
					int string_min = 1000000;

					for (int l = 0; l < n; l++)
						if (l != i && Matrix_new[l][j] && col_min > *Matrix_new[l][j])
							col_min = *Matrix_new[l][j];

					for (int l = 0; l < n; l++)
						if (l != j && Matrix_new[i][l] && string_min > *Matrix_new[i][l])
							string_min = *Matrix_new[i][l];

					Help_Matrix[i][j] = col_min + string_min;
				}
			}

		int mcost = 0, mi = 0, mj = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (Matrix_new[i][j] && mcost < Help_Matrix[i][j])
				{
					mcost = Help_Matrix[i][j];
					mi = i;
					mj = j;
				}
		path[mi] = mj;

		for (int i = 0; i < n; i++)
			Matrix_new[i][mj] = nullptr;

		for (int i = 0; i < n; i++)
			Matrix_new[mi][i] = nullptr;

		Matrix_new[mj][mi] = nullptr;
	}
}

// Creating an array needed to calculate the total length of the path traveled by the Salesman
void Matrix_Creation(int***& Matrix_new, int& n, int**& s, int*& way) {

	n = Node_Quantity;

	s = new int* [n];

	way = new int[n];

	Matrix_new = new int** [n];

	for (int i = 0; i <= n; i++) {

		s[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {

		Matrix_new[i] = new int* [n];

		for (int j = 0; j < n; j++) {

			if (graph.Matrix[i][j] == 0) {

				Matrix_new[i][j] = nullptr;
				continue;
			}

			Matrix_new[i][j] = new int(graph.Matrix[i][j]);
		}
	}
}

// Calculation of the value of the distance-optimal path traveled by the traveling salesman
void Kommivoyager(int*** Matrix_new, int n, int** s, int* way) {

	Matrix_Creation(Matrix_new, n, s, way);
	Finding_Answer(Matrix_new, n, s, way);

	int sum_length = 0;

	for (int i = 0, j = 0; i < n; i++) {

		j = way[i];
		// Calculating the length of the final path
		sum_length += graph.Matrix[i][j];
	}

	cout << "\n\nShortest path traveled by a salesman ";
	int slen = 0;

	for (int l = 0; l < n;) {

		for (int i = 0, j = 0; i < n; i++) {

			if ((slen == 0) || (slen == i + 1)) {

				if (slen == 0) {

					cout << i + 1;
				}

				j = way[i];
				slen = j + 1;

				if (slen > 0) {

					cout << " -> " << slen;
				}

				l++;
			}
		}
	}
	cout << "\n\nThe total length of the path that the salesman will take: " << sum_length << "\n\n";
}

// Listing edges between graph vertices
void Ouput_Ways(int*** Matrix_new, int n, int** s, int* way) {

	Matrix_Creation(Matrix_new, n, s, way);
	Finding_Answer(Matrix_new, n, s, way);

	int sum_length = 0;

	cout << "\n======================================";
	cout << "\nAll paths between cities that the traveling salesman will pass: \n";
	for (int i = 0, j = 0; i < n; i++) {

		j = way[i];
		cout << i + 1 << " -> " << j + 1 << '\n';
	}

}

// Creating a new graph
Graph <int> Create_Graph() {

	Graph<int> graph;
	int first, second, length;
	int* first_Node;
	int* second_Node;
	int* New_Node;

	cout << "\n======================================";
	cout << "\nEnter the number of cities that the salesman needs to visit: ";
	cout << "\n";
	cin >> Node_Quantity;

	cout << "\nEnter the number of routes between these cities: ";
	cout << "\n";
	cin >> Way_Quantity;

	for (int i = 1; i <= Node_Quantity; ++i) {

		New_Node = &i; // Записываем адрес вершины
		graph.Adding_Node(*New_Node); // Добавляем новую вершину в граф
	}

	for (int i = 0; i < Way_Quantity; ++i) {

		cout << "\nEnter the serial number of the city from which the path goes: ";
		cin >> first;
		first_Node = &first;

		cout << "\nEnter the serial number of the city to which the path goes: ";
		cin >> second;
		second_Node = &second;

		cout << "\n\tEnter the distance between cities " << first << " and " << second << " : ";
		cin >> length;

		graph.Adding_Way(*first_Node, *second_Node, length); // Добавляем путь между введенными вершинами, передача двух вершин графа по ссылке
	}

	return graph;
}

// Saving graph vertex coordinates
void save_node(int i, int n)
{
	int New_R;

	int x0 = WinW / 2;
	int y0 = WinH / 2;
	if (WinW > WinH)
	{
		R = 5 * (WinH / 13) / n;
		New_R = WinH / 2 - R - 10;
	}
	else {
		R = 5 * (WinW / 13) / n;
		New_R = WinW / 2 - R - 10;
	}
	float theta = 2.0f * 3.1415926f * float(i) / float(n);
	float y1 = New_R * cos(theta) + y0;
	float x1 = New_R * sin(theta) + x0;

	Node_Coord[i].x = x1;
	Node_Coord[i].y = y1;
}

// Graph vertex drawing
void Draw_City(int x, int y, int R)
{
	glColor3f(1.0 / 255.0 * 156, 1.0 / 255.0 * 156, 1.0 / 255.0 * 156); //перламутровый светло серый
	float x1, y1;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {

		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y1 = R / 2 * cos(theta) + y;
		x1 = R / 2 * sin(theta) + x;;
		glVertex2f(x1, y1);
	}
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	float x2, y2;
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; i++) {

		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y2 = R / 2 * cos(theta) + y;
		x2 = R / 2 * sin(theta) + x;
		glVertex2f(x2, y2);
	}
	glEnd();
}


// Drawing text on a graph
void New_Text(int nom, int x1, int y1)
{
	GLvoid* font = GLUT_BITMAP_HELVETICA_18;
	string s = to_string(nom);
	glRasterPos2i(x1 - 5, y1 - 5);
	for (int j = 0; j < s.length(); j++)
		glutBitmapCharacter(font, s[j]);
}

// Rreating a new node (calling the functions for drawing the vertex and the name)
void Draw_Node(int n)
{
	for (int i = 0; i < n; i++) {

		Draw_City(Node_Coord[i].x, Node_Coord[i].y, R);
		New_Text(i + 1, Node_Coord[i].x, Node_Coord[i].y);
	}
}

// Graph Edge Drawing
void Draw_Way(int text, int x0, int y0, int x1, int y1)
{
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex2i(x0, y0);
	glVertex2i(x1, y1);
	glEnd();

	New_Text(text, (x0 + x1) / 2 + 10, (y0 + y1) / 2 + 10);
}


template<class T>

// Calling a class method. Drawing a graph on the screen
void Graph<T>::Graph_Output()
{
	for (int i = 0; i < Node_List.size(); i++) {

		save_node(i, Node_List.size());
	}

	for (int i = 0; i < Node_List.size(); i++) {

		for (int j = i + 1; j < Node_List.size(); j++) {

			if (Matrix[i][j] != 0) {

				Draw_Way(Matrix[i][j], Node_Coord[i].x, Node_Coord[i].y, Node_Coord[j].x, Node_Coord[j].y);
			}
		}
	}
	Draw_Node(Node_List.size());
}

// The function of adapting the size of the graph to the current screen
void reshape(int w, int sum_length) {

	WinW = w;
	WinH = sum_length;
	glViewport(0, 0, (GLsizei)WinW, (GLsizei)WinH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, (GLdouble)WinW, 0, (GLdouble)WinH);
	glutPostRedisplay();
}

// Text output for the interface
void drawMenuText(string text, int x1, int y1)
{
	GLvoid* font = GLUT_BITMAP_HELVETICA_18;
	string s = text;
	glRasterPos2i(x1 + 5, y1 - 20);
	for (int j = 0; j < s.length(); j++)
		glutBitmapCharacter(font, s[j]);
}

// Displaying the functional menu of the interface
void drawMenu() {

	int width = 60;
	int lgth = 730;

	glColor3d(1.0 / 255.0 * 130, 1.0 / 255.0 * 130, 1.0 / 255.0 * 130);
	glBegin(GL_QUADS);
	glVertex2i(width - 20, lgth - width - 270);
	glVertex2i(width + 270, lgth - width - 270);
	glVertex2i(width + 270, lgth - width + 75);
	glVertex2i(width - 20, lgth - width + 75);
	glEnd();

	glColor3d(0, 0.3, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(width, lgth - width - 30);
	glVertex2i(width + 135, lgth - width - 30);
	glVertex2i(width + 135, lgth - width);
	glVertex2i(width, lgth - width);
	glEnd();
	glColor3d(1.0, 1.0, 1.0);
	drawMenuText("   Number of ways  ", width - 2, lgth - width + 50);
	glColor3d(1.0, 1.0, 1.0);
	drawMenuText("(increase / decrease): ", width - 2, lgth - width + 25);

	glColor3d(1.0 / 255.0 * 64, 1.0 / 255.0 * 58, 1.0 / 255.0 * 58);
	glBegin(GL_QUADS);
	glVertex2i(width, lgth - width - 30);
	glVertex2i(width + 150, lgth - width - 30);
	glVertex2i(width + 150, lgth - width);
	glVertex2i(width, lgth - width);
	glEnd();
	glColor3d(1.0, 1.0, 1.0);
	drawMenuText("+", width + 60, lgth - width - 2);

	glColor3d(1.0 / 255.0 * 64, 1.0 / 255.0 * 58, 1.0 / 255.0 * 58);
	glBegin(GL_QUADS);
	glVertex2i(width, lgth - width - 70);
	glVertex2i(width + 150, lgth - width - 70);
	glVertex2i(width + 150, lgth - width - 40);
	glVertex2i(width, lgth - width - 40);
	glEnd();
	glColor3d(1.0, 1.0, 1.0);
	drawMenuText("-", width + 60, lgth - width - 42);

	glColor3d(1.0 / 255.0 * 64, 1.0 / 255.0 * 58, 1.0 / 255.0 * 58);
	glBegin(GL_QUADS);
	glVertex2i(width, lgth - width - 110);
	glVertex2i(width + 255, lgth - width - 110);
	glVertex2i(width + 255, lgth - width - 80);
	glVertex2i(width, lgth - width - 80);
	glEnd();
	glColor3d(1.0, 1.0, 1.0);
	drawMenuText(" Output the adjacency matrix", width, lgth - width - 82);

	glColor3d(1.0 / 255.0 * 64, 1.0 / 255.0 * 58, 1.0 / 255.0 * 58);
	glBegin(GL_QUADS);
	glVertex2i(width, lgth - width - 180);
	glVertex2i(width + 255, lgth - width - 180);
	glVertex2i(width + 255, lgth - width - 120);
	glVertex2i(width, lgth - width - 120);
	glEnd();
	glColor3d(1.0, 1.0, 1.0);
	drawMenuText("Calculate the path traveled by ", width, lgth - width - 122);
	glColor3d(1.0, 1.0, 1.0);
	drawMenuText("a traveling salesman", width + 50, lgth - width - 150);

	glColor3d(1.0 / 255.0 * 64, 1.0 / 255.0 * 58, 1.0 / 255.0 * 58);
	glBegin(GL_QUADS);
	glVertex2i(width, lgth - width - 220);
	glVertex2i(width + 255, lgth - width - 220);
	glVertex2i(width + 255, lgth - width - 190);
	glVertex2i(width, lgth - width - 190);
	glEnd();
	glColor3d(1.0, 1.0, 1.0);
	drawMenuText("    Create a new road map", width, lgth - width - 190);

	glColor3d(1.0 / 255.0 * 64, 1.0 / 255.0 * 58, 1.0 / 255.0 * 58);
	glBegin(GL_QUADS);
	glVertex2i(width, lgth - width - 230);
	glVertex2i(width + 255, lgth - width - 230);
	glVertex2i(width + 255, lgth - width - 260);
	glVertex2i(width, lgth - width - 260);
	glEnd();
	glColor3d(1.0, 1.0, 1.0);
	drawMenuText("     List of possible ways", width, lgth - width - 230);

}

// Display with a set of functions, works on a mouse click on the screen
void mouseClick(int button, int stat, int x, int y) {
	int width = 60;
	int lgth = 730;

	if (stat == GLUT_DOWN) {

		if (x > width && x < width + 135 && y >  width && y < width + 30) {

			int first;
			int second;
			int length;
			int* first_node;
			int* second_node;


			cout << "\nOrdinal number of the city to be added: ";
			cin >> first;

			first_node = &first;
			cout << "\nDestination serial number: ";
			cin >> second;
			cout << "\n\n";
			second_node = &second;

			if (first > Node_Quantity || second > Node_Quantity) {

				Node_Quantity++;
				int* New_Node = &Node_Quantity;
				graph.Adding_Node(*New_Node);
			}

			cout << "Road length between cities: "; cin >> length; cout << endl;
			graph.Adding_Way(*first_node, *second_node, length);
		}
		if (x > width && x < width + 135 && y > width + 40 && y < width + 70) {

			int first;
			int second;
			int length;
			int* first_node;

			cout << "\nOrdinal number of the city to be deleted: ";
			cin >> first;
			cout << "\n";
			first_node = &first;
			if (first == Node_Quantity) {

				Node_Quantity--;
				graph.Deleting_Node();
			}
			else cout << "\nIt is not possible to delete a city point on the map. \n";
		}
		if (x > width && x < width + 240 && y >  width + 80 && y < width + 100) {

			graph.Matrix_Output();
		}
		if (x > width && x < width + 240 && y >  width + 120 && y < width + 140) {

			Kommivoyager(Matrix_new, n, s, way);
		}
		if (x > width && x < width + 240 && y >  width + 160 && y < width + 200) {

			graph = Create_Graph();
		}

		if (x > width && x < width + 240 && y >  width + 230 && y < width + 260) {

			Ouput_Ways(Matrix_new, n, s, way);
		}
	}
	glutPostRedisplay();
}

// User interface settings
void display() {

	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(0, WinW, 0, WinH);
	glViewport(0, 0, WinW, WinH);

	// Setting the color options for the main background of the interface window
	glClearColor(1.0 / 255.0 * 71, 1.0 / 255.0 * 74, 1.0 / 255.0 * 81, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	graph.Graph_Output();
	drawMenu();
	glutSwapBuffers();
}
