#include "MasterRenderer.h"

GLvoid glInit(GLsizei WIDTH, GLsizei HEIGHT)
{
  programIDs = new_uintVector(1);
  vbosIDs = new_uintVector(1);
  vaosIDs = new_uintVector(1);
  indexbuffersIDs = new_uintVector(1);

  Entities = init_EntityStack();

  setup_Camera(new_vec3(0.0f, 1.0f, 2.5f));

  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glEnable(GL_DEPTH_TEST);
  //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void glClearScene()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void Update()
{
  for(int UpdateFuncs_iterator = 0;
          UpdateFuncs_iterator < UpdateFuncs->size;
          UpdateFuncs_iterator++)
  {
    UpdateFuncs->func_ptrs[UpdateFuncs_iterator]();
  }

  UpdateEntities(DeltaTime.QuadPart);
  UpdateCamera(DeltaTime.QuadPart);
  UpdateControls(DeltaTime.QuadPart);
}

void Render()
{
  glClearScene();
  RenderEntities(DeltaTime.QuadPart);
}

void CLEANUP()
{
  for(int i = 0; i < vaosIDs->size; i++)
  {
    //glDeleteVertexArrays(1, vaosIDs->values[i]);
  }

  for(int i = 0; i < vbosIDs->size; i++)
  {
    //glDeleteBuffers(1, vbosIDs->values[i]);
  }

  cleanUpEntities();
}
