/*
* snake.h (1.0)
* ̰�������ݽṹ�������붨��
*
* By Eric-JR Chen
* diamont1001@163.com
* 2011��2��
*/

#ifndef SNAKE_H
#define SNAKE_H

#include <stdlib.h>
#include "main.h"

/* ��Ϸ��Դ */
extern const char *BG;
extern const char *BODY;
extern const char *BODY_HEAD;
extern const char *BODY_FOOD;

typedef struct _SHOWNODE
{
    int x;
    int y;
    char text[3];
}SHOWNODE;

typedef struct _SNAKE
{
    SHOWNODE node;
    struct _SNAKE *next;
}*SNAKE, SNAKENODE;

typedef struct _POINT
{
    int x;
    int y;
    int flag;
}Point;

SHOWNODE FOOD;      //ʳ��
SNAKE pSnakeHead, pSnakeTail;   //�߽ڵ�ָ��

/* ��ʼ��foodpool */
void initFoodPool(void);

/* ��ʳ����Ϊ������ */
void useFood(int x, int y);

/* ��ʳ����Ϊ���� */
void unuseFood(int x, int y);

/* ����foodpool */
void updateFoodpool(void);

/* ����һ��ʳ�� */
int GetFood(void);

/* Add Snake Node into link */
void AddSNode(SNAKE psa);

/* Del Snake Node from link */
void DelSNode(void);

/* ��ʼ��snake���� */
void InitSnake(int n);

/* ���snake�Ϸ��� */
int checkSnake(void);

/* ���snake��Դ */
void DeleteSnake(void);
#endif
