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

double GenerateNoise2D(double x, double y);

double GenerateFinalNoise2D(double x, double y, int octaves, double frequency, double amplitude, unsigned int normalized);

#endif
