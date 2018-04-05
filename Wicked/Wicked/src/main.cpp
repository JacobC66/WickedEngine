#include "classes/Application.h"
#include "Player.h"

int main()
{
	using namespace wicked;
	Application app(800, 600, "GameScene");
	app.run();

	return 0;
}