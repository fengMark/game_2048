#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
void showGame();
void AddRand();
void initGame();
void StartGame();
void mouseLeft();
void mouseRight();
void mouseUp();
void mouseDown();
bool isGameover();
bool isHasZero();
int score;
int best=0;
int map[4][4];
bool if_GameOver;
bool if_AddRand;
int main(){
	if_GameOver = false;
	initGame();
	StartGame();
	return 0;
}
void showGame(){
	printf("GAME:2048\n\n");
	printf("score:%d\tbest:%d\n",score,best);
	printf("┏━━┳━━┳━━┳━━┓\n");

	for (int i = 0; i < 4;i++){
		printf("┃");
		for (int j = 0; j < 4; j++){
			if (map[i][j] != 0){
				printf("%4d┃", map[i][j]);
			}
			else{
				printf("    ┃", map[i][j]);
			}
		}
		if (i < 3){
			printf("\n┣━━╋━━╋━━╋━━┫\n");
		}
		else{
			printf("\n┗━━┻━━┻━━┻━━┛");
		}
	}
	printf("\n\n----------------------------\n\n");
	printf("W↑\tS↓\tA←\tD→");
}
void AddRand(){
	srand((unsigned int)time(NULL));
	int i, j;
	while (true)
	{
		i = rand() % 4;
		j = rand() % 4;
		if (map[i][j] == 0){
			map[i][j] = (rand() % 3 ? 2 : 4);
			break;
		}
		else{
			continue;
		}
	}	
}
bool isGameover(){
	for (int i = 0; i < 4; i++){
		for (int j = 0,k=1; k < 4;j++,k++ ){
			if (map[i][j] == map[i][k]){
				return false;
			}
			if (map[j][i] == map[k][i]){
				return false;
			}
		}
	}
	return true;
}
bool isHasZero(){
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++)
		{
			if (map[i][j] == 0){
				return true;
			}
		}
	}
	return false;
}
void initGame(){
	score = 0;
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			map[i][j] = 0;
		}
	}
	srand((unsigned int)time(NULL));
	int i, j;
	i = rand() % 4;
	j = rand() % 4;
	map[i][j] = 2;
	AddRand();
	showGame();

}
void StartGame(){
	while (true)
	{
		switch (getch())
		{
		case 72:
		case 'W':
		case 'w':mouseUp();
				break;
		case 80:
		case 'S':
		case 's':mouseDown();
			break;
		case 75:
		case 'A':
		case 'a':mouseLeft();
			break;
		case 77:
		case 'D':
		case 'd':mouseRight();
			break;
		default:
			break;
		}
		system("cls");
		if (isHasZero()){
			AddRand();
		}
		else{
			if (isGameover()){//游戏结束
				if_GameOver = true;
				if (score > best){
					best = score;
				}
				printf("GAME OVER!\n\n");
				printf("best：%d\ncurrent:%d\n", best,score);
				printf("-------------------------------------------\n");
				printf("R:开始\tC:退出");
				while (true)
				{
					switch (getch())
					{
					case 'R':
					case 'r':
						initGame();
						if_GameOver = false;
						system("cls");
						break;
					case 'C':
					case 'c':
						return;
					default:
						break;
					}
					if (if_GameOver == false){
						break;
					}
				}
			}
		}
		showGame();
	}
}
void mouseLeft(){
	for (int i = 0; i < 4; i++){
		for (int j = 1, k = 0; j < 4; j++){
			if (map[i][j] != 0){
				if (map[i][j] == map[i][k]){
					score += (map[i][k++] <<=1);
					map[i][j] = 0;
				}
				else if (map[i][k] == 0){
					map[i][k] = map[i][j];
					map[i][j] = 0;
				}
				else 
				{
					if (map[i][++k] == 0){
						map[i][k] = map[i][j];
						map[i][j] = 0;
					}
				}
			}

		}
	}
}
void mouseRight(){
	for (int i = 0; i < 4; i++){
		for (int j = 2, k = 3; j >= 0; j--){
			if (map[i][j] != 0){
				if (map[i][j] == map[i][k]){
					score += (map[i][k--] <<= 1);
					map[i][j] = 0;
				}
				else if (map[i][k] == 0){
					map[i][k] = map[i][j];
					map[i][j] = 0;
				}
				else
				{
					if (map[i][--k] == 0){
						map[i][k] = map[i][j];
						map[i][j] = 0;
					}
				}
			}
		}
	}
}
void mouseUp(){
	for (int i = 0; i < 4; i++){
		for (int j = 1, k = 0; j < 4; j++){
			if (map[j][i] != 0){
				if (map[j][i] == map[k][i]){
					score += (map[k++][i] <<= 1);
					map[j][i] = 0;
				}
				else if (map[k][i] == 0){
					map[k][i] = map[j][i];
					map[j][i] = 0;
				}
				else 
				{
					if (map[++k][i] == 0){
						map[k][i] = map[j][i];
						map[j][i] = 0;
					}
				}
			}

		}
	}
}
void mouseDown(){
	for (int i = 0; i < 4; i++){
		for (int j = 2, k = 3; j >= 0; j--){
			if (map[j][i] != 0){
				if (map[j][i] == map[k][i]){
					score += (map[k--][i] <<= 1);
					map[j][i] = 0;
				}
				else if (map[k][i] == 0){
					map[k][i] = map[j][i];
					map[j][i] = 0;
				}
				else
				{
					if (map[--k][i] == 0){
						map[k][i] = map[j][i];
						map[j][i] = 0;
					}
				}
			}
		}
	}
}