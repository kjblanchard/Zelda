#include "items/Weapon.h"
#include "components/BoxColliderComponent.h"
#include "components/ImageComponent.h"

Weapon::Weapon(SG::Vector3 location, GameObject* owner, SG::GameObjectTypes gameObjectType) : GameObject(location,gameObjectType), Owner(owner)
{
}
