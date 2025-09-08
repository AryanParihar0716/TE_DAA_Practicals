#include <bits/stdc++.h>
using namespace std;
class knapsack{
    int m,n;
    vector<float> p;
    vector<float> w;
   public:
   void input(){ // input function for dynamic/user defined weights,no.of items,prices and knapsack size
    cout<<"Enter size of knapsack\n";
    cin>>m;
    cout<<"Enter total number of items\n";
    cin>>n;
    cout<<"Enter profits and weights\n";
    for(int i=0;i<n;i++){
        float a=0,b=0;
        cout<<"Enter weight "<<i+1<<"\n";
        cin>>a;
        w.push_back(a);                    //push_back function is a function which is used for putting values into array
        cout<<"\nEnter profit "<<i+1<<"\n";
        cin>>b;
        p.push_back(b);
        cout<<endl;
    }
    cout<<"\nInput complete!\n";
   }
  /* void bubbleSort(){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if ((p[j]/w[j])<=(p[j+1]/w[j+1])){ //sort in descending order according to profit/weight ratio
               swap(p[j],p[j+1]);
               swap(w[j],w[j+1]);

        }
    }
   }
 
}*/
 
     void merge(int left, int mid, int right) {        //merge functionality which merges two parts of array together
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<float> Lp(n1), Lw(n1), Rp(n2), Rw(n2);     //created dynamic array
        for (int i = 0; i < n1; i++) {
            Lp[i] = p[left + i];
            Lw[i] = w[left + i];
        }
        for (int j = 0; j < n2; j++) {
            Rp[j] = p[mid + 1 + j];
            Rw[j] = w[mid + 1 + j];
        }

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            float r1 = Lp[i] / Lw[i];
            float r2 = Rp[j] / Rw[j];
            if (r1 >= r2) {
                p[k] = Lp[i];
                w[k] = Lw[i];
                i++;
            } else {
                p[k] = Rp[j];
                w[k] = Rw[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            p[k] = Lp[i];
            w[k] = Lw[i];
            i++; k++;
        }
        while (j < n2) {
            p[k] = Rp[j];
            w[k] = Rw[j];
            j++; k++;
        }
    }

    void mergeSort(int left, int right) {       //mergeSort Logic
        if (left < right) {
            int mid = (left + right) / 2;
            mergeSort(left, mid);
            mergeSort(mid + 1, right);
            merge(left, mid, right);          //Call to the merge logic
        }
    }
    void sortItems(){      //an additional fumction to call mergeSort to sort items properly
       mergeSort(0,n-1);
    }
   vector<float> frac_knap (){ //knapsack function
    vector<float> x(n,0);
    int i,u=m;
    for(i=0;i<n;i++){ //loop through all items
        if(w[i]>u) break; //if weight of item is greater than remaining capacity, break
        else{
        x[i]=1.0; //else add whole item
        u-=w[i];
        } //reduce remaining capacity
    }
    if(i<=n){ //if there are still items left
        x[i]=u/w[i]; //add fraction of the next item
    }
    
    return x;//return the vector containing fractions of items added to knapsack
   }
   int calc_profit(vector<float> x){ //calculate profit from the fractions of items added to knapsack
    int profit=0;
    for(int i=0;i<n;i++){
        profit+=x[i]*p[i]; //multiply fraction of item by its profit and add to total profit
    }
    return profit; //return total profit
   }

};
int main(){ //main function
    knapsack k; //create knapsack class object
    k.input(); //take input
    k.sortItems(); //sort items according to profit/weight ratio
   vector<float> x =k.frac_knap(); //call knapsack function to get fractions of items added to knapsack
    cout<<"Knapsack is\n"; 
    for(float a:x){
        cout<<a<<" "; //print fractions of items added to knapsack
    }  
    cout<<endl;
    cout<<"Profit is "<<k.calc_profit(x)<<endl; //calculate and print total profit
    return 0;
}
