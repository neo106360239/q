#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define l 25
#define c 50
#define k 100
#define space 30
#define t 5
#define enter 13
#define max 4
#define MAXNUMWORDS 20
#define MAXWORDLENGTH 15

void print1();
void head1();
void game1();
void printpicture();
void coor(int x[l + 1][c + 1]);
void head2();
void star(int *y, int *z, int *buffer);
void printshrink(int x, int y, int *x2, int *y2, int buffer);
void printexpand(int x, int y, int x1, int y1, int buffer);
void delay(int z);
void head3();
void add();
void mul();
void tra();
void bbb();
void aaa();
void head4();
void gamestar(int *level);
void gamerule(int level);
void topic(int a[], int level);
void gamming(int *A, int B, int a[], int b[], int level);
void compare(int a[], int b[], int *A, int *B);
void gameend(int a[]);
void head5();
void head6();
void hangman_diagram(const char error[], int key[]);
void game(int WordsReadIn, char guessWords);

int main(void)
{
	int choic;
	char ch;
	do
	{
		print1();
		do
		{
			ch = getch();
			choic = ch - 0x30;
			void(*total[6])() = { head1,head2,head3,head4,head5,head6 };
			total[choic-1]();
		} while (choic < 1 || choic>7);
		printf("\t\t\t\t掰掰!  下次見");
	} while (choic != 7);

	printf("\n");
	system("pause");
	return 0;
}

void print1()
{
	system("cls");
	printf("\t\t\t\t請選擇想要的功能\n");
	printf("-----------------------------------------------------------------------------------------\n");
	printf("1不會自動移動的貪吃蛇\t\t\t2.矩形縮放投影機\t\t\t3.簡略計算機\n"
		"4.數字猜猜猜\t\t\t\t5.慘無人道的終極密碼\t\t\t6.hangman\n"
		"7.結束遊戲\n\n");
}

void head1()
{
		char ch;
		do
		{
			srand(time(NULL));
			game1();
			printf("\n按 p 在玩一次\n");
			printf("按 m 回主選單\n");
			do
			{
				ch = getch();
			} while ((ch != 'p') && (ch != 'm'));

		} while (ch == 'p');
	
}
void coor(int x[l + 1][c + 1])
{
	int i, j, z = 0;
	for (i = 0; i <= l; i++)
	{
		for (j = 0; j <= c; j++)
		{
			if (x[i][j] == 1)
				printf("*");
			else
				printf(" ");
		}
		printf("|");
		printf("\n");
	}
	for (j = 0; j <= c; j++)
	{
		printf("-");
	}
}

void game1()
{
		int x[l + 1][c + 1] = { 0 }, my[k] = { 0 }, mx[k] = { 0 };
		int a, b,/*蛇的初始點*/ a1, b1,/*點點的座標*/ i/*跑回圈用*/, d = 5/*蛇的原始長度*/, n = 0/*判斷是否往回走*/;
		char ch, ch1 = '\0';

		for (i = 0; i <= 10; i++)
			x[i][7] = 1;
		for (i = 0; i <= 20; i++)
			x[20][i] = 1;
		for (i = 5; i <= 15; i++)
			x[i][25] = 1;
		for (i = 25; i <= 50; i++)
			x[10][i] = 1;
		do
		{
			a = rand() % l;
			b = rand() % c;
			a1 = rand() % l;
			b1 = rand() % c;
		} while (a == a1 || b == b1 || x[a1][b1] == 1 || x[a][b] == 1);
		x[a1][b1] = 1;
		x[a][b] = 1;

		do
		{
			if (d > 5)
			{
				do
				{
					a1 = rand() % l;
					b1 = rand() % c;
				} while (x[a1][b1] == 1);
				x[a1][b1] = 1;
		}
			do
			{
				for (i = (d - 1); i > 0; i--)
				{
					my[i] = my[i - 1];
					mx[i] = mx[i - 1];
				}
				my[0] = a;
				mx[0] = b;

				printpicture();
				coor(x);
				/*for (i = (d - 1); i >= 0; i--)
				{
				printf("%d ", mx[i]);
				printf("%d ", my[i]);
				}*/
				do
				{
					ch = getch();
					switch (ch)
					{
					case 0x48:
						if (ch1 != 0x50)
						{
							n = 0;
							a--;
						}
						else
							n = 1;
						if (a == -1)
							a = l;
						break;
					case 0x50:
						if (ch1 != 0x48)
						{
							n = 0;
							a++;
						}
						else
							n = 1;
						if (a == (l + 1))
							a = 0;
						break;
					case 0x4D:
						if (ch1 != 0x4B)
						{
							n = 0;
							b++;
						}
						else
							n = 1;
						if (b == (c + 1))
							b = 0;
						break;
					case 0x4B:
						if (ch1 != 0x4D)
						{
							n = 0;
							b--;
						}
						else
							n = 1;
						if (b == -1)
							b = c;
						break;
					default:
						break;
					}
					if (n == 0)
						ch1 = ch;
				} while (mx[0] == b && my[0] == a && (ch != 'e'));
				if (x[a][b] == 0)
					x[a][b] = 1;
				else if (a != a1 && b != b1)
					ch = 'e';
				x[my[d - 1]][mx[d - 1]] = 0;
			} while (((b != b1) || (a != a1)) && (ch != 'e'));
			d++;
		} while (ch != 'e');
}

