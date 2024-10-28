#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define PLL pair<LL, LL>

struct crop
{
    LL w, l, r;
};

bool crop_cmp(const crop &a, const crop &b)
{
    return a.w < b.w;
}

void solve()
{
    LL n, m;
    cin >> n >> m;

    vector<crop> cr(n);
    LL tot = 0;
    LL least_time = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> cr[i].w >> cr[i].l >> cr[i].r;
        tot += cr[i].w * cr[i].l;
        least_time += cr[i].l;
    }
    sort(cr.begin(), cr.end(), crop_cmp);

    vector<LL> left_w(n + 1, 0);
    for (int i = 0; i < n; ++i)
        left_w[i + 1] = left_w[i] + cr[i].w * (cr[i].r - cr[i].l);

    LL ans_1 = tot + (m - least_time) * cr[n - 1].w;
    LL ans_2 = tot, tot_time = least_time;
    
    LL np, np_use;
    for (np = n - 1; np >= 0; --np)
    {
        tot_time += cr[np].r - cr[np].l;
        ans_2 += cr[np].w * (cr[np].r - cr[np].l);
        if (tot_time >= m)
        {
            ans_2 -= cr[np].w * (tot_time - m);
            np_use = cr[np].r - (tot_time - m);
            tot_time = m;
            break;
        }
    }

    LL max_ans_2 = max(ans_1, ans_2);
    for (int i = 0; i < n; ++i)
    {
        LL t_ans = ans_2, t_time = m;

        if (i > np)
        {
            t_ans -= cr[i].r * cr[i].w;
            t_time -= cr[i].r;
        }
        else if (i == np)
        {
            t_ans -= np_use * cr[i].w;
            t_time -= np_use;
        }
        else
        {
            t_ans -= cr[i].l * cr[i].w;
            t_time -= cr[i].l;
        }

        if (t_ans + (m - t_time) * cr[np].w < max_ans_2)
            continue;
        if (t_ans + left_w[np + 1] < max_ans_2)
            continue;
        
        for (int j = np; j >= 0; --j)
        {
            
            if (t_ans + (m - t_time) * cr[j].w < max_ans_2 || t_ans + left_w[j + 1] < max_ans_2)
                break;
            
            if (j == i)
                // continue;
                break;
            if (j == np)
            {
                t_time += cr[j].r - np_use;
                t_ans += cr[j].w * (cr[j].r - np_use);
            }   
            else
            {
                t_time += cr[j].r - cr[j].l;
                t_ans += cr[j].w * (cr[j].r - cr[j].l);
            }

            if (t_time >= m)
            {
                t_ans -= cr[j].w * (t_time - m);
                t_time = m;
                break;
            }
        }
        if (t_time < m)
            t_ans += (m - t_time) * cr[i].w;
        max_ans_2 = max(t_ans, max_ans_2);

        // cout << i << " " << t_ans << "\n";
    }
    // cout << ans_1 << " " << ans_2 << " " << max_ans_2 << '\n';
    ans_2 = max_ans_2;

    cout << max(ans_1, ans_2);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}