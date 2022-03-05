#pragma once

#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <memory>
#include <vector>

class Component;
class Entity;

using ComponentID = std::size_t;

inline ComponentID getComponentTypeID()
{
    static ComponentID lastID {0};
    return lastID++;
}

template <typename T> inline ComponentID getComponentTypeID() noexcept
{
    static ComponentID typeID {getComponentTypeID()};
    return typeID;
}

constexpr std::size_t maxComponents {32};

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

class Component
{
public:
    Entity* entity;

    virtual void init() {}
    virtual void update() {}
    virtual void draw() {}

    virtual ~Component() {}
};

class Entity
{
private:
    bool active {true};
    std::vector<std::unique_ptr<Component>> components;

    ComponentArray componentArray;
    ComponentBitSet componentBitSet;

public:
    void update()
    {
        for(auto& component : components) component->update();
        for(auto& component : components) component->draw();
    }

    void draw(){}

    bool isActive() const
    {
        return active;

    }

    void destroy() {
        active = false;
    }

    template <typename T> bool hasComponent() const
    {
        return componentBitSet[getComponentTypeID<T>];
    }

    template <typename T, typename... TArgs>
    T& addComponent(TArgs&&... mArgs)
    {
        T* component(new T(std::forward<TArgs>(mArgs)...));

        component->entity = this;

        std::unique_ptr<Component> uniquePointer{component};
        components.emplace_back(std::move(uniquePointer));

        componentArray[getComponentTypeID<T>()] = component;
        componentBitSet[getComponentTypeID<T>()] = true;

        component->init();
        
        return *component;
    }

    template<typename T> T& getComponent() const
    {
        auto pointer(componentArray[getComponentTypeID<T>()]);
        return *static_cast<T*>(pointer);
    }
};

class Manager
{
private:
    std::vector<std::unique_ptr<Entity>> entities;

public:
    void update()
    {
        for(auto& entity : entities)
        {
            entity->update();
        }
    }

    void draw()
    {
        for(auto& entity : entities)
        {
            entity->draw();
        }
    }

    void refresh()
    {
        entities.erase(std::remove_if(std::begin(entities), std::end(entities), [](const std::unique_ptr<Entity> &movedEntity)
        {
            return !movedEntity->isActive();
        }),
        std::end(entities));
    }

    Entity& addEntity()
    {
        Entity* entity {new Entity()};
        std::unique_ptr<Entity> uniquePointer { entity };
        entities.emplace_back(std::move(uniquePointer));
        return *entity;
    }
};