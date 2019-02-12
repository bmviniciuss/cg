## Atividade 1 - Algoritmos de Rasterização

### Trabalho realizado pelos alunos:

- Vinicius Barbosa de Medeiros - 20170003890
- Jorge Gomes de Melo Júnior - 20170009650

## Objetivo

O propósito do trabalho é implementar funções utilizando algoritmos para a rasteirização de primitivas, que possibilitam a formação de pontos e linhas na tela do computador. A rasterização será feita através da escrita direta na memória, para isso foi utilizado o framework fornecido pelo professor que simula o acesso à memória de vídeo.

## Funções Implementadas

A principio, foi criado uma estrutura que irá representar cada pixel. Para isso foi criado uma classe `Pixel` que guarda a posição `X` e `Y`, assim como as componentes do sistema RGBA.

```c++
class Pixel {
public:
  Pixel(int x, int y, int R, int G, int B, int A);
  int x, y, R, G, B, A;
  int getX();
  int getY();
};
```

## 1 - putPixel(Pixel pixel)

Essa função é responsável por desenhar um pixel, utilizando o framework dado, na tela através da posição e cor.

```c++
void putPixel(Pixel pixel)
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
```

Em primeiro lugar é feito uma checagem para saber se o pixel está dentro dos limites da janela criada. Caso ele estja dentro dos limites o pixel é posto na "memória de vídeo" simulada aqui pelo `FBptr`. É feito o cálculo de `offset` para saber a posição de cada cor do canal RGBA na memória.

## 2 - drawLine(Pixel initialPixel, Pixel finalPixel)

<p align="center"> 
<img src="./assets/Screenshot_20190211_221904.png" height="500">
</p>

<details>
<summary> Código da Imagem </summary><p>

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

  </p>
</details>
