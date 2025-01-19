#include <bits/stdc++.h>
using namespace std;

void generate_subsequences(int index, vector<int>& v, vector<int>& current) {
    if (index == v.size()) {
        cout << "{ ";
        for (int x : current) cout << x << " ";
        cout << "}" << endl;
        return;
    }

    generate_subsequences(index + 1, v, current);

    current.push_back(v[index]);
    generate_subsequences(index + 1, v, current);
    current.pop_back(); 
}

int main() {
    int n; cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    cout << "Subsequences are:" << endl;
    vector<int> current; 
    generate_subsequences(0, v, current);

    return 0;
}
