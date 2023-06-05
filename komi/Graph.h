#pragma once
#include <glut.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int WinW;
int WinH;

int R; // Основная окружность для отрисовки вершин графа

struct Coordinate
{
	int x, y;
};
Coordinate vertCord[20];

const int maxSize = 20;
int amountVerts;

template<class T>
class Graph
{
private:
	vector<T> vertexList;
	bool* visitedVerts = new bool[vertexList.size()];
public:
	int Matrix[maxSize][maxSize] = { 0 };
	Graph()
	{
		for (int i = 0; i < maxSize; ++i)
		{
			for (int j = 0; j < maxSize; ++j)
			{
				this->Matrix[i][j] = 0;
			}
		}
	}
	~Graph() {};
	void DrawGraph();
	void InsertEdge(const T& v1, const T& v2, int w)
	{
		if (this->GetVertPos(v1) != (-1) && this->GetVertPos(v2) != (-1)) {
			int v_Pos1 = GetVertPos(v1);
			int v_Pos2 = GetVertPos(v2);
			if (this->Matrix[v_Pos1][v_Pos2] != 0 && this->Matrix[v_Pos2][v_Pos1] != 0) {
				cout << "Одного из узлов в графе не существует" << endl;
				return;
			}
			else {
				this->Matrix[v_Pos1][v_Pos2] = w;
				this->Matrix[v_Pos2][v_Pos1] = w;
			}
		}
		else {
			cout << "Между данными вершинами уже есть ребро" << endl;
			return;
		}
	}
	void InsertVertex(const T& v)
	{
		if (!this->IsFull()) {
			this->vertexList.push_back(v);
		}
		else {
			cout << "Невозможно добавить вершину " << endl;
			return;
		}
	}
	void DeleteVertex()
	{
		this->vertexList.pop_back();
	}
	int GetVertPos(const T& v)
	{
		for (int i = 0; i < this->vertexList.size(); ++i) {
			if (this->vertexList[i] == v)
				return i;
		}
		return -1;
	}
	vector<T> GetNbrs(const T& v)
	{
		vector<T> nbrsList;
		int vertListSize = this->vertexList.size();
		int vertPos = this->GetVertPos(v);
		if (vertPos != (-1)) {

			for (int i = 0; i < vertListSize; ++i) {
				if (this->Matrix[vertPos][i] != 0 && this->Matrix[i][vertPos] != 0)
					nbrsList.push_back(this->vertexList[i]);
			}
		}
		return nbrsList;
	}
	int GetAmountVerts()
	{
		return this->vertexList.size();
	}
	int GetAmountEdges()
	{
		int amount = 0;
		int vertListSize = this->vertexList.size();
		if (!this->IsEmpty()) {
			for (int i = 0; i < vertListSize; ++i) {
				for (int j = 0; j < vertListSize; ++j) {
					if (this->Matrix[i][j] == this->Matrix[j][i] && this->Matrix[i][j] != 0)
						amount += 1;
				}
			}
			return (amount / 2);
		}
		else
			return 0;
	}
	int GetWeight(const T& v1, const T& v2)
	{
		if (!this->IsEmpty()) {
			int vertPos1 = GetVertPos(v1);
			int vertPos2 = GetVertPos(v2);
			return Matrix[vertPos1][vertPos2];
		}
		return 0;
	}
	bool IsEmpty()
	{
		if (this->vertexList.size() != 0)
			return false;
		else
			return true;
	}
	bool IsFull()
	{
		return (vertexList.size() == maxSize);
	}
	void Print()
	{
		int vertListSize = this->vertexList.size();
		if (!this->IsEmpty()) {
			cout << "Матрица смежности: " << endl;
			for (int i = 0; i < vertListSize; ++i) {
				for (int j = 0; j < vertListSize; ++j) {
					cout << " " << this->Matrix[i][j] << " ";
				}
				cout << endl;
			}
		}
	}
};

Graph<int> graph;

