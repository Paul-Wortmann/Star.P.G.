#include "SDL/SDL.h"
#include "timer.h"

timer::timer()
{
	running = false;
	startticks = 0;
}

timer::~timer()
{
}

int timer::start()
{
	if(running == false)
	{
		running = true;
		startticks = SDL_GetTicks();
	}
	return 0;
}
int timer::stop()
{
	if(running == true)
	{
		running = false;
	}
	return 0;
}

int timer::getticks()
{
if (running == true)
{return SDL_GetTicks() - startticks;}
else
{return 0;}
}
