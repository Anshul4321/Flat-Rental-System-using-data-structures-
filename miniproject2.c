#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct mynode {
    char name[30];
    char email[30];
    int cont;
    struct mynode* link;
} Node;
Node* start = NULL;

void view();
void inform();
void FLAT();
void LEISURE();
void Bill();
void heading();


int k, amount;
char type[60], sq[10], date[20];


void main()
{
    int a;
    int str1;
   // printf("###########################################################################################\n");
   // printf("###########################################################################################\n");
    printf("\n\n\n--------------------<<<<<<<<<<<<<<FLAT RENTAL SYSTEM >>>>>>>>>>>>>>------------------\n\n\n");


    printf("\t\t\t\t1) FLAT RENTALS\n");
    printf("\t\t\t\t2) LESIURE HOMES\n");
    printf("\t\t\t\t3) View the records(ONLY FOR ADMINS)\n");
    printf("\t\t\t\t4) search\n");
    printf("\t\t\t\tEnter Choice: ");
    scanf("%d", &a);
    switch (a) {
    case 1:
        FLAT();
        break;
    case 2:
        LEISURE();
        break;
    case 3:

        printf("\nenter password:");
        scanf("%d",&str1);
        //gets(str1);
        if(str1==4444)
        {
            view();
        }
        else
        {
            printf("Wrong password\n");
            exit(0);
        }
        break;
    case 4:
        search();
        break;

    default:
        printf("ERROR");
        break;
    }
    inform();
    Bill();
}
void LEISURE()
{
    int a,day;
    strcpy(type, "LEISURE HOMES");
    printf("\t\t\t\tNOTE: BREAKFAST ,LUNCH ,DINNER included for every option\n");
    printf("\t\t\t\t1) 1 BHK, 1 day Rs:2000\n");
    printf("\t\t\t\t2) 2 BHK, 1 day Rs:4000\n");
    printf("\t\t\t\t3) 3 BHK, 1 day RS:8000\n");
    printf("\t\t\t\tEnter Choice: ");
    scanf("%d", &a);
    printf("\t\t\t\tenter number of days");
    scanf("%d",&day);
    if (a == 1) {
        strcpy(sq, "1 BHK");
        amount = 2000*day;
    }
    else if (a == 2) {
        strcpy(sq, "2 BHK");
        amount = 4000*day;
    }
    else if (a == 3) {
        strcpy(sq, "3 BHK");
        amount = 8000*day;
    }
    else
        printf("error");
}
void FLAT()
{
    int a,mon;
    strcpy(type, "FLAT RENTALS");
    printf("\t\t\t\t1. 1BHK,1 month for Rs:5000\n");
    printf("\t\t\t\t2. 2BHK,1 month for Rs:8000\n");
    printf("\t\t\t\t3. 3BHK,1 month for Rs:10000\n");
    printf("\t\t\t\tEnter Choice: ");
    scanf("%d", &a);
    printf("\t\t\t\tEnter number of months");
    scanf("%d",&mon);
    if (a == 1) {
        strcpy(sq, "1 BHK");
        amount = 5000*mon;
    }
    else if (a == 2) {
        strcpy(sq, "2 BHK");
        amount = 8000*mon;
    }
    else if (a == 3) {
        strcpy(sq, "3 BHK");
        amount = 10000*mon;
    }
    else
        printf("Enter Correct Choice...");
}
void inform()
{
    char  a[30];
    char ele[20], email[40];
    printf("\t\t\t\tEnter Date (DD/MM/YY): ");
    scanf("%s",date);
    heading();
    printf("\n\t\t\t\tEnter The  Name: ");
    scanf("%s",ele);
    printf("\n\t\t\t\tEnter The  E-mail id: ");
    scanf("%s",email);
    printf("\n\t\t\t\tEnter The  Contact number: ");
    //scanf("%s", a);
    scanf("%s",a);
    newnode(ele, email, a);


}
void newnode(char l[30],char der[30], char b[30])
{
    Node *newptr = NULL, *ptr;
    newptr = (Node*)malloc(sizeof(Node));
    strcpy(newptr->name, l);
    strcpy(newptr->email, der);
    newptr->cont= b;
    newptr->link = NULL;
    if (start == NULL)
        start = newptr;
    else {
        ptr = start;
        while (ptr->link != NULL)
            ptr = ptr->link;
        ptr->link = newptr;
    }
}
void Bill()
{
    FILE *f;
    f=fopen("data.txt","a+");
    int i;
    Node* ptr = start;
    //heading();
    printf("\n\n\t\t\t\t\t| BILL |");
    printf("\n\t\t\t\tPerson Name: ");

    printf("%s",ptr->name);
    fprintf(f,"\nName: %s",ptr->name);

    printf("\n\t\t\t\tPerson E-mail: ");
    printf("%s",ptr->email);
    fprintf(f,"\nE-mail: %s",ptr->email);

    printf("\n\t\t\t\tPerson contact: %s", ptr->cont);
    fprintf(f,"\nContact: %s",ptr->cont);
    //ptr = ptr->link;
    //printf("\t\t\t\t| BILL |");
    printf("\n\t\t\t\tType: ");
    puts(type);
    fprintf(f,"\ntype %s",type);
    printf("\n\t\t\t\tAREA: ");
    puts(sq);
    fprintf(f,"\nArea: %s",sq);
    printf("\n\t\t\t\tDate: ");
    puts(date);
    fprintf(f,"\nDate: %s",date);
    printf("\n\t\t\t\tFinal Amount: %d", amount);
    fprintf(f,"\nAmount: %d",amount);
    char c=' ';
    fprintf(f,"\n---------------------------");
    printf("\n\n\t\t\t\t*Thank You For BOOKING*");
    fclose(f);
main();

}
void view(){
    FILE *f;
    char c;


    f=fopen("data.txt","r");
    while(1)
    {
      c = getc(f);
      if(c==EOF)
      {
        break;
      }
    printf("%c",c);
    }
    getch();
    fclose(f);
    main();
    }

void search()
{
    Node c;
    FILE *f;
    char name[30];
    int z=1,y;
    f=fopen("data.txt","r");
    fflush(stdin);
    system("cls");
    printf("\n Enter the name to search :");
    scanf("%s",name);
    while(fread(&c,sizeof(c),1,f)==1)
    {
        y=1;
        if(strcmp(c.name ,name)==0)
        {

            system("cls");
            printf("\n Record found");
            printf("\n\n email :%s ",c.email);
            z=0;
            break;
        }
        else if(z==1)
        {
            system("cls");
            printf("\nrecord not found\n");

        }
    }
    if(y!=1)
    {

        printf("\nthere are no records");
    }
    printf("\n enter any key to go back to main menu");
    getch();
    fclose(f);
    system("cls");
}
void heading()
{
    printf("\t\t\t\t\t**FLAT RENTAL SYSTEM**\n");

}
