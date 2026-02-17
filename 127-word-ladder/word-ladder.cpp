class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>words(wordList.begin(), wordList.end());
        unordered_set<string>visited;
        queue<string>q;
        q.push(beginWord);
        int level = 1;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                string temp = q.front();
                q.pop();
                if(temp == endWord){
                    return level;
                }
                    for(int i = 0; i < temp.size(); i++){
                        string s = temp;
                        for(char ch = 'a'; ch <= 'z'; ch++){
                        s[i] = ch;

                        if(visited.find(s) == visited.end() && words.find(s) != words.end()){
                            visited.insert(s);
                            q.push(s);
                            words.erase(s);
                        }
                    }
                }
            }
            level++;
        }
        return 0;
    }
};