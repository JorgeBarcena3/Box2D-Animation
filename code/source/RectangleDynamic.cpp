#include "..\headers\Body.hpp"
#include "..\headers\RectangleDynamic.hpp"
#include "..\headers\World.hpp"

using namespace Box2DAnimation;

Box2DAnimation::RectangleDynamic::RectangleDynamic(Body::BOX2D_LOCATION_ATTRBUTES transform, World& world, Body::SMLF_SHAPES_ATIBUTES attrb)
    : DynamicBody(transform,  world)
{

    sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2f(transform.size.x, transform.size.y));
    rectangle->setPosition(transform.position.x, transform.position.y);
    rectangle->setOrigin(transform.size.x / 2, transform.size.y / 2);
    rectangle->setFillColor(attrb.fillColor);

    sfml_shape = std::shared_ptr<sf::Shape>(rectangle);

    b2PolygonShape new_shape;

    new_shape.SetAsBox(
        sfml_shape->getLocalBounds().width / 2.0f / World::getInstance()->getWorldScale(),
        sfml_shape->getLocalBounds().height / 2.0f / World::getInstance()->getWorldScale()
    );

    shape = std::shared_ptr<b2Shape>(new b2PolygonShape(new_shape));

    body_fixture.shape = shape.get();
    body_fixture.isSensor = true;
    body_fixture.filter.groupIndex = -2;
    body->CreateFixture(&body_fixture);


}

void Box2DAnimation::RectangleDynamic::render(sf::RenderWindow& renderWindow)
{
   
    renderWindow.draw(*sfml_shape);
}

void Box2DAnimation::RectangleDynamic::update(float time)
{
    sfml_shape->setPosition(
        body->GetPosition().x * World::getInstance()->getWorldScale(),
        body->GetPosition().y * World::getInstance()->getWorldScale()
    );

    sfml_shape->setRotation(
        body->GetAngle() * 180 / b2_pi
    );

}

void Box2DAnimation::RectangleDynamic::modifyFixture(b2PolygonShape new_shape)
{

    new_shape.SetAsBox(
        sfml_shape->getLocalBounds().width / 2.0f / World::getInstance()->getWorldScale(),
        sfml_shape->getLocalBounds().height / 2.0f / World::getInstance()->getWorldScale()
    );

    shape = std::shared_ptr<b2Shape>(new b2PolygonShape(new_shape));

    body_fixture.shape = shape.get();
    body->CreateFixture(&body_fixture);
}

void Box2DAnimation::RectangleDynamic::updateFixture(b2FixtureDef fixture)
{
    body_fixture = fixture;
    body_fixture.shape = shape.get();
    body->CreateFixture(&body_fixture);

}