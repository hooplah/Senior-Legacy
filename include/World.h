#ifndef WORLD_H
#define WORLD_H

#include <memory>

#include <SFML/Graphics.hpp>

#include "Camera.h"
#include "ICollideable.h"
#include "Player.h"
#include "WorldObject.h"

class World
{
    public:
        World(std::string path);
        ~World();

        void update(int ticks);
        void draw(sf::RenderTarget& target, float alpha);
        void handleEvents(sf::Event& event);

        bool checkCollision(std::weak_ptr<ICollideable> a, std::weak_ptr<ICollideable> b);
        void resolveCollision(std::weak_ptr<ICollideable> a, std::weak_ptr<ICollideable> b);

    private:
        void loadWorld(std::string path);
        template <class T>
        void removeDeadObjects(std::vector<T>& v);

        sf::Vector2f mGravity;
        sf::Vector2f mSpawnPoint;
        sf::FloatRect mBoundaries;

        std::shared_ptr<Player> mPlayer;
        std::vector<std::shared_ptr<SpriteObject>> mRenderables;
        std::vector<std::shared_ptr<ICollideable>> mCollideables;

        sf::Sprite mBackground;

        Camera mCamera;
};

#endif // WORLD_H
