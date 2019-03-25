#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")
#include <math.h>

int main()
{
	int px, py, pz;
	getPlayerLocation(&px, &py, &pz);  // 플레이어의 위치값 얻기

	double dir = getPlayerDirection(); // 플레이어의 방향값 얻기

	double pi = 3.14159265358979323846;
	double radian = dir * pi / 180.;

	int dx = -10 * sin(radian);
	int dz =  10 * cos(radian);
	
	px += dx;
	pz += dz;

	ConcreteID my_lime = createConcrete(COLOR_LIME, true);
	ConcreteID my_black = createConcrete(COLOR_BLACK, true);

	for (int h = 0; h < 5; h++) // 1층 ~ 5층
	{
		for (int i = -2; i < 3; i++)
		{
			for (int j = -2; j < 3; j++)
			{
				if (abs(i) == 2 || abs(j) == 2)
				{
					if (abs(i) == 2 && abs(j) == 2)
					{
						continue;
					}

					else
					{
						locateBlock(my_lime, px + i, py + h, pz + j);
						locateBlock(my_lime, px + j, py + h, pz + i);
					}
				}

				else
				{
					continue;
				}
			}
		}

	}


	for (int h = 5; h < 7; h++) // 6층 ~ 7층
	{
		for (int i = -3; i < 4; i++)
		{
			for (int j = -3; j < 4; j++)
			{
				if (abs(i) * abs(j) < 5)
				{
					if (abs(i) * abs(j) == 4)
					{
						locateBlock(my_lime, px + i, py + h, pz + j);
					}

					else if (abs(i) == 3 || abs(j) == 3)
					{
						locateBlock(my_lime, px + i, py + h, pz + j);
						locateBlock(my_lime, px + j, py + h, pz + i);
					}

					else if (h == 5 && abs(i) * abs(j) <= 2)
					{
						locateBlock(my_black, px + i, py + h, pz + j);
						locateBlock(my_black, px + j, py + h, pz + i);
					}
				}

				else
				{
					continue;
				}
			}
		}
	}

}
