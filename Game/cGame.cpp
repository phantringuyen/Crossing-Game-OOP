#include "cGame.h"

cGame::cGame()
{
	lights = nullptr;
	player = nullptr;
	score = 0;
	MOVING = ' ';
	truck = nullptr;
	car = nullptr;
	bird = nullptr;
	dinosaur = nullptr;
	curAN = curVH = 0;
	level = 0;
}

void cGame::printTrafficLights()
{
	Graphics::DrawGraphics(GetStdHandle(STD_OUTPUT_HANDLE), "trafficlight.txt", COORD{ 65,38 }, (int)Color::white);
	lights->change(30);

	if (lights->getState() == 0) // trạng thái đỏ
	{
		// che đi số màu xanh
		Graphics::DrawGraphics(GetStdHandle(STD_OUTPUT_HANDLE), "blank.txt", COORD{ 74,40 }, (int)Color::black);

		//hiện màu đỏ cho đèn
		Graphics::DrawGraphics(GetStdHandle(STD_OUTPUT_HANDLE), "blank.txt", COORD{ 70,39 }, (int)Color::red);
		Graphics::GotoXY(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 74, 39 });
		cout << lights->getTime() << " ";

		if (lights->getTime() == 0)
			mciSendString(L"play TrafficLight.wav ", NULL, 0, NULL);
	}
	else
	{
		// che đi số màu đỏ
		Graphics::DrawGraphics(GetStdHandle(STD_OUTPUT_HANDLE), "blank.txt", COORD{ 74,39 }, (int)Color::black);

		//hiện màu đỏ cho xanh
		Graphics::DrawGraphics(GetStdHandle(STD_OUTPUT_HANDLE), "blank.txt", COORD{ 70,40 }, (int)Color::green);
		Graphics::GotoXY(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 74, 40 });
		cout << lights->getTime() << " ";

		if (lights->getTime() == 0)
			mciSendString(L"play TrafficLight.wav ", NULL, 0, NULL);
	}

}
void cGame::DrawGame() 
{ 
	Graphics::DrawGraphics(ohandle, "map.txt", COORD{ 0,0 }, (int)Color::yellow);
	while (!quit) 
	{
		if (!player->isDead()) 
		{
			UpdatePosPlayer(MOVING);
		}
		MOVING = ' ';
		player->Draw();
		UpdatePosVehicle();
		UpdatePosAnimal();
		printTrafficLights();
		if (player->isImpactTruck(truck, 6) ||
			player->isImpactCar(car, 6) ||
			player->isImpactBird(bird, 6) ||
			player->isImpactDinosaur(dinosaur, 6)
			)
		{
			quit = true;
			break;
		}
		if (player->isFinish())
		{
			LevelUp();
			PlaySound(L"BG.wav", NULL, SND_LOOP | SND_FILENAME | SND_ASYNC);
		}
		Sleep(60);
	}

}
void cGame::StartGame() 
{
	deleteObject();
	quit = false;
	lights = new TrafficLight;
	player = new cPlayer(COORD START_PLAYER_POINT, 1, true);
	score = 0;
	level = 1;
	curAN = 6;
	curVH = 6;
	truck = new cTruck[curVH];
	car = new cCar[curVH];
	bird = new cBird[curAN];
	dinosaur = new cDinosaur[curAN];
	for (unsigned int i = 0; i < curVH; i++)
	{
		truck[i].setPosition(LEFT, 18);
		truck[i].set_speed(1);
		car[i].setPosition(LEFT, 26);
		car[i].set_speed(1);
	}
	for (unsigned int i = 0; i < curAN; i++) 
	{
		bird[i].setPosition(RIGHT, 22);
		bird[i].set_speed(-1);
		dinosaur[i].setPosition(RIGHT, 31);
		dinosaur[i].set_speed(-1);
	}

	Graphics::SetColor(ohandle, 0);
	system("cls");
	Graphics::DrawGraphics(ohandle, "map.txt", COORD{ 0,0 }, (int)Color::yellow);
}

