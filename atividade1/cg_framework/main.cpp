#include "main.h"

void testeOctante()
{
	int red[4] = {255, 0, 0, 255};
	int orange[4] = {255, 127, 0, 255};
	int yellow[4] = {255, 255, 0, 255};
	int green[4] = {0, 255, 0, 255};
	int ligh_blue[4] = {0, 255, 255, 255};
	int blue[4] = {0, 0, 255, 255};
	int purple[4] = {127, 0, 255, 255};
	int pink[4] = {255, 0, 127, 255};
	int white[4] = {255, 255, 255, 255};

	int i;
	int step = 15;

	/* 1 octante*/
	// for (int i = 255; i < 512; i += step)
	// {
	// 	Pixel p_primeiro_i(255, 255, 255, 0, 0, 255);
	// 	Pixel p_primeiro_f(512, i, 0, 0, 255, 255);
	// 	drawLine(p_primeiro_i, p_primeiro_f);
	// }

	/* 2 octante*/
	// for (int i = 512; i >= 255; i -= step)
	// {
	// 	Pixel p_segundo_i(255, 255, orange);
	// 	Pixel p_segundo_f(i, 512, orange);
	// 	drawLine(p_segundo_i, p_segundo_f);
	// }

	// /* 3 octante*/
	// for (int i = 255; i >= 0; i -= step)
	// {
	// 	Pixel p_segundo_i(255, 255, yellow);
	// 	Pixel p_segundo_f(i, 512, yellow);
	// 	drawLine(p_segundo_i, p_segundo_f);
	// }

	// /* 4 octante*/
	// for (int i = 255; i <= 512; i += step)
	// {
	// 	Pixel p_segundo_i(255, 255, green);
	// 	Pixel p_segundo_f(0, i, green);
	// 	drawLine(p_segundo_i, p_segundo_f);
	// }

	// /* 5 octante*/
	// for (int i = 255; i >= 0; i -= step)
	// {
	// 	Pixel p_segundo_i(255, 255, ligh_blue);
	// 	Pixel p_segundo_f(0, i, ligh_blue);
	// 	drawLine(p_segundo_i, p_segundo_f);
	// }

	// /* 6 octante*/
	// for (int i = 0; i <= 255; i += step)
	// {
	// 	Pixel p_segundo_i(255, 255, blue);
	// 	Pixel p_segundo_f(i, 0, blue);
	// 	drawLine(p_segundo_i, p_segundo_f);
	// }

	// /* 7 octante*/
	// for (int i = 255; i <= 512; i += step)
	// {
	// 	Pixel p_segundo_i(255, 255, purple);
	// 	Pixel p_segundo_f(i, 0, purple);
	// 	drawLine(p_segundo_i, p_segundo_f);
	// }

	// /* 8 octante*/
	// for (int i = 0; i <= 255; i += step)
	// {
	// 	Pixel p_segundo_i(255, 255, pink);
	// 	Pixel p_segundo_f(512, i, pink);
	// 	drawLine(p_segundo_i, p_segundo_f);
	// }

	// /* DIAGONAL ESQ-> DIREITA*/
	// Pixel p_ded_i(0, 0, white);
	// Pixel p_ded_f(512, 512, white);
	// drawLine(p_ded_i, p_ded_f);

	// /* DIAGONAL ESQ-> DIREITA*/
	// Pixel p_dde_i(512, 0, white);
	// Pixel p_dde_f(0, 512, white);
	// drawLine(p_dde_i, p_dde_f);

	// /* VERTICAL CENTRAL */
	// Pixel p_vc_i(255, 0, white);
	// Pixel p_vc_f(255, 512, white);
	// drawLine(p_vc_i, p_vc_f);

	// /* HORIZONTAL CENTRO */
	// int vertial = 255;
	// Pixel p_hc_i(0, vertial, white);
	// Pixel p_hc_f(511, vertial, white);
	// drawLine(p_hc_i, p_hc_f);
}
//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	int red[4] = {255, 0, 0, 255};
	int green[4] = {0, 255, 0, 255};
	int blue[4] = {0, 0, 255, 255};
	int white[4] = {255, 255, 255, 255};
	int yellow[4] = {255, 255, 0, 255};
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************

	/* GRIDDDDDDDDDDDDD */
	testeOctante();

	Pixel p1(255, 150, 255, 0, 0, 255);
	Pixel p2(255, 450, 255, 127, 0, 255);
	Pixel p3(125, 500, 255, 255, 0, 255);

	drawTriangle(p1, p2, p3);
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
