#include "main.h"

void octantTest()
{
	/*
	int red[4] = {255, 0, 0, 255};
	int orange[4] = {255, 127, 0, 255};
	int yellow[4] = {255, 255, 0, 255};
	int green[4] = {0, 255, 0, 255};
	int ligh_blue[4] = {0, 255, 255, 255};
	int blue[4] = {0, 0, 255, 255};
	int purple[4] = {127, 0, 255, 255};
	int pink[4] = {255, 0, 127, 255};
	int white[4] = {255, 255, 255, 255};
	*/

	int i;
	int step = 15;

	/* 1st Octant */
	for (int i = 255; i < 512; i += step)
	{
		Pixel initialPixelFirstOctant(255, 255, 255, 0, 0, 255);
		Pixel finalPixelFirstOctant(512, i, 0, 0, 255, 0);
		drawLine(initialPixelFirstOctant, finalPixelFirstOctant);
	}

	/* 2nd Octant */
	for (int i = 512; i >= 255; i -= step)
	{
		Pixel initialPixelSecondOctant(255, 255, 255, 127, 0, 255);
		Pixel finalPixelSecondOctant(i, 512, 255, 0, 127, 255);
		drawLine(initialPixelSecondOctant, finalPixelSecondOctant);
	}

	/* 3rd Octant */
	for (int i = 255; i >= 0; i -= step)
	{
		Pixel initialPixelThirdOctant(255, 255, 255, 255, 0, 255);
		Pixel finalPixelThirdOctant(i, 512, 0, 255, 0, 255);
		drawLine(initialPixelThirdOctant, finalPixelThirdOctant);
	}

	/* 4th Octant */
	for (int i = 255; i <= 512; i += step)
	{
		Pixel initialPixelFourthOctant(255, 255, 255, 127, 0, 255);
		Pixel finalPixelFourthOctant(0, i, 0, 0, 255, 255);
		drawLine(initialPixelFourthOctant, finalPixelFourthOctant);
	}

	/* 5th Octant */
	for (int i = 255; i >= 0; i -= step)
	{
		Pixel initialPixelFifthOctant(255, 255, 0, 255, 255, 255);
		Pixel finalPixelFifthOctant(0, i, 0, 255, 0, 255);
		drawLine(initialPixelFifthOctant, finalPixelFifthOctant);
	}

	/* 6th Octant */
	for (int i = 0; i <= 255; i += step)
	{
		Pixel initialPixelSixthOctant(255, 255, 127, 0, 255, 255);
		Pixel finalPixelSixOctant(i, 0, 255, 127, 0, 255);
		drawLine(initialPixelSixthOctant, finalPixelSixOctant);
	}

	/* 7th Octant */
	for (int i = 255; i <= 512; i += step)
	{
		Pixel initialPixelSeventhOctant(255, 255, 0, 255, 255, 255);
		Pixel finalPixelSeventhOctant(i, 0, 255, 0, 127, 255);
		drawLine(initialPixelSeventhOctant, finalPixelSeventhOctant);
	}

	/* 8th Octant */
	for (int i = 0; i <= 255; i += step)
	{
		Pixel initialPixelEighthOctant(255, 255, 0, 0, 255, 255);
		Pixel finalPixelEighthOctant(512, i, 255, 255, 0, 255);
		drawLine(initialPixelEighthOctant, finalPixelEighthOctant);
	}
}

void drawCrossHair()
{
	/* Left -> Right Diagonal */
	Pixel initialPixelLeftRightDiagonal(0, 0, 0, 0, 255, 255);
	Pixel finalPixelLeftRightDiagonal(512, 512, 255, 0, 127, 255);
	drawLine(initialPixelLeftRightDiagonal, finalPixelLeftRightDiagonal);

	/* Right-> Left Diagonal */
	Pixel initialPixelRightLeftDiagonal(512, 0, 255, 255, 0, 255);
	Pixel finalPixelRightLeftDiagonal(0, 512, 0, 255, 255, 255);
	drawLine(initialPixelRightLeftDiagonal, finalPixelRightLeftDiagonal);

	/* Center Vertical */
	Pixel initialPixelCenterVertical(255, 0, 0, 255, 0, 255);
	Pixel finalPixelCenterVertical(255, 512, 127, 0, 255, 255);
	drawLine(initialPixelCenterVertical, finalPixelCenterVertical);

	/* Center Horizontal */
	Pixel initialPixelCenterHorizontal(0, 255, 255, 0, 0, 255);
	Pixel finalPixelCenterHorizontal(511, 255, 255, 127, 0, 255);
	drawLine(initialPixelCenterHorizontal, finalPixelCenterHorizontal);
}

void triangleTest()
{
	Pixel p1(255, 150, 255, 0, 0, 255);
	Pixel p2(255, 450, 255, 127, 0, 255);
	Pixel p3(125, 500, 255, 255, 0, 255);
	Pixel p4(280, 150, 255, 0, 0, 255);
	Pixel p5(490, 15, 0, 255, 0, 255);
	Pixel p6(400, 450, 0, 0, 255, 255);

	drawTriangle(p1, p2, p3);
	drawTriangle(p4, p5, p6);
}

void pixelTest()
{
	int step = 16;

	for (int i = 0; i <= 511; i += step)
	{
		Pixel pH(i, 255, 255, 0, 0, 255);
		putPixel(pH);
	}

	for (int i = 0; i <= 511; i += step)
	{
		Pixel pV(255, i, 255, 255, 0, 255);
		putPixel(pV);
	}
}
//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************
	pixelTest();
	// octantTest();
	// drawCrossHair();
	// triangleTest();
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
