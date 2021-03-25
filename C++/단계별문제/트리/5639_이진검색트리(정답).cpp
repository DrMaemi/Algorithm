#include <iostream>

using namespace std;

int arr[10002];

void print_tree(int l, int r){
    
    if(l>r) return;
    
    int root = arr[l];
    int p = r;
    while(arr[p]>root)
        p--;
    
    print_tree(l+1, p);
    print_tree(p+1, r);
    
    cout<<root<<"\n";
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int i = 0;
    int tmp = 0;
    
    while(cin>>tmp){
        if(tmp==EOF)
            break;
        arr[i] = tmp;
        i++;
    }
    
    print_tree(0, i-1);
    
    return 0;
}