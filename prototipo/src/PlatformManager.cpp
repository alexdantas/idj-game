#include "PlatformManager.hpp"
#include "SDL.hpp"
#include "GameObject.hpp"
#include "Log.hpp"

PlatformManager::PlatformManager():
    empty(true)
{
    this->sprites.resize(TYPE_MAX);

    this->sprites[GROUND] = new Sprite("img/plataforma1.png");
    this->sprites[CLOUD]  = new Sprite("img/plataforma2.png");
}
PlatformManager::~PlatformManager()
{
    int size = this->container.size();
    for (int i = 0; i < size; i++)
        if (this->container[i])
            delete this->container[i];

    size = this->sprites.size();
    for (int i = 0; i < size; i++)
        if (this->sprites[i])
            delete this->sprites[i];
}
void PlatformManager::add(Point p, PlatformType type)
{
    Platform* tmp = new Platform(this->sprites[type],
                                 p.x, p.y,
                                 this->sprites[type]->getWidth(),
                                 this->sprites[type]->getHeight());

    this->container.push_back(tmp);
    this->empty = false;

    Log::verbose("Platform::add");
}
void PlatformManager::addBetween(Point a, Point b, PlatformType type)
{
    // Taking into consideration the Platform's width
    int actualX = b.x - this->sprites[type]->getWidth();

    this->add(Point(SDL::randomNumberBetween(a.x, actualX),
                    SDL::randomNumberBetween(a.y, b.y)),
              type);
}
void PlatformManager::render(float cameraX, float cameraY)
{
    if (this->empty) return;

    int size = this->container.size();

    for (int i = 0; i < size; i++)
        this->container[i]->render(cameraX, cameraY);
}
void PlatformManager::update(uint32_t dt)
{
    if (this->empty) return;

    int size = this->container.size();

    for (int i = 0; i < size; i++)
        this->container[i]->update(dt);
}
bool PlatformManager::collidesWith(GameObject* other)
{
    if (this->empty) return false;

    int size = this->container.size();

    for (int i = 0; i < size; i++)
        if (other->oneWayCollidedWith(this->container[i]))
            return true;

    return false;
}
