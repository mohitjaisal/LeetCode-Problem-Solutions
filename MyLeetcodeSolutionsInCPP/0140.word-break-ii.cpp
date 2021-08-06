class Solution {
public:
    unordered_set<string> dict;
    unordered_map<string, vector<string>> cache;

    vector<string> next(const string &s) {
        if (cache.find(s) != cache.end()) return cache[s];
        vector<string> v;
        if (s.empty()) v.push_back("");

        for (int i = 1, n = s.size(); i <= n; ++i) {
            string word = s.substr(0, i);
            if (dict.find(word) == dict.end()) continue;

            vector<string> v1 = next(s.substr(i));
            for (auto &s1 : v1) v.push_back(word + (s1.empty() ? "" : " ") + s1);
        }
        return cache[s] = v;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (auto &word : wordDict) dict.insert(word);
        return next(s);
    }
};
