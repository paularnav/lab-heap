#include<iostream>
#include<algorithm>
using namespace std;
int index=0;
//int j;
class heap
{
  int h[100];
  public:
  heap()
  {
    for(int j=0;j<100;j++)
     h[j]=0;
  }
  void insert(int key)
  {
    if(index==0)
    {
      h[index]=key;
      ++index;
    }
    else
    {
      h[index]=key;
      int i=index;
      int p=(i-1)/2;
      while(i!=0 && h[i]>=h[p])
      {
        int temp;
        temp=h[i];
        h[i]=h[p];
        h[p]=temp;
        i=p;
        p=(i-1)/2;
      }
      ++index;
     }
   }
  void remove()
  {
    h[0]=h[index-1];
    h[index-1]=0;
    --index;
    int k,t;
    k=0;
    int left=1;int right=2;
    while(true)
    {
       if(h[left]==0 && h[right]==0)
         break;
       else if(h[left]!=0 &&  h[right]==0)
       {
         if(h[left]>=h[k])
         { 
          t=h[k];
          h[k]=h[left];
          h[left]=t; 
         k=left;
         }  
         else break;
      }  
       else if(h[right]!=0 && h[left]==0)
       {
         if(h[right]>=h[k])
         {
           t=h[k];
           h[k]=h[right];
           h[right]=t;
         k=right;
         }
        else
          break;
       }
       else
        {
          int m;
          m=std::max(h[left],h[right]);
          if(m==h[left])
          {
            t=h[k];
            h[k]=h[left];
            h[left]=t;
            k=left;
          }
          else if(m==h[right]){
          t=h[k];
          h[k]=h[right];
          h[right]=t;
          k=right;
        } 
         else break;
      }
      left=2*k+1;
      right=2*k+2;
    }
  }
 void heapify(int arr[],int i)
 {
   
 }      
  void display()
  {
    for(int j=0;j<index;j++)
    cout<<h[j]<<"	";
  }
};
int main()
{
  int ch;
  heap h; 
  do{
  cout<<"\n 1.insert \n 2.display \n 3.remove \n";
  cout<<"\n enter your choice : ";
  cin>>ch;
  switch(ch)
  {
   case 1: int x;
           cout<<"Enter the data : ";
           cin>>x;
           h.insert(x);
           break;
   case 2: h.display();
           break;
   case 3: h.remove();
           cout<<"after remove : \n";
           h.display();
           break;
   default : return 0;
  }
  }while(ch!=4);
  return 0;
} 
