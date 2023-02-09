/*
구현 문제이다. 

총 4가지의 상태가 있다. 
1. 기둥 설치
  - y==0 ?
  - 현재 설치할 기둥 아래에 기둥 존재? 
  - 현재설치할 기둥 기준으로 양 옆에 하나라도 보가 존재? 
2. 보 설치
  현재 설치될 보의 양 옆 인덱스는 각각 (x,y) / (x+1,y) 
  - x 기준으로 y-1,y 로 설치된 기둥이 존재? 
  - x+1 기준으로 y-1,y로 설치된 기둥이 존재? 
  - 보 양 옆에 이미 설치된 보가 존재? 
3. 기둥 삭제
  - (1) 이미 존재하고 있는 기둥에 영향
    - 바로 위에 있는 기둥이 존재한다면, 해당 기둥이 존재할 수 있는지? 
  - (2) 이미 존재하고 있는 보에 영향
    - 현재 삭제할 기둥에 붙어 있는 보들이 존재한다면, 해당 보들이 존재할 수 있는지? 
4. 보 삭제
 - (1) 이미 존재하고 있는 기둥에 영향
    - 삭제할 보 양 끝 인덱스 기준으로 설치된 기둥이 있는지 확인하고, 해당 기둥들이 존재할 수 있는지?
 - (2) 이미 존재하고 있는 보에 영향
    - 삭제할 보 양 끝 인덱스 기준으로 설치된 보들이 있는지 확인하고, 해당 보들이 존재할 수 있는지? 
    
세부적으로 코드에 작성되어 있는대로 구현하면 된다. 

*/

#include <bits/stdc++.h>
using namespace std;

set<pair<int,int>> bo[111];
set<pair<int,int>> gidung[111];

bool isAddGidung(int x,int y){
    if(y==0) return true;
    if(gidung[x].count({y-1,y})) return true;
    if(bo[y].count({x-1,x}) or bo[y].count({x,x+1})) return true;
    return false;
}
bool isAddBo(int x,int y){
    if(gidung[x].count({y-1,y})) return true;
    if(gidung[x+1].count({y-1,y})) return true;
    if(bo[y].count({x-1,x})and bo[y].count({x+1,x+2})) return true;
    return false;
}
bool isDelGidung(int x,int y){
    // 현재 기둥위에 또다른 기둥이 존재하는지
    gidung[x].erase({y,y+1});
    bool flag = true;
    if(gidung[x].count({y+1,y+2})){
        if(!bo[y+1].count({x-1,x}) and !bo[y+1].count({x,x+1})) flag = false;
    }
    // y+1 에 설치된 bo에 영향을 끼치는지 
    int left = x-1;
    while(bo[y+1].count({left,left+1})){
        if(!isAddBo(left,y+1)) flag = false;
        left--;
    }
    left = x;
    while(bo[y+1].count({left,left+1})){
        if(!isAddBo(left,y+1)) flag = false;
        left++;
    }
    if(!flag){
        gidung[x].insert({y,y+1});
    }
    return true;
}
bool isDelBo(int x,int y){
    bo[y].erase({x,x+1});
    bool flag = true;
    if(gidung[x].count({y,y+1})){
        if(!isAddGidung(x,y)) flag = false;
    }
    if(gidung[x+1].count({y,y+1})){
        if(!isAddGidung(x+1,y)) flag = false;
    }
    
    if(bo[y].count({x-1,x})){
        if(!isAddBo(x-1,y)) flag = false;
    }
    if(bo[y].count({x+1,x+2})){
        if(!isAddBo(x+1,y)) flag = false;
    }
    if(!flag){
        bo[y].insert({x,x+1});
    }
    return true;
}
struct P{
    int x;
    int y;
    int type;
};
bool cmp(P a,P b){
    if(a.x==b.x){
        if(a.y==b.y){
            return a.type<b.type;
        }
        return a.y < b.y;
    }
    return a.x < b.x;
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    
    for(auto u : build_frame){
        int x = u[0], y = u[1];
        int type = u[2], add = u[3];
        
        if(add){
            if(type==1){ // 보
                if(isAddBo(x,y)){
                    cout << "ADD BO" <<x << " " << y <<"\n";
                    bo[y].insert({x,x+1});
                }
            }else{ // 기둥
                if(isAddGidung(x,y)){
                    cout <<"ADD GIDUNG" <<x <<" " << y <<"\n";
                    gidung[x].insert({y,y+1});
                }
            }
        }else{
            if(type==1){ // 보
                if(isDelBo(x,y)){
                    cout <<"DEL BO" << x <<" " << y <<"\n";
                    // bo[y].erase({x,x+1});
                }
            }else{ // 기둥
                if(isDelGidung(x,y)){
                    cout <<"DEL GIDUNG" << x <<" " << y <<"\n";
                    // gidung[x].erase({y,y+1}g);
                }
            }
        }
    }
    vector<P> v;
    for(int i=0;i<=n;i++)
    {
        for(auto u : bo[i]){
            P temp;
            temp.x = u.first;
            temp.y = i;
            temp.type = 1;
            // cout << temp.x <<" " << temp.y <<" " << temp.type <<"\n";
            v.push_back(temp);
        }
        for(auto u : gidung[i]){
            P temp;
            temp.x = i;
            temp.y = u.first;
            temp.type = 0;
            // cout << temp.x <<" " << temp.y <<" " << temp.type <<"\n";
            v.push_back(temp);
        }
    }
    sort(v.begin(),v.end(),cmp);
    
    for(auto u : v){
        vector<int> temp;
        temp.push_back(u.x);
        temp.push_back(u.y);
        temp.push_back(u.type);
        answer.push_back(temp);
    }
    
    return answer;
}
