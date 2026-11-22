#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define T 80
#define N 60
typedef struct{
 int id;
 char title[T],author[N];
 float price;
 int avail;
}Book;
Book *b;
int n=0;
void clr(){int c;while((c=getchar())!='\n'&&c!=EOF);}
void rl(char *s,int sz){if(fgets(s,sz,stdin))s[strcspn(s,"\n")]='\0';}
void create(){
 printf("Number of books to add: ");
 if(scanf("%d",&n)!=1||n<=0){n=0;printf("Invalid number.\n");clr();return;}
 clr();
 free(b);
 b=calloc(n,sizeof(Book));
 if(!b){printf("Memory allocation failed.\n");n=0;return;}
 for(int i=0;i<n;i++){
  printf("\nBook %d ID: ",i+1);scanf("%d",&b[i].id);clr();
  printf("Title: ");rl(b[i].title,T);
  printf("Author: ");rl(b[i].author,N);
  printf("Price: ");scanf("%f",&b[i].price);clr();
  b[i].avail=1;
 }
}
int find(int id){
 for(int i=0;i<n;i++)if(b[i].id==id)return i;
 return -1;
}
void show(int i){
 printf("%d\t%s\t%s\t%.2f\t%s\n",b[i].id,b[i].title,b[i].author,b[i].price,b[i].avail?"Available":"Issued");
}
void display(){
 int count=0;
 if(!b||n==0){printf("No book records. Add records first.\n");return;}
 printf("ID\tTitle\tAuthor\tPrice\tStatus\n");
 for(int i=0;i<n;i++)if(b[i].avail){show(i);count++;}
 if(!count)printf("No books are currently available.\n");
}
void search(){
 int id;
 printf("Enter Book ID: ");
 scanf("%d",&id);
 int i=find(id);
 if(i<0){printf("Book not found.\n");return;}
 printf("ID\tTitle\tAuthor\tPrice\tStatus\n");
 show(i);
}
void issueBook(){
 int id;
 printf("Enter Book ID to issue: ");
 scanf("%d",&id);
 int i=find(id);
 if(i<0)printf("Book not found.\n");
 else if(!b[i].avail)printf("Book is already issued.\n");
 else{b[i].avail=0;printf("Book issued successfully.\n");}
}
void returnBook(){
 int id;
 printf("Enter Book ID to return: ");
 scanf("%d",&id);
 int i=find(id);
 if(i<0)printf("Book not found.\n");
 else if(b[i].avail)printf("Book is already available.\n");
 else{b[i].avail=1;printf("Book returned successfully.\n");}
}
int main(){
 int ch;
 do{
  printf("\n1.Add Book Records\n2.Display Available Books\n3.Search by ID\n4.Issue a Book\n5.Return a Book\n6.Exit\n");
  printf("Choice: ");
  if(scanf("%d",&ch)!=1)break;
  switch(ch){
   case 1:create();break;
   case 2:display();break;
   case 3:search();break;
   case 4:issueBook();break;
   case 5:returnBook();break;
   case 6:printf("Exiting.\n");break;
   default:printf("Invalid choice.\n");
  }
 }while(ch!=6);
 free(b);
 return 0;
}
