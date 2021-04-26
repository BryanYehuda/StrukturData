#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void construct_segment_tree(vector<LL> &segtree, vector<LL> &a, LL n)
{
    for (LL i = 0; i < n; i++)
    {
    	segtree[n + i] = a[i];
	}
        
    for (LL i = n - 1; i >= 1; i--)
    {
    	segtree[i] = max(segtree[2 * i],segtree[2 * i + 1]);
	}
}

void change(vector<LL> &segtree, LL pos, LL value, LL n)
{
    pos = pos + n;
    segtree[pos] = value;

    while (pos > 1)
    {
        pos >>= 1;
        segtree[pos] = max(segtree[2 * pos], segtree[2 * pos + 1]);
    }
}

LL maximum(vector<LL> &segtree, LL left, LL right, LL n)
{
    left = left + n;
    right = right + n;
    LL flag = (int)-1e9;

    while (left < right)
    {
        if (left & 1)
        {
            flag = max(flag, segtree[left]);
            left++;
        }

        if (right & 1)
        {
            right--;
            flag = max(flag, segtree[right]);
        }
        left /= 2;
        right /= 2;
    }
    return flag;
}

int main()
{
    LL n, q, query, x, y, t;
    cin >> n >> q;
    vector<LL> a;
    for (LL i = 0; i < n; i++)
    {
        cin >> t;
        a.push_back(t);
    }
    LL S = a.size();
    vector<LL> segtree(2 * S);
    construct_segment_tree(segtree, a, S);

    for (LL i = 0; i < q; i++)
    {
        cin >> query >> x >> y;
        if (query == 1)
        {
            change(segtree, x-1, y, S);
        }
        else
        {
            cout << maximum(segtree, x - 1, y, S) << endl;
        }
    }

    return 0;
}
