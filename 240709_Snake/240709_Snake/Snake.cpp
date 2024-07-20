#include "Snake.h"

//���ù�������
void SetPos(short x, short y)
{
    COORD pos = { x, y };
    HANDLE hOutput = NULL;
    //��ȡ��׼����ľ��(������ʶ��ͬ�豸����ֵ)
    hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    //���ñ�׼����Ϲ���λ��Ϊpos
    SetConsoleCursorPosition(hOutput, pos);
}

void WelcomeToGame()
{
    SetPos(40, 15);
    printf("��ӭ����̰����С��Ϸ");
    SetPos(40, 25);//�ð�����������ĳ��ֵ�λ�úÿ���
    system("pause");
    system("cls");
    SetPos(25, 12);
    printf("�� �� . �� . �� . �� �ֱ�����ߵ��ƶ��� F3Ϊ���٣�F4Ϊ����\n");
    SetPos(25, 13);
    printf("���ٽ��ܵõ����ߵķ�����\n");
    SetPos(40, 25);//�ð�����������ĳ��ֵ�λ�úÿ���
    system("pause");
    system("cls");
}

void CreateMap()
{
    int i = 0;
    //��(0,0)-(56, 0)
    SetPos(0, 0);
    for (i = 0; i < 58; i += 2)
    {
        wprintf(L"%c", WALL);
    }
    //��(0,26)-(56, 26)
    SetPos(0, 26);
    for (i = 0; i < 58; i += 2)
    {
        wprintf(L"%c", WALL);
    }
    //��
    //x��0��y��1��ʼ����
    for (i = 1; i < 26; i++)
    {
        SetPos(0, i);
        wprintf(L"%c", WALL);
    }
    //x��56��y��1��ʼ����
    for (i = 1; i < 26; i++)
    {
        SetPos(56, i);
        wprintf(L"%c", WALL);
    }
}


void InitSnake(pSnake ps)
{
    pSnakeNode cur = NULL;
    int i = 0;
    //��������ڵ㣬����ʼ������
    //ͷ�巨
    for (i = 0; i < 5; i++)
    {
        //��������Ľڵ�
        cur = (pSnakeNode)malloc(sizeof(SnakeNode));
        if (cur == NULL)
        {
            perror("InitSnake()::malloc()");
            return;
        }
        //��������
        cur->next = NULL;
        cur->x = POS_X + i * 2;
        cur->y = POS_Y;

        //ͷ�巨
        if (ps->_pSnake == NULL)
        {
            ps->_pSnake = cur;
        }
        else
        {
            cur->next = ps->_pSnake;
            ps->_pSnake = cur;
        }
    }

    //��ӡ�ߵ�����
    cur = ps->_pSnake;
    while (cur)
    {
        SetPos(cur->x, cur->y);
        wprintf(L"%c", BODY);
        cur = cur->next;
    }

    //��ʼ��̰��������
    ps->_SleepTime = 200;
    ps->_Socre = 0;
    ps->_Status = OK;
    ps->_Dir = RIGHT;
    ps->_Add = 10;
}



void CreateFood(pSnake ps)
{
    int x = 0;
    int y = 0;

again:
    //������x����Ӧ����2�ı����������ſ��ܺ���ͷ������롣
    do
    {
        x = rand() % 53 + 2;
        y = rand() % 25 + 1;
    } while (x % 2 != 0);

    pSnakeNode cur = ps->_pSnake;//��ȡָ����ͷ��ָ��
    //ʳ�ﲻ�ܺ������ͻ
    while (cur)
    {
        if (cur->x == x && cur->y == y)
        {
            goto again;
        }
        cur = cur->next;
    }

    pSnakeNode pFood = (pSnakeNode)malloc(sizeof(SnakeNode)); //����ʳ��
    if (pFood == NULL)
    {
        perror("CreateFood::malloc()");
        return;
    }
    else
    {
        pFood->x = x;
        pFood->y = y;
        SetPos(pFood->x, pFood->y);
        wprintf(L"%c", FOOD);
        ps->_pFood = pFood;
    }
}

