#include <iostream>
#include <stack>
using namespace std;
stack<int> mystack;
int main()
{
    string input;
    getline(cin, input);
    while (input.size() != 0)
    {
        int r_plus_pos = input.rfind("+");
        //cout << "input[r_plus_pos+1] = " << input.substr(r_plus_pos + 1) << endl;
        if (r_plus_pos == -1)
        {
            mystack.push(stoi(input.substr(r_plus_pos + 1)));
            break;
        }
        int in_s = stoi(input.substr(r_plus_pos + 1));
        //cout << in_s << endl;
        mystack.push(stoi(input.substr(r_plus_pos + 1)));
        //cout << "r_plus_pos = " << r_plus_pos;
        input.resize(r_plus_pos);
    }
    int ans = 0;
    while (!mystack.empty())
    {
        ans += mystack.top();
        mystack.pop();
    }
    cout << ans;
    return 0;
}