void cGame::RunGame() 
{
	PlaySound(L"BG.wav", NULL, SND_LOOP | SND_FILENAME | SND_ASYNC);
	thread t(&cGame::DrawGame, this);
	while (!quit)
	{
		if (_kbhit())
		{
			char current = _getch();

			if (current == 'q' || current == 'Q')
			{
				ExitGame(&t);

			}
			else if (current == 'p' || current == 'P')
			{
				PauseGame((HANDLE)t.native_handle());

				Graphics::SetColor(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				Graphics::GotoXY(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 82,40 });
				cout << "To continue game press any key !";
				char ans = _getch();

				if (ans != '@')
				{
					system("cls");
					Graphics::DrawGraphics(ohandle, "map.txt", COORD{ 0,0 }, (int)Color::yellow);
					ResumeGame((HANDLE)t.native_handle());
				}
				else
				{
					system("cls");
					Graphics::DrawGraphics(ohandle, "map.txt", COORD{ 0,0 }, (int)Color::yellow);
					ResumeGame((HANDLE)t.native_handle());
				}
			}
			else if (current == 'g' || current == 'G')
			{
				PauseGame((HANDLE)t.native_handle());
				SaveGame();
				Graphics::DrawGraphics(ohandle, "map.txt", COORD{ 0,0 }, (int)Color::yellow);
				ResumeGame((HANDLE)t.native_handle());
			}
			else if (current == 'l' || current == 'L')
			{
				PauseGame((HANDLE)t.native_handle());
				LoadGame();
				Graphics::DrawGraphics(ohandle, "map.txt", COORD{ 0,0 }, (int)Color::yellow);
				ResumeGame((HANDLE)t.native_handle());
			}
			else if
				(
					current == 'a' || current == 's' || current == 'd' || current == 'w' ||
					current == 'A' || current == 'S' || current == 'D' || current == 'W'
					)
			{
				score += 10;
				ResumeGame((HANDLE)t.native_handle());
				MOVING = current;
			}
			else continue;
		}
	}

	if (t.joinable())
	{
		t.join();
		system("cls");
		mciSendString(L"play GameOver.wav ", NULL, 0, NULL);
		Graphics::DrawGraphics(ohandle, "game over.txt", COORD{ 50,20 }, (int)Color::yellow);
	}
	system("pause");
}
void cGame::ResumeGame(HANDLE h) 
{
	ResumeThread(h);
	Sleep(150);
}

void cGame::PauseGame(HANDLE h) 
{
	SuspendThread(h);
}

void cGame::ExitGame(thread* t) 
{
	quit = true;
	t->join();
	system("cls");
}

void cGame::UpdatePosPlayer(char current) 
{
	player->Clear();
	if (current == 'a') player->Left();
	else if (current == 'd' && player->Get_X() <= RIGHT) player->Right();
	else if (current == 's') player->Down();
	else if (current == 'w' && player->Get_Y() >= TOP) player->Up();
	else return;
}

void cGame::UpdatePosVehicle() 
{
	for (int i = 0; i < 6; i++) 
	{
		/* -----Truck------ */
		if (truck[i].Get_X()==LEFT) 
		{
			if(rand() % 151 == 19)truck[i].Set_X(1);
		}
		else 
		{
			if (lights->getState() == 0) 
			{ // đèn đỏ
				truck[i].Draw();
			}
			else 
			{
				truck[i].Move();
				if (truck[i].Get_X() >= RIGHT) 
				{
					truck[i].Clear(truck[i].Get_X()+12,truck[i].Get_Y()+4);
					truck[i].Set_X(0);
				}
			}
		}

		/* -----Car------ */
		if (car[i].Get_X() == LEFT) 
		{
			if (rand() % 151 == 59)car[i].Set_X(LEFT+1);
		}
		else 
		{
			if (lights->getState() == 0) 
			{ // đèn đỏ
				car[i].Draw();
			}
			else 
			{
				car[i].Move();
				if (car[i].Get_X() >= RIGHT) 
				{
					car[i].Clear(car[i].Get_X() + 12, car[i].Get_Y() + 4);
					car[i].Set_X(LEFT);
				}
			}

		}
	}
}
void cGame::UpdatePosAnimal() 
{
	for (int i = 0; i < 6; i++) 
	{

		/* -----Dinosaur------ */
		if (dinosaur[i].Get_X() == RIGHT) 
		{
			if (rand() % 131 == 19)dinosaur[i].Set_X(RIGHT-1);
		}
		else 
		{
			if (lights->getState() == 0) 
			{ // đèn đỏ
				dinosaur[i].Draw();
			}
			else 
			{
				dinosaur[i].Move();
				if (dinosaur[i].Get_X() <= LEFT)
				{
					dinosaur[i].Clear(dinosaur[i].Get_X()+11,dinosaur[i].Get_Y()+4);
					dinosaur[i].Set_X(RIGHT);
				}
			}

		}

		/* -----Bird------ */

		if (bird[i].Get_X() == RIGHT)
		{
			if (rand() % 131 == 19)bird[i].Set_X(RIGHT-1);
		}
		else
		{
			if (lights->getState() == 0) 
			{ // đèn đỏ
				bird[i].Draw();
			}
			else 
			{
				bird[i].Move();
				if (bird[i].Get_X() <= LEFT) 
				{
					bird[i].Clear(bird[i].Get_X() + 6, bird[i].Get_Y() + 3);
					bird[i].Set_X(RIGHT);
				}
			}

		}
	}
}

