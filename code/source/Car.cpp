#include "..\headers\Body.hpp"
#include "..\headers\Car.hpp"
#include "..\headers\World.hpp"

using namespace Box2DAnimation;

Box2DAnimation::Car::Car(CAR_ATTRBUTES CAR_ATTRB, Body::SMLF_SHAPES_ATIBUTES attrb, std::string tag)
{

    // ************************ THE CAR ************************ //

    Body::SMLF_SHAPES_ATIBUTES carAttr({ sf::Color::Yellow });

    Body::BOX2D_LOCATION_ATTRBUTES chasisAttrb(
        {
            { 96, 450 },
            0,
            {120,20}
        });

    chasis = std::shared_ptr<Chasis>(new Chasis(chasisAttrb, *World::getInstance().get(), carAttr));
    chasis->tag = tag;

    Body::BOX2D_LOCATION_ATTRBUTES front_wheel_attrb(
        {
            { 56, 510 },
            0,
            {20,20}
        });

    front_wheel = std::shared_ptr<Wheel>(new Wheel(front_wheel_attrb, *World::getInstance().get(), attrb));
    front_wheel->tag = "Coche";

    Body::BOX2D_LOCATION_ATTRBUTES back_wheel_attrb(
        {
            { 130, 510 },
            0,
            {20,20}
        });

    back_wheel = std::shared_ptr<Wheel>(new Wheel(back_wheel_attrb, *World::getInstance().get(), attrb));
    back_wheel->tag = "Coche";
    configJoins();
}


void Box2DAnimation::Car::update(float time)
{

    static float motorSpeed = 0;

    switch (status)
    {

    case -1:

        motorSpeed += 0.5f;
        break;

    case 1:

        motorSpeed -= 0.1f;
        break;

    default:

        motorSpeed -= motorSpeed > 0 ? 0.01f : 0;
        break;
    }

    status = 0;
    motorSpeed *= 0.99f;
    if (motorSpeed > 5)
    {
        motorSpeed = 5;
    }
    front_join->SetMotorSpeed(motorSpeed);
    back_join->SetMotorSpeed(motorSpeed);

    chasis->update(time);
    back_wheel->update(time);
    front_wheel->update(time);

    if (chasis->body->GetPosition().y > 800)
        respawnCar();
}

void Box2DAnimation::Car::render(sf::RenderWindow& window)
{

    back_wheel->render(window);

    front_wheel->render(window);

    chasis->render(window);


}

void Box2DAnimation::Car::acelerate(int state)
{
    front_join->EnableMotor(true);
    back_join->EnableMotor(true);
    status = state;
}

void Box2DAnimation::Car::decelerate()
{
    front_join->EnableMotor(false);
    back_join->EnableMotor(false);

}

void Box2DAnimation::Car::configJoins()
{

    b2RevoluteJointDef revoluteJointDef = b2RevoluteJointDef();


    revoluteJointDef.Initialize(chasis->body, front_wheel->body, front_wheel->body->GetWorldCenter());

    revoluteJointDef.collideConnected = true;
    revoluteJointDef.referenceAngle = 0;
    revoluteJointDef.localAnchorA.Set(-50, 20);
    revoluteJointDef.localAnchorB.Set(0, 0);
    revoluteJointDef.enableMotor = false;
    revoluteJointDef.maxMotorTorque = powf(10, 16);

    front_join = (b2RevoluteJoint*)World::getInstance()->get_b2World()->CreateJoint(&revoluteJointDef);


    revoluteJointDef.Initialize(chasis->body, back_wheel->body, back_wheel->body->GetWorldCenter());
    revoluteJointDef.collideConnected = true;
    revoluteJointDef.referenceAngle = 0;
    revoluteJointDef.localAnchorA.Set(+50, 20);
    revoluteJointDef.localAnchorB.Set(0, 0);
    revoluteJointDef.enableMotor = false;
    revoluteJointDef.maxMotorTorque = powf(10, 16);

    back_join = (b2RevoluteJoint*)World::getInstance()->get_b2World()->CreateJoint(&revoluteJointDef);


}

void Box2DAnimation::Car::respawnCar()
{

    chasis->body->SetTransform({ 96, 450 }, 0);
    front_wheel->body->SetTransform({ 56, 510 }, 0);
    back_wheel->body->SetTransform({ 130, 510 }, 0);

}
