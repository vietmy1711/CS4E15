#include <iostream>
#include <stack>

using namespace std;

string encodeString(string s)
{
    stack<char> st;
    string res;
    int count = 1;
    st.push(s[0]);
    for (int i = 1; i < s.size(); ++i)
    {
        char c = s[i];
        if (st.top() != c)
        {
            res += st.top() + to_string(count);
            st.pop();
            st.push(c);
            count = 1;
        }
        else
        {
            count++;
        }
    }

    while (!st.empty())
    {
        res += st.top() + to_string(count);
        st.pop();
    }
    return res;
}

int main()
{
    string s;
    cin >> s;

    cout << encodeString(s);

    return 0;
}
