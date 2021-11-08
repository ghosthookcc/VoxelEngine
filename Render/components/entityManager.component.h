#ifndef ENTITY_MANAGER_COMPONENT_H
#define ENTITY_MANAGER_COMPONENT_H

#include <windows.h>
#include <gl/gl.h>

#include "staticRenderingVars.component.h"
#include "staticShaderManager.component.h"

#include "cameraManager.component.h"
#include "mesh.component.h"
#include "worldManager.component.h"

#include "config.h"

#include "initGLFuncs.h"
#include "generics.h"
#include "matrix.h"
#include "vec3.h"
#include "vec4.h"
#include "shaderClass.h"

EntityStack* Entities;

void loadToVAO(Mesh new_EntityMesh);

unsigned int createVAO();

void bindIndices(dynUByteArray* indicesBuffer);
void storeDataInAttributeList(int attribute, int coordinateSize, dynFloatArray* fbuffer);

void transformation_SetPosition(Entity* entity);
void transformation_SetRotation(Entity* entity);
void transformation_SetScale(Entity* entity);

mat4x4 make_TransformationMatrix();

void load_TransformationMatrix();

void cleanUpEntities();

#endif
