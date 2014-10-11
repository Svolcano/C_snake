/*
* main.h (1.0)
* ̰������Ϸ��Դ�����ݽṹ�������붨��
*
* By Eric-JR Chen
* diamont1001@163.com
* 2011��2��
*/

#ifndef MAIN_H
#define MAIN_H

#include "JR_timer.h"
#include "JR_Random.h"
#include "JR_Cursor.h"
#include "JR_KeyBoard.h"
#include "snake.h"


/* ������ */
#define ROW 20
#define COL 20

/* ��Ϸ״̬ */
typedef enum _STATUS{
    WELCOME, GAMING, DIE, PAUSE, STOP
}STATUS;

/* ���� */
typedef enum _DIRECTION{
    UP, DOWN, LEFT, RIGHT
}DIRECTION;

#endif
