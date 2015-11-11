#include "Player.h"

Player::Player(SpriteInfo& info, sf::Vector2f pos) :
    SpriteObject(info, pos),
    ICollideable(info.mHitBox, info.mFrameDim, pos)
{
    mGrounded = false;
}

Player::~Player()
{
    //dtor
}

void Player::update()
{
    SpriteObject::update();

    mOldPhysicsPosition = mPhysicsPosition;
    mPhysicsPosition += mVelocity;
}

void Player::draw(sf::RenderTarget& target)
{
    SpriteObject::draw(target);

    mRenderPosition = mPhysicsPosition;
}

void Player::handleEvents(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Space && mGrounded)
        {
            mVelocity.y = -5.f;
            mGrounded = false;
        }
        else if (event.key.code == sf::Keyboard::S)
        {
            mVelocity.y = 5.f;
        }
        if (event.key.code == sf::Keyboard::A)
        {
            mVelocity.x = -5.f;
        }
        else if (event.key.code == sf::Keyboard::D)
        {
            mVelocity.x = 5.f;
        }
    }
    else if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::W)
        {
            //mVelocity.y = 0.f;
        }
        else if (event.key.code == sf::Keyboard::S)
        {
            mVelocity.y = 0.f;
        }
        if (event.key.code == sf::Keyboard::A)
        {
            mVelocity.x = 0.f;
        }
        else if (event.key.code == sf::Keyboard::D)
        {
            mVelocity.x = 0.f;
        }
    }
}

bool Player::onContactBegin(std::weak_ptr<ICollideable> object, bool fromLeft, bool fromTop)
{
    mGrounded = true;
}
