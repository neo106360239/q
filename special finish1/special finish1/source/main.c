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
		printf("\t\t\t\t�T�T!  �U����");
	} while (choic != 7);

	printf("\n");
	system("pause");
	return 0;
}

void print1()
{
	system("cls");
	printf("\t\t\t\t�п�ܷQ�n���\��\n");
	printf("-----------------------------------------------------------------------------------------\n");
	printf("1���|�۰ʲ��ʪ��g�Y�D\t\t\t2.�x���Y���v��\t\t\t3.²���p���\n"
		"4.�Ʀr�q�q�q\t\t\t\t5.�G�L�H�D���׷��K�X\t\t\t6.hangman\n"
		"7.�����C��\n\n");
}

void head1()
{
		char ch;
		do
		{
			srand(time(NULL));
			game1();
			printf("\n�� p �b���@��\n");
			printf("�� m �^�D���\n");
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
		int a, b,/*�D����l�I*/ a1, b1,/*�I�I���y��*/ i/*�]�^���*/, d = 5/*�D����l����*/, n = 0/*�P�_�O�_���^��*/;
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
	printf("\t\t���|�۰ʲ��ʪ��g�Y�D\n");
	printf("\t\t   �� e �i�j������\n");
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
			printf("\n�� p �b���@��\n");
			printf("�� m �^�D���\n");
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
	printf("\t\t\t�x���Y���v��\n");
	printf("-------------------------------------------------------------\n");
	do
	{
		printf("�п�J�x�Ϊ��j�p(MAX=25,min=5):");
		fflush(stdin);
		scanf_s("%d", &b);
	} while (b > 25 || b < 5);

	do
	{
		printf("�Y�񪺦���(1-10��):");
		fflush(stdin);
		scanf_s("%d", &w);
	} while (w<1 || w>10);

	do
	{
		printf("��ܼƫ�(1.��  2.��  3.�C):");
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
			printf("\t\t\t\t²���p���\n");
			printf("----------------------------------------------------------------------------------------------------------------------\n");
			printf("��J1�i�J�[�k ��J2�i�J��k ��J3�i�J���k ��J4�i�J���k ��J5�i�J���� ��J6�����{��\n");
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
	int b[1000], h = 0, i = 0, a, j;
	printf("�[�k �Q�[�ƻP�[�� ��J0�N����\n");
	do
	{
		fflush(stdin);
		scanf_s("%d", &b[i]);
		a = b[i];
		i++;
	} while (a != 0 && i < 1000);
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
	printf("���k �п�J�Q���ƻP���� ��J0�N����\n");
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
	printf("��k �п�J�Q��ƻP��� ��J0�N����\n");
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
	printf("�ڭnA��B����:A = B =\n");
	fflush(stdin);
	scanf_s("%d %d", &a, &b);
	p = pow(a, b);
	printf("%d��%d����O%d\n", a, b, p);
}
void aaa()
{
	int b[100], h = 0, f = 1, u, i = 0, a, j, o;
	float q, w;
	printf("���k �п�J�Q���ƻP���� ��J0�N����\n");
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
	printf("\n\t\t�Ӽ� : %d\n", h);
	printf("\t\t�l�� : %d\n", o);
	printf("\t\t�p�� : %f\n", q);
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
			printf("\n�� p �b���@��\n");
			printf("�� m �^�D���\n");
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
	printf("\t\t  �Ʀr�q�q�q\n");
	printf("---------------------------------------------------\n");
	printf("�п�����d:\n");
	printf("1²��\t\t\t2.�x��\t\t");
	do
	{
		ch = getche();
		key = ch - 0x30;
	} while (key < 1 || key>2);
	*level = key;
	printf("\n---------------------------------------------------\n");
	gamerule(key);
	printf("---------------------------------------------------\n");
	printf("\t\t  �C���}�l\n\n");
}

void gamerule(int level)
{
	printf("�C���W�h�p�U:\n\n");
	if (level == 1)
		printf("1.�q�@�����ƪ��|��Ʀr\n");
	else
		printf("1.�q�@�|��Ʀr(�Ʀr�i����)\n");
	printf("2.�C�ӼƳ�0-9\n");
	printf("3.�p�G�A�q���Ʀr��A����l����ɡA�|�X�{B\n");
	printf("4.�p�G�A�q���Ʀr��A  ��l�]��ɡA�|�X�{A\n\n");
	if (level == 1)
		printf("ex:����4578--->�q8563=====>���|�X�{1A1B�����G\n\n");
	else
	{
		printf("ex:����4878--->�q8537=====>���|�X�{0A2B�����G\n\n");
		printf("ex:����4878--->�q8573=====>���|�X�{1A1B�����G\n\n");
	}
	printf("5.�u���Q�����|\n");
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
				printf("\t��J���~\n");
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
	printf("\t\t  �C������\n\n");
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
			printf("\t  �G�L�H�D���׷��K�X\n");
			printf("-----------------------------------------------------\n");
			max1 = 100;
			min = 1;
			srand(time(NULL));
			key = rand() % 100 + 1;
			do
			{
				printf("�п�J�q%d��%d���Ʀr:", min, max1);
				fflush(stdin);
				scanf_s("%d", &answer);
				while (answer > max1 || answer < min)
				{
					printf("\n877\n�A�դ@��\n�п�J�q%d��%d���Ʀr:", min, max1);
					fflush(stdin);
					scanf_s("%d", &answer);
				}

				if (answer > key)
					max1 = answer;
				if (answer < key)
					min = answer;
			} while (answer != key);
			printf("\n���ߡA�i�H�h�R�ֳz�F\n\n");

			printf("\n�� p �b���@��\n");
			printf("�� m �^�D���\n");
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
			printf("\n�� p �b���@��\n");
			printf("�� m �^�D���\n");
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
	printf("\t\t\t�C���W�h\n");
	printf("1.�вq�@�Ӥ��G���^��\n");
	printf("2.�u��8�����������|\n");
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