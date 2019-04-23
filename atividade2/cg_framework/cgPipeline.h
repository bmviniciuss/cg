
#include <iostream>
#include <math.h>
#include <glm/glm.hpp>
#include <glm/mat4x4.hpp>
#include "definitions.h"

glm::mat4x4 pipelineMatrix(float angle)
{

  // Model Matrix
  glm::mat4x4 mTranslation = glm::mat4x4(1, 0, 0, 0,
                                         0, 1, 0, 0,
                                         0, 0, 1, 0,
                                         0, 0, 0, 1);

  glm::mat4x4 mScale = glm::mat4x4(2.5, 0, 0, 0,
                                   0, -2.5, 0, 0,
                                   0, 0, 1, 0,
                                   0, 0, 0, 1);

  glm::mat4x4 mRotation = glm::mat4x4(cos(angle), 0, -sin(angle), 0,
                                      0, 1, 0, 0,
                                      sin(angle), 0, cos(angle), 0,
                                      0, 0, 0, 1);

  glm::mat4x4 mModel = mTranslation * mScale * mRotation;

  // Camera Settings
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

  glm::mat4x4 T = glm::mat4x4(1, 0, 0, 0,
                              0, 1, 0, 0,
                              0, 0, 1, 0,
                              -dirCam[0], -dirCam[1], -dirCam[2], 1);
  glm::mat4x4 mView = B * T;

  // ModelView Matrix
  glm::mat4x4 mModelView = mView * mModel;

  // Projection Matrix
  int d = 1;
  glm::mat4x4 mProjection = glm::mat4x4(1, 0, 0, 0,
                                        0, 1, 0, 0,
                                        0, 0, 1, -(1 / d),
                                        0, 0, d, 0);

  glm::mat4x4 mProjectionView = mProjection * mModelView;

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
  glm::mat4x4 mPipeline = mVP * mProjectionView;

  return mPipeline;
}