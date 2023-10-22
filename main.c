//result system
//code written by sumaya rahman
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void search();
void sr();
void add();
void del();
struct student{
    char f_n[30];
    char l_n[30];
    char id[10];
    float grad , cse , cse_lab , eee_lab , eee , math , english , physics , urem , total , grade;
};
int main()
{
    int options;
    while(options != 5){
        printf("\t\t\t\t\t\t========RESULTS OF STUDENTS OF CSE========");
        printf("\n");
        printf("\n\t\t\t\t\t 1.Add student's data        :\n");
        printf("\n\t\t\t\t\t 2.Watch student's record    :\n");
        printf("\n\t\t\t\t\t 3.Search a student's result :\n");
        printf("\n\t\t\t\t\t 4.Delete a student's result :\n");
        printf("\n\t\t\t\t\t 5.Exit\n");
        printf("\n\t\t\t\t\t _______________________________________\n");
        printf("\t\t\t\t    ");
         scanf("%d" , &options);
         switch(options){
     case 1:
         system("cls");
         add();
         system("cls");
         break;
     case 2:
        system("cls");
         sr();
         printf("\t\tpress any key to continue\n");
         getch();
         system("cls");
         break;
     case 3:
         system("cls");
         search();
         printf("\t\tpress any key to continue\n");
         getch();
         system("cls");
         break;
     case 4:
        system("cls");
         del();
         printf("\t\tpress any key to continue\n");
         getch();
         system("cls");
         break;
    case 5:
        system("cls");
         printf("\t\t\tThank YOU FOR USING MY APPLICATION . HAVE A NICE DAY !\n");
         exit(0);
         default:
        system("cls");
         getch();
         printf("\t\tinvalid input\n");
         printf("\t\tpress any key to continue\n");
         getch();
         system("cls");
        break;
        }
    }

}
void add(){
    char again;
    FILE *pr;
    struct student data;
    do{
         system("cls");
         printf("\t\t\t\t\t\t========ADD STUDENT'S DATA========\n\n\n");
         pr = fopen("student_data" , "a");
         printf("\n\t\tEnter first name  : ");
         scanf("%s" , data.f_n);
         printf("\n\t\tEnter last name   : ");
         scanf("%s" , data.l_n);
         printf("\n\t\tEnter ID          : ");
         scanf("%s" , data.id);
         printf("\t\tEnter CSE marks   :");
         scanf("%f" , &data.cse);
         printf("\t\tEnter EEE marks    :");
         scanf("%f" , &data.eee);
         printf("\t\tEnter PHYSICS marks  :");
         scanf("%f" , &data.physics);
         printf("\t\tEnter ENGLISH marks  :");
         scanf("%f" , &data.english);
         printf("\t\tEnter MATH marks     :");
         scanf("%f" , &data.math);
         printf("\t\tEnter UREM marks     :");
         scanf("%f" , &data.urem);
         printf("\t\tEnter CSE LAB marks  :");
         scanf("%f" , &data.cse_lab);
         printf("\t\tEnter EEE LAB marks  :");
         scanf("%f" , &data.eee_lab);
         data.total = data.cse + data.eee + data.physics + data.math + data.english + data.urem + data.cse_lab + data.eee_lab;
         data.grad = data.total / 8;
         if(data.grad >=80 && data.grad<=100)
    {
        data.grade = 4.00;
    }
    else if(data.grad >=75 && data.grad <80)
    {
        data.grade = 3.75;
    }
    else if(data.grad >=70 && data.grad <75)
    {
        data.grade = 3.50;
    }
    else if(data.grad >=65 && data.grad <70)
    {
        data.grade = 3.25;
    }
    else if(data.grad>=60 && data.grad<65)
    {
        data.grade = 3.00;
    }
    else if(data.grad>=55 && data.grad<60)
    {
        data.grade = 2.75;
    }
    else if(data.grad >=50 && data.grad <55)
    {
        data.grade = 2.50;
    }
    else if(data.grad>=45 && data.grad<50)
    {
        data.grade = 2.25;
    }
    else if(data.grad>=40 && data.grad<45)
    {
        data.grade = 2.00;
    }
    else
    {
        data.grade = 0.00;
    }
         printf("\t\tTotal percentage : %0.2f" , data.grad);
         printf("\n\t\t_______________________________________\n");
         if(pr == NULL){
            printf("Sorry , can't open file");
         }else{
            printf("\t\tRecord stored successfully\n");
         }
         fwrite(&data , sizeof(struct student) , 1 , pr);
         fclose(pr);
         printf("\t\tWant add data of another student ? Type y or n :");
         scanf(" %c" , &again);
    }while(again == 'Y' || again == 'y');
}
void sr()
{
    FILE *pr;
    struct student data;
         pr = fopen("student_data" , "r");

    printf("\t\t\t\t\t\t========CHECK ALL STUDENT'S DATA========\n\n\n");
    if(pr == NULL){
            printf("can't open file");
         }else{
            printf("\t\trecords\n");
            printf("\t\t___________\n\n");
            printf("\n\t\t_______________________________________\n");

         }
         while(fread(&data , sizeof(struct student) , 1 , pr)){
            printf("\n\t\tStudent name     : %s %s" , data.f_n , data.l_n);
            printf("\n\t\tStudent id       : %s" , data.id);

            printf("\n\t\tCSE marks        : %0.2f" , data.cse);
            printf("\n\t\tEEE marks        : %0.2f" , data.cse_lab);
            printf("\n\t\tCSE LAB marks    : %0.2f" , data.eee);
            printf("\n\t\tEEE LAB marks    : %0.2f" , data.eee_lab);
            printf("\n\t\tENGLISH marks    : %0.2f" , data.english);
            printf("\n\t\tPHYSICS marks    : %0.2f" , data.physics);
            printf("\n\t\tMATH marks       : %0.2f" , data.math);
            printf("\n\t\tUREM marks       : %0.2f" , data.urem);
            printf("\n\t\tTOTAL MARKS      : %0.2f" , data.total);
            printf("\n\t\tTOTAL PERCENTAGE : %0.2f" , data.grad);
            printf("\n\t\tTOTAL GPA        : %0.2f" , data.grade);
            printf("\n\t\t_______________________________________\n");
         }
         fclose(pr);
         getch();
}
void search()
{
    FILE *pr;
    struct student data;
    int find = 0;
    char id[10];
         pr = fopen("student_data" , "r");

         printf("\t\t\t\t\t\t========SEARCH STUDENT========\n\n\n");
         printf("\t\tEnter id no :");
         scanf(" %s" , &id);

         while(fread(&data , sizeof(struct student) , 1 , pr)){
                if(strcmp(data.id , id) == 0){
                        find = 1;
            printf("\n\t\tStudent name : %s %s" , data.f_n , data.l_n);
            printf("\n\t\tStudent id   : %s" , data.id);

            printf("\n\t\tCSE marks : %0.2f" , data.cse);
            printf("\n\t\tEEE marks : %0.2f" , data.cse_lab);
            printf("\n\t\tCSE LAB marks : %0.2f" , data.eee);
            printf("\n\t\tEEE LAB marks : %0.2f" , data.eee_lab);
            printf("\n\t\tENGLISH marks : %0.2f" , data.english);
            printf("\n\t\tPHYSICS marks : %0.2f" , data.physics);
            printf("\n\t\tMATH marks : %0.2f" , data.math);
            printf("\n\t\tUREM marks : %0.2f" , data.urem);
            printf("\n\t\tTOTAL MARKS : %0.2f" , data.total);
            printf("\n\t\tTOTAL PERCENTAGE : %0.2f" , data.grad);
            printf("\n\t\tTOTAL GPA : %0.2f" , data.grade);
            printf("\n\t\t_______________________________________\n");
         }
         }
         if(!find){
            printf("\t\tRecord not found");
         }
         fclose(pr);
         getch();
}
void del()
{
    FILE *pr , *pr1;
    struct student data;
    int find = 0;
    char id[10];
    printf("\t\t\t\t\t\t========DELETE A STUDENT========\n\n\n");
    pr = fopen("student_data" , "r");
    pr1 = fopen("hurr.txt" , "w");
    printf("\n\t\tEnter ID : ");
         scanf("%s" , &id);
if(pr == NULL){
            printf("can't open file");
         }
         while(fread(&data , sizeof(struct student) , 1 , pr)){
                if(strcmp(data.id , id) == 0){
                        find = 1;
                }else{
                fwrite(&data , sizeof(struct student) , 1 , pr1);
                }
         }
         fclose(pr);
         fclose(pr1);

         if(find){
            remove("student_data");
            rename("hurr.txt" , "student_data");
        printf("\t\tdeleted success\n");
         }else{
         printf("record not found\n");
         }
         getch();
}
