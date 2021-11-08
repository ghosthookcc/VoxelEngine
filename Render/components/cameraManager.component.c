#include "cameraManager.component.h"

void setup_Camera(vec3 start_position)
{
  m4_viewMatrix = Empty_mat4x4();
  Identity_existingMat4x4(&m4_viewMatrix);

  p_Entity.position = start_position;

  p_Entity.rotation.x = 0.0f;
  p_Entity.rotation.y = 0.0f;
  p_Entity.rotation.z = 0.0f;

  camera.target = new_vec3(0.0f, 0.0f, 0.0f);

  camera.FORWARD = new_vec3(0.0f, 0.0f, -1.0f);
  camera.RIGHT = new_vec3(1.0f, 0.0f, 0.0f);
  camera.UP = new_vec3(0.0f, 1.0f, 0.0f);

  UpdateCameraVars();
}

void UpdateCameraVars()
{
  camera.EYE            = p_Entity.position;
  camera.ROTATION.pitch = p_Entity.rotation.x;
  camera.ROTATION.yaw   = p_Entity.rotation.y;
  camera.ROTATION.roll  = p_Entity.rotation.z;
}

void hookCameraToEntity(Entity TargetEntity)
{
  p_Entity = TargetEntity;
}

mat4x4 make_projMatrix()
{
  m4_projMatrix.matrix[0][0] = 1.0f / (configurations.aspectRatio * configurations.tanHalfFOV);
  m4_projMatrix.matrix[1][1] = 1.0f / (configurations.tanHalfFOV);

  m4_projMatrix.matrix[2][2] = -(configurations.farthestZ + configurations.nearestZ) / (configurations.farthestZ - configurations.nearestZ);
  m4_projMatrix.matrix[2][3] = -1.0f;

  m4_projMatrix.matrix[3][2] = -(2.0f * configurations.farthestZ * configurations.nearestZ) / (configurations.farthestZ - configurations.nearestZ);
  return(m4_projMatrix);
}

mat4x4 make_viewMatrix()
{
  mat4x4 matrix = Empty_mat4x4();
  Identity_existingMat4x4(&matrix);

  quaternion rotation_Pitch, rotation_Yaw, rotation_Roll;
  getAxisAngle(&rotation_Pitch, new_vec3(1.0f, 0.0f, 0.0f), (float)degreesToRadians(camera.ROTATION.pitch));
  getAxisAngle(&rotation_Yaw, new_vec3(0.0f, 1.0f, 0.0f), (float)degreesToRadians(camera.ROTATION.yaw));
  getAxisAngle(&rotation_Roll, new_vec3(0.0f, 0.0f, 1.0f), (float)degreesToRadians(camera.ROTATION.roll));

  quaternion result = multiplyQuaternionByQuaternion(rotation_Pitch, rotation_Yaw);
  result = multiplyQuaternionByQuaternion(result, rotation_Roll);
  quaternionToMat4Rotation(result, &matrix);

  matrix.matrix[3][0] = camera.EYE.x;
  matrix.matrix[3][1] = camera.EYE.y;
  matrix.matrix[3][2] = camera.EYE.z;

  return(calcInverseMat4(matrix));
}

mat4x4 make_projViewMatrix()
{
  m4_projMatrix = make_projMatrix();
  m4_viewMatrix = make_viewMatrix();

  mat4x4 new_Mat4 = Empty_mat4x4();
  new_Mat4 = multiplyMat4ByMat4(m4_viewMatrix, m4_projMatrix);
  return(new_Mat4);
}

void load_projViewMatrix()
{
  storeMat4InFloatArray(m4_projViewMatrix, fArray_projViewArray);
  set_UniformMatrix4fv(programIDs->values[0], "projViewMatrix", GL_FALSE, fArray_projViewArray);
}

mat4x4 getViewMatrix()
{
    return(m4_viewMatrix);
}

mat4x4 getProjMatrix()
{
    return(m4_projMatrix);
}

mat4x4 getProjViewMatrix()
{
    return(m4_projViewMatrix);
}
