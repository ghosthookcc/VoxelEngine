#include "EntityManager.h"

void UpdateEntities(LONGLONG DeltaTime)
{
  for(int i = 0; i < entityStack_Count(Entities); i++)
  {
    Entities->entities[0].position.x += 0.00000001f * DeltaTime;
    Entities->entities[0].rotation.x += 0.001f * DeltaTime;

    Entities->entities[1].position.x -= 0.00000001f * DeltaTime;
    Entities->entities[1].rotation.x += 0.001f * DeltaTime;
  }
}

void RenderEntities(LONGLONG DeltaTime)
{
   for(int i = 0; i < entityStack_Count(Entities); i++)
   {
     glBindVertexArray(Entities->entities[i].vaoID);

     glEnableVertexAttribArray(0);

     transformation_SetPosition(&Entities->entities[i]);
     transformation_SetRotation(&Entities->entities[i]);
     transformation_SetScale(&Entities->entities[i]);

     m4_transformationMatrix = make_TransformationMatrix();
     load_TransformationMatrix();

     glDrawElements(GL_TRIANGLES, Entities->entities[i].vertexCount, GL_UNSIGNED_BYTE, 0);
   }

   glDisableVertexAttribArray(0);
   glBindVertexArray(0);
}
