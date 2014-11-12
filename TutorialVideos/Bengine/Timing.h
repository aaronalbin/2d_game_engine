#pragma once

namespace Bengine {

	class FPSLimiter {
	public:
		FPSLimiter();
		void init(float maxFPS);

		void setMaxFPS(float maxFPS);

		void begin();
		float end();  // returns current FPS

	private:
		void calculateFPS();

		float _fps;
		float _maxFPS;
		float _frameTime;
		unsigned int _startTicks;
	};

}
