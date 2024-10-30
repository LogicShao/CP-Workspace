    #include <bits/stdc++.h>
    using namespace std;
    void work()
    {
        string s;
        cin >> s;
        vector<int> a(s.size(), 0);
        for (int i = 0; i < s.size() - 2; i++)
        {
            char ch1 = s[i], ch2 = s[(i + 1)], ch3 = s[(i + 2)];
            if (ch1 == ch2 && ch2 == ch3)
            {
                cout << "No" << endl;
                return;
            }
        }
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            if (ch == '[' || ch == ']')
                a[i] = 1;
            if (ch == '(' || ch == ')')
                a[i] = 2;
        }
        int ans = 0;
        for (int i = 1; i < a.size(); i++)
        {
            ans += a[i] == a[i - 1];
        }
        if (ans < 3)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    int main()
    {
        int t;
        cin >> t;
        while (t--)
        {
            work();
        }
    }