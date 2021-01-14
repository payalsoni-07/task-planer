// This is simply a to-do planner for my weekly goals.
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
//functions
//void check_list();
void edit_list(); 
void create();
char task_name[10];
char task[100];
void main(){
    int n,op;
    printf("Hello user, what do you want to do? you can enter your choice by given data below.");
    printf("\nenter 1 for create new list:");
    printf("\nenter 2 for edit to do list:");
    printf("\nenter 3 for check old to-do list:");
    printf("\nenter 4 for delete list\n");
    scanf("%d",&op);
    switch (op){
        case 1:
            create();
            break;
        case 2:
            edit_list();
            break;
    /*    case 3:
            check_list();
            break;
        case 4: 
            delete list();
            break; */
        default:
            printf("Dear User! you have entered wrong choice.");
    }
    getch();
}
void create(){
    FILE *fp;
    char name[15];
    printf("enter your name:");
    scanf("%s",&name);
    printf("\nenter the topic of task:");
    scanf("%s",&task_name);
    fp = fopen(name,"a+");
    printf("\nplease enter the details of your task:");
    fflush(stdin);
    gets(task);
    fprintf(fp,"\nTOPIC:%s\n%s",task_name,task);
    fclose(fp);
}
void edit_list(){
    FILE *fp;
    char name[15],ch[3];
    printf("enter your name:");
    scanf("%s",&name);
    fp = fopen(name,"a");
    if(fp==NULL){
        printf("sorry:(  there is no such a file exists.\n");
        printf("do you want to create new one: y/n\n");
        scanf("%s",ch);
        if(strcmp(ch,"y")==0){
            create();
        }
        else if(strcmp(ch,"n")==0){
            printf("\nthanks for using this software.");
            exit(1);
        }
        else{
            printf("\nOOPS :( you have entered something wrong!");
        }
    }
    else{
        printf("\nenter the topic of new task:");
    scanf("%s",&task_name);
    printf("\nplease enter the details of new task:");
    fflush(stdin);
    gets(task);
    fprintf(fp,"\nTOPIC:%s\n%s",task_name,task);
    fclose(fp);
    }
}