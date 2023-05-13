#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

struct WordFrequency {
    string word;
    int frequency;
    bool operator<(const WordFrequency& other) const {
        if (frequency != other.frequency) {
            return frequency < other.frequency;
        }
        return word > other.word;
    }
};

void getMostFrequentWords(int k, const string& text) {
    stringstream ss(text);
    string word;
    unordered_map<string, int> frequencyMap;
    while (ss >> word) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
        frequencyMap[word]++;
    }

    priority_queue<WordFrequency> pq;
    for (auto& entry : frequencyMap) {
        pq.push({entry.first, entry.second});
    }

    // Print the top k words
    for (int i = 0; i < k && !pq.empty(); i++) {
        WordFrequency wf = pq.top();
        pq.pop();
        cout << wf.word << '\t' << wf.frequency << endl;
    }
}

int main() {
    int k;
    cin >> k;
    cin.ignore();
    string text;
    getline(cin, text);
    getMostFrequentWords(k, text);
    return 0;
}
