#include "Weapon.h"


Weapon::Weapon(SG::Vector3 location, GameObject* owner, SG::GameObjectTypes gameObjectType) : GameObject(location,gameObjectType), Owner(owner)
{
}
