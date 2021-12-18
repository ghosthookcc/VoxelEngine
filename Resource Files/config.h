#ifndef CONFIG_H
#define CONFIG_H

struct config
{
    float WIDTH;
    float HEIGHT;

    int RenderDistance;
    float fov;
    float tanHalfFOV;
    float aspectRatio;

    float nearestZ;
    float farthestZ;
    float scale;
};

struct config configurations;

#endif
