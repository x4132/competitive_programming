#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        map<string, bool> vMap;
        map<string, string> iMap;

        for (string s : wordList)
        {
            vMap.insert_or_assign(s, false);
        }

        queue<string> wordQueue;
        wordQueue.push(beginWord);
        vMap.insert_or_assign(beginWord, true);
        iMap.insert_or_assign(beginWord, "");
        while (!wordQueue.empty())
        {
            string cur = wordQueue.front();
            wordQueue.pop();
            for (int i = 0; i < cur.length(); i++)
            {
                string st = cur.substr(0, i);
                string en = cur.substr(0 + 1 + i, cur.length());
                for (int c = 0; c < 26; c++)
                {
                    string mid = "";
                    mid.push_back((char)((int)'a' + c));

                    auto iter = vMap.find(st + mid + en);
                    if (iter != vMap.end() && iter->second == false)
                    {
                        if (st + mid + en == endWord)
                        {
                            int dist = 0;
                            string next = cur;
                            while (1)
                            {
                                dist++;
                                auto iter = iMap.find(next);
                                if (iter != iMap.end())
                                {
                                    next = iter->second;
                                }
                                else
                                {
                                    break;
                                }
                            }

                            return dist;
                        }
                        
                        vMap.insert_or_assign(st + mid + en, true);
                        iMap.insert_or_assign(st + mid + en, cur);
                        wordQueue.push(st + mid + en);
                    }
                }
            }
        }

        return 0;
    }
};

int main()
{
    Solution s;
    string sArr[] = {"hot", "dot", "dog", "lot", "log"};
    vector<string> wl(begin(sArr), end(sArr));
    cout << s.ladderLength("hit", "cog", wl);
}