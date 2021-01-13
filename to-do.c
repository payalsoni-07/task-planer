// This is simply a to-do planner for my weekly goals.
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
typedef  struct data{
    int task_name;
    int task;
    struct time date;
};
struct time{
    int dd;
    int mm;
    int yy;
};
void main(){
    int n,op;
    printf("Hello user, what do you want to do? you can enter your choice by given data below.");
    printf("\nenter 1 for check old to-do list:");
    printf("\nenter 2 for edit to do list:");
    printf("\nenter 3 for create new list:");
    scanf("%d",&op);
    switch op{
        case 1:
            check_list();
            break;
        case 2:
            edit_list();
            break;
        case 3:
            create();
            break;
        default:
            printf("Dear User! you have entered wrong choice.");
    }
}