class Solution
{
public:
    string removeHash(string a)
    {
        int idx = 0; //  a##c ab#c
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] == '#')
            {
                idx--;
                if (idx < 0)
                    idx = 0;
            }
            else
            {
                a[idx] = a[i];
                idx++;
            }
        }
        return a.substr(0, idx);
    }

    bool backspaceCompare(string s, string t)
    {
        s = removeHash(s);
        t = removeHash(t);
        if (s.length() != t.length())
            return false;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != t[i])
                return false;
        }
        return true;
    }
};