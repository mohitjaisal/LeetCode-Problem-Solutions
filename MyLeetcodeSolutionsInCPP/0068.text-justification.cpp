class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int p = 0, start = 0, sizecount = 0;
        vector<string> ans;
        while (p < words.size())    {
            if (sizecount + p - start + words[p].length() <= L)  {
                sizecount += words[p].length();
                p++;
            }
            else    {
                ans.push_back(generate(words, start, p - 1, sizecount, L));
                sizecount = 0;
                start = p;
            }
        }
        if (words.size() - 1 >= start)
            ans.push_back(generate1(words, start, words.size() - 1, sizecount, L));
        
        return ans;
    }
    
    string generate(vector<string> &words, int start, int end, int length, int L)   {
        if (end == start)   {
            return words[start] + string(L - length, ' ');
        }
        else    {
            string s = words[start];
            int bn = end - start, ball = L - length;
            for (int i = start + 1; i <= end; i++)  {
                s += string(ball / bn + (ball % bn >= i - start), ' ');
                s += words[i];
            }
            return s;
        }
    }
    
    string generate1(vector<string> &words, int start, int end, int length, int L)   {
        if (end == start)   {
            return words[start] + string(L - length, ' ');
        }
        else    {
            string s = words[start];
            for (int i = start + 1; i <= end; i++)  {
                s += " ";
                s += words[i];
            }
            s += string(L - s.length(), ' ');
            return s;
        }
    }
};
