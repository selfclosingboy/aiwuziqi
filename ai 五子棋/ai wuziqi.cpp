#include<stdio.h>
#include<windows.h>
#include<graphics.h>
#include <iostream>


IMAGE l;
IMAGE a;
IMAGE k;
IMAGE Y;


int shuzu[15][15];
int cheh[15][15];
int p = 0;
int q = 0;
int num = 1;


void hualine() {
	setlinecolor(BLACK);
	for (int x = 15; x < 480; x += 30)
		line(x, 15, x, 465);
	for (int y = 15; y < 480; y += 30)
		line(15, y, 465, y);

}

void huapoint() {
	setfillcolor(BLACK);
	fillcircle(4 * 30 - 15, 4 * 30 - 15, 3);
	fillcircle(13 * 30 - 15, 4 * 30 - 15, 3);
	fillcircle(4 * 30 - 15, 13 * 30 - 15, 3);
	fillcircle(13 * 30 - 15, 13 * 30 - 15, 3);
}

int z(int x, int y) {
	if (shuzu[x][y] != 0 || y >= 15 || x >= 15 || y < 1 || x < 1)
		return 0;
	else
		shuzu[x][y] = num;

	num *= -1;
	return 1;
}



void b(int b, int c) {
	setfillcolor(RED);
	int x = b / 30;
	int y = c / 30;
	if (z(x, y) == 0 ) {
		return;
	}
	cheh[x][y] = p;
	p += 1;
	q += 1;
	fillcircle(b - b % 30 + 15, c - c % 30 + 15, 10);
	loadimage(&Y, _T("5.jpg"));
	putimage(0, 470, 266, 520, &Y, 0, 0);
	settextcolor(YELLOW);
	outtextxy(25, 470, _T("ai turn"));
}

void red(int b, int c) {
	setfillcolor(RED);
	int x = b / 30;
	int y = c / 30;
	if (z(x, y) == 0) {
		return;
	}
	cheh[x][y] = p;
	p += 1;
	fillcircle(b - b % 30 + 15, c - c % 30 + 15, 10);
	loadimage(&Y, _T("5.jpg"));
	putimage(0, 470, 266, 520, &Y, 0, 0);
	settextcolor(YELLOW);
	outtextxy(25, 470, _T("yellow turn"));
}

void yellow(int b,int c) {
	setfillcolor(YELLOW);
	int x = b / 30;
	int y = c / 30;
	if (z(x, y) == 0) {
		return;
	}
	cheh[x][y] = p;
	p += 1;
	fillcircle(b - b % 30 + 15, c - c % 30 + 15, 10);
	loadimage(&Y, _T("5.jpg"));
	putimage(0, 470, 266, 520, &Y, 0, 0);
	settextcolor(RED);
	outtextxy(25, 470, _T("red turn"));
}




