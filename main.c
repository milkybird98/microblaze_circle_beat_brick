//
//  main.c
//  xyz_caculater
//
//  Created by 袁若宸 on 2019/6/10.
//  Copyright © 2019年 yrc. All rights reserved.
//

#include <stdio.h>
#include "math.h"

#define ;

typedef struct _BoardPositionStatus {
    int x;
    int y;
    int raw_x;
    int raw_y;
    int pow_x;
    int pow_y;
    int dest;//　0-》1象限；1-》2象限；2-》3x象限；3-〉4象限；4->原点
    int pre_x;
    int pre_y;
    int speed;
}BoardPositionStatus;

typedef struct _SlashPositionStatus{
    int x;
    int y;
    int base_length;
    int decrease_length;
}SlashPositionStatus;

typedef struct _ball{
    int x;
    int y;
}ball;

typedef struct _brick{
    int tag;
    
}brick;

int main(int argc, const char * argv[]) {
    return 0;
}

void InitialPositionData(BoardPositionStatus *board_positon){
    board_positon->pow_x=-1;
    board_positon->pow_y=-1;
    board_positon->pre_x=-1;
    board_positon->pre_y=-1;
    board_positon->x=-1;
    board_positon->y=-1;
    board_positon->dest=-1;
    board_positon->speed=-1;
    board_positon->raw_x=-1;
    board_positon->raw_y=-1;
}



void CalculatePositionData(BoardPositionStatus *board_positon){
    if(board_positon->raw_x!=-1&&board_positon->raw_y!=-1){
        int pow_of_raw_x=pow(board_positon->raw_x,2);
        int pow_of_raw_y=pow(board_positon->raw_y,2);
        board_positon->pow_x=10000*pow_of_raw_x/(pow_of_raw_x+pow_of_raw_y);
        board_positon->pow_y=10000*pow_of_raw_y/(pow_of_raw_x+pow_of_raw_y);
    }
    
    if(board_positon->x!=-1&&board_positon->y!=-1){
        board_positon->pre_x=board_positon->x;
        board_positon->pre_y=board_positon->y;
    }

    if(board_positon->pow_x!=-1&&board_positon->pow_y!=-1){
        board_positon->x=sqrt(board_positon->pow_x);
        board_positon->y=sqrt(board_positon->pow_y);
    }
    
    if(board_positon->pre_x!=-1&&board_positon->pre_y!=-1){
        board_positon->speed=pow(board_positon->x - board_positon->pre_x,2)+pow(board_positon->y - board_positon->pre_y,2);
    }
    
    if(board_positon->raw_x>=0 && board_positon->raw_y>0)
        board_positon->dest=0;
    else if (board_positon->raw_x<0 && board_positon->raw_y>=0)
        board_positon->dest=1;
    else if (board_positon->raw_x<=0 && board_positon->raw_y<0)
        board_positon->dest=2;
    else if (board_positon->raw_x>0 && board_positon->raw_y<=0)
        board_positon->dest=3;
    else
        board_positon->dest=4;
    
}

void InitialSlash(SlashPositionStatus *slash_position){
    slash_position->x=-1;
    slash_position->y=-1;
    slash_position->base_length=100;
    slash_position->decrease_length=0;
}

void CalculateSlash(SlashPositionStatus *slash_position,BoardPositionStatus *board_position){
    slash_position->x=512+0.7*board_position->x;
    slash_position->y=256-0.7*board_position->y;//计左上角为原点，y轴正方向向下，x轴正方向向右
    slash_position->decrease_length=512*board_position->speed;
                                                //板子长度减少量与紧张度的换算，需要修改
    
}

void clash(ball *ball){
    
}

