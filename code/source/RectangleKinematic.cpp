#include "..\headers\Body.hpp"
#include "..\headers\RectangleKinematic.hpp"
#include "..\headers\World.hpp"

using namespace Box2DAnimation;

Box2DAnimation::RectangleKinematic::RectangleKinematic(Body::BOX2D_LOCATION_ATTRBUTES transform, World& world, Body::SMLF_SHAPES_ATIBUTES attrb)
    : KinematicBody(transform,  world)
{

    sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2f(transform.size.x, transform.size.y));
    rectangle->setPosition(transform.position.x, transform.position.y);
    rectangle->setOrigin(transform.size.x / 2, transform.size.y / 2);
    rectangle->setFillColor(attrb.fillColor);

    sfml_shape = rectangle;

    b2PolygonShape new_shape;

    new_shape.SetAsBox(
        sfml_shape->getLocalBounds().width / 2.0f / World::getInstance()->getWorldScale(),
        sfml_shape->getLocalBounds().height / 2.0f / World::getInstance()->getWorldScale()
    );

    shape = new b2PolygonShape(new_shape);

    body_fixture_def.shape = shape;
    body_fixture_def.isSensor = true;
    body_fixture_def.filter.groupIndex = -2;
    body_fixture = body->CreateFixture(&body_fixture_def);
    body->SetUserData(this);



}

void Box2DAnimation::RectangleKinematic::render(sf::RenderWindow& renderWindow)
{
   
    renderWindow.draw(*sfml_shape);
}

void Box2DAnimation::RectangleKinematic::update(float time)
{
    sfml_shape->setPosition(
        body->GetPosition().x * World::getInstance()->getWorldScale(),
        body->GetPosition().y * World::getInstance()->getWorldScale()
    );

    sfml_shape->setRotation(
        body->GetAngle() * 180 / b2_pi
    );

}

void Box2DAnimation::RectangleKinematic::modifyFixture(b2PolygonShape new_shape)
{

    new_shape.SetAsBox(
        sfml_shape->getLocalBounds().width / 2.0f / World::getInstance()->getWorldScale(),
        sfml_shape->getLocalBounds().height / 2.0f / World::getInstance()->getWorldScale()
    );

    shape = new b2PolygonShape(new_shape);

    body_fixture_def.shape = shape;
    body->CreateFixture(&body_fixture_def);
}

void Box2DAnimation::RectangleKinematic::updateFixture(b2FixtureDef fixture)
{
    body_fixture_def = fixture;
    body_fixture_def.shape = shape;
    body->CreateFixture(&body_fixture_def);

}