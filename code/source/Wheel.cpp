#include "..\headers\Wheel.hpp"

Box2DAnimation::Wheel::Wheel(Body::BOX2D_LOCATION_ATTRBUTES transform, World& world, Body::SMLF_SHAPES_ATIBUTES attrb)
    : BallDynamic(20, transform, world, attrb)
{
    sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2f(transform.size.x, transform.size.y));
    rectangle->setPosition(transform.position.x, transform.position.y);
    rectangle->setOrigin(transform.size.x / 2, transform.size.y / 2);
    rectangle->setFillColor(sf::Color::Magenta);

    axe.sfml_shape = std::shared_ptr<sf::Shape>(rectangle);

    body_fixture_def.density = 500;
    body_fixture_def.filter.groupIndex = -1;
    body_fixture_def.friction = 3;
    body->DestroyFixture(body_fixture);
    body_fixture = body->CreateFixture(&body_fixture_def);
    body->SetUserData(this);

    configAxe(transform, world, attrb);

    configJoins();


}

void Box2DAnimation::Wheel::update(float time)
{
    BallDynamic::update(time);

    float angle = body->GetAngle();
    
    axe.update(time);
}

void Box2DAnimation::Wheel::render(sf::RenderWindow& window)
{
    BallDynamic::render(window);

    axe.draw(window);
}

void Box2DAnimation::Wheel::acelerate(float speed)
{
    join->SetMotorSpeed(speed);
}

void Box2DAnimation::Wheel::decelerate()
{
    join->SetMotorSpeed(0);

}

void Box2DAnimation::Wheel::configAxe(Body::BOX2D_LOCATION_ATTRBUTES transform, World& world, Body::SMLF_SHAPES_ATIBUTES attrb)
{

    axe.body = std::shared_ptr<RectangleDynamic>(new RectangleDynamic(transform, world, attrb));

    // fixture
    axe.body->body_fixture_def.density = 10;
    axe.body->body_fixture_def.friction = 3;
    axe.body->body_fixture_def.restitution = 0.3;
    axe.body->body_fixture_def.filter.groupIndex = -1;

    axe.body->body->DestroyFixture(axe.body->body_fixture);
    axe.body->body_fixture = axe.body->body->CreateFixture(&axe.body->body_fixture_def);


}

void Box2DAnimation::Wheel::configJoins()
{
    // ************************ REVOLUTE JOINTS ************************ //
            // rear joint
    b2RevoluteJointDef rearWheelRevoluteJointDef = b2RevoluteJointDef();

    rearWheelRevoluteJointDef.Initialize(body, axe.getb2Body(), body->GetWorldCenter());
    rearWheelRevoluteJointDef.enableMotor = true;

    rearWheelRevoluteJointDef.maxMotorTorque = powf(10, 10);

    join = (b2RevoluteJoint*)World::getInstance()->get_b2World()->CreateJoint(&rearWheelRevoluteJointDef);
}
