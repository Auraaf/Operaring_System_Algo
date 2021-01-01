#include<bits/stdc++.h>
using namespace std;

int main()
{ 
 
 int size;
 int arr;
 int k = 0;
 int val;
 size = 3; 
 bool check[100];
 for(int i =0; i< 100; i++)
 check[i] = false;
 int  pg_flt = 0;
 int frame[size];
 int time[size];
 for(int i = 0; i <size ; i++)
 {
  cin >> val;
  frame[i] =  val;
  time[i] = i;
  check[val] = true;
  //cout<<frame[i][0]<<" ";
  pg_flt += 1;
 } 
 
 for(int m = 0; m < size ; m++ )
     cout<< frame[m] <<" ";
     cout<<endl;
  k = size -1;
  
  
 while(true)
 { 
   
   cin >> val;
   if(val != -1)
   { 
     
     k++;
      int  i = 0;
   if(check[val])
   { cout<<"p"<<endl;
   while(frame[i] != val)
      i++;
      cout<<i<<endl;
      time[i] = k;
      check[val]  = true;
   }
   
   
   else
   {cout<<"a"<<endl;
    pg_flt += 1;
    int* indx = min_element(time, time + size);
    
     i = indx - time;
     //cout<<i<<endl;
     check[frame[i]] = false;
     frame[i] = val;
     check[val] = true;
     time[i] = k; 
   }
     for(int m = 0; m < size ; m++ )
     cout<< frame[m] <<" "<<time[m] <<endl;
     cout<<endl;
   }
   
   else
   break;
   
}

}
