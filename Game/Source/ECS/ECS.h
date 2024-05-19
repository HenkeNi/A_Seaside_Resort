#pragma once
#include "Components/ComponentManager.h"
#include "Entities/EntityManager.h"
#include "Systems/SystemManager.h"

// Context, or World?
class ECS
{
public:

private:
	EntityManager	 m_entityManager;
	ComponentManager m_componentManager;
	SystemManager	 m_systemManager;
};

