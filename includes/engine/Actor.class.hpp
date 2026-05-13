#ifndef ACTOR_CLASS_CPP
#define ACTOR_CLASS_CPP

class Actor {
	public:
		Actor();
		virtual ~Actor();

		/**
		 * This method will be called every frame by the game loop. It should contain the logic for updating
		 * the actor's state, such as movement, animation, and interactions with other actors. It should not contain
		 * any rendering code, as that should be handled by the Render class.
		 */
		void tick();

	protected:
		// -- Variables --
		int x = 0;
		int y = 0; // Position
		int speed = 0; // Speed of movement

		// -- Events --
		// Logic events
		virtual void preStep(){};
		virtual void step(){};
		virtual void postStep(){};

		// Render events
		virtual void preDraw(){};
		virtual void draw(){};
		virtual void drawGUI(){};
		virtual void postDraw(){};

};

#endif // ACTOR_CLASS_CPP
