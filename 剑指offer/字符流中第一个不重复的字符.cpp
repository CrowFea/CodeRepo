class Solution
{
public:
    string s;
    int m[256]={0};
  //Insert one char from stringstream
    void Insert(char ch)
    {
        s+=ch;
        m[ch]++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        for(int i=0;i<s.size();i++){
            if(m[s[i]]==1)    return s[i];
        }
        return '#';
    }

};