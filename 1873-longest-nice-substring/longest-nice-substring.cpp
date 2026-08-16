class Solution {
public:
    string longestNiceSubstring(string s) {
        string ans = "";

        for(int i = 0; i < s.length(); i++)
        {
            for(int j = i; j < s.length(); j++)
            {
                string temp = s.substr(i, j - i + 1);

                bool ok = true;

                for(char ch : temp)
                {
                    if(islower(ch))
                    {
                        if(temp.find(toupper(ch)) == string::npos)
                        {
                            ok = false;
                            break;
                        }
                    }
                    else
                    {
                        if(temp.find(tolower(ch)) == string::npos)
                        {
                            ok = false;
                            break;
                        }
                    }
                }

                if(ok && temp.length() > ans.length())
                {
                    ans = temp;
                }
            }
        }

        return ans;
        
    }
};