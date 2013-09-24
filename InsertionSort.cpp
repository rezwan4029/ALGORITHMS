#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std ;
#define max(a,b) a > b ? a : b

int n , a[110] ;

void Insertion_Sort(){
    for(int j = 2 ; j <= n ; j++ ){
        int key = a[j] ,  i = j - 1 ;
        while( i > 0 && a[i] > key ){
            a[i+1] = a[i];
            i--;
        }
        a[i+1] = key ;
    }
}

int main(){
   scanf("%d",&n);
   for(int i = 1 ; i <= n ; i++ ) {
        scanf("%d",&a[i]);
   }
   Insertion_Sort();
   for(int i = 1 ; i <= n ; i++ ) printf("%d ",a[i]);
}