int zhizhang(int x, int y) {
	if (shuzu[x - 1][y] == shuzu[x - 2][y] && shuzu[x - 1][y] == shuzu[x - 3][y] && shuzu[x - 1][y] == shuzu[x - 4][y] && shuzu[x - 1][y] == -1)
		return 1000;
	if (shuzu[x - 1][y + 1] == shuzu[x - 2][y + 2] && shuzu[x - 1][y + 1] == shuzu[x - 3][y + 3] && shuzu[x - 1][y + 1] == shuzu[x - 4][y + 4] && shuzu[x - 1][y + 1] == -1)
		return 1000;
	if (shuzu[x - 1][y - 1] == shuzu[x - 2][y - 2] && shuzu[x - 1][y - 1] == shuzu[x - 3][y - 3] && shuzu[x - 1][y - 1] == shuzu[x - 4][y - 4] && shuzu[x - 1][y - 1] == -1)
		return 1000;
	if (shuzu[x][y + 1] == shuzu[x][y + 2] && shuzu[x][y + 1] == shuzu[x][y + 3] && shuzu[x][y + 1] == shuzu[x][y + 4] && shuzu[x][y + 1] == -1)
		return 1000;
	if (shuzu[x][y - 1] == shuzu[x][y - 2] && shuzu[x][y - 1] == shuzu[x][y - 3] && shuzu[x][y - 1] == shuzu[x][y - 4] && shuzu[x][y - 1] == -1)
		return 1000;
	if (shuzu[x + 1][y] == shuzu[x + 2][y] && shuzu[x + 1][y] == shuzu[x + 3][y] && shuzu[x + 1][y] == shuzu[x + 4][y] && shuzu[x + 1][y] == -1)
		return 1000;
	if (shuzu[x + 1][y - 1] == shuzu[x + 2][y - 2] && shuzu[x + 1][y - 1] == shuzu[x + 3][y - 3] && shuzu[x + 1][y - 1] == shuzu[x + 4][y - 4] && shuzu[x + 1][y - 1] == -1)
		return 1000;
	if (shuzu[x + 1][y + 1] == shuzu[x + 2][y + 2] && shuzu[x + 1][y + 1] == shuzu[x + 3][y + 3] && shuzu[x + 1][y + 1] == shuzu[x + 4][y + 4] && shuzu[x + 1][y + 1] == -1)
		return 1000;
//赢


	if (shuzu[x - 1][y] == shuzu[x - 2][y] && shuzu[x - 1][y] == shuzu[x - 3][y]&& shuzu[x - 1][y] == shuzu[x - 4][y] && shuzu[x - 1][y] == 1)
		return 100;
	if (shuzu[x - 1][y + 1] == shuzu[x - 2][y + 2] && shuzu[x - 1][y + 1] == shuzu[x - 3][y + 3] && shuzu[x - 1][y + 1] == shuzu[x - 4][y + 4] && shuzu[x - 1][y + 1] == 1)
		return 100;
	if (shuzu[x - 1][y - 1] == shuzu[x - 2][y - 2] && shuzu[x - 1][y - 1] == shuzu[x - 3][y - 3] && shuzu[x - 1][y - 1] == shuzu[x - 4][y - 4] && shuzu[x - 1][y - 1] == 1)
		return 100;
	if (shuzu[x][y + 1] == shuzu[x][y + 2] && shuzu[x][y + 1] == shuzu[x][y + 3] && shuzu[x][y + 1] == shuzu[x][y + 4] && shuzu[x][y + 1] == 1)
		return 100;
	if (shuzu[x][y - 1] == shuzu[x][y - 2] && shuzu[x][y - 1] == shuzu[x][y - 3] && shuzu[x][y - 1] == shuzu[x][y - 4] && shuzu[x][y - 1] == 1)
		return 100;
	if (shuzu[x + 1][y] == shuzu[x + 2][y] && shuzu[x + 1][y] == shuzu[x + 3][y] && shuzu[x + 1][y] == shuzu[x + 4][y] && shuzu[x + 1][y] == 1)
		return 100;
	if (shuzu[x + 1][y - 1] == shuzu[x + 2][y - 2] && shuzu[x + 1][y - 1] == shuzu[x + 3][y - 3] && shuzu[x + 1][y - 1] == shuzu[x + 4][y - 4] && shuzu[x + 1][y - 1] == 1)
		return 100;
	if (shuzu[x + 1][y + 1] == shuzu[x + 2][y + 2] && shuzu[x + 1][y + 1] == shuzu[x + 3][y + 3] && shuzu[x + 1][y + 1] == shuzu[x + 4][y + 4] && shuzu[x + 1][y + 1] == 1)
		return 100;
//堵4


	if (shuzu[x - 1][y] == shuzu[x - 2][y] && shuzu[x - 1][y] == shuzu[x +1][y] && shuzu[x - 1][y] == -1)
		return 25;
	if (shuzu[x - 1][y + 1] == shuzu[x - 2][y + 2] && shuzu[x - 1][y + 1] == shuzu[x +1][y -1] && shuzu[x - 1][y + 1] == -1)
		return 25;
	if (shuzu[x - 1][y - 1] == shuzu[x - 2][y - 2] && shuzu[x - 1][y - 1] == shuzu[x +1][y +1] && shuzu[x - 1][y - 1] == -1)
		return 25;
	if (shuzu[x][y + 1] == shuzu[x][y + 2] && shuzu[x][y + 1] == shuzu[x][y - 1] && shuzu[x][y + 1] == -1)
		return 25;
	if (shuzu[x][y - 1] == shuzu[x][y - 2] && shuzu[x][y - 1] == shuzu[x][y + 1] && shuzu[x][y - 1] == -1)
		return 25;
	if (shuzu[x + 1][y] == shuzu[x + 2][y] && shuzu[x + 1][y] == shuzu[x - 1][y] && shuzu[x + 1][y] == -1)
		return 25;
	if (shuzu[x + 1][y - 1] == shuzu[x + 2][y - 2] && shuzu[x + 1][y - 1] == shuzu[x -1][y + 1] && shuzu[x + 1][y - 1] == -1)
		return 25;
	if (shuzu[x + 1][y + 1] == shuzu[x + 2][y + 2] && shuzu[x + 1][y + 1] == shuzu[x -1 ][y - 1] && shuzu[x + 1][y + 1] == -1)
		return 25;


	if (shuzu[x - 1][y] == shuzu[x - 2][y] && shuzu[x - 1][y] == shuzu[x - 3][y] && shuzu[x - 1][y] == -1)
		return 25;
	if (shuzu[x - 1][y + 1] == shuzu[x - 2][y + 2] && shuzu[x - 1][y + 1] == shuzu[x - 3][y + 3] && shuzu[x - 1][y + 1] == -1)
		return 25;
	if (shuzu[x - 1][y - 1] == shuzu[x - 2][y - 2] && shuzu[x - 1][y - 1] == shuzu[x - 3][y - 3] && shuzu[x - 1][y - 1] == -1)
		return 25;
	if (shuzu[x][y + 1] == shuzu[x][y + 2] && shuzu[x][y + 1] == shuzu[x][y + 3] && shuzu[x][y + 1] == -1)
		return 25;
	if (shuzu[x][y - 1] == shuzu[x][y - 2] && shuzu[x][y - 1] == shuzu[x][y - 3] && shuzu[x][y - 1] == -1)
		return 25;
	if (shuzu[x + 1][y] == shuzu[x + 2][y] && shuzu[x + 1][y] == shuzu[x + 3][y] && shuzu[x + 1][y] == -1)
		return 25;                
	if (shuzu[x + 1][y - 1] == shuzu[x + 2][y - 2] && shuzu[x + 1][y - 1] == shuzu[x + 3][y - 3] && shuzu[x + 1][y - 1] == -1)
		return 25;
	if (shuzu[x + 1][y + 1] == shuzu[x + 2][y + 2] && shuzu[x + 1][y + 1] == shuzu[x + 3][y + 3] && shuzu[x + 1][y + 1] == -1)
		return 25;
//成4


	if (shuzu[x - 1][y] == shuzu[x - 2][y] && shuzu[x - 1][y] == shuzu[x - 3][y] && shuzu[x - 1][y] == 1 && shuzu[x - 4][y]== 0)
		return 20;
	if (shuzu[x - 1][y + 1] == shuzu[x - 2][y + 2] && shuzu[x - 1][y + 1] == shuzu[x - 3][y + 3] && shuzu[x - 1][y + 1] == 1 && shuzu[x - 4][y+4] == 0)
		return 20;
	if (shuzu[x - 1][y - 1] == shuzu[x - 2][y - 2] && shuzu[x - 1][y - 1] == shuzu[x - 3][y - 3] && shuzu[x - 1][y - 1] == 1 && shuzu[x - 4][y-4] == 0)
		return 20;
	if (shuzu[x][y + 1] == shuzu[x][y + 2] && shuzu[x][y + 1] == shuzu[x][y + 3] && shuzu[x][y + 1] == 1 && shuzu[x][y + 4] == 0)
		return 20;
	if (shuzu[x][y - 1] == shuzu[x][y - 2] && shuzu[x][y - 1] == shuzu[x][y - 3] && shuzu[x][y - 1] == 1 && shuzu[x][y - 4] == 0)
		return 20;
	if (shuzu[x + 1][y] == shuzu[x + 2][y] && shuzu[x + 1][y] == shuzu[x + 3][y] && shuzu[x + 1][y] == 1 && shuzu[x + 4][y] == 0)
		return 20;
	if (shuzu[x + 1][y - 1] == shuzu[x + 2][y - 2] && shuzu[x + 1][y - 1] == shuzu[x + 3][y - 3] && shuzu[x + 1][y - 1] == 1 && shuzu[x + 4][y - 4] == 0)
		return 20;
	if (shuzu[x + 1][y + 1] == shuzu[x + 2][y + 2] && shuzu[x + 1][y + 1] == shuzu[x + 3][y + 3] && shuzu[x + 1][y + 1] == 1 && shuzu[x + 4][y + 4] == 0)
		return 20;
// 堵3 两边无子

	if (shuzu[x - 1][y] == shuzu[x + 1][y] && shuzu[x - 1][y] == 1 && (shuzu[x - 2][y] == 0 || shuzu[x + 2][y] == 0))
		return 15;
	if (shuzu[x - 1][y + 1] == shuzu[x - 1][y - 1] && shuzu[x - 1][y + 1] == 1 && (shuzu[x - 2][y + 2] == 0 || shuzu[x + 2][y - 2] == 0))
		return 15;
	if (shuzu[x - 1][y - 1] == shuzu[x + 1][y + 1] && shuzu[x - 1][y - 1] == 1 && (shuzu[x - 2][y - 2] == 0 || shuzu[x + 2][y + 2] == 0))
		return 15;
	if (shuzu[x][y + 1] == shuzu[x][y - 1] && shuzu[x][y + 1] == 1 && (shuzu[x ][y - 2] == 0 || shuzu[x][y + 2] == 0))
		return 15;
//堵夹

	if (shuzu[x - 1][y] == shuzu[x - 2][y]&& shuzu[x - 1][y] == shuzu[x - 3][y] && shuzu[x - 1][y] == 1 && shuzu[x - 4][y] == -1)
		return 10;
	if (shuzu[x - 1][y + 1] == shuzu[x - 2][y + 2] && shuzu[x - 1][y + 1] == shuzu[x - 3][y + 3] &&shuzu[x - 1][y + 1] == 1 && shuzu[x - 4][y] == -1)
		return 10;
	if (shuzu[x - 1][y - 1] == shuzu[x - 2][y - 2] && shuzu[x - 1][y - 1] == shuzu[x - 3][y - 3] && shuzu[x - 1][y - 1] == 1 && shuzu[x - 4][y] == -1)
		return 10;
	if (shuzu[x][y + 1] == shuzu[x][y + 2] && shuzu[x][y + 1] == shuzu[x][y + 3] && shuzu[x][y + 1] == 1 && shuzu[x - 4][y] == -1)
		return 10;
	if (shuzu[x][y - 1] == shuzu[x][y - 2] && shuzu[x][y - 1] == shuzu[x][y - 3] && shuzu[x][y - 1] == 1 && shuzu[x - 4][y] == -1)
		return 10;
	if (shuzu[x + 1][y] == shuzu[x + 2][y]&& shuzu[x + 1][y] == shuzu[x + 3][y] && shuzu[x + 1][y] == 1 && shuzu[x - 4][y] == -1)
		return 10;
	if (shuzu[x + 1][y - 1] == shuzu[x + 2][y - 2] && shuzu[x + 1][y - 1] == shuzu[x + 3][y - 3] && shuzu[x + 1][y - 1] == 1 && shuzu[x - 4][y] == -1)
		return 10;
	if (shuzu[x + 1][y + 1] == shuzu[x + 2][y + 2] && shuzu[x + 1][y + 1] == shuzu[x + 3][y + 3] &&shuzu[x + 1][y + 1] == 1 && shuzu[x - 4][y] == -1)
		return 10;
//堵3 有子

	if (shuzu[x - 1][y] == shuzu[x - 2][y] && shuzu[x - 1][y] == 1 && shuzu[x - 3][y] == 0)
		return 4;
	if (shuzu[x - 1][y + 1] == shuzu[x - 2][y + 2] && shuzu[x - 1][y + 1] == 1 && shuzu[x - 3][y + 3] == 0)
		return 4;
	if (shuzu[x - 1][y - 1] == shuzu[x - 2][y - 2] && shuzu[x - 1][y - 1] == 1 && shuzu[x - 3][y - 3] == 0)
		return 4;
	if (shuzu[x][y + 1] == shuzu[x][y + 2] && shuzu[x][y + 1] == 1 && shuzu[x][y + 3] == 0)
		return 4;
	if (shuzu[x][y - 1] == shuzu[x][y - 2] && shuzu[x][y - 1] == 1 && shuzu[x][y - 3] == 0)
		return 4;
	if (shuzu[x + 1][y] == shuzu[x + 2][y] && shuzu[x + 1][y] == 1 && shuzu[x + 3][y] == 0)
		return 4;
	if (shuzu[x + 1][y - 1] == shuzu[x + 2][y - 2] && shuzu[x + 1][y - 1] == 1 && shuzu[x + 3][y - 3] == 0)
		return 4;
	if (shuzu[x + 1][y + 1] == shuzu[x + 2][y + 2] && shuzu[x + 1][y + 1] == 1 && shuzu[x + 3][y + 3] == 0)
		return 4;

//堵2


	if (shuzu[x - 1][y] == shuzu[x - 2][y] && shuzu[x - 1][y] == -1 && shuzu[x - 3][y] == 0)
		return 3;
	if (shuzu[x - 1][y + 1] == shuzu[x - 2][y + 2] && shuzu[x - 1][y + 1] == -1 && shuzu[x - 3][y + 3] == 0)
		return 3;
	if (shuzu[x - 1][y - 1] == shuzu[x - 2][y - 2] && shuzu[x - 1][y - 1] == -1 && shuzu[x - 3][y - 3] == 0)
		return 3;
	if (shuzu[x][y + 1] == shuzu[x][y + 2] && shuzu[x][y + 1] == -1 && shuzu[x][y + 3] == 0)
		return 3;
	if (shuzu[x][y - 1] == shuzu[x][y - 2] && shuzu[x][y - 1] == -1 && shuzu[x][y - 3] == 0)
		return 3;
	if (shuzu[x + 1][y] == shuzu[x + 2][y] && shuzu[x + 1][y] == -1 && shuzu[x + 3][y] == 0)
		return 3;
	if (shuzu[x + 1][y - 1] == shuzu[x + 2][y - 2] && shuzu[x + 1][y - 1] == -1 && shuzu[x + 3][y - 3] == 0)
		return 3;
	if (shuzu[x + 1][y + 1] == shuzu[x + 2][y + 2] && shuzu[x + 1][y + 1] == -1 && shuzu[x + 3][y + 3] == 0)
		return 3;
//成3

	if (shuzu[x - 1][y]== shuzu[x - 2][y] && shuzu[x - 1][y] == 1)
		return 2;
	if (shuzu[x - 1][y+1] == shuzu[x - 2][y + 2]&& shuzu[x - 1][y + 1] == 1)
		return 2;
	if (shuzu[x - 1][y-1] == shuzu[x - 2][y-2]&& shuzu[x - 1][y - 1] == 1)
		return 2;
	if (shuzu[x][y+1] == shuzu[x][y + 2]&& shuzu[x][y + 1] == 1)
		return 2;
	if (shuzu[x][y-1] == shuzu[x][y - 2]&& shuzu[x][y - 1] == 1)
		return 2;
	if (shuzu[x + 1][y] == shuzu[x + 2][y]&& shuzu[x + 1][y] == 1)
		return 2;
	if (shuzu[x + 1][y-1] == shuzu[x + 2][y - 2]&& shuzu[x + 1][y - 1] == 1)
		return 2;
	if (shuzu[x + 1][y+1] == shuzu[x + 2][y + 2 ] && shuzu[x + 1][y + 1] == 1)
		return 2;
//堵2

	if (shuzu[x - 1][y] == 1)
		return 1;
	if (shuzu[x + 1][y] == 1)
		return 1;
	if (shuzu[x][y + 1] == 1)
		return 1;
	if (shuzu[x][y - 1] == 1)
		return 1;
	if (shuzu[x + 1][y+1] == 1)
		return 1;
	if (shuzu[x + 1][y-1] == 1)
		return 1;
	if (shuzu[x - 1][y+1] == 1)
		return 1;
	if (shuzu[x - 1][y - 1] == 1)
		return 1;
	else
		return 0;
}
//堵1
void zhineng() {
	setfillcolor(YELLOW);
	int a = 0;
	int b;
	int c; 
	for (int i = 1; i < 15; i++)
		for (int j = 1; j < 15; j++) {
			if (a < zhizhang(i, j) && shuzu[i][j] == 0) {
				a = zhizhang(i, j);
				b = i;
				c = j;
			}
		}
	if (a == 0) {
		b = 7;
		c = 6;

	}
	fillcircle(b*30 + 15, c*30 + 15, 10);
	shuzu[b][c] = num;
	cheh[b][c] = p;
	p += 1;


}






