#pragma once

namespace Priviya {
	class Maths {
	public:
		inline static float clampf(float val, float min, float max) {
			if (val < min) val = min;
			if (val > max) val = max;
			return val;
		}

		inline static float clampd(double val, double min, double max) {
			if (val < min) val = min;
			if (val > max) val = max;
			return val;
		}

		inline static float clamp(int val, int min, int max) {
			if (val < min) val = min;
			if (val > max) val = max;
			return val;
		}
	};
}