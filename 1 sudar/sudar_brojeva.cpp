#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace::std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string a, b;
    cin >> a >> b;
    string c = "";
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int i;
    for(i=0;i<min(a.length(), b.length()); i++) {
        if(a[i] == b[i]) c += a[i], c += a[i];
        else c += max(a[i], b[i]);
    }
    while(i<a.length()) c += a[i++];
    while(i<b.length()) c += b[i++];
    reverse(c.begin(), c.end());
    cout << c << '\n';
    return 0;
}
