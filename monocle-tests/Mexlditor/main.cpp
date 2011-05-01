#include <Monocle/Monocle.h>
#include "MexlditorTest.h"

using namespace Monocle;

int main(void)
{
	Game *game = new Game();
	game->SetScene(new MexlditorTest::EditorScene());
	game->Main();
	delete game;
	return 0;
}
