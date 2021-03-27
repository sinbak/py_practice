# include "omok.h"
<<<<<<< HEAD
int status = WHITE;
int block[20][20]; //2차원 배열 활용
void game_control(void) {
	// 전체적인 게임의 흐름을 제어하는 함수
	show_map();
	move_position();
};

void gotoxy(int x, int y) {
	// 화면상의 커서 위치를 파악하고 제어하는 함수
	COORD pos = { x * 2,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
};

void show_stone(int x, int y) {
	// 바둑돌을 보여주는 함수
	if (block[y][x] == 0) {
		if (status == BLACK) {
			//백돌
			printf("●");
			block[y][x] = BLACK;
			status = WHITE;
		}
		else if (status == WHITE) {
			//흑돌
			printf("○");
			block[y][x] = WHITE;
			status = BLACK;
		}
	}
};

void move_position() {
	// 사용자가 입력하는 화살표 키에 따라 좌표 x, y값을 변경하는 함수
	char loc = 0;
	int x = 0;
	int y = 0;
	while (1)
	{
		gotoxy(x, y);
		//printf("○");
		if (_kbhit())
		{
			loc = _getch();

			switch (loc)
			{
			case 72:
				y--;
				break;
			case 75:
				x--;
				break;
			case 77:
				x++;
				break;
			case 80:
				y++;
				break;
			case 32:
				//printf("○");
				show_stone(x, y);
				break;
			default:
				break;
			}
			//system("cls");
		}

	}
	return;
};

void show_map() {
	//바둑판을 보여주는 함수
	int Row;
	int Col;

	for (Row = 0; Row < 20; Row++) {
		for (Col = 0; Col < 20; Col++) {
			if (Row == 0 && Col == 0)
				printf("┌ ");
			else if (Col == 19 && Row == 0)
				printf("┐ ");
			else if (Col == 0 && Row == 19)
				printf("└ ");
			else if (Col == 19 && Row == 19)
				printf("┘ ");
			else if (Col == 0)
				printf("├ ");
			else if (Col == 19)
				printf("┤ ");
			else if (Row == 0)
				printf("┬ ");
			else if (Row == 19)
				printf("┴ ");
			else
				printf("┼ ");
		}
		printf("\n");
	}
};
=======

int status = BLACK;
int block[20][20] = { 0, };

void game_control(void) {
    // ��ü���� ������ �帧�� �����ϴ� �Լ�
    int x = 9, y = 9;   // x,y ��ǥ ��
    show_map();

    while (1)
    {
        move_position(x, y);
        int stone = Finish(block);
        gotoxy(1, 23);

        if (stone == 0)
        {
            gotoxy(1, 24);
            printf("�������� �̰���ϴ�.\n");
            break;
        }
        else if (stone == 1)
        {
            gotoxy(1, 24);
            printf("���� �̰���ϴ�.\n");
            break;
        }
    };
};

void gotoxy(int x, int y) {
    // ȭ����� Ŀ�� ��ġ�� �ľ��ϰ� �����ϴ� �Լ�
    COORD pos = { x * 2 ,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
};

void show_stone(int x, int y) {
    // �ٵϵ��� �����ִ� �Լ�
    if (block[y][x] == 0) {                        // 2���� �迭�� ���� ���� ��
        if (status == WHITE) {                     // status = �ٵϵ� �� ���� ����(status -> ���� ����)
            printf("��");                        // �����ʸ� �� ����
            block[y][x] = WHITE;                  // 2���� �迭�� �� ǥ�� (block �迭 -> ���� ����)
            status = BLACK;                        // ���� ���� �浹 ���� ����
        }
        else if (status == BLACK) {
            //�浹
            printf("��");
            block[y][x] = BLACK;
            status = WHITE;
        }
    }
}

void move_position(int x, int y) {
    // ����ڰ� �Է��ϴ� ȭ��ǥ Ű�� ���� ��ǥ x, y���� �����ϴ� �Լ�
    char loc;      // Ű �Է� ��

    while (1)
    {
        gotoxy(x, y);
        if (_kbhit())
        {
            loc = _getch();

            switch (loc)
            {
            case 72:         //��   = �ƽ�Ű �ڵ�
                y--;
                break;
            case 75:         // ��  = �ƽ�Ű �ڵ�
                x--;
                break;
            case 77:         // ��  = �ƽ�Ű �ڵ�
                x++;
                break;
            case 80:         //��   = �ƽ�Ű �ڵ�
                y++;
                break;
            case 32: // Space Bar = �ƽ�Ű �ڵ�
                show_stone(x, y);
                goto RE;
            case 8:
                return;
            default:
                break;
            }
        }
    }
    RE:
    return;
};

void show_map() {
    //�ٵ����� �����ִ� �Լ�
    int Row;
    int Col;

    for (Row = 0; Row < 20; Row++) {
        for (Col = 0; Col < 20; Col++) {
            if (Row == 0 && Col == 0)
                printf("�� ");
            else if (Col == 19 && Row == 0)
                printf("�� ");
            else if (Col == 0 && Row == 19)
                printf("�� ");
            else if (Col == 19 && Row == 19)
                printf("�� ");
            else if (Col == 0)
                printf("�� ");
            else if (Col == 19)
                printf("�� ");
            else if (Row == 0)
                printf("�� ");
            else if (Row == 19)
                printf("�� ");
            else
                printf("�� ");
        }
        printf("\n");
    }
};

int Finish(int block[20][20])
{
    int count = 0;

    for (int x = 0; x < 20; x++) {              //���ΰ˻�
        for (int y = 0; y < 20; y++) {
            if (block[x][y] == BLACK)
                count++;
            else
                count = 0;

            if (count == 5) {
                return 0;
            }
        }
    }
    for (int x = 0; x < 20; x++) {              
        for (int y = 0; y < 20; y++) {
            if (block[x][y] == WHITE)
                count++;
            else
                count = 0;

            if (count == 5) {
                return 1;
            }
        }
    }
    for (int y = 0; y < 20; y++) {              //���ΰ˻�
        for (int x = 0; x < 20; x++) {
            if (block[x][y] == BLACK)
                count++;
            else
                count = 0;

            if (count == 5) {
                return 0;
            }
        }
    }
    for (int y = 0; y < 20; y++) {
        for (int x = 0; x < 20; x++) {
            if (block[x][y] == WHITE)
                count++;
            else
                count = 0;

            if (count == 5) {
                return 1;
            }
        }
    }
    for (int x = 0; x < 20; x++)
    {
        for (int y = 0; y < 20; y++)
        {
            int arr1 = x;
            int arr2 = y;

            for (int i = 0; i < 5; i++)
            {
                if (block[arr1++][arr2++] == BLACK) {
                    count++;
                }
                else
                    count = 0;
            }
            if (count == 5)
                return 0;
        }
    }

    for (int x = 0; x <20; x++)
    {
        for (int y = 0; y <20; y++)
        {
            int arr1 = x;
            int arr2 = y;

            for (int i = 0; i < 5; i++)
            {
                if (block[arr1++][arr2++] == WHITE) {
                    count++;
                }
                else
                    count = 0;
            }
            if (count == 5)
                return 1;
        }
    }

    for (int x = 0; x <20; x++)
    {
        for (int y = 0; y <= 20; y++)
        {
            int arr1 = x;
            int arr2 = y;

            for (int i = 0; i < 5; i++)
            {
                if (block[arr1++][arr2--] == BLACK) {
                    count++;
                }
                else
                    count = 0;
            }
            if (count == 5)
                return 0;
        }
    }

    for (int x = 0; x <20; x++)
    {
        for (int y = 0; y <= 20; y++)
        {
            int arr1 = x;
            int arr2 = y;

            for (int i = 0; i < 5; i++)
            {
                if (block[arr1++][arr2--] == WHITE) {
                    count++;
                }
                else
                    count = 0;
            }
            if (count == 5)
                return 1;
        }
    }
    return 3;
}
>>>>>>> c0b4b23a2d708ac96000b59ba44e128889f33a70
