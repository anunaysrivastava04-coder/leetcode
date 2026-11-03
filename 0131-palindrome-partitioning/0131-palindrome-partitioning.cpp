class Solution {
public:
    bool isPalindrome( int start , int end , string s ){
        while( start <= end ){
            if(s[start] == s[end]){
                start++;
                end--;

            }
            else{

                return false;
            }
        }
        return true; 

    }
    void combo( string s , vector<string> &curr , vector<vector<string>> &ans , int start , int end ){
        if( start == s.size() ){
            ans.push_back(curr);
            return;
        }
        for( end = start ; end < s.size() ; end++ ){
            if( isPalindrome( start , end , s )){

                curr.push_back(s.substr( start , end-start+1 ));
                combo( s , curr , ans , end+1 , end );
                curr.pop_back();
            }

        }

    }
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        vector<vector<string>> ans;
        int start = 0;
        int end = 0;
        combo( s , curr , ans , start , end );
        return ans;   
    }
};