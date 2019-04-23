#define GLM_ENABLE_EXPERIMENTAL

#include <iostream>
#include <math.h>
#include <glm/glm.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtx/string_cast.hpp>
#include "mygl.h"
#include "definitions.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <vector>
#include "loader.h"

void pipeline(float angle)
{

  glm::mat4x4 mTranslacao = glm::mat4x4(1, 0, 0, 0,
                                        0, 1, 0, 0,
                                        0, 0, 1, 0,
                                        0, 0, 0, 1);

  glm::mat4x4 mEscala = glm::mat4x4(2.5, 0, 0, 0,
                                    0, -2.5, 0, 0,
                                    0, 0, 1, 0,
                                    0, 0, 0, 1);

  glm::mat4x4 mRotacao = glm::mat4x4(cos(angle), 0, -sin(angle), 0,
                                     0, 1, 0, 0,
                                     sin(angle), 0, cos(angle), 0,
                                     0, 0, 0, 1);

  glm::mat4x4 mModel = mTranslacao * mEscala * mRotacao;

  // View
  glm::vec3 lookCam = glm::vec3(0, 0, 0);
  glm::vec3 posCam = glm::vec3(0, 0, -5);
  glm::vec3 upCam = glm::vec3(0, 1, 0);

  glm::vec3 dirCam = lookCam - posCam;

  glm::vec3 zCam = -normalize(dirCam);
  glm::vec3 xCam = normalize(cross(upCam, zCam));
  glm::vec3 yCam = cross(zCam, xCam);

  glm::mat4x4 B = glm::mat4x4(xCam[0], yCam[0], zCam[0], 0,
                              xCam[1], yCam[1], zCam[1], 0,
                              xCam[2], yCam[2], zCam[2], 0,
                              0, 0, 0, 1);

  // glm::mat4x4 T = glm::mat4x4(1, 0, 0, -posCam[0],
  //                             0, 1, 0, -posCam[1],
  //                             0, 0, 1, -posCam[2],
  //                             0, 0, 0, 1);

  glm::mat4x4 T = glm::mat4x4(1, 0, 0, 0,
                              0, 1, 0, 0,
                              0, 0, 1, 0,
                              -dirCam[0], -dirCam[1], -dirCam[2], 1);
  glm::mat4x4 mView = B * T;
  // std::cout << glm::to_string(mView) << std::endl;

  glm::mat4x4 modelView = mView * mModel;

  // Projection Matrix
  int d = 1;
  glm::mat4x4 mProjection = glm::mat4x4(1, 0, 0, 0,
                                        0, 1, 0, 0,
                                        0, 0, 1, -(1 / d),
                                        0, 0, d, 0);

  glm::mat4x4 mProjectionView = mProjection * modelView;

  // Viewport Matrix
  glm::mat4x4 mVPTranslate = glm::mat4x4(1, 0, 0, 0,
                                         0, 1, 0, 0,
                                         0, 0, 1, 0,
                                         (IMAGE_WIDTH - 1) / 2, (IMAGE_HEIGHT - 1) / 2, 0, 1);
  glm::mat4x4 mVPScale = glm::mat4x4((IMAGE_WIDTH / 2), 0, 0, 0,
                                     0, (IMAGE_HEIGHT / 2), 0, 0,
                                     0, 0, 1, 0,
                                     0, 0, 0, 1);
  glm::mat4x4 mVPInvert = glm::mat4x4(1, 0, 0, 0,
                                      0, -1, 0, 0,
                                      0, 0, 1, 0,
                                      0, 0, 0, 1);
  glm::mat4x4 mVP = mVPTranslate * mVPScale * mVPInvert;

  // Pipeline Matrix
  glm::mat4x4 mPipeline = mVP * mProjection * mView * mModel;
  // std::cout << glm::to_string(mPipeline) << std::endl;
  // std::cout << glm::to_string(mPipeline) << std::endl;

  std::vector<glm::vec4> vertices = loadModel("monkey_model.obj");

  for (int i = 0; i < vertices.size(); i++)
  {
    vertices[i] = mPipeline * vertices[i];
    vertices[i] = vertices[i] / vertices[i].w;
  }

  for (int i = 0; i < vertices.size(); i += 3)
  {
    Pixel p1((int)vertices[i].x, (int)vertices[i].y, 255, 255, 255, 255);
    Pixel p2((int)vertices[i + 1].x, (int)vertices[i + 1].y, 255, 255, 255, 255);
    Pixel p3((int)vertices[i + 2].x, (int)vertices[i + 2].y, 255, 255, 255, 255);
    drawTriangle(p1, p2, p3);
  }
}