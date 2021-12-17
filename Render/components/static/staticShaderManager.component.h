#ifndef STATIC_SHADER_MANAGER_COMPONENT_H
#define STATIC_SHADER_MANAGER_COMPONENT_H

#include <windows.h>
#include <gl/gl.h>

#include "staticRenderingVars.component.h"

#include "initGLFuncs.h"
#include "generics.h"
#include "matrix.h"

float get_Uniformfv(GLuint ID, char* uniformName);

void set_Uniform1f(GLuint ID, char* uniformName, float v0);
void set_Uniform3f(GLuint ID, char* uniformName, float v0, float v1, float v2);
void set_Uniform4f(GLuint ID, char* uniformName, float v0, float v1, float v2, float v3);
void set_UniformMatrix4fv(GLuint ID, char* uniformName, GLboolean transpose, float fArray[]);

#endif
