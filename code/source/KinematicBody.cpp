#include "..\headers\Body.hpp"
#include "..\headers\DynamicBody.hpp"
#include "..\headers\World.hpp"
#include "..\headers\KinematicBody.hpp"

using namespace Box2DAnimation;

Box2DAnimation::KinematicBody::KinematicBody(Body::BOX2D_LOCATION_ATTRBUTES transform, World& world)
{
    body_definition.type = b2_kinematicBody;
    body_definition.position.Set(transform.position.x / World::getInstance()->getWorldScale(), transform.position.y / World::getInstance()->getWorldScale());
    body_definition.angle = transform.rotation * 3.1415 / 180;

    body = world.createBody(std::shared_ptr<Body>(this));
}
