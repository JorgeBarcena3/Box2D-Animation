#include "..\headers\Wheel.hpp"

Box2DAnimation::Wheel::Wheel(Body::BOX2D_LOCATION_ATTRBUTES transform, World& world, Body::SMLF_SHAPES_ATIBUTES attrb)
    : BallDynamic(25, transform, world, attrb)
{


    body_fixture_def.density = 500;
    body_fixture_def.filter.groupIndex = -1;
    body_fixture_def.friction = 3;
    body->DestroyFixture(body_fixture);
    body_fixture = body->CreateFixture(&body_fixture_def);
    body->SetUserData(this);


}

void Box2DAnimation::Wheel::update(float time)
{
    BallDynamic::update(time);

    float angle = body->GetAngle();
   
}

void Box2DAnimation::Wheel::render(sf::RenderWindow& window)
{
    BallDynamic::render(window);
}

