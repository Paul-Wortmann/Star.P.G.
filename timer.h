
class timer
{
public:
	timer();
	~timer();
	int start();
	int stop();
	int getticks();
private:
	bool running;
	int startticks;
};
