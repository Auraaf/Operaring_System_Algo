 import java.util.*;
 import java.util.Scanner;
 
 import java.io.*;
  
 class Main
 {
     
     public static int FindSmallest (int [] arr1) {
       int index = 0;
       int min = arr1[index];

       for (int i=1; i<arr1.length; i++) {
           

           if (arr1[i] < min) {
               min = arr1[i];
               index = i;
           }
           
       }
       return index;
}


     
     public static void main(String args[])
     {
         Scanner in = new Scanner(System.in); 
           int size;
           size = in.nextInt();
           
          int[] frame;
          frame = new int[size];
          boolean[] check;
          check = new boolean[100];
          for(int i =0; i< 100; i++)
             check[i] = false;
          int[] time ;
          time = new int [size];
          
           
 
 int k = 0;
 int val;
  
 
 int  pg_flt = 0;
 
 for(int i = 0; i <size ; i++)
 {
  val = in.nextInt();
  frame[i] =  val;
  time[i] = i;
  check[val] = true;
  //cout<<frame[i][0]<<" ";
  pg_flt += 1;
 } 
  System.out.println("Frame snapshot:");
 for(int m = 0; m < size ; m++ )
 {   
     System.out.println(frame[m]);}
  k = size -1;
  
  
 while(true)
 { 
   
   val = in.nextInt();
   if(val != -1)
   { 
     
     k++;
      int  i = 0;
   if(check[val])
   { System.out.println( "No page fault" );
   while(frame[i] != val)
      i++;
      //System.out.println(i);
      time[i] = k;
      check[val]  = true;
   }
   
   
   else
   {System.out.println("Page_fault occurs");
    pg_flt += 1;
    i = FindSmallest(time);
     
     //cout<<i<<endl;
     check[frame[i]] = false;
     System.out.println("page:" + val +" replaces page:" +frame[i]);
     frame[i] = val;
     check[val] = true;
     time[i] = k; 
   }
      System.out.println("Frame snapshot:");
     for(int m = 0; m < size ; m++ )
     {  
        System.out.println(frame[m] );    
     }
     
     
   }
   
   else
   {  System.out.println("Total Page_fault:" + pg_flt);
     break;  
   }
   
   
}
     }
     

   
 }
 
