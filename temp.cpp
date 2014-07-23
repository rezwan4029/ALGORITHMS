const int MX = 50 ;
void Print( int x[MX][MX] , int n ){
    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < n ; j++ ) printf("%4d",x[i][j]);
        puts("");
    }
}
void Rotate( int m[MX][MX], int n ){
    for( int layer = 0 ; layer < n /2 ; layer++ ){
        int first = layer ;
        int last = n - layer - 1 ;
        for( int i = first ; i < last ; i++ ){
            int offset = i - first;
            int top = m[first][i];
            m[first][i] = m[last - offset][first];
            m[last-offset][first] = m[last][last-offset];
            m[last][last-offset] = m[i][last];
            m[i][last] = top ;
        }
    }
    cout << "Final : \n" << endl;
    Print(m,n);
}

int main(){
    int n ;
    cin >> n ;
    int a[MX][MX];
    for( int i = 0 ; i < n ; i++ ) for( int j = 0 ; j < n ; j++ ) a[i][j] = n*i+j +1;
    cout << "Initial : \n" << endl;
    Print(a,n);
    puts("");
    Rotate(a,n);
}
