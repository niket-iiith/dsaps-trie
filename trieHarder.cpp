#include<iostream>
#include<string>
#include<vector>

using namespace std;

class trieNode
{
    private :
        trieNode* letter[26];
        bool end;
    
    public:
        trieNode(){
            for(int i=0; i<26; i++) letter[i] = NULL;
            end = false;
        }

        // returns true if node has letter 'c'
        bool hasletter(char c){
            if( letter[c - 'a'] != NULL ) return true;
            else return false;
        }

        // put letter 'c' into the node
        void putletter(trieNode* node, char c){
            letter[c - 'a'] = node;
        }

        // get node with letter 'c'
        trieNode* getletter(char c){
            return letter[c - 'a'];
        }

        // set letter 'end' to true
        void setEnd(){
            end = true;
        }

        // return true if 'end' == true
        bool isEnd(){
            return end;
        }
};

class trieHarder
{
    private:
        trieNode* root;
        char alphabets[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    public:
        trieHarder(){
            root = new trieNode();
        }

        // inserts a word into the trie
        void insertWord(string word){
            trieNode* node = root;
            for(int i=0; i<word.size(); i++)
            {
                // if current node don't have letter = 'word[i]', then put that letter in the current node 
                if( !node->hasletter(word[i]) ){
                    node->putletter(new trieNode(), word[i]);
                }
                // move to the node with letter = 'word[i]'
                node = node->getletter(word[i]);
            }
            node->setEnd();
        }

        bool searchWord(string word){
            trieNode* node = root;
            for(int i=0; i<word.length(); i++)
            {
                // if current node has letter = 'word[i]', then move to next node with letter = 'word[i]'
                if(node->hasletter(word[i])){
                    node = node->getletter(word[i]);
                }
                else {
                    return false;
                }
            }

            // if the current node 'end' == true, then it is a word
            return node->isEnd();
        }

        void autocomplete(trieNode* root, string str, vector<string>& result)
        {
            if(root->isEnd()){
                result.push_back(str);
            }

            // iterate through all letters; if present, then iterate using recuresion; else return    
            for(int i=0; i<26; i++){
                if(root->hasletter(alphabets[i])){
                    autocomplete(root->getletter(alphabets[i]), str+alphabets[i], result);
                }

            }
        }

        vector<string> beginsWith(string prefix)
        {
            trieNode* node = root;
            vector<string> result;

            // iterate to the prefix
            for(int i=0; i<prefix.size(); i++){
                if(node->hasletter(prefix[i])){
                    node = node->getletter(prefix[i]);
                }
                else{
                    cout << "error: prefix not found" << endl;
                    return result;
                }
            }

            // print all the possible words from here
            string str = "" ;
            autocomplete(node, str, result);

            return result;
        }

};


int main()
{
    trieHarder* dict = new trieHarder();
    int n, q;
    cin >> n >> q;

    while(n--){
        string s;
        cin >> s;

        dict->insertWord(s);
    }

    int a[q];
    int _q = q;
    string t[q];
    int i = 0;

    while(_q--){
        cin >> a[i] >> t[i];
        i++;
    }

    for(int j=0; j<q; j++){
        switch(a[j])
        {
            // spell-check
            case 1 : {
                if(dict->searchWord(t[j])) 
                    cout << "1" << endl;
                else 
                    cout << "0" << endl; 
            }
                break;
            
            case 2 : {
                vector<string> result = dict->beginsWith(t[j]);
                if(result.size()){
                    cout << result.size() << endl;
                    for(int i=0; i<result.size(); i++){
                        cout << t[j] << result[i] << endl;
                    }
                }
                else    
                    cout << "0" << endl;
            }

            case 3 : {

            }
        }
    }

}