void OpWay(int*** matrix, int n, int** h0, int* wayop) // Метод ветвей и границ
{

	for (int l = 0; l < n; l++)
	{
		for (int i = 0; i < n; i++)
		{
			int min = 1000000;
			for (int j = 0; j < n; j++) // Нахождение минимумов строк
				if (matrix[i][j] && min > *matrix[i][j])
					min = *matrix[i][j];
			for (int j = 0; j < n; j++) // Редукция строк
				if (matrix[i][j])
					*matrix[i][j] -= min;
		}
		for (int j = 0; j < n; j++)
		{
			int min = 1000000;
			for (int i = 0; i < n; i++)
				if (matrix[i][j] && min > *matrix[i][j]) // Нахождение минимумов столбцов
					min = *matrix[i][j];
			for (int i = 0; i < n; i++) // Редукция столбцов
				if (matrix[i][j])
					*matrix[i][j] -= min;
		}

		for (int i = 0; i < n; i++) // Матрица оценок нулей
			for (int j = 0; j < n; j++)
				h0[i][j] = 0;

		for (int i = 0; i < n; i++) // Нахождение оценок для нулевых элементов
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] && !*matrix[i][j])
				{
					int TMPmin = 1000000;
					int TMP2min = 1000000;

					for (int l = 0; l < n; l++)
						if (l != i && matrix[l][j] && TMPmin > *matrix[l][j])
							TMPmin = *matrix[l][j];

					for (int l = 0; l < n; l++)
						if (l != j && matrix[i][l] && TMP2min > *matrix[i][l])
							TMP2min = *matrix[i][l];

					h0[i][j] = TMPmin + TMP2min; // Оценка
				}
			}

		int mcost = 0, mi = 0, mj = 0;
		for (int i = 0; i < n; i++) // Выбор нулевого элемента с наибольшей оценкой
			for (int j = 0; j < n; j++)
				if (matrix[i][j] && mcost < h0[i][j])
				{
					mcost = h0[i][j];
					mi = i; // Для редукции матрицы 
					mj = j; //
				}
		wayop[mi] = mj;

		for (int i = 0; i < n; i++) // Редукция матрицы по столбцам
			matrix[i][mj] = nullptr;

		for (int i = 0; i < n; i++) // Редукция матрицы по строкам
			matrix[mi][i] = nullptr;

		matrix[mj][mi] = nullptr; // Ну и сам нулевой элемент убираем
	}
}

void ZadachaKomi() // Путь 
{
	int n = amountVerts;
	int** h0 = new int* [n];
	int* wayop = new int[n];
	int*** matrix = new int** [n];
	for (int i = 0; i <= n; i++)
	{
		h0[i] = new int[n];
	}
	for (int i = 0; i < n; i++) // Копия матрицы смежности для последующих редукций
	{
		matrix[i] = new int* [n];
		for (int j = 0; j < n; j++)
		{
			if (graph.Matrix[i][j] == 0) {
				matrix[i][j] = nullptr;
				continue;
			}
			matrix[i][j] = new int(graph.Matrix[i][j]);
		}
	}
	int s = 0;
	int j;
	OpWay(matrix, n, h0, wayop);
	cout << "\nОптимальный путь: ";
	int tmp = 0;
	for (int i = 0; i < n; i++)
	{
		j = wayop[i];
		if (!graph.Matrix[i][j])
		{
			cout << "Произошла ошибка с вершиной\n";
			break;
		}
		s += graph.Matrix[i][j];
	}
	for (int l = 0; l < n;)
	{
		for (int i = 0, j = 0; i < n; i++)
		{
			if (tmp == 0 || i + 1 == tmp)
			{
				if (tmp == 0) cout << i + 1;
				j = wayop[i];
				tmp = j + 1;
				if (tmp > 0)	cout << " -> " << tmp;
				l++;
			}
		}
	}
	cout << "\nИтоговый путь: " << s;
	cout << endl;
}


Graph<int> makeGraph() // Создание графа как таблица смежности
{
	Graph<int> graph;
	int amountEdges, sourceVertex, targetVertex, edgeWeight;
	cout << "Введите количество вершин: ";
	cin >> amountVerts;
	cout << endl;
	cout << "Введите количество ребер: ";
	cin >> amountEdges;
	cout << endl;
	for (int i = 1; i <= amountVerts; ++i) {
		int* vertPtr = &i;
		graph.InsertVertex(*vertPtr);
	}

	for (int i = 0; i < amountEdges; ++i) {
		cout << "Начальная вершина: ";
		cin >> sourceVertex;
		cout << endl;
		int* sourceVertPtr = &sourceVertex;
		cout << "Конечная вершина: ";
		cin >> targetVertex;
		cout << endl;
		int* targetVertPtr = &targetVertex;
		cout << "Вес ребра: "; cin >> edgeWeight; cout << endl;
		graph.InsertEdge(*sourceVertPtr, *targetVertPtr, edgeWeight);
	}
	cout << endl;
	return graph;
}


