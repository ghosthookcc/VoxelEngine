#include "noise.h"

void init_NoiseGenerator()
{
  NoisePrivates.perm = malloc(sizeof(int) * 512);
  NoisePrivates.offsetX = 0;
  NoisePrivates.offsetY = 0;
  NoisePrivates.offsetZ = 0;
}

int NoiseFloor(float x)
{
  return(x >= 0 ? (int) x : (int) x - 1);
}

float NoiseFade(float x)
{
  return(x * x * x * (x * (x * 6 - 15) + 10));
}

float NoiseLerp(float x, float y, float z)
{
  return(y + x * (z - y));
}

float NoiseGrad(int hash, float x, float y, float z)
{
  hash &= 15;
  float u = hash < 8 ? x : y;
  float v = hash < 4 ? y : hash == 12 || hash == 14 ? x : z;
  return(((hash & 1) == 0 ? u : -u) + ((hash & 2) == 0 ? v : -v));
}

float GenerateNoise3D(float x, float y, float z)
{
  x += NoisePrivates.offsetX;
  y += NoisePrivates.offsetY;
  z += NoisePrivates.offsetZ;

  int floorX = NoiseFloor(x);
  int floorY = NoiseFloor(y);
  int floorZ = NoiseFloor(z);

  int X = floorX & 255;
  int Y = floorY & 255;
  int Z = floorZ & 255;

  x -= floorX;
  y -= floorY;
  z -= floorZ;

  float fX = NoiseFade(x);
  float fY = NoiseFade(y);
  float fZ = NoiseFade(z);

  int A = NoisePrivates.perm[X] + Y;
  int AA = NoisePrivates.perm[A] + Z;
  int AB = NoisePrivates.perm[A + 1] + Z;

  int B = NoisePrivates.perm[X + 1] + Y;
  int BA = NoisePrivates.perm[B] + Z;
  int BB = NoisePrivates.perm[B + 1] + Z;

  return(NoiseLerp(fZ, NoiseLerp(fY, NoiseLerp(fX,
                       NoiseGrad(NoisePrivates.perm[AA], x, y, z),
                       NoiseGrad(NoisePrivates.perm[BA], x-1, y, z)),
         NoiseLerp(fX,
                       NoiseGrad(NoisePrivates.perm[AB], x, y-1, z),
                       NoiseGrad(NoisePrivates.perm[BB], x-1, y-1, z))),
         NoiseLerp(fY, NoiseLerp(fX,
                       NoiseGrad(NoisePrivates.perm[AA+1], x, y, z-1),
                       NoiseGrad(NoisePrivates.perm[BA+1], x-1, y, z-1)),
         NoiseLerp(fX,
                       NoiseGrad(NoisePrivates.perm[AB+1], x, y-1, z-1),
                       NoiseGrad(NoisePrivates.perm[BB+1], x-1, y-1, z-1)))));
}

float GenerateFinalNoise3D(float x, float y, float z, int octaves, float frequency, float amplitude, unsigned int normalized)
{
  float result = 0.0;
  float amp = 1.0;
  float freq = 1.0;
  float max = 0.0;

  for(int i = 0; i < octaves; i++)
  {
    result += GenerateNoise3D(x * freq, y * freq, z * freq) * amp;
    max += amp;
    freq *= frequency;
    amp *= amplitude;
  }

  if(normalized == 1)
  {
    result /= max;
  }

  return(result);
}

int** getPermPTR()
{
  return(&NoisePrivates.perm);
}

void setOffsetX(int new_x)
{
  NoisePrivates.offsetX = new_x;
}

int getOffsetX()
{
  return(NoisePrivates.offsetX);
}

void setOffsetY(int new_y)
{
  NoisePrivates.offsetY = new_y;
}

int getOffsetY()
{
  return(NoisePrivates.offsetY);
}

void setOffsetZ(int new_z)
{
  NoisePrivates.offsetZ = new_z;
}

int getOffsetZ()
{
  return(NoisePrivates.offsetZ);
}