void y() {
	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 15; j++)
			shuzu[i][j] = 0;
}

void yc() {
	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 15; j++)
			cheh[i][j] = 0;
}

int check_5(int x, int y) {
	if (shuzu[x][y] == 1) {
		if (shuzu[x][y] == shuzu[x - 1][y] && shuzu[x][y] == shuzu[x - 2][y] && shuzu[x][y] == shuzu[x + 1][y] && shuzu[x][y] == shuzu[x + 2][y])
			return 1;
		if (shuzu[x][y] == shuzu[x][y + 1] && shuzu[x][y] == shuzu[x][y + 2] && shuzu[x][y] == shuzu[x][y - 1] && shuzu[x][y] == shuzu[x][y - 2])
			return 1;
		if (shuzu[x][y] == shuzu[x - 1][y - 1] && shuzu[x][y] == shuzu[x - 2][y - 2] && shuzu[x][y] == shuzu[x + 1][y + 1] && shuzu[x][y] == shuzu[x + 2][y + 2])
			return 1;
		if (shuzu[x][y] == shuzu[x - 1][y + 1] && shuzu[x][y] == shuzu[x - 2][y + 2] && shuzu[x][y] == shuzu[x + 1][y - 1] && shuzu[x][y] == shuzu[x + 2][y - 2])
			return 1;
	}
	if (shuzu[x][y] == -1) {
		if (shuzu[x][y] == shuzu[x - 1][y] && shuzu[x][y] == shuzu[x - 2][y] && shuzu[x][y] == shuzu[x + 1][y] && shuzu[x][y] == shuzu[x + 2][y])
			return -1;
		if (shuzu[x][y] == shuzu[x][y + 1] && shuzu[x][y] == shuzu[x][y + 2] && shuzu[x][y] == shuzu[x][y - 1] && shuzu[x][y] == shuzu[x][y - 2])
			return -1;
		if (shuzu[x][y] == shuzu[x - 1][y - 1] && shuzu[x][y] == shuzu[x - 2][y - 2] && shuzu[x][y] == shuzu[x + 1][y + 1] && shuzu[x][y] == shuzu[x + 2][y + 2])
			return -1;
		if (shuzu[x][y] == shuzu[x - 1][y + 1] && shuzu[x][y] == shuzu[x - 2][y + 2] && shuzu[x][y] == shuzu[x + 1][y - 1] && shuzu[x][y] == shuzu[x + 2][y - 2])
			return -1;
	}

	return 0;

}