void PrintHelpInfo()
{
    //��ӡ��ʾ��Ϣ
    SetPos(64, 15);
    printf("���ܴ�ǽ������ҧ���Լ�\n");
    SetPos(64, 16);
    printf("�á�.��.��.���ֱ�����ߵ��ƶ�.");
    SetPos(64, 17);
    printf("F1 Ϊ���٣�F2 Ϊ����\n");
    SetPos(64, 18);
    printf("ESC ���˳���Ϸ.space����ͣ��Ϸ.");
}

void pause()//��ͣ
{
    while (1)
    {
        Sleep(300);
        if (KEY_PRESS(VK_SPACE))
        {
            break;
        }
    }
}

//pSnakeNode psn ����һ���ڵ�ĵ�ַ
//pSnake ps ά���ߵ�ָ��
int NextIsFood(pSnakeNode psn, pSnake ps)
{
    return (psn->x == ps->_pFood->x) && (psn->y == ps->_pFood->y);
}

//pSnakeNode psn ����һ���ڵ�ĵ�ַ
//pSnake ps ά���ߵ�ָ��
void EatFood(pSnakeNode psn, pSnake ps)
{
    //ͷ�巨
    psn->next = ps->_pSnake;
    ps->_pSnake = psn;
    pSnakeNode cur = ps->_pSnake;
    //��ӡ��
    while (cur)
    {
        SetPos(cur->x, cur->y);
        wprintf(L"%c", BODY);
        cur = cur->next;
    }
    ps->_Socre += ps->_Add;

    free(ps->_pFood);
    CreateFood(ps);
}

//pSnakeNode psn ����һ���ڵ�ĵ�ַ
//pSnake ps ά���ߵ�ָ��
void NoFood(pSnakeNode psn, pSnake ps)
{
    //ͷ�巨
    psn->next = ps->_pSnake;
    ps->_pSnake = psn;
    pSnakeNode cur = ps->_pSnake;
    //��ӡ��
    while (cur->next->next)
    {
        SetPos(cur->x, cur->y);
        wprintf(L"%c", BODY);
        cur = cur->next;
    }
    SetPos(cur->x, cur->y);
    wprintf(L"%c", BODY);
    //���һ��λ�ô�ӡ�ո�Ȼ���ͷŽڵ�
    SetPos(cur->next->x, cur->next->y);
    printf("  ");
    free(cur->next);
    cur->next = NULL;
}

//pSnake ps ά���ߵ�ָ��
int KillByWall(pSnake ps)
{
    if ((ps->_pSnake->x == 0)
        || (ps->_pSnake->x == 56)
        || (ps->_pSnake->y == 0)
        || (ps->_pSnake->y == 26))
    {
        ps->_Status = KILL_BY_WALL;
        return 1;
    }
    return 0;
}

//pSnake ps ά���ߵ�ָ��
int KillBySelf(pSnake ps)
{
    pSnakeNode cur = ps->_pSnake->next;
    while (cur)
    {
        if ((ps->_pSnake->x == cur->x)
            && (ps->_pSnake->y == cur->y))
        {
            ps->_Status = KILL_BY_SELF;
            return 1;
        }
        cur = cur->next;
    }
    return 0;
}


void SnakeMove(pSnake ps)
{
    //������һ���ڵ�
    pSnakeNode pNextNode = (pSnakeNode)malloc(sizeof(SnakeNode));
    if (pNextNode == NULL)
    {
        perror("SnakeMove()::malloc()");
        return;
    }
    //ȷ����һ���ڵ�����꣬��һ���ڵ��������ݣ���ͷ������ͷ���ȷ��
    switch (ps->_Dir)
    {
    case UP:
    {
        pNextNode->x = ps->_pSnake->x;
        pNextNode->y = ps->_pSnake->y - 1;
    }
    break;
    case DOWN:
    {
        pNextNode->x = ps->_pSnake->x;
        pNextNode->y = ps->_pSnake->y + 1;
    }
    break;
    case LEFT:
    {
        pNextNode->x = ps->_pSnake->x - 2;
        pNextNode->y = ps->_pSnake->y;
    }
    break;
    case RIGHT:
    {
        pNextNode->x = ps->_pSnake->x + 2;
        pNextNode->y = ps->_pSnake->y;
    }
    break;
    }

    //�����һ��λ�þ���ʳ��
    if (NextIsFood(pNextNode, ps))
    {
        EatFood(pNextNode, ps);
    }
    else//���û��ʳ��
    {
        NoFood(pNextNode, ps);
    }

    KillByWall(ps);
    KillBySelf(ps);
}



