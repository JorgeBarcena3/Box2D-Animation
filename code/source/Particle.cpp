#include "..\headers\Particle.hpp"
#include "..\headers\ParticleSystem.hpp"

Box2DAnimation::Particle::Particle(ParticleSystem* _system, bool _active)
{
    particleSystem = std::shared_ptr<ParticleSystem>(_system);
    active = _active;

    particleDefinition.color = particleSystem->particleDefinition.randomColor ? sf::Color(rand() % + 255, rand() % +255, rand() % +255, 255) : particleSystem->particleDefinition.color;
    particleDefinition.size = particleSystem->particleDefinition.baseSize;

    switch (particleSystem->particleDefinition.type)
    {

    case PARTICLE_TYPE::POLYGON:

        particleDefinition.shape = std::shared_ptr<sf::ConvexShape>(new sf::ConvexShape());
        break;

    case PARTICLE_TYPE::RECTANGLE:

        particleDefinition.shape = std::shared_ptr<sf::RectangleShape>(new sf::RectangleShape(particleDefinition.size));
        break;

    case PARTICLE_TYPE::CIRCLE:

        particleDefinition.shape = std::shared_ptr<sf::CircleShape>(new sf::CircleShape(particleDefinition.size.x));
        break;
    }


    active = _active;

    initialiceParticlesValues();
}

void Box2DAnimation::Particle::Update(float time)
{
    if (active)
    {
        position += direction * speed;
        alpha -= speed;
        particleDefinition.color.a = (uint8)alpha;

        particleDefinition.shape->setPosition(position);
        particleDefinition.shape->setFillColor(particleDefinition.color);

        if (alpha <= 0)
        {
            reset();
        }
    }
}

void Box2DAnimation::Particle::render(sf::RenderWindow& window)
{
    if (active)
    {
        window.draw(*particleDefinition.shape);
    }
}

void Box2DAnimation::Particle::eneable()
{
    active = true;
}

void Box2DAnimation::Particle::disable()
{
    active = false;
}

void Box2DAnimation::Particle::reset()
{

    initialiceParticlesValues();

}

void Box2DAnimation::Particle::initialiceParticlesValues()
{
    ///Properties of the shape

    particleDefinition.shape->setFillColor(particleDefinition.color);
    particleDefinition.shape->setPosition(particleSystem->position);

    switch (particleDefinition.type)
    {

    case PARTICLE_TYPE::POLYGON:

        particleDefinition.shape->setScale(particleDefinition.size);
        break;

    case PARTICLE_TYPE::RECTANGLE:

        ((sf::RectangleShape*)(particleDefinition.shape.get()))->setSize(particleDefinition.size);
        break;

    case PARTICLE_TYPE::CIRCLE:

        ((sf::CircleShape*)(particleDefinition.shape.get()))->setRadius(particleDefinition.size.x);
        break;
    }

    position = particleSystem->position;
    alpha = 255;
    speed = rand() % particleSystem->particleDefinition.speedRange.y + particleSystem->particleDefinition.speedRange.x;

    float angleTolerance = particleSystem->particleDefinition.coneAngle * b2_pi / 180.f;
    float HI = angleTolerance;
    float LO = -angleTolerance;
    float angle = LO + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (HI - LO)));

    b2Vec2 new_direction = {
        cosf(angle) * -particleSystem->particleDefinition.direction.x - sinf(angle) * -particleSystem->particleDefinition.direction.y ,
        sinf(angle) * -particleSystem->particleDefinition.direction.x + cosf(angle) * -particleSystem->particleDefinition.direction.y
    };

    new_direction.Normalize();

    direction = { new_direction.x, new_direction.y };

}
