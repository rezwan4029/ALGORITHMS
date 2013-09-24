#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std ;

void swap(int &x , int &y){
    int temp = x ;
    x = y , y = temp ;
}

int a[110] ;

int partition(int p , int r){
    int x = a[ r ] ;
    int i = p - 1 ;
    for(int j = p ; j < r  ; j++ ){
            if( a[j] <= x ){
                i++ ;
                swap(a[i],a[j]);
            }
    }
    swap(a[i+1],a[r]);
    return i + 1 ;
}

void Qsort(int p , int r){
    if( p < r ){
        int q = partition(p,r);
        Qsort(p,q-1);
        Qsort(q+1,r);
    }
}

int main(){
   int n ;
   scanf("%d",&n);
   for(int i = 0 ; i < n ; i++ ) scanf("%d",&a[i]);
   Qsort(0,n-1);
   for(int i = 0 ; i < n ; i++ ) printf("%d ",a[i]);
}
