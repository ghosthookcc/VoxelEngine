#ifndef WORLD_MANAGER_COMPONENT_H
#define WORLD_MANAGER_COMPONENT_H

#include "entityManager.component.h"
#include "staticChunkManager.component.h"
#include "staticVoxelGeometry.component.h"

#include "mesh.component.h"

#include "parser.h"

void LoadPlanetData(struct blist bodylist);

/*
struct blist bodylist;


void LoadPlanetProperties();

struct body* GetBodyList();
struct blist* GetWorld();
*/

void setup_world();

#endif