void printpicture()
{
	system("cls");
	printf("\t\t不會自動移動的貪吃蛇\n");
	printf("\t\t   按 e 可強迫結束\n");
	printf("----------------------------------------------------\n");
}


void head2()
{

		char ch;
		int buffer;
		int x, y, z, x2, y2;
		int i = 0;
		do
		{
			star(&y, &z, &buffer);
			x = 2 * y;
			while (i++ < z)
			{
				printshrink(x, y, &x2, &y2, buffer);
				system("cls");
				delay(buffer);
				printexpand(x, y, x2, y2, buffer);
			}
			printf("\n按 p 在玩一次\n");
			printf("按 m 回主選單\n");
			do
			{
				ch = getch();
			} while ((ch != 'p') && (ch != 'm'));

		} while (ch == 'p');
}
void star(int *y, int *z, int *buffer)
{
	int b, w, d;
	int i[3] = { { 200 }, { 450 }, { 700 } };

	system("cls");
	printf("\t\t\t矩形縮放投影機\n");
	printf("-------------------------------------------------------------\n");
	do
	{
		printf("請輸入矩形的大小(MAX=25,min=5):");
		fflush(stdin);
		scanf_s("%d", &b);
	} while (b > 25 || b < 5);

	do
	{
		printf("縮放的次數(1-10次):");
		fflush(stdin);
		scanf_s("%d", &w);
	} while (w<1 || w>10);

	do
	{
		printf("選擇數度(1.快  2.中  3.慢):");
		fflush(stdin);
		scanf_s("%d", &d);
	} while (d<1 || d>3);
	*y = b;
	*z = w;
	*buffer = i[d - 1];
	system("cls");
}

void printshrink(int x, int y, int *x2, int *y2, int buffer)
{
	int i, j, z;
	int tx = space, ty = t, x1 = x, y1 = y;

	while (x1 >0 || y1 > 0)
	{
		for (z = 0; z <ty; z++)
			printf("\n");
		for (i = 1; i <= y1; i++)
		{
			for (z = 0; z <tx; z++)
				printf(" ");
			for (j = 1; j <= x1; j++)
			{
				if (i == 1 || i == y1 || j == 1 || j == x1)
					printf("*");
				else
					printf(" ");
			}
			printf("\n");
		}
		tx = tx + 2;
		ty++;
		x1 = x1 - 4;
		y1 = y1 - 2;
		delay(buffer);
		system("cls");
	}
	*x2 = x1 + 4;
	*y2 = y1 + 2;
}

void printexpand(int x, int y, int x1, int y1, int buffer)
{
	int i, j, z;
	int tx = x / 2 + space - (((x / 2) % 2) == 0 ? 2 : 1), ty = (y / 2) + t - ((y % 2) == 0 ? (((y / 2) % 2)) : 0);

	while (x1 <= x || y1 <= y)
	{
		for (z = ty; z >0; z--)
			printf("\n");
		for (i = y1; i >= 1; i--)
		{
			for (z = tx; z >0; z--)
				printf(" ");
			for (j = x1; j >= 1; j--)
			{
				if (i == 1 || i == y1 || j == 1 || j == x1)
					printf("*");
				else
					printf(" ");
			}
			printf("\n");
		}
		tx = tx - 2;
		ty--;
		x1 = x1 + 4;
		y1 = y1 + 2;
		delay(buffer);
		system("cls");
	}
}

