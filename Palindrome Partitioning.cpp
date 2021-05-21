/*--------------------------------------Question--------------------------------------------------------*/

Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.
  
  
  /*----------------------------------------Solution---------------------------------------------------*/
  
  class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> pars;
        vector<string> par;
        partition(s,0,par,pars);
        return pars;
    }
    
    void partition(string s,int start,vector<string>& par,vector<vector<string>>& pars){
        int n=s.length();
        if(start==n){
            pars.push_back(par);
            
        }
        else{
            for(int i=start;i<n;i++)
                if(isPalindrome(s,start,i)){
                   par.push_back(s.substr(start,i-start+1));
                   partition(s,i+1,par,pars);
                   par.pop_back();   //Backtrack
                }
         }
    }
    
    bool isPalindrome(string s,int lo,int hi)
    {
        while(hi>=lo){
            if(s[hi--]!=s[lo++])
                return false;
        }
        return true;
    }
};
