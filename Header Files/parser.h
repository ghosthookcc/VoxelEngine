#ifndef PARSER_H
#define PARSER_H

#include <malloc.h>

#include "configurations/bodies.h"

#include "staticVoxelGeometry.component.h"

#include "entityManager.component.h"
#include "mesh.component.h"

#include "dynArray.h"
#include "vec3.h"

void LoadPlanetData(struct bodies* bodylist);

void parseFile();

#endif
