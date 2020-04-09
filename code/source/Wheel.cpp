#include "..\headers\Wheel.hpp"

Box2DAnimation::Wheel::Wheel(Body::BOX2D_LOCATION_ATTRBUTES location, World& world, Body::SMLF_SHAPES_ATIBUTES attrb)
    : BallDynamic(15, location, world, attrb)
{
}

void Box2DAnimation::Wheel::update(float time)
{
}
