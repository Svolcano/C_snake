/*
* snake.c (1.0)
* ̰���ߵ�ʵ��
*
* By Eric-JR Chen
* diamont1001@163.com
* 2011��2��
*/

#include "snake.h"
#include <string.h>

//ʳ���
Point FoodPool[ROW*COL];

/* ��ʼ��foodpool */
void initFoodPool(void){
    int i = 0;
    for(i=0; i<ROW*COL; i++){
        FoodPool[i].x = (i * 2) % (COL * 2);
        FoodPool[i].y = i / COL;
        FoodPool[i].flag = 1;
    }
}

/* ��ʳ����Ϊ������ */
void useFood(int x, int y){
    FoodPool[x/2 + y*COL].flag = 0;
}

/* ��ʳ����Ϊ���� */
void unuseFood(int x, int y){
    FoodPool[x/2 + y*COL].flag = 1;
}

/* ����foodpool */
void updateFoodpool(void){
    SNAKE ps = pSnakeHead;
    initFoodPool();
    while(ps){
        useFood(ps->node.x, ps->node.y);
        ps = ps->next;
    }
}

/* ����ʳ�� */
int GetFood(void){
    int i = JR_randomIn(ROW*COL-1);
    int tmp = i, flag = 0;
    while(!FoodPool[tmp].flag){
        if(!flag){
            if(tmp > 0) tmp --;
            else{
                tmp = i;
                flag = 1;
            }
        }else{
            if(tmp < COL-1) tmp ++;
            else return 0;
        }
    }
    useFood(FoodPool[tmp].x, FoodPool[tmp].y);
    FoodPool[tmp].flag = 1;
    FOOD.x = FoodPool[tmp].x;
    FOOD.y = FoodPool[tmp].y;
    return 1;
}

/* Add Snake Node into link */
void AddSNode(SNAKE psa){
    useFood(psa->node.x, psa->node.y);
    strcpy(pSnakeTail->node.text, BODY);
    pSnakeTail->next = psa;
    pSnakeTail = psa;
    pSnakeTail->next = NULL;
    strcpy(pSnakeTail->node.text, BODY_HEAD);
}

/* Del Snake Node from link */
void DelSNode(void){
    SNAKE p = pSnakeHead;
    unuseFood(p->node.x, p->node.y);
    pSnakeHead = pSnakeHead->next;
    free(p);
}

/* ��ʼ��snake���� */
void InitSnake(int n){
    int i = 0;
    initFoodPool();
    memset(FOOD.text, 0, sizeof(FOOD.text));
    strcpy(FOOD.text, BODY_FOOD);

    pSnakeTail = malloc(sizeof(SNAKENODE));
    pSnakeTail->node.x = 0;
    pSnakeTail->node.y = 0;
    strcpy(pSnakeTail->node.text, BODY);
    pSnakeTail->next = NULL;
    pSnakeHead = pSnakeTail;
    useFood(pSnakeTail->node.x, pSnakeTail->node.y);

    for(i=1; i<n; i++){
        SNAKE psa = malloc(sizeof(SNAKENODE));
        psa->node.x = i * 2;
        psa->node.y = 0;
        strcpy(psa->node.text, BODY);
        psa->next = NULL;
        AddSNode(psa);
    }
}

/* ���snake�Ϸ��� */
int checkSnake(void){
    if(pSnakeTail->node.x < 0 || pSnakeTail->node.x > (COL-1)*2 || pSnakeTail->node.y < 0 || pSnakeTail->node.y > ROW-1)
        return 0;
    SNAKE ps = pSnakeHead;
    while(ps != pSnakeTail){
        if(ps->node.x == pSnakeTail->node.x && ps->node.y == pSnakeTail->node.y)
            return 0;
        ps = ps->next;
    }
    return 1;
}

/* ���snake��Դ */
void DeleteSnake(void){
    SNAKE tp = pSnakeHead, tp1 = NULL;
    while(tp != pSnakeTail){
        tp1 = tp->next;
        free(tp);
        tp = tp1;
    }
}
