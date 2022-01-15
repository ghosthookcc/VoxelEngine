#ifndef PERLIN_H
#define PERLIN_H

#include <time.h>
#include <stdlib.h>

#include "noise.h"

struct PerlinPrivates
{
  int grad3[12][3];
  int p[256];
};

static struct PerlinPrivates PerlinPrivates;

void init_PerlinGenerator();

void SetPerlinNoise();

float GenerateNoise2D(float x, float y);

float GenerateFinalNoise2D(float x, float y, int octaves, float frequency, float amplitude, unsigned int normalized);

#endif
