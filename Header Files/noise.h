#ifndef NOISE_H
#define NOISE_H

#include <malloc.h>
#include <time.h>
#include <stdlib.h>

#include "ghostymath.h"

struct NoisePrivates
{
  int* perm;
  int offsetX;
  int offsetY;
  int offsetZ;
};

static struct NoisePrivates NoisePrivates;

float random_range(int min_value, int max_value);

float random_range_step(int min_value, int max_value, float step);

void init_NoiseGenerator();

int NoiseFloor(float x);

float NoiseFade(float x);

float NoiseLerp(float x, float y, float z);

float NoiseGrad(int hash, float x, float y, float z);

float GenerateNoise3D(float x, float y, float z);

float GenerateFinalNoise3D(float x, float y, float z, int octaves, float frequency, float amplitude, unsigned int normalized);

int** getPermPTR();

void setOffsetX(int new_x);

int getOffsetX();

void setOffsetY(int new_y);

int getOffsetY();

void setOffsetZ(int new_z);

int getOffsetZ();

#endif
