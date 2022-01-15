#ifndef NOISE_H
#define NOISE_H

#include <malloc.h>

#include "ghostymath.h"

struct NoisePrivates
{
  int* perm;
  double offsetX;
  double offsetY;
  double offsetZ;
};

static struct NoisePrivates NoisePrivates;

void init_NoiseGenerator();

int NoiseFloor(double x);

double NoiseFade(double x);

double NoiseLerp(double x, double y, double z);

double NoiseGrad(int hash, double x, double y, double z);

double GenerateNoise3D(double x, double y, double z);

double GenerateFinalNoise3D(double x, double y, double z, int octaves, double frequency, double amplitude, unsigned int normalized);

int** getPermPTR();

void setOffsetX(double new_x);

double getOffsetX();

void setOffsetY(double new_y);

double getOffsetY();

void setOffsetZ(double new_z);

double getOffsetZ();

#endif
