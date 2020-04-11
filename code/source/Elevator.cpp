#include "..\headers\Body.hpp"
#include "..\headers\Elevator.hpp"
#include "..\headers\World.hpp"

using namespace Box2DAnimation;

Box2DAnimation::Elevator::Elevator(Body::BOX2D_LOCATION_ATTRBUTES transform, World& world, Body::SMLF_SHAPES_ATIBUTES attrb, bool isSensor)
    : DynamicBody(transform, world)
{


    Body::BOX2D_LOCATION_ATTRBUTES anchorTransform({ {transform.position.x, transform.position.y - 1200}, 0, transform.size });

    anchorRectangle = new RectangleStatic(anchorTransform, world, { sf::Color::Red });

    sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2f(transform.size.x, transform.size.y));
    rectangle->setPosition(transform.position.x, transform.position.y);
    rectangle->setOrigin(transform.size.x / 2, transform.size.y / 2);
    rectangle->setFillColor(attrb.fillColor);

    sfml_shape =rectangle;

    b2PolygonShape new_shape;

    new_shape.SetAsBox(
        sfml_shape->getLocalBounds().width / 2.0f / World::getInstance()->getWorldScale(),
        sfml_shape->getLocalBounds().height / 2.0f / World::getInstance()->getWorldScale()
    );

    shape = new b2PolygonShape(new_shape);

    body_fixture_def.shape = shape;


    body_fixture_def.density = 1000;
    body_fixture_def.friction = 1.0f;
    body_fixture_def.filter.groupIndex = -3;


    body_fixture = body->CreateFixture(&body_fixture_def);
    body->SetUserData(this);

    b2PrismaticJointDef  platform_Joint;
    platform_Joint.bodyA = body;
    platform_Joint.bodyB = anchorRectangle->body;
    platform_Joint.collideConnected = false;
    platform_Joint.enableLimit = true;
    platform_Joint.lowerTranslation = -900;
    platform_Joint.upperTranslation = 0;
    platform_Joint.enableMotor = false;
    platform_Joint.maxMotorForce = powf(10, 16);//this is a powerful machine after all...
    platform_Joint.motorSpeed = 200;//5 units per second in positive axis direction
    platform_Joint.localAxisA.Set(0, 1);

    elevatorJoint = (b2PrismaticJoint*)world.get_b2World()->CreateJoint(&platform_Joint);


}

Box2DAnimation::Elevator::~Elevator()
{
    //world->get_b2World()->DestroyJoint(elevatorJoin);
    //world->get_b2World()->DestroyBody(body);
    delete anchorRectangle;
}

void Box2DAnimation::Elevator::render(sf::RenderWindow& renderWindow)
{
    renderWindow.draw(*sfml_shape);
}

void Box2DAnimation::Elevator::update(float time)
{

    static float motorSpeed = 0;
    currentTime += time;

    if (eneabled && currentTime >= maxTimer)
    {
        if (body->GetPosition().y <= yLimit)
        {
            eneabled = false;
        }
        else
        {
            elevatorJoint->SetMotorSpeed(100);
            motorSpeed += 1;
        }


    }
    else
    {
        elevatorJoint->SetMotorSpeed(0);
    }


    sfml_shape->setPosition(
        body->GetPosition().x * World::getInstance()->getWorldScale(),
        body->GetPosition().y * World::getInstance()->getWorldScale()
    );

    sfml_shape->setRotation(
        body->GetAngle() * 180 / b2_pi
    );

}

void Box2DAnimation::Elevator::modifyFixture(b2PolygonShape new_shape)
{

    new_shape.SetAsBox(
        sfml_shape->getLocalBounds().width / 2.0f / World::getInstance()->getWorldScale(),
        sfml_shape->getLocalBounds().height / 2.0f / World::getInstance()->getWorldScale()
    );

    shape = new b2PolygonShape(new_shape);

    body_fixture_def.shape = shape;
    body->CreateFixture(&body_fixture_def);
}

void Box2DAnimation::Elevator::updateFixture(b2FixtureDef fixture)
{
    body_fixture_def = fixture;
    body_fixture_def.shape = shape;
    body->CreateFixture(&body_fixture_def);

}

void Box2DAnimation::Elevator::up(float timeToStart, float limit)
{
    if (!eneabled)
    {
        yLimit = limit;
        maxTimer = timeToStart;
        currentTime = 0;
        elevatorJoint->EnableMotor(true);
        eneabled = true;

    }
}


void Box2DAnimation::Elevator::Stop()
{
    eneabled = false;
}
