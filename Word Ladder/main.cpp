class Solution {
private:
    int dis(string s1, string s2) {
        int cnt = 0;
        for(int i = 0;i<s1.size();i++) {
            if(s1[i] != s2[i]) cnt++;
        }

        return cnt;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();

        unordered_set<string> s;
        s.insert(beginWord);
        queue<pair<string,int>> q;
        q.push({beginWord,1});

        if(find(begin(wordList),end(wordList),endWord) == wordList.end()) return 0;

        while(!q.empty()) {
            pair<string,int> p = q.front();
            q.pop();

            string s1 = p.first;
            int mut = p.second;

            if(s1 == endWord) return mut;

            for(auto i: wordList) {
                if(s.find(i) == s.end()) {
                    if(dis(s1,i) == 1) {
                        s.insert(i);
                        q.push({i,mut+1});
                    }

                }
            }

        }

        return 0;

    }
};