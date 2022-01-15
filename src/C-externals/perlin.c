#include "perlin.h"

void init_PerlinGenerator()
{
  struct PerlinPrivates PerlinPrivates_construct =
  {
     // init grad3
     .grad3 =
     {{1, 1, 0}, {-1, 1, 0}, {1, -1, 0}, {-1, -1, 0},
      {1, 0, 1}, {-1, 0, 1}, {1, 0, -1}, {-1, 0, -1},
      {0, 1, 1}, {0, -1, 1}, {0, 1, -1}, {0, -1, -1}},

     // init p
     .p =
     {151, 160, 137, 91, 90, 15, 131, 13, 201,
      95, 96, 53, 194, 233, 7, 225, 140, 36, 103, 30, 69, 142, 8, 99, 37,
      240, 21, 10, 23, 190, 6, 148, 247, 120, 234, 75, 0, 26, 197, 62,
      94, 252, 219, 203, 117, 35, 11, 32, 57, 177, 33, 88, 237, 149, 56,
      87, 174, 20, 125, 136, 171, 168, 68, 175, 74, 165, 71, 134, 139,
      48, 27, 166, 77, 146, 158, 231, 83, 111, 229, 122, 60, 211, 133,
      230, 220, 105, 92, 41, 55, 46, 245, 40, 244, 102, 143, 54, 65, 25,
      63, 161, 1, 216, 80, 73, 209, 76, 132, 187, 208, 89, 18, 169, 200,
      196, 135, 130, 116, 188, 159, 86, 164, 100, 109, 198, 173, 186, 3,
      64, 52, 217, 226, 250, 124, 123, 5, 202, 38, 147, 118, 126, 255,
      82, 85, 212, 207, 206, 59, 227, 47, 16, 58, 17, 182, 189, 28, 42,
      223, 183, 170, 213, 119, 248, 152, 2, 44, 154, 163, 70, 221, 153,
      101, 155, 167, 43, 172, 9, 129, 22, 39, 253, 19, 98, 108, 110, 79,
      113, 224, 232, 178, 185, 112, 104, 218, 246, 97, 228, 251, 34, 242,
      193, 238, 210, 144, 12, 191, 179, 162, 241, 81, 51, 145, 235, 249,
      14, 239, 107, 49, 192, 214, 31, 181, 199, 106, 157, 184, 84, 204,
      176, 115, 121, 50, 45, 127, 4, 150, 254, 138, 236, 205, 93, 222,
      114, 67, 29, 24, 72, 243, 141, 128, 195, 78, 66, 215, 61, 156, 180}
  };

  int** perm = getPermPTR();
  for(int i = 0; i < 512; i++)
  {
    (*perm)[i] = PerlinPrivates_construct.p[i & 255];
  }

  PerlinPrivates = PerlinPrivates_construct;
  SetPerlinNoise();
}

void SetPerlinNoise()
{
  srand(time(NULL));

  setOffsetX(rand() % 256);
  setOffsetY(rand() % 256);
  setOffsetZ(rand() % 256);

  int** perm = getPermPTR();
  int pos;
  int old;
  for(int i = 0; i < 256; i++)
  {
    pos = rand() % (256 - i) + i;
    old = (*perm)[i];

    (*perm)[i] = (*perm)[pos];
    (*perm)[pos] = old;
    (*perm)[i + 256] = (*perm)[i];
  }
}

float GenerateNoise2D(float x, float y)
{
  int X = NoiseFloor(x) & 255;
  int Y = NoiseFloor(y) & 255;

  float xf = x - NoiseFloor(x);
  float yf = y - NoiseFloor(y);

  vec2 topRight = new_vec2((float)xf - 1.0f, (float)yf - 1.0f);
  vec2 topLeft = new_vec2((float)xf, (float)yf - 1.0f);
  vec2 bottomRight = new_vec2((float)xf - 1.0f, (float)yf);
  vec2 bottomLeft = new_vec2((float)xf, (float)yf);

  int valueTopRight = PerlinPrivates.p[PerlinPrivates.p[X+1]+Y+1];
  int valueTopLeft = PerlinPrivates.p[PerlinPrivates.p[X]+Y+1];
  int valueBottomRight = PerlinPrivates.p[PerlinPrivates.p[X+1]+Y];
  int valueBottomLeft = PerlinPrivates.p[PerlinPrivates.p[X]+Y];

  float dotTopRight = calcVec2DotProduct(topRight, GetVec2Const(valueTopRight));
  float dotTopLeft = calcVec2DotProduct(topLeft, GetVec2Const(valueTopLeft));
  float dotBottomRight = calcVec2DotProduct(bottomRight, GetVec2Const(valueBottomRight));
  float dotBottomLeft = calcVec2DotProduct(bottomLeft, GetVec2Const(valueBottomLeft));

  float u = NoiseFade(xf);
  float v = NoiseFade(yf);

  return(NoiseLerp(u,
         NoiseLerp(v, dotBottomLeft, dotTopLeft),
         NoiseLerp(v, dotBottomRight, dotTopRight)));
}

float GenerateFinalNoise2D(float x, float y, int octaves, float frequency, float amplitude, unsigned int normalized)
{
  float result = 0.0;
  float amp = 1.0;
  float freq = 1.0;
  float max = 0.0;

  for(int i = 0; i < octaves; i++)
  {
    result += GenerateNoise2D(x * freq, y * freq) * amp;
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
