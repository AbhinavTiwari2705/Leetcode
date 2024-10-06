class Solution {
public:
    vector<string> splitSentence(const string &sentence) {
    vector<string> words;
    size_t start = 0, end;
    while ((end = sentence.find(' ', start)) != string::npos) {
        words.push_back(sentence.substr(start, end - start));
        start = end + 1;
    }
    
    words.push_back(sentence.substr(start));
    return words;
}

bool areSentencesSimilar(string s1, string s2) {
    vector<string> words1 = splitSentence(s1);
    vector<string> words2 = splitSentence(s2);

    int n1 = words1.size(), n2 = words2.size();
    int i = 0;

    if (n1 > n2) {
        return areSentencesSimilar(s2, s1);
    }
    
    while (i < n1 && words1[i] == words2[i]) {
        ++i;
    }

    while (i < n1 && words1[i] == words2[n2 - n1 + i]) {
        ++i;
    }

    return i == n1;
}
};
