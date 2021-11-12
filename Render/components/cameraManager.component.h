#ifndef CAMERA_COMPONENT_H
#define CAMERA_COMPONENT_H

#include <math.h>

#include "staticRenderingVars.component.h"
#include "staticShaderManager.component.h"

#include "config.h"

#include "generics.h"
#include "matrix.h"
#include "ghostymath.h"

// start glob variables definition

struct Camera camera;
Entity p_Entity;

mat4x4 m4_projMatrix;
mat4x4 m4_viewMatrix;
mat4x4 m4_projViewMatrix;
float fArray_projViewArray[16];

mat4x4 m4_translationMatrix;
mat4x4 m4_rotationMatrix;
mat4x4 m4_scaleMatrix;
mat4x4 m4_MVPMatrix;
float fArray_MVPArray[16];

// end glob variables definition

// start CameraManager funcs

void setup_Camera(vec3 start_position);

void UpdateCameraVars();

void hookCameraToEntity();

mat4x4 make_projMatrix();
mat4x4 make_viewMatrix();
mat4x4 make_projViewMatrix();
mat4x4 make_MVPMatrix();

void load_MVPMatrix();

// end CameraManager funcs

// start getters

mat4x4 getViewMatrix();
mat4x4 getProjMatrix();
mat4x4 getProjViewMatrix();

// end getters

#endif
