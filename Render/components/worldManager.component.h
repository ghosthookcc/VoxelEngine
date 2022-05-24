#ifndef WORLD_MANAGER_COMPONENT_H
#define WORLD_MANAGER_COMPONENT_H

#include "entityManager.component.h"
#include "staticChunkManager.component.h"
#include "staticVoxelGeometry.component.h"

#include "mesh.component.h"

#include "parser.h"

/*
struct blist bodylist;

void LoadPlanetData();
void LoadPlanetProperties();

struct bodies* GetBodyList();
*/

void LoadPlanetData(struct blist bodylist);
void setup_world(struct blist bodylist);

#endif
