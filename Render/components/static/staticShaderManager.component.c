#include "staticShaderManager.component.h"

float get_Uniformfv(GLuint ID, char* uniformName)
{
  GLfloat* params = malloc(sizeof(float));
  glGetUniformfv(ID, glGetUniformLocation(ID, uniformName), params);
  return(params[0]);
}

void set_Uniform1f(GLuint ID, char* uniformName, float v0)
{
  glUniform1f(glGetUniformLocation(ID, uniformName), v0);
}

void set_Uniform3f(GLuint ID, char* uniformName, float v0, float v1, float v2)
{
  glUniform3f(glGetUniformLocation(ID, uniformName), v0, v1, v2);
}

void set_Uniform4f(GLuint ID, char* uniformName, float v0, float v1, float v2, float v3)
{
  glUniform4f(glGetUniformLocation(ID, uniformName), v0, v1, v2, v3);
}

void set_UniformSample2D(GLuint ID, char* uniformName)
{

}

void set_UniformMatrix4fv(GLuint ID, char* uniformName, GLboolean transpose, float fArray[])
{
  glUniformMatrix4fv(glGetUniformLocation(ID, uniformName), 1, transpose, fArray);
}
