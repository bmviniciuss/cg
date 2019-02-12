#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"
#include "Pixel.h"

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************

void PutPixel(Pixel pixel)
{
  if (pixel.x < 0 || pixel.x >= IMAGE_WIDTH || pixel.y < 0 || pixel.y >= IMAGE_HEIGHT)
  {
    return;
  }

  FBptr[(pixel.x * 4) + (pixel.y * IMAGE_WIDTH * 4) + 0] = pixel.R;
  FBptr[(pixel.x * 4) + (pixel.y * IMAGE_WIDTH * 4) + 1] = pixel.G;
  FBptr[(pixel.x * 4) + (pixel.y * IMAGE_WIDTH * 4) + 2] = pixel.B;
  FBptr[(pixel.x * 4) + (pixel.y * IMAGE_WIDTH * 4) + 3] = pixel.A;
}

void drawLine(Pixel pInitial, Pixel pFinal)
{
  /* Compute o dX and dY */
  int dx = pFinal.x - pInitial.x;
  int dy = pFinal.y - pInitial.y;

  /* Algorithm's starting point */
  Pixel currentPixel = pInitial;

  /* Rate Direction */
  float direction = (abs(dx) >= abs(dy)) ? dx : dy;

  /* Compute RGB change */
  double changeR, changeG, changeB, changeA;
  float R, G, B, A;

  R = currentPixel.R;
  G = currentPixel.G;
  B = currentPixel.B;
  A = currentPixel.A;

  changeR = (double)(pFinal.R - pInitial.R) / abs(direction);
  changeG = (double)(pFinal.G - pInitial.G) / abs(direction);
  changeB = (double)(pFinal.B - pInitial.B) / abs(direction);
  changeA = (double)(pFinal.A - pInitial.A) / abs(direction);

  /* Draw First Pixel*/
  PutPixel(currentPixel);

  /* Check octants */
  if (dx < 0) // 3rd,4th,5th or 6th octant
  {
    // Just flip initial and final points
    drawLine(pFinal, pInitial);
  }
  else // 1st,2nd,7th or 8th octant
  {
    if (dy > 0) // 1st or 2nd octant
    {

      if (abs(dx) >= abs(dy)) // 1st octant
      {

        // std::cout << "1st\n";
        /* Compute D for 1st point */
        int d = 2 * dy - dx;

        /* Increments */
        int incr_e = 2 * dy;
        int incr_ne = 2 * (dy - dx);
        while (currentPixel.x < pFinal.x)
        {
          if (d <= 0)
          {
            d += incr_e;
            currentPixel.x++;
          }
          else
          {
            d += incr_ne;
            currentPixel.y++;
            currentPixel.x++;
          }

          /* Color Increments */
          R += changeR;
          G += changeG;
          B += changeB;
          A += changeA;

          /* Change current color */
          currentPixel.R = R;
          currentPixel.G = G;
          currentPixel.B = B;
          currentPixel.A = A;

          PutPixel(currentPixel);
        }
      }
      else // 2nd octant
      {
        // std::cout << "2nd\n";
        int d = dy - 2 * dx;

        /* increments */
        int incr_e = 2 * (-dy + dx);
        int incr_ne = 2 * (dx);

        while (currentPixel.y < pFinal.y)
        {
          if (d < 0)
          {
            d += incr_ne;
            currentPixel.y++;
          }
          else
          {
            d += incr_e;
            currentPixel.x++;
            currentPixel.y++;
          }

          /* Color Increments */
          R += changeR;
          G += changeG;
          B += changeB;
          A += changeA;

          /* Change current color */
          currentPixel.R = R;
          currentPixel.G = G;
          currentPixel.B = B;
          currentPixel.A = A;

          PutPixel(currentPixel);
        }
      }
    }
    else // (dy < 0)  7th or 8th octant
    {
      if (abs(dy) > abs(dx)) // 7th octant
      {
        // std::cout << "7th\n";
        int d = dy + 2 * dx;
        int incr_e = 2 * dx;
        int incr_ne = 2 * (dy + dx);
        while (currentPixel.y > pFinal.y)
        {
          if (d < 0)
          {
            d += incr_e;
            currentPixel.y--;
          }
          else
          {
            d += incr_ne;
            currentPixel.x++;
            currentPixel.y--;
          }

          /* Color Increments */
          R += changeR;
          G += changeG;
          B += changeB;
          A += changeA;

          /* Change current color */
          currentPixel.R = R;
          currentPixel.G = G;
          currentPixel.B = B;
          currentPixel.A = A;

          PutPixel(currentPixel);
        }
      }
      else // 8th octante
      {
        // std::cout << "8th\n";
        int d = -2 * dy + dx;
        int incr_e = -2 * dy;
        int incr_ne = 2 * (-dy - dx);
        while (currentPixel.x < pFinal.x)
        {
          if (d < 0)
          {
            d += incr_e;
            currentPixel.x++;
          }
          else
          {
            d += incr_ne;
            currentPixel.x++;
            currentPixel.y--;
          }

          /* Color Increments */
          R += changeR;
          G += changeG;
          B += changeB;
          A += changeA;

          /* Change current color */
          currentPixel.R = R;
          currentPixel.G = G;
          currentPixel.B = B;
          currentPixel.A = A;

          PutPixel(currentPixel);
        }
      }
    }
  }
}

void drawTriangle(Pixel p1, Pixel p2, Pixel p3)
{
  drawLine(p1, p2);
  drawLine(p2, p3);
  drawLine(p3, p1);
}
#endif // _MYGL_H_
