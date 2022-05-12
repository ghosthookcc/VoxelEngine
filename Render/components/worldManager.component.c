#include "worldManager.component.h"

#include "configurations/config.h"

#include <inttypes.h>

void LoadPlanetData()
{
  /*
  Mesh sphere = new_Mesh();
  for(unsigned int PlanetIterator = 0; PlanetIterator < bodylist.size; PlanetIterator++)
  {
    sphere = fast_sphere(bodylist.planets[PlanetIterator].radius, 100, 100);
    loadToVAO(sphere, bodylist.planets[PlanetIterator].position);
  }
  */
}

void LoadPlanetProperties()
{
  body Sol = { 0 };
  Sol.bID = 1;
  Sol.radius = 696342000;
  Sol.mass = 1988500e+24f;
  Sol.position = new_dvec3(-1.068108951496322e+09,
                          -4.177210908491462E+08,
                          3.086887010002915E+07);
  Sol.velocity = new_dvec3(9.305302656256911E+00,
                          -1.283177282717393E+01,
                          -1.631700118015769E-01);

  body Mercury = { 0 };
  Mercury.bID = 2;
  Mercury.radius = 2439.5;
  Mercury.mass = 0.330e24f;
  Mercury.position = new_dvec3(-2.212073002393702E+10,
                              -6.682435921338345E+10,
                              -3.461577076477692E+09);
  Mercury.velocity = new_dvec3(3.666229234452722E+04,
                              -1.230266984222893E+04,
                              -4.368336206255391E+03);

  body Venus = { 0 };
  Venus.bID = 3;
  Venus.radius = 6051.84;
  Venus.mass = 4.8685e24f;
  Venus.position = new_dvec3(-1.085736592234813E+11,
                            -3.784241757371509E+09,
                            6.190088659339075E+09);
  Venus.velocity = new_dvec3(8.984650886248794E+02,
                            -3.517203951420625E+04,
                            -5.320225928762774E+02);

  body Earth = { 0 };
  Earth.bID = 4;
  Earth.radius = 6371.01;
  Earth.mass = 5.97219e24f;
  Earth.position = new_dvec3(-2.627903751048988E+10,
                            1.445101984929515E+11,
                            3.025245352813601E+07);
  Earth.velocity = new_dvec3(-2.983052803412253E+04,
                            -5.220465675237847E+03,
                            -1.014855999592612E-01);

  body Moon = { 0 };
  Moon.bID = 5;
  Moon.radius = 1737.53;
  Moon.mass = 7.349e22f;
  Moon.position = new_dvec3(-2.659668775178492E+10,
                           1.442683153167126E+11,
                           6.680827660505474E+07);
  Moon.velocity = new_dvec3(-2.926974096801152E+04,
                           -6.020397935372383E+03,
                           1.740818643718001E+00);

  body Mars = { 0 };
  Mars.bID = 6;
  Mars.radius = 3389.92;
  Mars.mass = 0.641e24f;
  Mars.position = new_dvec3(2.069270543147017E+11,
                           -3.560689745239088E+09,
                           -5.147936537447235E+09);
  Mars.velocity = new_dvec3(1.304308833322233E+03,
                           2.628158890420931E+04,
                           5.188465740839767E+02);

  Sol.position = divideDVec3ByDouble(Sol.position, 100000000.0);
  Sol.radius /= 1000000000.0;

  printf("Sol (x, y, z) :: (%f, %f, %f) ;\n", Sol.position.x, Sol.position.y, Sol.position.z);
  printf("Sol radius :: %f ;", Sol.radius);

  bodylist.size = 6;
  bodylist.planets[0] = Sol;
  bodylist.planets[1] = Mercury;
  bodylist.planets[2] = Venus;
  bodylist.planets[3] = Earth;
  bodylist.planets[4] = Moon;
  bodylist.planets[5] = Mars;
}

struct bodies* GetBodyList()
{
  return(&bodylist);
}

void setup_world()
{
  LARGE_INTEGER diff;
  LARGE_INTEGER timeNow, timePrev;
  LARGE_INTEGER Frequency;

  QueryPerformanceFrequency(&Frequency);

  QueryPerformanceCounter(&timeNow);

  if(configurations.terrain_render == 1)
  {
    if(configurations.blocky_render == 0)
    {
      generateSmoothChunk();
    }
    else
    {
      generateBlockChunk();
    }
  }

  LoadPlanetData(GetBodyList());

  QueryPerformanceCounter(&timePrev);

  diff.QuadPart = timePrev.QuadPart - timeNow.QuadPart;
  diff.QuadPart *= 1000000;
  diff.QuadPart /= Frequency.QuadPart;

  printf("Chunk of size [%i] %"PRId64" milliseconds", configurations.CHUNK_XYZ_SIZE, diff.QuadPart / 1000);

  if(configurations.model_render == 1)
    loadModelToVAO("../Resource Files/obj/suzanne.obj");
}
