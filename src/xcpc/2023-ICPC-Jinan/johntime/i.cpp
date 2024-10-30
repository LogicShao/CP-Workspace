#include <bits/stdc++.h>
using namespace std;
void work()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++){
        if(a[i]==i+1) continue;
        for(int j=n-1;j>i;j--){
            if(a[j]<a[i]){
                ans.push_back({i,j});
                sort(a.begin()+i,a.begin()+j+1);
                if(is_sorted(a.begin(),a.end())) goto end;
            }
        }
    }
    end:
    cout << ans.size() << endl;
    for (auto [x, y] : ans)
        cout << x + 1 << ' ' << y + 1 << endl;
}
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
        work();
}