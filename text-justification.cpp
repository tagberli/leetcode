class Solution {
public:
    // solution time: ~1h, beats 8%, needs further optimization
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int curWidth = 0;
        int curSize = 0;
        int i = 0;
        
        while(i < words.size()){
            if(curWidth + words[i].size() + curSize <= maxWidth){
                curWidth += words[i].size();
                curSize++;
                i++;
                continue;
            }
            int extraSpace = maxWidth - curWidth; 
            string line;
            if(curSize > 1){
                int spacePerWord = extraSpace / (curSize - 1);
                int rem = extraSpace - (spacePerWord * (curSize - 1));

                // retrieve the words and fully-justified spaces
                for(int j = i - curSize; j < i; j++){
                    line += words[j];
                    if(j + 1 == i) continue;
                    line += string(spacePerWord + (rem > 0), ' ');
                    rem--;
                }
            }else{
                for(int j = i - curSize; j < i; j++){
                    line += words[j];
                }
                line += string(extraSpace, ' ');
            }

            ans.push_back(line);
            curWidth = 0;
            curSize = 0;
        }
        // last line
        if(curWidth){
            int extraSpace = maxWidth - curWidth - (curSize - 1); 

            // retrieve the words and add left-justified spaces
            string line;
            for(int j = i - curSize; j < i; j++){
                line += words[j];
                if(j + 1 == i) continue;
                line += " ";
            }
            line += string(extraSpace, ' ');

            ans.push_back(line);
            curWidth = 0;
            curSize = 0;
        }
        return ans;
    }
};
