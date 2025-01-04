class Solution {
private:
    int dis(string s1, string s2) {
        int cnt = 0;
        for(int i = 0;i<8;i++) {
            if(s1[i] != s2[i]) cnt++;
        }
        return cnt;
    }
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int n = bank.size();
        unordered_set<string> s;
        queue<pair<string,int>> q;
        q.push({startGene,0});
        s.insert(startGene);
        
        while(!q.empty()) {
            pair<string,int> p = q.front();
            q.pop();

            string s1 = p.first;
            int mut = p.second;

            if(s1 == endGene) return mut;

            for(auto i: bank) {
                if(s.find(i) == s.end()) {
                    if(dis(i,s1) == 1) {
                        s.insert(i);
                        q.push({i,mut+1});
                    }
                }
            }
        }

        return -1;
    }
};