void delay(int z)
{
	for (int i = 0; i < z; i++)
	{
		for (int j = 0; j < z; j++)
			for (int y = 0; y < z; y++);
	}
}


void head3()
{
	
		char ch;
		int a;
		system("cls");
		do
		{
			printf("\t\t\t\t簡略計算機\n");
			printf("----------------------------------------------------------------------------------------------------------------------\n");
			printf("輸入1進入加法 輸入2進入減法 輸入3進入乘法 輸入4進入除法 輸入5進入次方 輸入6結束程式\n");
			do
			{
				ch = getch();
				a = ch - 0x30;
			} while (a<1 || a>6);
			system("cls");
			if (a != 6)
			{
				a--;
				void(*fuck[5])() = { add, tra, mul, aaa, bbb };
				fuck[a]();
			}
		} while (a != 6);
}

void add()
{
	int b[100], h = 0, i = 0, a, j;
	printf("加法 被加數與加數 輸入0代表等於\n");
	do
	{
		fflush(stdin);
		scanf_s("%d", &b[i]);
		a = b[i];
		i++;
	} while (a != 0 && i < 100);
	i = i - 2;
	for (j = 0; j < i; j++)
		printf("%d+", b[j]);
	printf("%d=", b[j]);
	i = i + 1;
	for (j = 0; j < i; j++)
		h += b[j];
	printf(" %d\n", h);
}
void mul()
{
	int b[100], h = 1, i = 0, a, j;
	printf("乘法 請輸入被乘數與乘數 輸入0代表等於\n");
	do
	{
		fflush(stdin);
		scanf_s("%d", &b[i]);
		a = b[i];
		i++;
	} while (a != 0 && i < 100);
	i = i - 2;
	for (j = 0; j < i; j++)
		printf("%d*", b[j]);
	printf("%d=", b[j]);
	i = i + 1;
	for (j = 0; j < i; j++)
		h *= b[j];
	printf(" %d\n", h);
}
void tra()
{
	int b[100], h = 0, i = 0, a, j;
	printf("減法 請輸入被減數與減數 輸入0代表等於\n");
	do
	{
		fflush(stdin);
		scanf_s("%d", &b[i]);
		a = b[i];
		i++;
	} while (a != 0 && i < 100);
	i = i - 2;
	for (j = 0; j < i; j++)
		printf("%d-", b[j]);
	printf("%d=", b[j]);
	i = i + 1;
	h = b[0];
	for (j = 1; j < i; j++)
		h -= b[j];
	printf(" %d\n", h);
}
void bbb()
{
	int a, b, p;
	printf("我要A的B次方:A = B =\n");
	fflush(stdin);
	scanf_s("%d %d", &a, &b);
	p = pow(a, b);
	printf("%d的%d次方是%d\n", a, b, p);
}
void aaa()
{
	int b[100], h = 0, f = 1, u, i = 0, a, j, o;
	float q, w;
	printf("除法 請輸入被除數與除數 輸入0代表等於\n");
	do
	{
		fflush(stdin);
		scanf_s("%d", &b[i]);
		a = b[i];
		i++;
	} while (a != 0 && i < 100);
	i = i - 2;
	for (j = 0; j < i; j++)
		printf("%d/", b[j]);
	printf("%d=", b[j]);
	i = i + 1;
	h = b[0];
	for (j = 1; j < i; j++)
		h /= b[j];
	i = i - 1;
	for (u = 1; u <= i; u++)
	{
		f *= b[u];
	}
	o = b[0] % f;
	w = b[0];
	q = w / f;
	printf("\n\t\t商數 : %d\n", h);
	printf("\t\t餘數 : %d\n", o);
	printf("\t\t小數 : %f\n", q);
}

void head4()
{

	//#define debug 
	
		char ch;
		int i, A = 0, B = 0;
		int a[4], b[4];
		int level = 0;

		do
		{
			gamestar(&level);
			srand(time(NULL));
			topic(a, level);
#ifdef debug 
			for (i = 0; i < 4; i++)
				printf("%d", a[i]);
			printf("\n");
#endif
			gamming(&A, B, a, b, level);
			gameend(a, A);
			printf("\n按 p 在玩一次\n");
			printf("按 m 回主選單\n");
			do
			{
				ch = getch();
			} while ((ch != 'p') && (ch != 'm'));

		} while (ch == 'p');
}

