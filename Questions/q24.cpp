// Print All Subsets: Write a recursive function to print all possible subsets of a given set.


#include <bits/stdc++.h>
using namespace std;

void printSubsets(const vector<int>& set , vector<int>& subset , int index){
    if(index == set.size()){
        cout<<"{";
        for (int num : subset)
        {
            cout<<num<<" ";
        }
        cout<<"}"<<endl;
        return;
    }
    // Recursive case: Explore including the current element in the subset.
    subset.push_back(set[index]);
    printSubsets(set, subset, index + 1);

    // Backtrack by excluding the current element from the subset.
    subset.pop_back();

    // Recursive case: Explore excluding the current element in the subset.
    printSubsets(set, subset, index + 1);
}

int main()
{  
   vector<int> set;
   set.push_back(1);
   set.push_back(2);
   set.push_back(3);
   vector<int> subset;

   printSubsets(set,subset,0);
   return 0;
}