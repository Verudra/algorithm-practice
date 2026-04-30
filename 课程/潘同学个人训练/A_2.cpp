#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    vector<int>vec(n+1);
    for(int i = 1;i <= n;i ++) scanf("%d",&vec[i]);
    auto getMaxposAndMinval = [](vector<int>& vec) -> pair<int,int> {
        int k = -1, maxn = 0, minn = 100;
        for(int i = 1;i < vec.size();i ++){
            if(vec[i] >= maxn) maxn = vec[i], k = i;
            if(vec[i] != 0) minn = min(minn, vec[i]);
        }
        return make_pair(vec[k]==0?-1:k,minn);
    };
    for(int i = 1;;i ++){
        auto pr = getMaxposAndMinval(vec);
        if(pr.first == -1){
            printf("%d",i-1);
            break;
        }
        else vec[pr.first] -= pr.second;
    }
    return 0;
}