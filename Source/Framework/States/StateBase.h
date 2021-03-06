#pragma once

#include <SFML/Graphics.hpp>

#include "../Util/NonCopyable.h"

class Game;

class StateBase : public NonCopyable
{
    public:
        StateBase(Game& game, const char* name)
            : m_pGame(&game)
            , m_name(name)
        {}

        virtual ~StateBase() = default;

        virtual void handleEvent(sf::Event e) {}
        virtual void handleInput() = 0;
        virtual void update(sf::Time deltaTime) {}
        virtual void fixedUpdate(sf::Time deltaTime) {}
        virtual void render(sf::RenderTarget& renderer) = 0;

        const std::string& getName() { return m_name;  }

    protected:
        Game* m_pGame;
        std::string m_name;
};
