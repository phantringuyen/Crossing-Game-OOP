#ifndef _TrafficLight_h_
#define _TrafficLight_h_

#include<iostream>
#include<Windows.h>
using namespace std;

class TrafficLight
{
private:
	int state, time;
public:
	TrafficLight();
	TrafficLight(int s, int t);
	int getState();
	int getTime();
	void setState(int state_);
	void setTime(int time_);
	void change(int newTime);
};
#endif // !_TrafficLight_h_