void GameStart(pSnake ps)
{
    //���ÿ���̨���ڵĴ�С��30�У�100��
    //mode ΪDOS����
    system("mode con cols=100 lines=30");
    //����cmd��������
    system("title ̰����");

    //��ȡ��׼����ľ��(������ʶ��ͬ�豸����ֵ)
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    //Ӱ�ع�����
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(hOutput, &CursorInfo);//��ȡ����̨�����Ϣ
    CursorInfo.bVisible = false; //���ؿ���̨���
    SetConsoleCursorInfo(hOutput, &CursorInfo);//���ÿ���̨���״̬

    //��ӡ��ӭ����
    WelcomeToGame();
    //��ӡ��ͼ
    CreateMap();
    //��ʼ����
    InitSnake(ps);
    //�����һ��ʳ��
    CreateFood(ps);
}


void GameRun(pSnake ps)
{
    //��ӡ�Ҳ������Ϣ
    PrintHelpInfo();
    do
    {
        SetPos(64, 10);
        printf("�÷֣�%d ", ps->_Socre);
        printf("ÿ��ʳ��÷֣�%d��", ps->_Add);
        if (KEY_PRESS(VK_UP) && ps->_Dir != DOWN)
        {
            ps->_Dir = UP;
        }
        else if (KEY_PRESS(VK_DOWN) && ps->_Dir != UP)
        {
            ps->_Dir = DOWN;
        }
        else if (KEY_PRESS(VK_LEFT) && ps->_Dir != RIGHT)
        {
            ps->_Dir = LEFT;
        }
        else if (KEY_PRESS(VK_RIGHT) && ps->_Dir != LEFT)
        {
            ps->_Dir = RIGHT;
        }
        else if (KEY_PRESS(VK_SPACE))
        {
            pause();
        }
        else if (KEY_PRESS(VK_ESCAPE))
        {
            ps->_Status = END_NOMAL;
            break;
        }
        else if (KEY_PRESS(VK_F3))
        {
            if (ps->_SleepTime >= 50)
            {
                ps->_SleepTime -= 30;
                ps->_Add += 2;
            }
        }
        else if (KEY_PRESS(VK_F4))
        {
            if (ps->_SleepTime < 350)
            {
                ps->_SleepTime += 30;
                ps->_Add -= 2;
                if (ps->_SleepTime == 350)
                {
                    ps->_Add = 1;
                }
            }
        }
        //��ÿ��һ��֮��Ҫ���ߵ�ʱ�䣬ʱ��̣����ƶ��ٶȾͿ�
        Sleep(ps->_SleepTime);
        SnakeMove(ps);

    } while (ps->_Status == OK);
}

void GameEnd(pSnake ps)
{
    pSnakeNode cur = ps->_pSnake;
    SetPos(24, 12);
    switch (ps->_Status)
    {
    case END_NOMAL:
        printf("�������˳���Ϸ\n");
        break;
    case KILL_BY_SELF:
        printf("��ײ���Լ��� ,��Ϸ����!\n");
        break;
    case KILL_BY_WALL:
        printf("��ײǽ��,��Ϸ����!\n");
        break;
    }

    //�ͷ�����Ľڵ�
    while (cur)
    {
        pSnakeNode del = cur;
        cur = cur->next;
        free(del);
    }
}