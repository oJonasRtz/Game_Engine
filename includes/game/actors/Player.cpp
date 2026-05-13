#include "../../engine/Actor.class.hpp"
#include "../../engine/Render/Renderer.class.hpp"

class Player : public Actor {
	public:
		Player(): Actor() {
			this->x = 100;
			this->y = 100;
			this->speed = 10;
		};
		~Player(){};

	protected:		
		void step() override {
			this->x += this->speed;
			if (this->x > 400) {
				this->x = 100;
			}
		}

		void draw() override {
			Render::draw_rectangle(this->x, this->y, 50, 50, Colors::RED);
		}
};