void GraphCircle(int i, int n) // Для отрисовки вершин графа по окружности
{
	int Rtmp;

	int x0 = WinW / 2; // Середина окна 
	int y0 = WinH / 2; //
	if (WinW > WinH)
	{
		R = 5 * (WinH / 18) / n;
		Rtmp = WinH / 2 - R - 10;
	}
	else {
		R = 5 * (WinW / 18) / n;
		Rtmp = WinW / 2 - R - 10;
	}
	float fi = 2.0f * 3.1415926f * float(i) / float(n);
	float y1 = Rtmp * cos(fi) + y0;
	float x1 = Rtmp * sin(fi) + x0;

	vertCord[i].x = x1; // Запоминаем координаты для отрисовки цифр вершин графа
	vertCord[i].y = y1; //
}

void drawCircle(int x, int y, int R) // Для отрисовки окружностей вершин графа
{
	glColor3f(1.0, 0.1, 0.1);
	float x1, y1;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		float fi = 2.0f * 3.1415926f * float(i) / float(360);
		y1 = R * cos(fi) + y;
		x1 = R * sin(fi) + x;;
		glVertex2f(x1, y1);
	}
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	float x2, y2;
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; i++)
	{
		float fi = 2.0f * 3.1415926f * float(i) / float(360);
		y2 = R * cos(fi) + y;
		x2 = R * sin(fi) + x;
		glVertex2f(x2, y2);
	}
	glEnd();
}

void drawText(int num, int x1, int y1) // Отрисовка текста
{
	GLvoid* font = GLUT_BITMAP_HELVETICA_18;
	string s = to_string(num);
	glRasterPos2i(x1 - 5, y1 - 5);
	for (int j = 0; j < s.length(); j++)
		glutBitmapCharacter(font, s[j]);
}

void drawVertex(int n) // Отрисовка уже самих вершин графа, включает круг и текст внутри него
{
	for (int i = 0; i < n; i++) {
		drawCircle(vertCord[i].x, vertCord[i].y, R);
		drawText(i + 1, vertCord[i].x, vertCord[i].y);
	}
}

void drawLine(int text, int x0, int y0, int x1, int y1) // Отрезок(Ребро) + его Вес
{
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex2i(x0, y0);
	glVertex2i(x1, y1);
	glEnd();
	drawText(text, (x0 + x1) / 2 + 15, (y0 + y1) / 2 + 15);
}


template<class T>
void Graph<T>::DrawGraph() // Полная отрисовка графа
{
	int n = vertexList.size();
	for (int i = 0; i < n; i++) // Как раз подготовка невидимой окружности для вершин
	{
		GraphCircle(i, n);
	}
	for (int i = 0; i < n; i++) // Отрисовка ребер графа
	{
		for (int j = i + 1; j < n; j++)
		{
			int a = Matrix[i][j];
			if (a != 0)
			{
				drawLine(a, vertCord[i].x, vertCord[i].y, vertCord[j].x, vertCord[j].y);
			}
		}
	}
	drawVertex(n); // Отрисовка вершин графа
}

void WindowsChange(int w, int h) // Окно
{
	WinW = w;
	WinH = h;
	glViewport(0, 0, (GLsizei)WinW, (GLsizei)WinH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, (GLdouble)WinW, 0, (GLdouble)WinH);
	glutPostRedisplay();
}

void drawMenuText(string text, int x1, int y1) // Текст для кнопок на меню
{
	GLvoid* font = GLUT_BITMAP_HELVETICA_18;
	string s = text;
	glRasterPos2i(x1 + 5, y1 - 20);
	for (int j = 0; j < s.length(); j++)
		glutBitmapCharacter(font, s[j]);
}

