#ifndef _PIXEL_H_
#define _PIXEL_H_

class Pixel
{
public:
  Pixel(int x, int y, int R, int G, int B, int A);
  int x, y, R, G, B, A;
  int getX();
  int getY();
};

Pixel::Pixel(int x, int y, int R, int G, int B, int A)
{
  this->x = x;
  this->y = y;
  this->R = R;
  this->G = G;
  this->B = B;
  this->A = A;
}

int Pixel::getX()
{
  return this->x;
}

int Pixel::getY()
{
  return this->y;
}

#endif // _PIXEL_H_
