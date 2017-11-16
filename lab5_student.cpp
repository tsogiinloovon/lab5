#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
class students
{
public:
    int level;
    char name[20];
    void getdata();
    void setdata();
    bool before(students &a);
    bool greatThan(students &a);
    void update(students &a);
private:
    char sisi[20];
    float GD;

};
int i=0;
void sort_name(students a[],int n)
{
    for(int j=0; j<n; j++)
    {
        for(int i=0; i<n-1; i++)
        {
            if(a[i].before(a[i+1])==0)
            {
                a[i].update(a[i+1]);
            }
        }
    }
}
bool students::before(students &a)
{
    if(strcmp(name,a.name)<=0)
        return true;
    else return false;
}
void sort_level(students a[],int n)
{
    for(int j=0; j<n; j++)
    {
        for(int i=0; i<n-1; i++)
        {
            if(a[i].greatThan(a[i+1])==1)
            {
                a[i].update(a[i+1]);
            }
        }
    }
}
bool students::greatThan(students &a)
{
    if(level<=a.level)
        return 1;
    else return 0;
}
void students::update(students &a)
{
    char change[20];
    strcpy(change,name);
    strcpy(name,a.name);
    strcpy(a.name,change);
    int changee;
    changee=level;
    level=a.level;
    a.level=changee;
    char z[20];
    strcpy(z,sisi);
    strcpy(sisi,a.sisi);
    strcpy(a.sisi,z);
    int k;
    k=GD;
    GD=a.GD;
    a.GD=k;
}

void students::getdata()
{
    i++;
    cout<<"\nstudent "<<i;
    cout<<"\n___________\n";
    cout<<"NAME:";
    cin>>name;
    cout<<"\nSISI:";
    cin>>sisi;
in:
    cout<<"\nGD:";
    cin>>GD;
    if(GD!=4&&GD!=3&&GD!=2&&GD!=1)
    {
        cout<<"not described number!.. insert again";
        goto in;
    }
in1:
    cout<<"\nLEVEL:";
    cin>>level;
    if(level!=4&&level!=3&&level!=2&&level!=1)
    {
        cout<<"not described number!.. insert again";
        goto in1;
    }

}

void students::setdata()
{
    cout<<"  "<<name<<"   |   "<<sisi<<"   |   "<<GD<<"   |   "<<level<<"\n";

}
int main()
{
    char choose[20];
    int n,i;
     students *student=NULL;
     student=new students[100];
    cout<<"                    started\n";
    do
    {
        cin>>choose;
        if(strcmp(choose,"insert")==0)
        {
            cout<<"numbet of students :";
            cin>>n;
            for(i=0; i<n; i++)
                student[i].getdata();
        }
        if(strcmp(choose,"print")==0)
            for(i=0; i<n; i++)
                student[i].setdata();
        if(strcmp(choose,"sortname")==0)
        {
            sort_name(student,n);
        }
        if(strcmp(choose,"sortlevel")==0)
        {
            sort_level(student,n);
        }

    }
    while(strcmp(choose,"exit")==1);
    delete student;
}
