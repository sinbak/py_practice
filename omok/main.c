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



// Import Header file
# include "omok.h"

// Main Function
void printMenu() {
    printf("�١ڡ١ڡ١�CMD Winter Mini project�ڡ١ڡ١ڡ�\n");
    printf("===================  Team B  ===================\n");
    printf("1. ��Ģ\n");
    printf("2. ����\n");
    printf("3. ����\n");
    printf("===================  Team B  ===================\n");
    printf("���� �Է� : ");
}
int main() {

    int game = 1;
    char input = '0';
    while (game == 1) {

        printMenu();

        scanf_s("%c", &input);
        getchar();
        switch (input) {
            case '1':
                system("cls");
                printf("============== CMD W M P Team B  ==============\n\n");
                printf("- spacebar�� ������ ���� ���� �� �ֽ��ϴ�..\n");
                printf("- ������ ���� ���� ���� �����մϴ�.\n");
                printf("- ����, ����, �밢�� �������� ������ ���� 5���� �̾��� ��� �¸��ϰ� �˴ϴ�.\n\n");
                break;

            case '2':
                system("cls");
                game_control();
                break;

            case '3':
                game = 0;
                break;

        }

    }

    return 0;
}