#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std ;
#define max(a,b) a > b ? a : b

int n , a[110] , b[110] , c[110];

// b is the output array and c is temporary
// k is the max number in the input array a

void Counting_Sort(int k){
    for(int i = 0 ; i <= k ; i++ ) c[i] = 0 ;
    for(int j = 1 ; j <= n ; j++ ) c[ a[j] ] = c[ a[j] ] + 1 ;
    for(int i = 1 ; i <= k ; i++ ) c[i] = c[i] + c[i-1] ;
    for(int j = n ; j >= 1 ; j-- ){
        b[ c[ a[j] ] ] = a[j];
        c[ a[j] ]-- ;
    }
}

int main(){
   int K = 0 ;
   scanf("%d",&n);
   for(int i = 1 ; i <= n ; i++ ) {
        scanf("%d",&a[i]);
        K = max(a[i],K);
   }
   Counting_Sort(K);
   for(int i = 1 ; i <= n ; i++ ) printf("%d ",b[i]);
}
