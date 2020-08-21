#include "CVEHICLE.h"
#include "Console.h"
#include "CPEOPLE.h"
#include "CGame.h"

char MOVING;
CGAME* cg;

void SubThread() {
	int timeTraffic = 0;
	while (1) {
		if (!cg->getPeople().isDead()) {
			cg->drawGame(219);
			GotoXY(WIDTH_CONSOLE + 8, HEIGHT_CONSOLE / 2);
			cg->updatePosPeople(MOVING);
			MOVING = ' ';
			/*if (cg->getPeople().isImpact(cg->getTruck()) ||
				cg->getPeople().isImpact(cg->getCar()) ||
				cg->getPeople().isImpact(cg->getBird()) ||
				cg->getPeople().isImpact(cg->getDinausor())) {
				GotoXY(0, HEIGHT + 1);
				cout << "Dead, press Y to start a new game!";
				cg->getPeople().setState(false);
			}
			else if (cg->getPeople().isFinish()) {
				cg->drawGame(255);
				cg->getPeople().setLevel(2);
				cg->resize(2);
				cg->resetGame();
			}
			else if (cg->getPeople().isLevelUp()) {
				cg->drawGame(255);
				cg->getPeople().setLevel(g->getPeople().getLevel() + 1);
				cg->resize(g->getPeople().getLevel());
				cg->resetGame();
			}*/
			//Sleep(80);
		}
	}
}
int main()
{
	cg = new CGAME;
	int temp;
	FixConsoleWindow();
	cg->startGame();
	thread t1(SubThread);
	while (1)
	{
		temp = toupper(_getch());
		if (!cg->getPeople().isDead())
		{
			if (temp == 27) {
				cg->exitGame(t1.native_handle());
				return 0;
			}
			else if (temp == 'P') {
				cg->pauseGame(t1.native_handle());

			}
			else {
				cg->resumeGame((HANDLE)t1.native_handle());
				MOVING = temp;
			}
		}
		else
		{
			if (temp == 'Y') cg->startGame();
			else 
			{
				cg->exitGame(t1.native_handle());
				return 0;
			}
		}
	}
	t1.join();
	return 0;
}