#include "parser.h"

void LoadPlanetData()
{
  body Sol;
  Sol.bID = 1;
  Sol.radius = 696342000;
  Sol.mass = 1988500e+24f;
  Sol.position = new_vec3(-1.068108951496322e+09f,
                          -4.177210908491462E+08f,
                          3.086887010002915E+07f);
  Sol.velocity = new_vec3(9.305302656256911E+00f,
                          -1.283177282717393E+01f,
                          -1.631700118015769E-01f);

  body Mercury;
  Mercury.bID = 2;
  Mercury.radius = 2439.5f;
  Mercury.mass = 0.330e24f;
  Mercury.position = new_vec3(-2.212073002393702E+10f,
                              -6.682435921338345E+10f,
                              -3.461577076477692E+09f);
  Mercury.velocity = new_vec3(3.666229234452722E+04f,
                              -1.230266984222893E+04f,
                              -4.368336206255391E+03f);

  body Venus;
  Venus.bID = 3;
  Venus.radius = 6051.84f;
  Venus.mass = 4.8685e24f;
  Venus.position = new_vec3(-1.085736592234813E+11f,
                            -3.784241757371509E+09f,
                            6.190088659339075E+09f);
  Venus.velocity = new_vec3(8.984650886248794E+02f,
                            -3.517203951420625E+04f,
                            -5.320225928762774E+02f);

  body Earth;
  Earth.bID = 4;
  Earth.radius = 6371.01f;
  Earth.mass = 5.97219e24f;
  Earth.position = new_vec3(-2.627903751048988E+10f,
                            1.445101984929515E+11f,
                            3.025245352813601E+07f);
  Earth.velocity = new_vec3(-2.983052803412253E+04f,
                            -5.220465675237847E+03f,
                            -1.014855999592612E-01f);

  body Moon;
  Moon.bID = 5;
  Moon.radius = 1737.53f;
  Moon.mass = 7.349e22f;
  Moon.position = new_vec3(-2.659668775178492E+10f,
                           1.442683153167126E+11f,
                           6.680827660505474E+07f);
  Moon.velocity = new_vec3(-2.926974096801152E+04f,
                           -6.020397935372383E+03f,
                           1.740818643718001E+00f);

  body Mars;
  Mars.bID = 6;
  Mars.radius = 3389.92f;
  Mars.mass = 0.641e24f;
  Mars.position = new_vec3(2.069270543147017E+11f,
                           -3.560689745239088E+09f,
                           -5.147936537447235E+09f);
  Mars.velocity = new_vec3(1.304308833322233E+03f,
                           2.628158890420931E+04f,
                           5.188465740839767E+02f);

  bodylist.size = 6;
  bodylist.planets[0] = Sol;
  bodylist.planets[1] = Mercury;
  bodylist.planets[2] = Venus;
  bodylist.planets[3] = Earth;
  bodylist.planets[4] = Moon;
  bodylist.planets[5] = Mars;

  Mesh sphere = new_Mesh();

  sphere = fast_sphere(4.0f, 100, 100);
  loadToVAO(sphere, new_vec3(1.0f, 2.0f, -5.0f));

  /*
  sphere = fast_sphere(Mercury.radius, 100, 100);
  loadToVAO(sphere, Mercury.position);

  sphere = fast_sphere(Venus.radius, 100, 100);
  loadToVAO(sphere, Venus.position);

  sphere = fast_sphere(Earth.radius, 100, 100);
  loadToVAO(sphere, Earth.position);

  sphere = fast_sphere(Moon.radius, 100, 100);
  loadToVAO(sphere, Moon.position);

  sphere = fast_sphere(Mars.radius, 100, 100);
  loadToVAO(sphere, Mars.position);
  */
}

void parseFile()
{

}
