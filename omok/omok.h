#pragma once
/*
============================================================
                    CMD_Winter Mini Ptj
    1. ��� �� : Starter Season_Winter_Team_A, B
    2. ptj ���� : ����
    3. �ش� ��� ��
        01. ���� ��Ģ �����ֱ�
        02. �ٵ��� ǥ���ϱ�
        03. ȭ��ǥ Ű�� ���� �ٵϵ��� ��ġ�� ����ǰ� �ϰ� �����̽��ٸ� �̿��� �ٵϵ� ����
        04. ������ ���и� ������ �� �ֱ�
============================================================
*/

# ifndef OMOK_H
# define OMOK_H
// Import Header file

# include <stdio.h>
# include <stdlib.h>
# include <conio.h>
# include <windows.h>

#define BLACK 1
#define WHITE 2

// Custom Function Declaration
void game_control(void);
void gotoxy(int x, int y);
void show_stone(int x, int y);
<<<<<<< HEAD
void move_position();
=======
void move_position(int x, int y);
>>>>>>> c0b4b23a2d708ac96000b59ba44e128889f33a70
void show_map();
int Finish(int block[20][20]);
// etc...



# endif