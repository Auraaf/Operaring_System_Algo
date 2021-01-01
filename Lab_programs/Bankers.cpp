#include<bits/stdc++.h>
using namespace std;

  /*int m , n ;
  int All[10][10]; //= {{ 0 , 1 , 0} , { 2 ,0 ,0 }, { 3, 0 , 2}, { 2 , 1, 1} , { 0 , 0 , 2}};
  
  int Max[10][10] ;//= {{ 7 ,5, 3} , { 3 ,2, 2}, { 9 ,0 ,2}, { 2 ,2, 2} , { 4 , 3 ,3}};
  
  int Ava[10] ;//= { 3 , 3, 2};*/

bool safe_states( vector<vector<int>>  &All , vector<vector<int>> &Need , vector<int> &Ava)
{
  int  n  =All.size();
   int m = Ava.size();
   
  
   int work[m];
   int k = 0;
   for(k = 0; k< m ;k++)
   work[k] = Ava[k];
   bool finish[n];
   
   for(int i =0; i< n; i++)
   finish[i] = false;
   vector<int> prc;
   for(int  i =0 ; i< n; i++)
   {
        for( int  j = 0; j< n; j++)
     {
					if(!finish[j])
					{
					  
					     k = 0;
						 
								while( Need[j][k] <= Ava[k] && k<m)
								k++;
								
								
						 if ( k == m)
						 {  cout<<"P"<<j<<" ";
								for( k = 0; k< m ;k++)
								     cout<<Need[j][k]<<" "; 
								     
								     cout<<"  ";
								for( k = 0; k< m ;k++)
								{
								   
										 Ava[k] = Ava[k] + All[j][k];
										 cout<<Ava[k]<<" ";
								}     
										 //cout<< j <<" ";
										 finish[j] = true;
										 prc.push_back(j);
										 cout<<endl;
						 }
						 
						 
					 
				  }
     }   
						if(prc.size() == n)
						break;     
	 }
	 
	      for (int w= 0; w< m ; w++)
	        {
	         int sum =0;
	         for(int f = 0; f< n ; f++)
	          sum = sum + All[f][w];
	         Ava[w] = Ava[w] - sum; 
	        }
	        
	        
	        
					 if(prc.size() == n)
					 {
						for( int  j = 0; j< n; j++)
						 cout<<prc[j]<<" ";
						
						cout<< endl<<"safe"<<endl;
						 prc.clear();
						 
						 
					return true;
					 }
					 
					 
					 else
						{
							for(k = 0; k< m ;k++)
								Ava[k] = work[k]  ;
								cout<<endl<<"unsafe"<<endl;
							 prc.clear();
							return false;
							}

}



int main()
{ 
    int m = 3; int n = 5;int k;int p_no ;
    vector<vector<int>> All =  {{ 0 , 1 , 0} , { 2 ,0 ,0 }, { 3, 0 , 2}, { 2 , 1, 1} , { 0 , 0 , 2}};
  
    vector<vector<int>> Max = {{ 7 ,5, 3} , { 3 ,2, 2}, { 9 ,0 ,2}, { 2 ,2, 2} , { 4 , 3 ,3}};
  
    vector<int> Ava = { 3 , 3, 2};
    
    vector<int> Req ;//= { 1, 0 ,2 };
    vector< int > temp = { 3 ,3, 2};
    int i;
    
    vector<vector<int>>  Need;
      vector<int> row;
    int val;
     
     while(true)
     {
     int prg;
     cin>>prg; 
     if(  prg == 1) 
      break;
     else
     {
          for (int  i = 0; i <n; i++) 
     {
     for(int j = 0; j< m; j++)
     { 
         
         row.push_back(Max[i][j] - All[i][j]);
     }
     Need.push_back(row);
     row.clear();
     }
  
  
     i = 0;
     int val;
      for(int  l = 0; l< m ; l++)
      { 
       cin>>val;
       Req.push_back(val); 
      }
      
      while(Req[i] <= temp[i] && i< m)
       i++;
      
     p_no = 1; 
    
    
    
    if(i == m)
     {
				  for( i = 0; i< m; i++)
				  {
								All[p_no][i] += Req[i];
								cout<<All[p_no][i];
								Need[p_no][i] -= Req[i];
                 cout<<" "<<Need[p_no][i]		;						
								temp[i] -= Req[i];
								cout<<" "<<temp[i]<<endl;
								
				  }
				  
				  
				  
				  
				  
				   if( safe_states(All ,Need , temp ))
				   {
								 cout<<"Acc"<<"  "; 
								 for( i = 0; i< m; i++) 
								 {
								   Ava[i] = temp[i] ;    
								 cout<<Ava[i] << "  ";

								 }
								 				   }
				   
				   else
				   {
									cout<< "Not_acc";
									
									for( i = 0; i< m; i++)
								{
									All[p_no][i] -= Req[i];
									Need[p_no][i] += Req[i];
								 }
							}	 
     }
      
       Req.clear();
     }

     }
 }    
            
   /* vector<int> row;
    int val;
     for (int  i = 0; i <5; i++) 
     {
     for(int j = 0; j< 3; j++)
     { 
         cin>>val;
         row.push_back(val);
     }
     All.push_back(row);
     row.clear();
     }*/
   //safe_states (All, Need,Ava);
   
   
      

