int check_end() {
	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 15; j++)
		{
			if (shuzu[i][j] == 0)
				continue;
			if (check_5(i, j) == 1)
				return 1;
			if (check_5(i, j) == -1)
				return -1;
		}
	return 0;
}

int remove(int e) {
	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 15; j++) {
			if (cheh[i][j] == e) {
				shuzu[i][j] = 0;
				cheh[i][j] = 0;
				num *= -1;
				cleardevice();
				loadimage(&a, _T("1.jpg"));
				putimage(0, 0, 480, 520, &a, 200, 400);
				hualine();
				huapoint();
				
				for (int i = 0; i < 15; i++) {
					for (int j = 0; j < 15; j++) {
						if (shuzu[i][j] == 1) {
							setfillcolor(RED);
							fillcircle(i * 30 + 15, j * 30 + 15, 10);
						}
						if (shuzu[i][j] == -1) {
							setfillcolor(YELLOW);
							fillcircle(i * 30 + 15, j * 30 + 15, 10);
						}
					}
				}
				return 0;
			}
		}

	return 0;
}




int again() {
	cleardevice();
	loadimage(&l, _T("4.jpg"));
	putimage(0, 0, 480, 520, &l, 0, 0);
	loadimage(&k, _T("3.jpg"));
	putimage(50, 150, 480, 480, &k, 0, 0);
	settextcolor(RGB(102, 153, 255));
	outtextxy(130, 200, _T("AGAIN?"));
	MOUSEMSG I;

	while (1) {
		I = GetMouseMsg();
		if (I.uMsg == WM_LBUTTONDOWN) {
			return 0;
		}
	}
	
}

