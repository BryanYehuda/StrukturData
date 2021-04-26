#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main()
{
 vector< LL > atom;
 atom.push_back(2);
 while (atom.back() <= (LL)1e18)
 {
  LL ans = (LL)atom.size() + 1;
  LL tmp = 2 * ans * ans;
  atom.push_back(tmp + atom.back());
 }
 LL tc;
 cin >> tc;
 while (tc--)
 {
  LL k;
  cin >> k;
  LL ans = lower_bound(atom.begin(),atom.end(),k) - atom.begin() + 1;
  cout << ans << endl;
 }
 return 0;
}