void cGame::LevelUp() 
{
	score += 1000;
	PlaySound(TEXT("CompleteLevel.wav"), NULL, SND_ASYNC);
	system("cls");
	Graphics::DrawGraphics(ohandle, "Congrat_Table.txt", COORD{ 68,15 }, (int)Color::lightblue);
	Graphics::SetColor(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	Graphics::GotoXY(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 71,20 });
	cout << "*CONGRATULATION*";

	Graphics::SetColor(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	Graphics::GotoXY(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 69,22 });
	cout<<"NOW YOUR LEVEL IS : " << ++level;
	
	Graphics::SetColor(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	Graphics::GotoXY(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 70,23 });
	cout << "YOUR SCORE IS: " << score;

	

	Sleep(10000);

	// Reset Screen
	system("cls");
	player->setPosition((LEFT + RIGHT) / 2, TOP - 5);
	Graphics::DrawGraphics(ohandle, "map.txt", COORD{ 0,0 }, (int)Color::yellow);
	for (unsigned int i = 0; i < curVH; i++) 
	{
		truck[i].Set_X(LEFT);
		car[i].Set_X(LEFT);
		if (rand() % 2 == 0)truck[i].set_speed(truck[i].get_speed() + 1);
		else car[i].set_speed(car[i].get_speed() + 1);
	}
	for (unsigned int i = 0; i < curAN; i++) 
	{
		bird[i].Set_X(RIGHT);
		dinosaur[i].Set_X(RIGHT);
		if (rand() % 2 == 0)bird[i].set_speed(bird[i].get_speed() - 1);
		else dinosaur[i].set_speed(dinosaur[i].get_speed() - 1);
	}
}

void cGame::SaveGame() 
{
	string name;
	Graphics::SetColor(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	Graphics::GotoXY(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 82,40 });
	cout << "The name of file that you want to SAVE is: ";

	Graphics::SetColor(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	Graphics::GotoXY(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 82,41 });
	cin >> name;

	system("cls");

	string load = name + ".txt";
	fstream file(load, ios::out);
	file <<lights->getState()<<" "<<lights->getTime()<<" " << level << " " << score << " "
		<< player->Get_X() << " " << player->Get_Y() << " " 
		<< player->Get_State() << " " << player->Get_Speed() << " ";
	file << curVH << " ";
	for (unsigned int i = 0; i < curAN; i++)
	{
		file << truck[i].Get_X() << " " << truck[i].Get_Y() << " " << truck[i].get_speed() << " ";
	}
	for (unsigned int i = 0; i < curAN; i++) 
	{
		file << car[i].Get_X() << " " << car[i].Get_Y() << " " << car[i].get_speed() << " ";
	}
	file << curAN << " ";
	for (unsigned int i = 0; i < curAN; i++) 
	{
		file << bird[i].Get_X() << " " << bird[i].Get_Y() << " " << bird[i].get_speed() << " ";
	}
	for (unsigned int i = 0; i < curAN; i++)
	{
		file << dinosaur[i].Get_X() << " " << dinosaur[i].Get_Y() << " " << dinosaur[i].get_speed() << " ";
	}
	file.close();
}

void cGame::LoadGame() 
{
	Graphics::SetColor(ohandle, 0);
	system("cls");
	string name;
	Graphics::SetColor(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	Graphics::GotoXY(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 82,40 });
	cout << "The name of file that you want to LOAD is: "; 
	
	Graphics::SetColor(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	Graphics::GotoXY(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 82,39 });
	cin >> name;
	deleteObject();
	Graphics::SetColor(ohandle, 0);
	system("cls");
	Graphics::DrawGraphics(ohandle, "map.txt", COORD{ 0,0 }, (int)Color::yellow);
	quit = false;
	string load = name + ".txt";
	fstream file(load, ios::in);
	short x, y, s, t;
	file >> x;
	file >> y;
	lights = new TrafficLight(x, y);
	file >> level;
	file >> score;
	file >> x;
	file >> y;
	file >> s;
	file >> t;
	player = new cPlayer(COORD{ x,y }, s, t);
	file >> curVH;
	truck = new cTruck[curVH]();
	for (unsigned int i = 0; i < curVH; i++) 
	{
		file >> x;
		file >> y;
		file >> s;
		truck[i].Set_X(x);
		truck[i].Set_Y(y);
		truck[i].set_speed(s);
	}
	car = new cCar[curVH]();
	for (unsigned int i = 0; i < curVH; i++) 
	{
		file >> x;
		file >> y;
		file >> s;
		car[i].Set_X(x);
		car[i].Set_Y(y);
		car[i].set_speed(s);
	}
	file >> curAN;
	bird = new cBird[curAN]();
	for (unsigned int i = 0; i < curAN; i++) 
	{
		file >> x;
		file >> y;
		file >> s;
		bird[i].Set_X(x);
		bird[i].Set_Y(y);
		bird[i].set_speed(s);
	}
	dinosaur = new cDinosaur[curAN]();
	for (unsigned int i = 0; i < curAN; i++) 
	{
		file >> x;
		file >> y;
		file >> s;
		dinosaur[i].Set_X(x);
		dinosaur[i].Set_Y(y);
		dinosaur[i].set_speed(s);
	}
	file.close();
}