#include "../../includes/engine/Actor.class.hpp"
#include "../../includes/engine/Engine.class.hpp"
#include <algorithm>

Actor::Actor() {
	Engine::actors.push_back(this);
}
Actor::~Actor() {
	// Remove this actor from the engine's list of actors
	auto it = std::find(Engine::actors.begin(), Engine::actors.end(), this);
	if (it != Engine::actors.end()) {
		Engine::actors.erase(it);
	}
}

void Actor::tick()
{
	this->preStep();
	this->step();
	this->postStep();

	this->preDraw();
	this->draw();
	this->drawGUI();
	this->postDraw();
}
