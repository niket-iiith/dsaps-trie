#include<iostream>
#include<string>

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

        void beginsWith(string prefix)
        {
            trieNode* node = root;

            // iterate to the prefix
            for(int i=0; i<prefix.size(); i++){
                if(node->hasletter(prefix[i])){
                    node = node->getletter(prefix[i]);
                }
                else{
                    cout << "error: prefix not found" << endl;
                    return;
                }
            }

            // print all the possible words from here
            

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

            }

            case 3 : {

            }
        }
    }

}