#include<iostream>
#include<string.h>
using namespace std;

struct record
{
string name;
long int tel;
};

class hash_table
{
public:
int i,j;
int max;
int comparison1[10];
int comparison2[10];
hash_table()
{
max=10;
}
record obj[10];
record obj1[10];
void setdata(char key1[20],int loc1);
void display(int g);
int check(int loc2);
int address_calculation(char key2[20]);
int linear_probing(int loc3,char key3[20],long int phone);
void initialize();
int quadretic_probing(char key5[20],int loc5,long int f);
};

void hash_table::initialize()
{
for(i=0;i<max;i++)
{
obj[i].name="none";
obj[i].tel=0;
}

for(i=0;i<max;i++)
{
obj1[i].name="none";
obj1[i].tel=0;
}

for(i=0;i<max;i++)
{
comparison1[i]=0;
comparison2[i]=0;
}
}

void hash_table::setdata(char key1[20],int loc1)
{
obj[loc1].name=key1;
obj1[loc1].name=key1;
cout<<"enter telephone number of this person"<<endl;
long int c;
cin>>c;
obj[loc1].tel=c;
obj1[loc1].tel=c;
comparison1[loc1]=0;
comparison2[loc1]=0;
}

void hash_table::display(int g)
{
  if(g==1)
{
cout<<"name"<<"   |   "<<"tel"<<"   |   "<<"      comparison"<<endl;
for(i=0;i<max;i++)
{
cout<<obj[i].name<<"       "<<obj[i].tel<<"     "<<comparison1[i]<<endl;
}
}
else 
{
cout<<"name"<<"    |    "<<"tel"<<"    | "<<"      comparison"<<endl;
for(i=0;i<max;i++)
{
cout<<obj1[i].name<<"      "<<obj1[i].tel<<"       "<<comparison2[i]<<endl;
}
}
}
int hash_table::check(int loc2)
{
if(obj[loc2].name=="none")
{
return 0;
}

else
{
return 1;
}
}

int hash_table::address_calculation(char key2[20])
{
int count=0;
for(i=0;key2[i]!='\0';i++)
{
count=count+1;
}


int h=0;

for(i=0;i<count;i++)
{
h=h+key2[i];
}

int loc4=h%max;
cout<<loc4<<endl;
return loc4;
}

int hash_table::linear_probing(int loc3,char key3[20],long int phone)
{
int offset=0;
int final_index;
int comp=0;
for(i=loc3;i<max;i++)
{
comp++;
if(obj[i].name=="none")
{
offset=-1;
final_index=i;
break;
}
}

if(offset==0)
{
for(i=0;i<loc3;i++)
{comp++;
if(obj[i].name=="none")
{
offset=-1;
final_index=i;
break;
}
}
}

if(offset==0)
{
cout<<"hash table is full"<<endl;
return -1;
}

else
{
obj[final_index].name=key3;

obj[final_index].tel=phone;
comparison1[final_index]=comp;
return 0;
}
}

int hash_table::quadretic_probing(char key5[20],int loc5,long int f)
{
int offset=0;
int flag=0;
int prob=1;
int p=0;
int new_address;
for(i=0;i<max;i++)
{
if(obj1[i].name=="none")
{
p=1;
break;
}

}

if(p==1)
{
while(offset==0)
{
new_address=(loc5+prob*prob)%max;
if(obj1[new_address].name=="none")
{
offset=-1;
flag=1;
obj1[new_address].name=key5;

obj1[new_address].tel=f;
comparison2[new_address]=prob;
break;
}

else
{
prob++;
}
}}

if(flag==1)
{
return 0;
}

else
{
return -1;
}
}


int main()
{
char choice;
hash_table object;
int x=0;
int responce,location;
long int phone_number;
char key4[20];
object.initialize();

do
{
cout<<"enter name  to store"<<endl;
cin>>key4;
location=object.address_calculation(key4);
//cout<<location;
responce=object.check(location);
if(responce==0)
{
object.setdata(key4,location);
}

else
{
cout<<"enter telephone number of this person"<<endl;
cin>>phone_number;
x=object.linear_probing(location,key4,phone_number);
x=object.quadretic_probing(key4,location,phone_number);
}
if(x==0)
{
cout<<"do you want to add more data y/n"<<endl;
cin>>choice;
}

else
{
cout<<"hash table is full"<<endl;
break;
}
}while(choice=='y');
int z=1;
int w=0;

cout<<"LINEAR PROBING*****************************"<<endl;
object.display(z);
cout<<"    "<<endl;
cout<<"QUADRETIC PROBING************************* "<<endl;
object.display(w);
}