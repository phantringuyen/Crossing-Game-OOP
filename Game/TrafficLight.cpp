#include"TrafficLight.h"

TrafficLight::TrafficLight()
{
	state = 1;
	time = 40;
}

TrafficLight::TrafficLight(int state, int time)
{
	this->state = state;
	this->time = time;
}

int TrafficLight::getState()
{
	return state;
}
int TrafficLight::getTime()
{
	return time;
}

void TrafficLight::setState(int state_)
{
	this->state = state_;
}
void TrafficLight::setTime(int time_)
{
	this->time = time_;
}

void TrafficLight::change(int newTime)
{
	if (time == 0)
	{
		state = 1 - state;
		time = (state ? newTime : newTime);
	}
	else
	{
		time--;
	}
}