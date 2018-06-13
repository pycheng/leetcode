//#dp
#if 0
Given two sequences A, B, find out number of unique ways in sequence A, 
to form a subsequence of A that is identical to the sequence B. 
Transformation is meant by converting string A (by removing 0 or 
more characters) to string B.

Input : A = "abcccdf", B = "abccdf"
Output : 3
Explanation : Three ways will be -> "ab.ccdf",   "abc.cdf" & "abcc.df" 
["." is where character is removed. ]

Input : A = "aabba", B = "ab"
Output : 4
Expalnation : Four ways will be -> "a.b..", "a..b.", ".ab.." & ".a.b." 
["." is where char  acters are removed.]
#endif
#include <iostream>
#include <string>
using namespace std;

int cntxform(string a, string b){
    int **dp; 
    int row = a.size();
    int col = b.size();
    int rslt;
    
    dp = (int**)malloc(sizeof(int*)*col);
    dp[0] = (int*)malloc(sizeof(int)*col*row);
    memset(dp[0], 0, sizeof(int)*col*row);

    for(int i=1; i<col; i++){
        dp[i] = dp[0]+i*row;
    }
    
    cout <<  "\nallocate memory" << dp[0] <<".." << dp[0]+col*row<<"\n"; 
    cout << sizeof(int)*col*row <<".."<< sizeof(int) <<"\n";
    for(int k=0; k<col; k++){
        for(int h=0; h<row; h++){
            cout<<&dp[k][h]<<",";
        }
        cout<<"\n";
    }
    cout <<  "\nallocate memory" << dp <<".." << dp+col<<"\n"; 
    cout << sizeof(int*)*col <<".."<< sizeof(int*) <<"\n";
    for(int k=0; k<col; k++){
            cout<<&dp[k]<<",";
    }
    cout<<"\n";
    cout << col << "," << row <<"\n\n";

    for(int i=0; i<col; i++){
        for(int j=i; j<row; j++){
            if(i==0){
                if(a[j] == b[i] && j == 0){
                    dp[i][j]=1;
                }else if(a[j] == b[i]){
                    dp[i][j]=dp[i][j-1]+1;
                }else{
                    dp[i][j]=dp[i][j-1];
                }
            }else{
                if(a[j] == b[i]){
                    dp[i][j]=dp[i][j-1]+dp[i-1][j-1];
                }else{
                    dp[i][j]=dp[i][j-1];
                }
            }
            cout<<"("<<i<<","<<j<<"), ";
        }

        cout << "\n----------------\n"; 
        for(int k=0; k<col; k++){
            for(int h=0; h<row; h++){
                cout<<dp[k][h]<<",";
            }
            cout<<"\n";
        }
    }

    rslt = dp[col-1][row-1]; 

        cout << "\n----------------\n"; 
        int oh = 0;
        for(int k=0; k<col; k++){
            for(int h=0; h<row; h++){
                dp[k][h]=oh++;
            }
        }
        cout << "\n----------------\n"; 
        for(int k=0; k<col; k++){
            for(int h=0; h<row; h++){
                cout<<dp[k][h]<<",";
            }
            cout<<"\n";
        }
    free(dp);
    free(dp[0]);
    return rslt;
}

int main(){
    //string a = "abcccdf";
    //string b = "abccdf";
    string a = "aabba";
    string b = "ab";
   
    cout << cntxform(a,b);

    return 0;
}
