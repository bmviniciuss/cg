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

Em primeiro lugar é feito uma checagem para saber se o pixel está dentro dos limites da janela criada. Caso ele estja dentro dos limites o pixel é posto na "memória de vídeo" simulada aqui pelo `FBptr`. É feito o calculo de `offset` para saber a posição de cada cor do canal RGBA na memória.
