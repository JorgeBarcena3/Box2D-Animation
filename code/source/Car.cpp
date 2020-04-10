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

        //motorSpeed -= motorSpeed > 0 ? 0.1f : 0;
        break;
    }

    status = 0;
    motorSpeed *= 0.99f;
    if (motorSpeed > 5)
    {                
        motorSpeed = 5;
    }
    front_join->SetMotorSpeed(motorSpeed);
    back_join->SetMotorSpeed( motorSpeed);

    if (chasis != nullptr)
        chasis->update(time);

    if (back_wheel != nullptr)
        back_wheel->update(time);

    if (front_wheel != nullptr)
        front_wheel->update(time);
}

void Box2DAnimation::Car::render(sf::RenderWindow& window)
{
    if (chasis != nullptr)
        chasis->render(window);

    if (back_wheel != nullptr)
        back_wheel->render(window);

    if (front_wheel != nullptr)
        front_wheel->render(window);
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
    back_join->EnableMotor( false);

}

void Box2DAnimation::Car::configJoins()
{

    // ************************ PRISMATIC JOINTS ************************ //
            //  definition
    b2RevoluteJointDef axlePrismaticJointDef = b2RevoluteJointDef();


    // front axle

    axlePrismaticJointDef.Initialize(chasis->body, front_wheel->body, front_wheel->body->GetWorldCenter());

    axlePrismaticJointDef.collideConnected = true;
    axlePrismaticJointDef.referenceAngle = 0;
    axlePrismaticJointDef.localAnchorA.Set(-50, 20);
    axlePrismaticJointDef.localAnchorB.Set(0, 0);
    axlePrismaticJointDef.enableMotor = false;
    axlePrismaticJointDef.maxMotorTorque = powf(10, 16);

    front_join = (b2RevoluteJoint*)World::getInstance()->get_b2World()->CreateJoint(&axlePrismaticJointDef);

    // rear axle
    axlePrismaticJointDef.Initialize(chasis->body, back_wheel->body, back_wheel->body->GetWorldCenter());
    axlePrismaticJointDef.collideConnected = true;
    axlePrismaticJointDef.referenceAngle = 0;
    axlePrismaticJointDef.localAnchorA.Set(+50, 20);
    axlePrismaticJointDef.localAnchorB.Set(0, 0);
    axlePrismaticJointDef.enableMotor = false;
    axlePrismaticJointDef.maxMotorTorque = powf(10, 16);

    back_join = (b2RevoluteJoint*)World::getInstance()->get_b2World()->CreateJoint(&axlePrismaticJointDef);


}