void kaishi() {
	
	cleardevice();
	loadimage(&l, _T("4.jpg"));
	putimage(0, 0, 480, 520, &l, 0, 0);
	settextstyle(50, 20, _T("黑体"));
	loadimage(&k, _T("3.jpg"));
	putimage(50, 30, 480, 172, &k, 0, 0);
	putimage(50, 300, 480, 432, &k, 0, 0);
	setbkmode(TRANSPARENT);
	settextcolor(RGB(102, 153, 255));
	outtextxy(150, 80, _T("AI GAME"));
	settextcolor(RGB(102, 153, 255));
	outtextxy(95, 340, _T("HUMAN GAME"));
}

void humenkaishi() {
	cleardevice();
	loadimage(&a, _T("1.jpg"));
	putimage(0, 0, 480, 520, &a, 200, 400);

	hualine();
	huapoint();
	settextstyle(50, 20, _T("黑体"));
	setbkmode(TRANSPARENT);
	settextcolor(RED);
	loadimage(&Y, _T("5.jpg"));
	putimage(0, 470, 266, 520, &Y, 0, 0);
	outtextxy(20, 470, _T("red turn"));
}

void aikaishi() {
	cleardevice();
	loadimage(&a, _T("1.jpg"));
	putimage(0, 0, 480, 520, &a, 200, 400);

	hualine();
	huapoint();
	settextstyle(50, 20, _T("黑体"));
	setbkmode(TRANSPARENT);
	settextcolor(RED);
	loadimage(&Y, _T("5.jpg"));
	putimage(0, 470, 266, 520, &Y, 0, 0);
	outtextxy(20, 470, _T("your turn"));
}

