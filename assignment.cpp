#include <fstream>
#include <iostream>
#include <memory>
#include <vector>
#include<stack>
#include<stdio.h>
#include <bits/stdc++.h>
using namespace std;

//Note: Do not change any part of the existing code.
int main(int argc, char *argv[]) {
    std::vector<int> numVec;
    int nextNum;
    ifstream inFile;
    inFile.open("input");
    ofstream outfile;
    outfile.open("output");

    while(inFile >> nextNum){
        
        numVec.push_back(nextNum);
    }
    
    // Write your code to remove all occurences 3 contiguous numbers that add up to 0 from the vector numVec
    // Note that the output vector should not have any occurances where 3 contiguous numbers sum to 0

    stack<int> s;
    for(int j=0;j<numVec.size();j++) 
    {
    	s.push(numVec[j]);
        if(s.size()>=3)
        {
            int x=s.top();
            s.pop();
            int y=s.top();
            s.pop();
            int z=s.top();
            s.pop();
            int sum=x+y+z;
            if(sum!=0)
            {
                s.push(z);
                s.push(y);
                s.push(x);
            }
        }
    }
    vector<int>ans;
    while(!(s.empty()))
    {
        ans.push_back(s.top());
        s.pop();
    }
    reverse(ans.begin(),ans.end());
    numVec.clear();
    for (int i=0;i<ans.size();i++){
        numVec.push_back(ans[i]);
    }

   for(int i = 0;i<numVec.size();i++) {
      outfile << numVec[i] << endl; 
   }
}
