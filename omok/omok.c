# include "omok.h"
<<<<<<< HEAD
int status = WHITE;
int block[20][20]; //2ì°¨ì› ë°°ì—´ í™œìš©
void game_control(void) {
	// ì „ì²´ì ì¸ ê²Œìž„ì˜ íë¦„ì„ ì œì–´í•˜ëŠ” í•¨ìˆ˜
	show_map();
	move_position();
};

void gotoxy(int x, int y) {
	// í™”ë©´ìƒì˜ ì»¤ì„œ ìœ„ì¹˜ë¥¼ íŒŒì•…í•˜ê³  ì œì–´í•˜ëŠ” í•¨ìˆ˜
	COORD pos = { x * 2,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
};

void show_stone(int x, int y) {
	// ë°”ë‘‘ëŒì„ ë³´ì—¬ì£¼ëŠ” í•¨ìˆ˜
	if (block[y][x] == 0) {
		if (status == BLACK) {
			//ë°±ëŒ
			printf("â—");
			block[y][x] = BLACK;
			status = WHITE;
		}
		else if (status == WHITE) {
			//í‘ëŒ
			printf("â—‹");
			block[y][x] = WHITE;
			status = BLACK;
		}
	}
};

void move_position() {
	// ì‚¬ìš©ìžê°€ ìž…ë ¥í•˜ëŠ” í™”ì‚´í‘œ í‚¤ì— ë”°ë¼ ì¢Œí‘œ x, yê°’ì„ ë³€ê²½í•˜ëŠ” í•¨ìˆ˜
	char loc = 0;
	int x = 0;
	int y = 0;
	while (1)
	{
		gotoxy(x, y);
		//printf("â—‹");
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
				//printf("â—‹");
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
	//ë°”ë‘‘íŒì„ ë³´ì—¬ì£¼ëŠ” í•¨ìˆ˜
	int Row;
	int Col;

	for (Row = 0; Row < 20; Row++) {
		for (Col = 0; Col < 20; Col++) {
			if (Row == 0 && Col == 0)
				printf("â”Œ ");
			else if (Col == 19 && Row == 0)
				printf("â” ");
			else if (Col == 0 && Row == 19)
				printf("â”” ");
			else if (Col == 19 && Row == 19)
				printf("â”˜ ");
			else if (Col == 0)
				printf("â”œ ");
			else if (Col == 19)
				printf("â”¤ ");
			else if (Row == 0)
				printf("â”¬ ");
			else if (Row == 19)
				printf("â”´ ");
			else
				printf("â”¼ ");
		}
		printf("\n");
	}
};
=======

int status = BLACK;
int block[20][20] = { 0, };

void game_control(void) {
    // ÀüÃ¼ÀûÀÎ °ÔÀÓÀÇ Èå¸§À» Á¦¾îÇÏ´Â ÇÔ¼ö
    int x = 9, y = 9;   // x,y ÁÂÇ¥ °ª
    show_map();

    while (1)
    {
        move_position(x, y);
        int stone = Finish(block);
        gotoxy(1, 23);

        if (stone == 0)
        {
            gotoxy(1, 24);
            printf("°ËÀºµ¹ÀÌ ÀÌ°å½À´Ï´Ù.\n");
            break;
        }
        else if (stone == 1)
        {
            gotoxy(1, 24);
            printf("Èòµ¹ÀÌ ÀÌ°å½À´Ï´Ù.\n");
            break;
        }
    };
};

void gotoxy(int x, int y) {
    // È­¸é»óÀÇ Ä¿¼­ À§Ä¡¸¦ ÆÄ¾ÇÇÏ°í Á¦¾îÇÏ´Â ÇÔ¼ö
    COORD pos = { x * 2 ,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
};

void show_stone(int x, int y) {
    // ¹ÙµÏµ¹À» º¸¿©ÁÖ´Â ÇÔ¼ö
    if (block[y][x] == 0) {                        // 2Â÷¿ø ¹è¿­¿¡ µ¹ÀÌ ¾øÀ» ¶§
        if (status == WHITE) {                     // status = ¹ÙµÏµ¹ »ö ³õ´Â ¼ø¼­(status -> Àü¿ª º¯¼ö)
            printf("¡Ü");                        // Èòµ¹Â÷·Ê¸é Èòµ¹ ³õ±â
            block[y][x] = WHITE;                  // 2Â÷¿ø ¹è¿­¿¡ Èòµ¹ Ç¥½Ã (block ¹è¿­ -> Àü¿ª º¯¼ö)
            status = BLACK;                        // ´ÙÀ½ Â÷·Ê Èæµ¹ Â÷·Ê º¯°æ
        }
        else if (status == BLACK) {
            //Èæµ¹
            printf("¡Û");
            block[y][x] = BLACK;
            status = WHITE;
        }
    }
}

void move_position(int x, int y) {
    // »ç¿ëÀÚ°¡ ÀÔ·ÂÇÏ´Â È­»ìÇ¥ Å°¿¡ µû¶ó ÁÂÇ¥ x, y°ªÀ» º¯°æÇÏ´Â ÇÔ¼ö
    char loc;      // Å° ÀÔ·Â °ª

    while (1)
    {
        gotoxy(x, y);
        if (_kbhit())
        {
            loc = _getch();

            switch (loc)
            {
            case 72:         //¡è   = ¾Æ½ºÅ° ÄÚµå
                y--;
                break;
            case 75:         // ¡ç  = ¾Æ½ºÅ° ÄÚµå
                x--;
                break;
            case 77:         // ¡æ  = ¾Æ½ºÅ° ÄÚµå
                x++;
                break;
            case 80:         //¡é   = ¾Æ½ºÅ° ÄÚµå
                y++;
                break;
            case 32: // Space Bar = ¾Æ½ºÅ° ÄÚµå
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
    //¹ÙµÏÆÇÀ» º¸¿©ÁÖ´Â ÇÔ¼ö
    int Row;
    int Col;

    for (Row = 0; Row < 20; Row++) {
        for (Col = 0; Col < 20; Col++) {
            if (Row == 0 && Col == 0)
                printf("¦£ ");
            else if (Col == 19 && Row == 0)
                printf("¦¤ ");
            else if (Col == 0 && Row == 19)
                printf("¦¦ ");
            else if (Col == 19 && Row == 19)
                printf("¦¥ ");
            else if (Col == 0)
                printf("¦§ ");
            else if (Col == 19)
                printf("¦© ");
            else if (Row == 0)
                printf("¦¨ ");
            else if (Row == 19)
                printf("¦ª ");
            else
                printf("¦« ");
        }
        printf("\n");
    }
};

int Finish(int block[20][20])
{
    int count = 0;

    for (int x = 0; x < 20; x++) {              //°¡·Î°Ë»ç
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
    for (int y = 0; y < 20; y++) {              //¼¼·Î°Ë»ç
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
