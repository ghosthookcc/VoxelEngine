#ifndef CONFIG_H
#define CONFIG_H

struct config
{
    float WIDTH;
    float HEIGHT;

    int RenderDistance;
    int fov;
    float tanHalfFOV;
    float aspectRatio;

    float nearestZ;
    float farthestZ;
    float scale;

    float camera_velocity;

    int CHUNK_XYZ_SIZE;
    int CHUNK_AREA;
    int CHUNK_VOLUME;

    int octaves_noise;
    float amplitude_noise;
    float frequency_noise;
    int normalized_noise;

    int terrain_render;
    int blocky_render;
    int model_render;
    int efficient_render;

    float timestep;
};
struct config configurations;

#endif
