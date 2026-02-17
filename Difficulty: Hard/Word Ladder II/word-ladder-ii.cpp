// User function Template for C++

class Solution {
  public:
    vector<vector<string>> findSequences(string beginWord, string endWord,
                                         vector<string>& wordList) {
        unordered_set<string>words(wordList.begin(), wordList.end());
        vector<vector<string>>ans;
        queue<vector<string>>q;
        q.push({beginWord});
        vector<string>usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;
        while(!q.empty()){
            vector<string>vec = q.front();
            q.pop();

            if(vec.size() > level){
                level++;
                for(auto it: usedOnLevel){
                    words.erase(it);
                }
                usedOnLevel.clear();
            }

            string word = vec.back();
            if(word == endWord){
                if(ans.size() == 0){
                    ans.push_back(vec);
                }
                else if(ans[0].size() == vec.size()){
                    ans.push_back(vec);
                }
            }
            for(int i = 0; i < word.size(); i++){
                char original = word[i];
                for(char c = 'a'; c <= 'z'; c++){
                    word[i] = c;
                    if(words.count(word) > 0){
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};