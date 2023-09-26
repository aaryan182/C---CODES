#include <bits/stdc++.h>
using namespace std;

int main()
{  
    // creation of ordered map or map TC: O(log n)
    map<string, int> m;

    // creation of unorder map (order is not the same as given input) TC: O(1)
    // unordered_map<string, int> um;

    //insertion

    // 1 method
    pair<string,int> p = make_pair("aaryan", 1);
    m.insert(p);
    
    // 2 method
    pair<string,int> pair2("abc", 1);
    m.insert(pair2);

    // 3 method
    m["abc"] = 2;

    //searching 
    cout<<m["abc"]<<endl;
    cout<<m.at("aaryan")<<endl;

    //cout<<m.at("xyz")<<endl;
    cout<<m["xyz"]<<endl; // it made a new entry for xyz and return output as 0
    // jaise hi hum ab likhengae na m.at wali line tou ab zero show hoga kyunki upar wali line ek entry bnadi uski 

    cout<<m.at("xyz")<<endl;

    // size 
    cout<<m.size()<<endl;

    //to check presence of key
    cout<<m.count("abc")<<endl;
    // if key is not found it returns zero 
    cout<<m.count("ac")<<endl;

    // erase
    m.erase("abc");
    cout<<m.size()<<endl;

    // method 1 to access all the elements of map 
    for(auto i:m)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }

    // method 2 using iterators accessing all the elements of map
    map<string, int>::iterator it = m.begin();

     while (it!=m.end())
     {
        cout<<it->first<<" "<<it->second<<endl;
        it++;
     } 
     

   return 0;
}