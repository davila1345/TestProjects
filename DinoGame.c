#pragma debuggerWindows(nxtLCDScreen)

#include "DinoGameImages.h";

task main()
{
	Object player;
	defineObjectParameters(player,Dino,4,0,3);

	Object hazard;
	assignHazard(hazard);

	Object secondHazard;
	assignHazard(secondHazard);
	bool includeSecond = false;

	int jumpInitialY = 0;
	int jumpTime = 1000;
	int jumpMaxHeight = 15;
	bool jump = false;

	int timeToNight = 20000;
	bool isNight = false;

	bool gameOver = false;
	int score = 0;
	int highScore = 0;
	bool showHi = false;


	while(true)
	{
		displayCenteredBigTextLine(3,"Start");
		while(nNxtButtonPressed == -1)
		{
		}
		time1[T1] = 0;		//jump time
		time1[T2] = 0;		//cnight time
		time1[T3] = 0;		//difficulty
		time1[T4] = 0;		//score keeper
		while(!gameOver)
		{
			eraseDisplay();

			//draw
			drawHazard(hazard);
			if(includeSecond) drawHazard(secondHazard);

			if(nNxtButtonPressed == kExitButton)
			{
				dinoDuckingImage(player);
			}
			else
			{
				dinoImage(player);
			}
			//score
			score = time1[T4] / 200;
			displayStringAt(0,60,"%d",score);
			if(showHi)
			{
				if(score > highScore)		highScore = score;
				displayStringAt(0,60,"%d			Hi:%d",score,highScore);
			}
			if(isNight) nightTime();

			if(crashedIntoSomething(player,hazard) || crashedIntoSomething(player,secondHazard))

			{
				gameOver = true;
				break;
			}

			//update
			if(nNxtButtonPressed == kEnterButton && player.pos.y == 0)
			{
				jump = true;
				jumpInitialY = player.pos.y;
				time1[T1] = 0;
			}

			if(jump && time1[T1] < jumpTime)
			{
				if(player.pos.y < jumpInitialY + jumpMaxHeight)		player.pos.y += player.speed.y;
				player.alternate = false;
			}
			else
			{
				if(player.pos.y > 0)	player.pos.y -= player.speed.y;
				jump = false;
			}

			if(!jump) player.alternate = !player.alternate;
			if(hazard.pos.x < - 15)
			{
				assignHazard(hazard);
			}

			if(time1[T2] > timeToNight)
			{
				time1[T2] = 0;
				isNight = !isNight;
			}


			if(time1[T3] > 5000 && hazard.pos.x >= 48 && hazard.pos.x <= 55
				&& (secondHazard.pos.x < -15 || secondHazard.pos.x == 100))
			{
				assignHazard(secondHazard);
				includeSecond = true;
			}

			hazard.pos.x -= hazard.speed.x;
			hazard.alternate = !hazard.alternate;
			if(includeSecond)
			{
				secondHazard.pos.x -= secondHazard.speed.x;
				secondHazard.alternate = !secondHazard.alternate;
			}
			if(score > 300)
			{
				hazard.speed.x = 2;
				hazard.speed.y -= 1;
				secondHazard.speed.x = 2;
				secondHazard.speed.y -=1;
				jumpTime = 600;
			}
			//delay loop
			delay(25);
		}
		eraseDisplay();
		displayCenteredBigTextLine(0,"Game");
		displayCenteredBigTextLine(2,"Over");
		//draw
		drawHazard(hazard);
		if(includeSecond) drawHazard(secondHazard);

		if(nNxtButtonPressed == kExitButton)
		{
			dinoDuckingImage(player);
		}
		else
		{
			dinoImage(player);
		}
		if(isNight) nightTime();

		while(nNxtButtonPressed !=kRightButton && nNxtButtonPressed != kLeftButton)
		{
		}
		gameOver = false;
		if(score > highScore)		highScore = score;
		showHi = true;
		score = 0;
		assignHazard(hazard);
		assignHazard(secondHazard);
		time1[T3] = 0;
		time1[T4] = 0;
		jumpTime = 1000;
		includeSecond = false;
	}
}
