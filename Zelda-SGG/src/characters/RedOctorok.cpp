#include "characters/RedOctorok.h"

RedOctorok::RedOctorok()
{
	_location = SG::Vector3(0);
}

RedOctorok::RedOctorok(SG::Vector3 location) : GameObject(location,SG::GameObjectTypes::Enemy)
{

}
