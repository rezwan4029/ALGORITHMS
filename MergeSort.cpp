#include <stdio.h>
#include <math.h>
#include <stdlib.h>
using namespace std ;

#define INF 100000000

int n , a [110] , L [110] , R [100] ;

void MERGE(int p , int q , int r){
    int n1 = q - p + 1 ;
    int n2 = r - q ;
    for( int i = 1 ; i <= n1 ; i++ ) L[i] = a[ p + i - 1 ];
    for( int j = 1 ; j <= n2 ; j++ ) R[j] = a[ q + j ];
    L[ n1 + 1 ] =  R[ n2 + 1 ] = INF ;
    int i = 1 , j = 1 ;
    for( int k = p ; k <= r ; k++ ){
        if( L[i] <= R[j] ){
            a[k] = L[i] ;
            i++;
        }
        else{
            a[k] = R[j];
            j++;
        }
    }
}

void MERGE_SORT(int p , int r ){
    if( p < r ){
        int q = floor( (p+r)/2 );
        MERGE_SORT(p,q);
        MERGE_SORT(q+1,r);
        MERGE(p,q,r);
    }
}

int main(){
   scanf("%d",&n);
   for(int i = 1 ; i <= n ; i++ ) {
        scanf("%d",&a[i]);
   }
   MERGE_SORT(1,n);
   for(int i = 1 ; i <= n ; i++ ) printf("%d ",a[i]);
}
