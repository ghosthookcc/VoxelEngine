#ifndef PHYSICS_COMPONENT_H
#define PHYSICS_COMPONENT_H

#include <malloc.h>

#include "configurations/bodies.h"

#include "entityManager.component.h"

#include "generics.h"
#include "vec3.h"

#include "ghostymath.h"

void CreateAndLoadCollider(vec3 negBl, vec3 posBl,
                           vec3 negBr, vec3 posBr,
                           vec3 negTl, vec3 posTl,
                           vec3 negTr, vec3 posTr);

unsigned int CheckForCollision(Entity* object);

struct blist ProcessPhysics(struct blist *bodylist);

#endif
