enum Image
{
	Dino,
	Cactus,
	Rock,
	Pterodactyl,
	LowDivePterodactyl,
	HighDivePterodactyl,
};

struct Point
{
	int x;
	int y;
};

struct Object
{
	Image drawing;
	Point pos;
	Point topRightBoundary;
	Point speed;
	bool alternate;
};


void dinoSteps(int x, int y, bool leftLeg)
{
	if(leftLeg)
	{
		drawLine(x + 6, y+ 2, x + 6, y + 3);
		setPixel(x + 7, y+ 2);
		drawLine(x + 9, y, x + 9, y + 3);
		setPixel(x + 10, y);
	}
	else
	{
		drawLine(x + 6, y, x + 6, y + 3);
		setPixel(x + 7, y);
		drawLine(x + 9, y + 2, x + 9, y + 3);
		setPixel(x + 10, y + 2);
	}
}

void dinoImage(Object& image)
{
	int x = image.pos.x;
	int y = image.pos.y;
	int leg = image.alternate;
	image.topRightBoundary.x = image.pos.x + 11;
	image.topRightBoundary.y = image.pos.y + 12;
	//head
	fillEllipse(x + 9,y + 7, x + 14, y + 12);
	fillEllipse(x + 12,y + 7, x + 17, y + 12);
	invertPixel(x + 12,y + 11);
	eraseLine(x + 13,y + 9,x + 17, y + 9);
	//body
	fillEllipse(x + 4, y + 3, x + 10,y + 7);
	drawLine(x + 9, y + 5, x + 12, y + 7);
	drawLine(x + 9, y + 3, x + 12, y + 6);
	setPixel(x + 11, y + 7);

	//tail
	drawLine(x + 3, y + 5, x, y + 8);
	drawLine(x + 5,	y + 6, x, y + 8);
	setPixel(x + 3, y + 6);

	dinoSteps(x,y,leg);
}

void dinoDuckingImage(Object& image)
{
	int x = image.pos.x;
	int y = image.pos.y;
	int leg = image.alternate;
	image.topRightBoundary.x = image.pos.x + 19;
	image.topRightBoundary.y = image.pos.y + 8;

	//head
	fillEllipse(x + 11,y + 3, x + 16, y + 8);
	fillEllipse(x + 14,y + 3, x + 19, y + 8);
	invertPixel(x + 14,y + 7);
	eraseLine(x + 15,y + 5,x + 19, y + 5);
	//body
	fillEllipse(x + 4, y + 3, x + 10,y + 7);
	drawLine(x + 9, y + 5, x + 12, y + 7);
	drawLine(x + 9, y + 3, x + 12, y + 6);
	setPixel(x + 11, y + 7);
	//tail
	drawLine(x + 3, y + 5, x, y + 5);
	drawLine(x + 5,	y + 6, x, y + 5);
	setPixel(x + 3, y + 6);

	dinoSteps(x,y,leg);
}

void cactusImage(Object& image)
{
	int x = image.pos.x;
	int y = image.pos.y;
	image.topRightBoundary.x = image.pos.x + 6;
	image.topRightBoundary.y = image.pos.y + 13;

	fillRect(x + 4, y, x + 7, y + 12);
	drawLine(x + 5, y + 13, x + 6, y + 13);

	fillRect(x , y + 6, x + 2, y + 10);
	setPixel(x + 1, y + 11);
	drawLine(x + 1, y + 5, x + 4, y + 5);
	setPixel(x + 3, y + 6);

	fillRect(x + 9, y + 7, x + 11, y + 11);
	setPixel(x + 10, y + 12);
	drawLine(x + 7, y + 6, x + 10, y + 6);
	setPixel(x + 8, y + 7);
}

void pterodactylWingsUp(int x, int y)
{
	drawLine(x + 8, y + 8, x + 8, y + 13);
	drawLine(x + 9, y + 8, x + 9, y + 12);
	drawLine(x + 10, y + 8, x + 10, y + 10);
}

void pterodactylWingsDown(int x , int y)
{
	drawLine(x + 8, y, x + 8, y + 3);
	drawLine(x + 9, y + 1, x + 9, y + 3);
	setPixel(x + 10, y + 3);
}

