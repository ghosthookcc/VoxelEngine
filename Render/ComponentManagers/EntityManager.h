#ifndef ENTITY_RENDERER_H
#define ENTITY_RENDERER_H

#include "entityManager.component.h"

void UpdateEntities(LONGLONG DeltaTime, LPCRITICAL_SECTION* critsection, struct blist* shared_mem, struct blist* local_list);

void RenderEntities(LONGLONG DeltaTime);

#endif
