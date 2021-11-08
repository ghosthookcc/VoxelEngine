#include "shaderClass.h"

char* read_Shader(char** filename)
{
  HANDLE file_Handle = CreateFile(*(filename),
                           GENERIC_READ,
                           0,
                           NULL,
                           OPEN_EXISTING,
                           FILE_ATTRIBUTE_NORMAL,
                           NULL);

  if (file_Handle == INVALID_HANDLE_VALUE)
  {
    printf("\nFailed to create/open file :: %s ;\n", *(filename));
    return FALSE;
  }

  DWORD filesize = GetFileSize(file_Handle, NULL);

  char* buffer = 0;
  buffer = malloc(filesize);

  DWORD nRead;

  ReadFile(file_Handle, buffer, filesize, &nRead, NULL);
  CloseHandle(file_Handle);

  buffer[filesize] = '\0';

  return buffer;
}

GLuint set_Shader(GLuint ID, char* filename, enum shadertype shadertype)
{
  char* shaderCode = read_Shader((char**)&filename);
  GLuint shader = glCreateShader(shadertype);
  glShaderSource(shader, 1, (const char**)&shaderCode, NULL);
  glCompileShader(shader);

  glAttachShader(ID, shader);
  return shader;
}

void unset_Shader()
{
  glUseProgram(0);
}

void detachDel_Shader(GLuint ID, GLuint shader)
{
  glDetachShader(ID, shader);
  glDeleteShader(shader);
}
