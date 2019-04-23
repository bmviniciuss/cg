#include <stdio.h>
#include <iostream>
#include "main.h"
#include "pipeline.h"

float angle = 0;
//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	clearBackground();
	pipeline(angle);
	angle += 0.01;
	if (angle > 361)
	{
		angle = 0;
	}
	// clearBackground();
}

//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{

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
