class Solution {
  public:
    int wordLadderLength(string startWord, string targetWord,
                         vector<string>& wordList) {
    unordered_set<string>words(wordList.begin(), wordList.end());
        unordered_set<string>visited;
        queue<string>q;
        q.push(startWord);
        int level = 1;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                string temp = q.front();
                q.pop();
                if(temp == targetWord){
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