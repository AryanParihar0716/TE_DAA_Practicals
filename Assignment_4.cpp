/*#include<bits/stdc++.h>
using namespace std;


class Queen{
  private:
  int n;
  int *x;
  public:
   void Count(){
      cout<<"Enter number of queens"<<endl;
      cin>>n;
      cout<<"Number of queens are :"<<n<<endl;
      cout<<"ChessBoard is of size"<<n*n<<""<<endl;
      x=new int[n]();
   }
   bool place(int k, int i){
      for(int j=0;j<k;j++){
         if((x[j]==i || abs(x[j]-i)==abs(j-k))){
            return false;}
      }
      return true;
   
   }
   void queen(int k){
     for(int i=0;i<n;i++){
         if(place(k,i)){
            x[k]=i;
            if(k==n)
              for(int i=0;i<n;i++){
                cout<<i<<":"<<x[i]<<endl;
              }
         }
         else{
           queen(k+1);
         }
         
         }
     
     }
   
   };
int main(){
   Queen q1;
   q1.Count();
   q1.queen(0);
   return 0;
   
}*/
#include <bits/stdc++.h>
using namespace std;

class Queen {
private:
    int n;
    vector<int> x; // Use vector instead of raw pointer

public:
    void Count() {
        cout << "Enter number of queens: ";
        cin >> n;
        cout << "Number of queens are: " << n << endl;
        cout << "ChessBoard is of size " << n << "x" << n << endl;
        x.resize(n, -1); // Initialize with -1
    }

    bool place(int k, int i) {
        for (int j = 0; j < k; j++) {
            if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
                return false;
            }
        }
        return true;
    }

    void queen(int k) {
        if (k == n) {  // Base case: all queens placed
            for (int i = 0; i < n; i++) {
                cout << i << ": " << x[i] << endl;
            }
            cout << "-----" << endl;
            return;
        }

        for (int i = 0; i < n; i++) {
            if (place(k, i)) {
                x[k] = i;      // Place queen
                queen(k + 1);  // Recurse to next row
                x[k] = -1;     // Backtrack
            }
        }
    }
};

int main() {
    Queen q1;
    q1.Count();
    q1.queen(0);
    return 0;
}

