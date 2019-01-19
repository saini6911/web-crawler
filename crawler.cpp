#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

using namespace std;
struct node
{
char link[1000];
struct node *next;
};
struct node *head=NULL;
void addnode(char *n)
{
    struct node* newnode=new node;
    struct node * t=new node;

    strcpy(newnode->link,n);
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
else
{
    t=head;

}
while(t->next!=NULL)
{
    t=t->next;
}
t->next=newnode;
}
void display()
{
int count=1;
    struct node* temp=head;
    while(temp!=NULL)
    {
        cout<<count<<" "<<temp->link<<endl;
        temp=temp->next;
        count++;
        }
}
int isSubstring(char *s1, char *s2)
{
    int M = strlen(s1);
    int N = strlen(s2);

    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) {
        int j;


        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;

        if (j == M)
            return 1;
    }

    return 0;
}
int check_duplicate(char *link)
{
struct node* temp=head;
    while(temp!=NULL)
    {
                if(strcmp(link,temp->link)==0)
                        return 0;

        temp=temp->next;

}
return 1;
}

void testDir(char *dir)
{
  struct stat statbuf;
  if ( stat(dir, &statbuf) == -1 )
  {
    fprintf(stderr, "-----------------\n");
    fprintf(stderr, "Invalid directory\n");
    fprintf(stderr, "-----------------\n");
    exit(1);
  }

  //Both check if there's a directory and if it's writable
  if ( !S_ISDIR(statbuf.st_mode) )
  {
    fprintf(stderr, "-----------------------------------------------------\n");
    fprintf(stderr, "Invalid directory entry. Your input isn't a directory\n");
    fprintf(stderr, "-----------------------------------------------------\n");
    exit(1);
  }

  if ( (statbuf.st_mode & S_IWUSR) != S_IWUSR )
  {
    fprintf(stderr, "------------------------------------------\n");
    fprintf(stderr, "Invalid directory entry. It isn't writable\n");
    fprintf(stderr, "------------------------------------------\n");
    exit(1);
  }
}
char seed_url[100];
void link_print(int sf)
{

        char *c,*d,*pr;
pr=(char*)malloc(sizeof(char)*1000);
c=(char*)malloc(sizeof(char)*sf);
//printf("before file");
FILE *fp=fopen("temp.txt","r");
//printf("\nafter file opening");
fgets(c,sf+1,fp);

while(!feof(fp))
        {
d=strstr(c,"a href");
if(d)
{

int i=8;
while(d[i]!='"')
i++;
d[i]='\0';
strcpy(pr,d+8);
if(strcmp(pr,seed_url)!=0 && isSubstring(seed_url, pr) == 1 &&
check_duplicate(pr)==1)
addnode(pr);
//printf(" \n%s",pr);

}

fgets(c,sf+1,fp);
}

}

int main(int argc,char** argv){

/*char s1[1000]="wget --no-check-certificate -O ";
testDir(argv[2]);
strcat(s1,argv[2]);
strcat(s1,"/temp.txt ");
strcat(s1,argv[1]);
if(!system(s1))
{

cout<<"validate\n";
}
else
cout<<"invalid\n";*/

strcpy(seed_url,argv[1]);
struct stat st; //variable which will count length of file.
stat("temp.txt",&st); // temp.txt is the file where wget fetch the html
int file_size=st.st_size;

/*sprintf(itostring,"%d",file_no); //converts integer into string
char file[]="/temp"; //name of file.
char f[]=".txt";
strcat(p,path); //creating path using strcat in p.
strcat(p,file);
strcat(p,itostring);
strcat(p,f);
printf("PATH has been created\n");
*/

link_print(file_size);
display();

return 0;
}