void gamestar(int *level)
{
	char ch;
	int key;
	system("cls");
	printf("\t\t  數字猜猜猜\n");
	printf("---------------------------------------------------\n");
	printf("請選擇關卡:\n");
	printf("1簡單\t\t\t2.困難\t\t");
	do
	{
		ch = getche();
		key = ch - 0x30;
	} while (key < 1 || key>2);
	*level = key;
	printf("\n---------------------------------------------------\n");
	gamerule(key);
	printf("---------------------------------------------------\n");
	printf("\t\t  遊戲開始\n\n");
}

void gamerule(int level)
{
	printf("遊戲規則如下:\n\n");
	if (level == 1)
		printf("1.猜一不重複的四位數字\n");
	else
		printf("1.猜一四位數字(數字可重複)\n");
	printf("2.每個數都0-9\n");
	printf("3.如果你猜的數字對，但位子不對時，會出現B\n");
	printf("4.如果你猜的數字對，  位子也對時，會出現A\n\n");
	if (level == 1)
		printf("ex:正解4578--->猜8563=====>那會出現1A1B的結果\n\n");
	else
	{
		printf("ex:正解4878--->猜8537=====>那會出現0A2B的結果\n\n");
		printf("ex:正解4878--->猜8573=====>那會出現1A1B的結果\n\n");
	}
	printf("5.只有十次機會\n");
}

void topic(int a[], int level)
{
	int i, j;
	int check = 0;
	for (i = 0; i < 4; i++)
		a[i] = rand() % 10;
	for (i = 0; i < 3; i++)
		for (j = 1; j < 4 - i; j++)
			if (a[i] == a[i + j]) check = 1;
	if (level == 1)
	{
		if (check)
			topic(a, level);
	}
	else
	{
		if (!check)
			topic(a, level);
	}
}

void gamming(int *A, int B, int a[], int b[], int level)
{
	char ch;
	int check, i;
	int n = 0, in;
	while (n++ < 10 && (*A) != 4)
	{
		printf("%2d. ", n);
		do
		{
			check = 0;
			for (i = 0; i < 4; i++)
			{
				do
				{
					ch = getch();
					in = ch - 0x30;
				} while (in < 0 || in > 9);
				b[i] = in;
				printf("%d", in);
			}
			if (level == 1)
			{
				for (i = 0; i < 3; i++)
					for (int j = 1; j < 4 - i; j++)
						if (b[i] == b[i + j])
						{
							check = 1;
						}
			}
			if (check)
			{
				printf("\t輸入錯誤\n");
				printf("%2d. ", n);
			}
		} while (check);
		printf("\t");
		compare(a, b, A, &B);
		printf("\n");
	}
}

void compare(int a[], int b[], int *A, int *B)
{
	*A = 0;
	*B = 0;
	int i, j, z;
	int pos[4] = { 0 };
	for (i = 0; i < 4; i++)
	{
		if (a[i] == b[i])
		{
			(*A)++;
			pos[i] = 1;
		}
	}
	for (i = 0; i < 4; i++)
	{
		if (pos[i] != 1)
		{
			for (j = 0; j < 4; j++)
				if (a[i] == b[j])
				{
					(*B)++;
					break;
				}
		}
	}
	printf("%dA%dB", *A, *B);
}

void gameend(int a[], int e)
{
	int i;
	printf("\n---------------------------------------------------\n");
	printf("\t\t  遊戲結束\n\n");
	if (e == 4)
		printf(" you win\t\t");
	else
		printf(" you lose\t\t");
	printf("The answer is ");
	for (i = 0; i < 4; i++)
		printf("%d", a[i]);
	printf("\n");
}

void head5()
{
		char ch;
		int max1 = 100;
		int min = 1;
		int key;
		int answer;

		do
		{
			system("cls");
			printf("\t  慘無人道的終極密碼\n");
			printf("-----------------------------------------------------\n");
			max1 = 100;
			min = 1;
			srand(time(NULL));
			key = rand() % 100 + 1;
			do
			{
				printf("請輸入從%d到%d的數字:", min, max1);
				fflush(stdin);
				scanf_s("%d", &answer);
				while (answer > max1 || answer < min)
				{
					printf("\n877\n再試一次\n請輸入從%d到%d的數字:", min, max1);
					fflush(stdin);
					scanf_s("%d", &answer);
				}

				if (answer > key)
					max1 = answer;
				if (answer < key)
					min = answer;
			} while (answer != key);
			printf("\n恭喜，可以去買樂透了\n\n");

			printf("\n按 p 在玩一次\n");
			printf("按 m 回主選單\n");
			do
			{
				ch = getch();
			} while ((ch != 'p') && (ch != 'm'));

		} while (ch == 'p');
}

