/*
누적합 문제이다. 
(y1,x1) ~ (y2,x2) 에 T 만큼의 값을 변경하기 위해선 
(y1,x1), (y2+1,x2+1) : +T 
(y1,x2+1) , (y2+1,x1) : -T 

T 0 0 0 -T
0 0 0 0 0
0 0 0 0 0
-T0 0 0 -T

를 왼쪽에서 오른쪽으로 그다음, 위에서 아래로 누적합하게 되면

T T T T 0 ...
T T T T 0 ...
T T T T 0 ...
0 0 0 0 0 ...
... 


*/

#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int n = board.size(); int m = board[0].size();
    vector<vector<int>> psum(n,vector<int>(m,0));
    for(int i=0;i<skill.size();i++){
        int value = (skill[i][0]==1?-1:1) * skill[i][5];
        int y1,x1,y2,x2; 
        y1 = skill[i][1], x1 = skill[i][2], y2 = skill[i][3], x2 = skill[i][4];
        psum[y1][x1] += value;
        if(y2+1<n) psum[y2+1][x1] += -value;
        if(x2+1<m) psum[y1][x2+1] += -value;
        if(y2+1<n&&x2+1<m) psum[y2+1][x2+1] += value;
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            psum[i][j] += psum[i][j-1];
        }
    }
    for(int j=0;j<m;j++)
    {
        for(int i=1;i<n;i++)
        {
            psum[i][j] += psum[i-1][j];
        }
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            board[i][j]+=psum[i][j];
            if(board[i][j]>0) answer++;
        };
    }
    
    
    return answer;
}