int ai_or_human(int a,int b){
	if (a > 50 && a < 450 && b>30 && b < 172) {
		return 1;
	}
	if (a > 50 && a < 450 && b>300 && b < 432) {
		return -1;
	}
	return 0;
}

int main() {
	initgraph(480, 520);
	kaishi();
	while (1) {
		y();
		yc();
		int che = 1;
		MOUSEMSG s;
		num = 1;
		q = 0;
		p = 1;
		int c = 0;
		s = GetMouseMsg();
		if (s.uMsg == WM_LBUTTONDOWN) {
			if (ai_or_human(s.x, s.y) == 1) {
				aikaishi();
				MOUSEMSG m;
				while (1) {
					m = GetMouseMsg();
					if (num == 1) {
						if (m.uMsg == WM_LBUTTONDOWN) {
							b(m.x, m.y);




						}
					}
					if (m.uMsg == WM_RBUTTONDOWN) {

						remove(q);
						
						q -= 1;
						p -= 1;
						remove(q);

						q -= 1;
						p -= 1;

						if (num == 1) {
							settextcolor(RED);
							loadimage(&Y, _T("5.jpg"));
							putimage(0, 470, 266, 520, &Y, 0, 0);
							outtextxy(20, 470, _T("red turn"));
							num = 1;
						}
						if (num == -1) {
							settextcolor(YELLOW);
							loadimage(&Y, _T("5.jpg"));
							putimage(0, 470, 266, 520, &Y, 0, 0);
							outtextxy(20, 470, _T("yellow turn"));
							num = -1;
						}
						
					}

					
					if (check_end() == 1) {
						loadimage(&Y, _T("5.jpg"));
						putimage(0, 470, 266, 520, &Y, 0, 0);
						settextcolor(RED);
						outtextxy(185, 200, _T("you win"));
						Sleep(3000);
						if (again() == 0) {
							kaishi();
							break;
						}

					}
					if (num == -1 ) {
						Sleep(1000); //ai dangjishijian
						zhineng();
						q += 1;
						num *= -1;
						settextcolor(RED);
						loadimage(&Y, _T("5.jpg"));
						putimage(0, 470, 266, 520, &Y, 0, 0);
						outtextxy(20, 470, _T("your turn"));
					}

					if (check_end() == -1) {
						loadimage(&Y, _T("5.jpg"));
						putimage(0, 470, 266, 520, &Y, 0, 0);
						settextcolor(YELLOW);
						outtextxy(185, 200, _T("ai win"));

						Sleep(3000);
						if (again() == 0) {
							kaishi();
							break;
						}
					}
					

			




				}
			}
			if (ai_or_human(s.x, s.y) == -1) {
				humenkaishi();
				MOUSEMSG t;
				
				while (1) {
					t = GetMouseMsg();
					if (t.uMsg == WM_LBUTTONDOWN) {
						if (num == 1) {
							red(t.x, t.y);

						}
						if (num == -1) {
							yellow(t.x, t.y);
						}
						q += 1;

					}



					if (check_end() == 1) {
						loadimage(&Y, _T("5.jpg"));
						putimage(0, 470, 266, 520, &Y, 0, 0);
						settextcolor(RED);
						outtextxy(185, 200, _T("red win"));
						Sleep(3000);
						if (again() == 0) {
							kaishi();
							break;
						}

					}


					if (check_end() == -1) {
						loadimage(&Y, _T("5.jpg"));
						putimage(0, 470, 266, 520, &Y, 0, 0);
						settextcolor(YELLOW);
						outtextxy(130, 200, _T("yellow win"));
						Sleep(3000);
						if (again() == 0) {
							kaishi();
							break;
						}
					}
					if (t.uMsg == WM_RBUTTONDOWN) {
						remove(q);
						q -= 1;
						p -= 1;

						if (num == 1) {
							settextcolor(RED);
							loadimage(&Y, _T("5.jpg"));
							putimage(0, 470, 266, 520, &Y, 0, 0);
							outtextxy(20, 470, _T("red turn"));
							num = 1;
						}
						if (num == -1) {
							settextcolor(YELLOW);
							loadimage(&Y, _T("5.jpg"));
							putimage(0, 470, 266, 520, &Y, 0, 0);
							outtextxy(20, 470, _T("yellow turn"));
							num = -1;
						}
						
					}
				}
			}
		}


	}


	return 0;
}
