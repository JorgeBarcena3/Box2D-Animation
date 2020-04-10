#include "..\headers\Body.hpp"
#include "..\headers\RectangleStatic.hpp"
#include "..\headers\BallDynamic.hpp"
#include "..\headers\World.hpp"

using namespace Box2DAnimation;

Box2DAnimation::BallDynamic::BallDynamic(float r, Body::BOX2D_LOCATION_ATTRBUTES transform, World& world, Body::SMLF_SHAPES_ATIBUTES attrb) :
    DynamicBody(transform, world)
{

    radius = r;

    sf::CircleShape* circle = new sf::CircleShape(radius);
    circle->setPosition(transform.position.x, transform.position.y);
    circle->setOrigin(radius, radius);
    circle->setFillColor(attrb.fillColor);
    sfml_shape = std::shared_ptr<sf::Shape>(circle);


    b2CircleShape new_shape;
    new_shape.m_radius = r;


    shape = std::shared_ptr<b2Shape>(new b2CircleShape(new_shape));

    body_fixture_def.shape = shape.get();
    body_fixture_def.density = 1;
    body_fixture_def.friction = 0;
    body_fixture_def.restitution = 0.0f; // Make it bounce a little bit

    body_fixture = body->CreateFixture(&body_fixture_def);
    body->SetUserData(this);

}

void Box2DAnimation::BallDynamic::render(sf::RenderWindow& renderWindow)
{
   
    renderWindow.draw(*sfml_shape);
}

void Box2DAnimation::BallDynamic::update(float time)
{

    sfml_shape->setRotation(
        body->GetAngle() * 180 / b2_pi
    );

    sfml_shape->setPosition(
        body->GetPosition().x * World::getInstance()->getWorldScale(),
        body->GetPosition().y * World::getInstance()->getWorldScale()
    );

   


}

void Box2DAnimation::BallDynamic::modifyFixture(b2CircleShape newShape, b2FixtureDef newFixture)
{
 
    shape = std::shared_ptr<b2Shape>(new b2CircleShape(newShape));

    body_fixture_def = newFixture;
    body_fixture_def.shape = shape.get();
 
    body->DestroyFixture(body_fixture);
    body_fixture = body->CreateFixture(&body_fixture_def);

}

void Box2DAnimation::BallDynamic::updateFixture(b2FixtureDef fixture)
{

    body_fixture_def = fixture;
    body_fixture_def.shape = shape.get();

    body->DestroyFixture(body_fixture);
    body_fixture = body->CreateFixture(&body_fixture_def);

}
