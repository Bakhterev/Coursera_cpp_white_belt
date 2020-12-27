
class SortedStrings {
public:
  void AddString(const string& s) {
    words.push_back(s);
  }
  vector<string> GetSortedStrings() {
    sort(begin(words), end(words));
    return words;
  }
private:
  vector<string> words;
};

