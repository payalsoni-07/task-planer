// This is simply a to-do planner for my weekly goals.
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
//functions
void delete();
void edit_list(); 
void create();
void check_list();
void pick();
int is_valid(char d[]);
char task_name[10];
char task[100];
char date[15];
void main(){
    int n,op;
    char ch[3];
    again:
    printf("\n\n**************************************************************************************************");
    printf("\n\n********************************  THOUGHT OF THE DAY  ********************************************\n");
    pick();
    printf("\n\n\n\n**************************************************************************************************");
    printf("\n\n**********************************WELCOME TO PERSONAL TASK SCHEDULER******************************");
    printf("\n\n**************************************************************************************************");
    printf("\nHello user, what do you want to do?\nYou can enter your choice by given data below.");
    printf("\nenter 1 for create new task's list:");
    printf("\nenter 2 for add tasks to list:");
    printf("\nenter 3 for check old tasks's list:");
    printf("\nenter 4 for delete list\n");
    scanf("%d",&op);
    switch (op){
        case 1:
            create();
            break;
        case 2:
            edit_list();
            break;
        case 3:
            check_list();
            break;
        case 4: 
            delete();
            break; 
        default:
            printf("Dear User! you have entered wrong choice.");
    }
    printf("\nDo you want to do more task. Type 'y' for YES and 'n' for NO\n");
    scanf("%s",ch);
    if(strcmp(ch,"y")==0||strcmp(ch,"Y")==0){
        goto again;
    }
    else if(strcmp(ch,"n")==0){
        printf("\nthanks for using this software.");
        exit(1);
    }
    else{
        printf("\nOOPS :( you have entered something wrong!");
    }
}
void create(){
    FILE *fp;
    char name[20];
    printf("enter your name:");
    fflush(stdin);
    gets(name);
    printf("\nplease enter date in dd/mm/yyyy format:\n");
    scanf("%s",&date);
    int p=is_valid(date);
    if(p==1){
        printf("\nenter the topic of task:");
        fflush(stdin);
        gets(task_name);
        fp = fopen(name,"a+");
        printf("\nplease enter the details of your task:");
        fflush(stdin);
        gets(task);
        fprintf(fp,"\nTOPIC: %s\tDATE: %s\nDETAILS: %s\n",task_name,date,task);
        fclose(fp);
    }
    else{
        printf("SORRY :( you have entered wrong format of date.");
    }
}
void edit_list(){
    FILE *fp;
    char ch[3],name[20];
    fflush(stdin);
    printf("enter your name:");
    gets(name);
    fp = fopen(name,"a+");
    printf("\nplease enter date in dd/mm/yyyy format:\n");
    scanf("%s",&date);
    int p = is_valid(date);
    if(p==1){
        printf("\nenter the topic of new task:");
        scanf("%s",&task_name);
        printf("\nplease enter the details of new task:");
        fflush(stdin);
        gets(task);
        fprintf(fp,"\nTOPIC:%s \tDATE:%s \nDETAILS:%s",task_name,date,task);
        fclose(fp);
    }
    else{
        printf("SORRY :( you have entered wrong format of date.");
    }
}
void delete(){
    char name[20];
    printf("enter your name:");
    fflush(stdin);
    gets(name);
    remove(name);
    printf("your task planer file has been deleted successfully.");
}
int is_valid(char d[]){
    int flag =0;
    if((d[2]=='/')&&(d[5]=='/')){
        if(isdigit(d[0])&&isdigit(d[1])){
            flag=1;
        }
        else if(isdigit(d[3])&&(isdigit(d[4]))){
            flag=1;
        }
        else if((isdigit(d[6]))&&(isdigit(d[7]))&&(isdigit(d[8]))&&(isdigit(d[9]))){
            flag=1;
        }
        else{
            flag=0;
        }
    }
    else{
        flag =0;
    }
    return flag;
}
void check_list(){
    FILE *fp;
    char a[1000];
    char ch[3],name[20];
    fflush(stdin);
    printf("enter your name:");
    gets(name);
    fp = fopen(name,"rb");
    if(fp==NULL){
        printf("sorry:(  there is no such a file exists.\n");
        printf("\nDo you want to create new one: y/n\n");
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
    while(!feof(fp)){
        fgets(a,1000,fp);
        puts(a);
    }
    fclose(fp);
}
void pick(){
    char *words[10];
    words[0] = "\nSet your goals high, and don't stop till you get there.\n - Bo Jackson";
    words[1] = "\nIt always seems impossible until it's done.\n - Nelson Mandela";
    words[2] = "\nDon't watch the clock; do what it does. Keep going.\n -Sam Levenson";
    words[3] = "\nThe secret of getting ahead is getting started.\n - Mark Twain";
    words[4] = "\nCreativity is intelligence having fun.\n - Albert Einstein";
    words[5] = "\nAlways keep your eyes open. Keep watching. Because whatever you see can inspire you.\n - Grace Coddington";
    words[6] = "\nIf it scares you, it might be a good thing to try.\n - Seth Godin";
    words[7] = "\nYou will succeed because most people are lazy.\n - Shahir Zag";
    words[8] = "\nYou must be the change you wish to see in the world.\n - Mahatma Gandhi";
    words[9] = "\nDo it with passion, or not at all.\n - Rosa Nouchette Carey";
    char *random;
    srand(time(NULL));
    random = words[rand() % 10];
    printf(random);
}