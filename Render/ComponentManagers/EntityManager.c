#include "EntityManager.h"

void UpdateEntities(LPCRITICAL_SECTION *critsection, struct blist *shared_mem, struct blist *local_list)
{
  size_t size;

  BOOL res = TryEnterCriticalSection(critsection);
  if(res == 0)
  {
    return;
  }
  size = shared_mem->size;
  memcpy(local_list->planets, shared_mem->planets, sizeof(struct body) * size);
  LeaveCriticalSection(critsection);
  struct body farthest_object = local_list->planets[size - 1];

  double dist_scalar = 75 / calcDVec3length(farthest_object.position);

  for(int i = 0; i < entityStack_Count(Entities); i++)
  {
    Entities->entities[i].position = dvec3ToVec3(multiplyDVec3ByDouble(local_list->planets[i].position, dist_scalar));
    Entities->entities[i].velocity = dvec3ToVec3(multiplyDVec3ByDouble(local_list->planets[i].velocity, dist_scalar));
  }
}

void RenderEntities(LONGLONG DeltaTime)
{
  for(int i = 0; i < entityStack_Count(Entities); i++)
  {
   glBindVertexArray(Entities->entities[i].vaoID);

   glEnableVertexAttribArray(0);
   glEnableVertexAttribArray(1);
   glEnableVertexAttribArray(2);

   transformation_SetPosition(Entities->entities[i].position);
   transformation_SetScale(&Entities->entities[i]);
   transformation_SetRotation(&Entities->entities[i]);

   m4_MVPMatrix = make_MVPMatrix();
   load_MVPMatrix();

   if(Entities->entities[i].mesh.edges->size == 0)
   {
     glDrawArrays(GL_TRIANGLES, 0, Entities->entities[i].triangleCount);
     continue;
   }
   glDrawElements(GL_TRIANGLES, Entities->entities[i].mesh.edges->size, GL_UNSIGNED_INT, (GLvoid*)0);
 }

 glDisableVertexAttribArray(0);
 glDisableVertexAttribArray(1);
 glDisableVertexAttribArray(2);
 glBindVertexArray(0);
}
