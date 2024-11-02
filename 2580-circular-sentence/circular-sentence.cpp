class Solution {
public:
    bool isCircularSentence(string sentence) {
        stringstream ss(sentence);
        string word;
        char f = sentence[0];
        char prev = f;
        string last = "";
        while(ss >> word){
            if(prev != word[0]) return false;
            prev = word[word.size()-1];
            last = word;
        }
        if(f != last[last.size()-1]) return false;
        return true;
    }
};