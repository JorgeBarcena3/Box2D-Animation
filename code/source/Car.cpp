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

    //Sistema de particulas
    Box2DAnimation::ParticleSystem::ParticleSystemDef def;
    def.color = sf::Color::Red;
    def.randomColor = true;
    def.coneAngle = 15;
    def.direction = { 0,1 };
    def.particlesNumber = 50;
    def.type = Box2DAnimation::PARTICLE_TYPE::RECTANGLE;
    def.baseSize = { 10,10 };
    def.speedRange = { 1,5 };

    particleSystem.push_back(std::shared_ptr<ParticleSystem>(new ParticleSystem({ 0,0 }, def, false)));
    particleSystem.push_back(std::shared_ptr<ParticleSystem>(new ParticleSystem({ 0,0 }, def, false)));
}


void Box2DAnimation::Car::update(float time)
{

    SetCarSpeed();

    chasis->update(time);
    back_wheel->update(time);
    front_wheel->update(time);

    for (auto system : particleSystem)
    {
        system->update(time);

    }

    b2Vec2 pos = b2Mul(chasis->body->GetTransform(), b2Vec2(-70, -50));
    particleSystem[0]->setPosition({ pos.x, pos.y });

    pos = b2Mul(chasis->body->GetTransform(), b2Vec2(65, -50));
    particleSystem[1]->setPosition({ pos.x, pos.y });

    if (chasis->body->GetPosition().y > 800)
        respawnCar();
}

void Box2DAnimation::Car::SetCarSpeed()
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

    if (!rotating)
    {
        front_join->SetMotorSpeed(motorSpeed);
        back_join->SetMotorSpeed(motorSpeed);
    }
}

void Box2DAnimation::Car::render(sf::RenderWindow& window)
{

    back_wheel->render(window);

    front_wheel->render(window);

    chasis->render(window);

    for (auto system : particleSystem)
    {
        system->render(window);
    }


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

void Box2DAnimation::Car::startParticles()
{
    for (auto system : particleSystem)
    {
        system->start();
    }
}

void Box2DAnimation::Car::stopParticles()
{
    for (auto system : particleSystem)
    {
        system->stop();
    }
}

void Box2DAnimation::Car::rotateCar()
{
    decelerate();

    front_join->SetMotorSpeed(0);
    back_join->SetMotorSpeed(0);
    chasis->body->SetAngularVelocity(-200);
    rotating = true;

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
