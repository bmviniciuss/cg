#include <stdio.h>
#include <iostream>
#include "main.h"
#include "cgPipeline.h"
#include <iostream>
#include <math.h>
#include <glm/glm.hpp>
#include <glm/mat4x4.hpp>
#include "mygl.h"
#include "definitions.h"
#include <vector>
#include "loader.h"

float angle = 0;
std::vector<glm::vec4> vertices;

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	std::vector<glm::vec4> modelVertices = vertices;
	clearBackground();
	glm::mat4x4 mPipeline = pipelineMatrix(angle);
	for (int i = 0; i < modelVertices.size(); i++)
	{
		modelVertices[i] = mPipeline * modelVertices[i];
		modelVertices[i] = modelVertices[i] / modelVertices[i].w;
	}
	srand(time(NULL));
	for (int i = 0; i < modelVertices.size(); i += 3)
	{
		Pixel p1((int)modelVertices[i].x, (int)modelVertices[i].y, rand() % 256, rand() % 256, rand() % 256, 255);
		Pixel p2((int)modelVertices[i + 1].x, (int)modelVertices[i + 1].y, rand() % 256, rand() % 256, rand() % 256, 255);
		Pixel p3((int)modelVertices[i + 2].x, (int)modelVertices[i + 2].y, rand() % 256, rand() % 256, rand() % 256, 255);
		drawTriangle(p1, p2, p3);
	}
	angle += 0.01;
	if (angle > 361)
	{
		angle = 0;
	}
}

//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
	// LoadModel
	vertices = loadModel("monkey_model.obj");

	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}
