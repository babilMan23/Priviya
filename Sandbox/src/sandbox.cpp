#include <Core.h>

namespace Priviya {
	class Application {
	public:
		PV_API PVResult run();
	};
}

namespace Priviya {
	class Sandbox : public Application {
	public:
		Sandbox() { };
		~Sandbox() { }
	};
}

using namespace Priviya;

int main(void) {
	Sandbox* sandbox = new Sandbox();
	PVResult result = sandbox->run();
	delete sandbox;

	return result;
}