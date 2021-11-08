#include "entityManager.component.h"

void loadToVAO(Mesh new_EntityMesh)
{
  unsigned int vaoID = createVAO();
  bindIndices(new_EntityMesh.edges);
  storeDataInAttributeList(0, 3, new_EntityMesh.vertices);

  Entity* entity = malloc(sizeof(struct Entity));

  entity->vaoID = vaoID; // THE MISSILE KNOWS WHERE IT IS AT ALL TIMES, IT KNOWS THIS BECAUSE IT KNOWS WHERE IT ISNT.
  entity->position = new_vec3(0.0f, 0.0f, 0.0f);
  entity->rotation = new_vec3(0.0f, 0.0f, 0.0f);
  entity->scale    = new_vec3(1.0f, 1.0f, 1.0f);
  entity->mesh     = new_EntityMesh;
  entity->vertexCount =  (*new_EntityMesh.edges).size;

  entityStack_Push(&Entities, entity);
}

unsigned int createVAO()
{
  unsigned int vaoID;
  glGenVertexArrays(1, &vaoID);

  uintVector_Push(&vaosIDs, vaoID);
  glBindVertexArray(vaoID);

  return vaoID;
}

void bindIndices(dynUByteArray* indicesBuffer)
{
  int vboID = 0;
  glGenBuffers(1, &vboID);

  uintVector_Push(&vbosIDs, vboID);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboID);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, (*indicesBuffer).size * sizeof(float), (*indicesBuffer).items, GL_STATIC_DRAW);
}

void storeDataInAttributeList(int attribute, int coordinateSize, dynFloatArray* fbuffer)
{
  unsigned int vboID;
  glGenBuffers(1, &vboID);

  uintVector_Push(&vbosIDs, vboID);
  glBindBuffer(GL_ARRAY_BUFFER, vboID);
  glBufferData(GL_ARRAY_BUFFER, (*fbuffer).size * sizeof(float), (*fbuffer).items, GL_DYNAMIC_DRAW);
  glVertexAttribPointer(attribute, coordinateSize, GL_FLOAT, GL_FALSE, 0, 0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void transformation_SetPosition(Entity* entity)
{
  set_Uniform3f(programIDs->values[0], "offset", entity->position.x,
                                                 entity->position.y,
                                                 entity->position.z);

  mat4x4 new_TranslationMatrix = Empty_mat4x4();
  Identity_existingMat4x4(&new_TranslationMatrix);

  new_TranslationMatrix.matrix[3][0] = entity->position.x;
  new_TranslationMatrix.matrix[3][1] = entity->position.y;
  new_TranslationMatrix.matrix[3][2] = entity->position.z;

  m4_translationMatrix = new_TranslationMatrix;
}

void transformation_SetRotation(Entity* entity)
{
  mat4x4 new_RotationMatrix = Empty_mat4x4();

  quaternion rotation_Pitch, rotation_Yaw, rotation_Roll;
  getAxisAngle(&rotation_Pitch, new_vec3(1.0f, 0.0f, 0.0f), (float)degreesToRadians(entity->rotation.x));
  getAxisAngle(&rotation_Yaw, new_vec3(0.0f, 1.0f, 0.0f), (float)degreesToRadians(entity->rotation.y));
  getAxisAngle(&rotation_Roll, new_vec3(0.0f, 0.0f, 1.0f), (float)degreesToRadians(entity->rotation.z));

  quaternion result = multiplyQuaternionByQuaternion(rotation_Pitch, rotation_Yaw);
  result = multiplyQuaternionByQuaternion(result, rotation_Roll);
  quaternionToMat4Rotation(result, &new_RotationMatrix);

  m4_rotationMatrix = calcInverseMat4(new_RotationMatrix);
}

void transformation_SetScale(Entity* entity)
{
  mat4x4 new_ScaleMatrix = Empty_mat4x4();

  new_ScaleMatrix.matrix[0][0] = entity->scale.x;
  new_ScaleMatrix.matrix[1][1] = entity->scale.y;
  new_ScaleMatrix.matrix[2][2] = entity->scale.z;
  new_ScaleMatrix.matrix[3][3] = 1.0f;

  m4_scaleMatrix = new_ScaleMatrix;
}

mat4x4 make_TransformationMatrix()
{
  mat4x4 new_TranslationMatrix;
  mat4x4 new_RotationMatrix;
  mat4x4 new_ScaleMatrix;

  new_TranslationMatrix = m4_scaleMatrix;
  new_RotationMatrix = m4_rotationMatrix;
  new_ScaleMatrix = m4_scaleMatrix;

  mat4x4 scaleXrotationMatrix = Empty_mat4x4();
  scaleXrotationMatrix = multiplyMat4ByMat4(new_ScaleMatrix, new_RotationMatrix);

  mat4x4 new_TransformationMatrix = Empty_mat4x4();
  new_TransformationMatrix = multiplyMat4ByMat4(scaleXrotationMatrix, new_TranslationMatrix);

  return(new_TransformationMatrix);
}

void load_TransformationMatrix()
{
  storeMat4InFloatArray(m4_transformationMatrix, fArray_transformationArray);
  set_UniformMatrix4fv(programIDs->values[0], "transformationMatrix", GL_FALSE, fArray_transformationArray);
}

void cleanUpEntities()
{
  for(int i = 0; i < entityStack_Count(Entities); i++)
  {
    entityStack_Pop(&Entities);
  }
}