void pterodactylImage(Object& image)
{
	int x = image.pos.x;
	int y = image.pos.y;
	bool wings = image.alternate;
	image.topRightBoundary.x = image.pos.x + 10;
	image.topRightBoundary.y = image.pos.y + 10;

	fillEllipse(x + 6,y + 3, x + 14 , y +	8);
	drawLine(x, y + 8, x + 13, y + 6);
	drawLine(x, y + 8, x + 5, y + 11);
	drawLine(x + 5, y + 11, x + 5, y + 8);
	drawLine(x + 13, y + 7, x + 17, y + 7);
	drawLine(x + 13, y + 5, x + 16, y + 5);
	drawLine(x + 4, y + 8, x + 4, y + 10);
	setPixel(x + 3, y + 9);

	if(wings)
	{
		pterodactylWingsUp(x, y);
	}
	else
	{
		pterodactylWingsDown(x, y);
	}
}

void rockImage(Object& image)
{
	int x = image.pos.x;
	int y = image.pos.y;
	image.topRightBoundary.x = image.pos.x + 4;
	image.topRightBoundary.y = image.pos.y + 7;

	fillRect(x, y , x + 11, y + 5);
	fillRect(x + 2, y + 2, x + 7, y + 8);
	drawLine(x + 12, y + 1, x + 12, y + 4);
	invertPixel(x, y);
	invertPixel(x, y + 5);
	invertPixel(x + 2, y + 8);
	invertPixel(x + 11, y + 5);
	invertPixel(x + 8, y + 7);
	invertLine(x + 6, y + 8, x + 10, y + 3);
}

void nightTime()
{
	for(int i = 0; i < 64; i++)
	{
		invertLine(0,i,99,i);
	}
}

bool crashedIntoSomething(Object& player, Object& hazard)
{
	bool deadz = false;
	if(player.pos.y < hazard.topRightBoundary.y
		&& player.topRightBoundary.y > hazard.pos.y
	&& player.topRightBoundary.x > hazard.pos.x
	&& player.pos.x < hazard.topRightBoundary.x)
	{
		deadz = true;
	}
	return deadz;
}

void defineObjectParameters(Object& object,Image draw, int x, int y, int speed = 1, bool alternate = true)
{
	object.drawing = draw;
	object.pos.x = x;
	object.pos.y = y;
	object.speed.x = speed;
	object.speed.y = speed;
	object.alternate = alternate;
}


void assignHazard(Object& obstacle)
{
	int hazardType = rand() % 5 + 1;
	switch(hazardType)
	{
	case Cactus:
		defineObjectParameters(obstacle,Cactus,100,0);
		break;
	case Rock:
		defineObjectParameters(obstacle,Rock,100,0);
		break;
	case Pterodactyl:
		int height = rand() % 40;
		defineObjectParameters(obstacle,Pterodactyl,100,height); //9 just passes the dino
		break;
	case LowDivePterodactyl:
		int dive = rand() % 50 + 20;
		defineObjectParameters(obstacle,LowDivePterodactyl,100,dive); //9 just passes the dino
		break;
	case HighDivePterodactyl:
		int highDive = rand() % 90 + 35;
		defineObjectParameters(obstacle,HighDivePterodactyl,100,highDive); //9 just passes the dino
		break;
	}
}

void drawHazard(Object& obstacle)
{
	switch(obstacle.drawing)
	{
	case Cactus:
		cactusImage(obstacle);
		break;
	case Pterodactyl:
		if (obstacle.pos.y > 2 && obstacle.pos.y < 9 ||obstacle.pos.y > 60 ) obstacle.pos.y = 9;
		pterodactylImage(obstacle);
		break;
	case LowDivePterodactyl:
		if (obstacle.pos.y > 0) obstacle.pos.y -= 1;
		pterodactylImage(obstacle);
		break;
	case HighDivePterodactyl:
		if (obstacle.pos.y > 9) obstacle.pos.y -= 1;
		pterodactylImage(obstacle);
		break;
	case Rock:
		rockImage(obstacle);
		break;
	}



}