void drawMenu() // Отрисовка самого меню
{
	int height = 800;

	glColor3d(0.0, 0.0, 0.0); // Треугольники для увеличения вершин графа
	glBegin(GL_TRIANGLES);
	glVertex2i(23, height - 79);
	glVertex2i(187, height - 79);
	glVertex2i(105, height - 40);
	glEnd();
	glColor3d(0.4, 1.0, 0.5);
	glBegin(GL_TRIANGLES);
	glVertex2i(40, height - 75);
	glVertex2i(170, height - 75);
	glVertex2i(105, height - 45);
	glEnd();
	glColor3d(0.0, 0.0, 0.0);
	drawMenuText("Insert New Vertex", 35, height - 15);

	glColor3d(0.0, 0.0, 0.0); // Треугольники для уменьшения вершин графа
	glBegin(GL_TRIANGLES);
	glVertex2i(23, height - 86);
	glVertex2i(187, height - 86);
	glVertex2i(105, height - 125);
	glEnd();
	glColor3d(1.0, 0.2, 0.3);
	glBegin(GL_TRIANGLES);
	glVertex2i(40, height - 90);
	glVertex2i(170, height - 90);
	glVertex2i(105, height - 120);
	glEnd();
	glColor3d(0.0, 0.0, 0.0);
	drawMenuText("Delete Vertex", 50, height - 120);

	glColor3d(0.2, 0.2, 0.2); // Прямоугольник для кнопки вывода таблицы смежности
	glBegin(GL_QUADS);
	glVertex2i(110, height - 550);
	glVertex2i(213, height - 550);
	glVertex2i(213, height - 525);
	glVertex2i(110, height - 525);
	glEnd();
	glColor3d(0.8, 1.0, 0.9);
	drawMenuText("Print Matrix", 110, height - 525);

	glColor3d(0.2, 0.2, 0.2); // Прямоугольники для кнопки запуска Коммивояжера
	glBegin(GL_QUADS);
	glVertex2i(40, height - 560);
	glVertex2i(303, height - 560);
	glVertex2i(303, height - 610);
	glVertex2i(40, height - 610);
	glEnd();
	glColor3d(0.2, 1.0, 0.2);
	glBegin(GL_QUADS);
	glVertex2i(50, height - 570);
	glVertex2i(293, height - 570);
	glVertex2i(293, height - 600);
	glVertex2i(50, height - 600);
	glEnd();
	glColor3d(0.0, 0.0, 0.0);
	drawMenuText("Traveling Salesman Problem", 50, height - 572);

}

void MouseAction(int del, int action, int x, int y) { // Функция для отслеживания нажатий для кнопок
	int shift = 50;
	int height = 800;

	if (action == GLUT_DOWN) {

		if ((x > 40) && (x < 170) && y > 50 && y < 80) // Кнопка добавить вершину
		{
			int sourceVertex;
			int targetVertex;
			int edgeWeight;
			cout << "Начальная вершина: "; cin >> sourceVertex; cout << endl;
			cout << "Конечная вершина: "; cin >> targetVertex; cout << endl;
			if (sourceVertex > amountVerts || targetVertex > amountVerts) {
				amountVerts++;
				graph.InsertVertex(amountVerts);
			}

			cout << "Ну и вес ребра: "; cin >> edgeWeight; cout << endl;
			graph.InsertEdge(sourceVertex, targetVertex, edgeWeight); // 
		}
		if ((x > 40) && (x < 170) && y > 90 && y < 160) // Кнопка убрать вершину
		{
			int sourceVertex;
			cout << "Введите последнию вершину: "; cin >> sourceVertex; cout << endl;
			if (sourceVertex == amountVerts)
			{
				amountVerts--;
				graph.DeleteVertex();
			}
			else cout << "Это не последняя вершина" << endl;
		}
		if (x > 110 && x < 213 && y > 525 && y < 550) // Кнока вывода таблицы смежности
		{
			graph.Print();
		}
		if (x > 50 && x < 293 && y > 570 && y < 600) // Кнопка для запуска Коммивояжера
		{
			ZadachaKomi();
		}
	}
	glutPostRedisplay();
}

void display()
{
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, WinW, 0, WinH);
	glViewport(0, 0, WinW, WinH);
	glClearColor(0.8, 0.8, 0.8, 0.8);
	glClear(GL_COLOR_BUFFER_BIT);
	graph.DrawGraph();
	drawMenu();
	glutSwapBuffers();
}

void visual()
{

}