void head6()
{
		char input[64];
		char ch;
		char guessWords[MAXNUMWORDS][MAXWORDLENGTH];
		int WordsReadIn = 0;

		FILE *pToFile = fopen("text.txt", "r");

		if (pToFile == NULL)
		{
			printf("Failed To Open File\n");
			system("pause");
			return 0;
		}

		while (fgets(input, 15, pToFile))
		{
			sscanf(input, "%s", guessWords[WordsReadIn]);
			WordsReadIn++;
		}
		fclose(pToFile);

		do
		{
			game(WordsReadIn, guessWords);
			printf("\n按 p 在玩一次\n");
			printf("按 m 回主選單\n");
			do
			{
				ch = getch();
			} while ((ch != 'p') && (ch != 'm'));
		} while (ch == 'p');
}

void game(int WordsReadIn, char guessWords[][MAXWORDLENGTH])
{
	srand(time(NULL));
	int i, j = 0, z = 0;
	int randomIndex = rand() % WordsReadIn;
	int numCorrect = 0;
	int oldCorrect = 0;
	int lengthOfWord = strlen(guessWords[randomIndex]);
	int hint = rand() % lengthOfWord;
	int letterGuessed[10] = { 0 };
	int key[8] = { 0 };
	int loopIndex;
	char guess, ch;
	char letterEntered = '\0';
	const char error[8] = { { '|' }, { '0' }, { '/' }, { '|' }, { '\\' }, { '|' }, { '/' }, { '\\' } };
	letterGuessed[hint] = 1;
	z++;
	while ((z < lengthOfWord) && (j < 8))
	{
		hangman_diagram(error, key);
		letterGuessed[hint] = 1;
		for (loopIndex = 0; loopIndex < lengthOfWord; loopIndex++)
		{

			if (letterGuessed[loopIndex] == 1)
				printf("%c", guessWords[randomIndex][loopIndex]);
			else
				printf("-");
		}
		printf("\n\t\t\tletterEntered:%c\n", letterEntered);
		printf("\t\t\tEnter a guess letter:");

		fflush(stdin);
		guess = getche();
		numCorrect = 0;
		oldCorrect = 0;
		letterEntered = guess;
		for (loopIndex = 0; loopIndex < lengthOfWord; loopIndex++)
		{
			if (letterGuessed[loopIndex] == 0)
			{
				if ((guessWords[randomIndex][loopIndex] == letterEntered) && (!oldCorrect))
				{
					letterGuessed[loopIndex] = 1;
					z++;
					oldCorrect = 1;
				}
				else if (!numCorrect && !oldCorrect)
				{
					key[j] = 1;
					j++;
					numCorrect = 1;
				}
			}
		}
	}

	hangman_diagram(error, key);

	if (j >= 8)
	{
		printf("\n\t\t\tSorry you lose, the word was:\n\t\t\t%s\n\n",
			guessWords[randomIndex]);
	}
	else
	{
		printf("\n\t\t\tYOU WIN!!! :) the word was:\n\t\t\t%s\n\n",
			guessWords[randomIndex]);
	}
}

void hangman_diagram(const char error[], int key[])
{
	system("cls");
	printf("\n\t\t\tHangman Word:\n");
	printf("----------------------------------------------------------------------\n");
	printf("\t\t\t遊戲規則\n");
	printf("1.請猜一個水果的英文\n");
	printf("2.只有8次答錯的機會\n");
	printf("----------------------------------------------------------------------\n");
	printf("\t\t\t__________\n");
	printf("\t\t\t|   %c\n", key[0] == 1 ? error[0] : '\0');
	printf("\t\t\t|   %c\n", key[1] == 1 ? error[1] : '\0');
	printf("\t\t\t|  %c%c%c\n", key[2] == 1 ? error[2] : '\0', key[3] == 1 ? error[3] : '\0', key[4] == 1 ? error[4] : '\0');
	printf("\t\t\t|   %c\n", key[5] == 1 ? error[5] : '\0');
	printf("\t\t\t|  %c %c\n", key[6] == 1 ? error[6] : '\0', key[7] == 1 ? error[7] : '\0');
	printf("\t\t\t|\n");
	printf("\t\t\t----------\n\n");
	printf("\t\t\t");
}