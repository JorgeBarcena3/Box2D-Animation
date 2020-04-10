#include "..\headers\ParticleSystem.hpp"

Box2DAnimation::ParticleSystem::ParticleSystem(sf::Vector2f _position, ParticleSystemDef definition, bool _eneable)
{
    position = _position;
    particleDefinition = definition;
    eneabled = _eneable;
    particlePool = std::vector<std::shared_ptr<Particle>>(particleDefinition.particlesNumber);


    for (size_t i = 0; i < particlePool.size(); i++)
    {
        particlePool[i] = std::shared_ptr<Particle>(new Particle(this, eneabled));
    }

}

void Box2DAnimation::ParticleSystem::update(float time)
{

    if (eneabled)
    {

        for (auto particle : particlePool)
        {
            particle->Update(time);
        }

    }

}

void Box2DAnimation::ParticleSystem::render(sf::RenderWindow& window)
{
    if (eneabled)
    {

        for (auto particle : particlePool)
        {
            particle->render(window);
        }

    }
}

void Box2DAnimation::ParticleSystem::start()
{

    eneabled = true;

    for (auto particle : particlePool)
    {
        particle->eneable();
    }
}

void Box2DAnimation::ParticleSystem::stop()
{

    eneabled = false;

    for (auto particle : particlePool)
    {
        particle->disable();
    }

}

void Box2DAnimation::ParticleSystem::restart()
{
    for (auto particle : particlePool)
    {
        particle->reset();
    }
}

void Box2DAnimation::ParticleSystem::setPosition(sf::Vector2f newPosition)
{

    position = newPosition;

}
