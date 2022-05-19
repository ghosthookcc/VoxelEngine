#ifndef STATIC_RENDERING_VARS_COMPONENT_H
#define STATIC_RENDERING_VARS_COMPONENT_H

#include "vector.h"
#include "matrix.h"
#include "configurations/config.h"

struct uintVector* programIDs;
struct uintVector* vbosIDs;
struct uintVector* vaosIDs;
struct uintVector* texturesIDs;
struct uintVector* indexbuffersIDs;
unsigned int fboIDs[2];
unsigned int rboIDs[1];
unsigned int dboIDs[1];
unsigned int textures[1];

#endif
