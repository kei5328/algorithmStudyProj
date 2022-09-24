
class Solution {
public:
    bool wordPattern(string pattern, string s) {

        bool result = true;
        // generate a hash map
        HashMap * map = init_map();

        // loop thru the pattern and string.
        uint16_t start=0;
        uint16_t fin = 0;
        for (int ii = 0; ii<pattern.size(); ii++)
        {
            char key = pattern[ii];
            string word = find_word_idx(s, start, start, fin);
            if (word=="") return false;
            start = fin+1;

            if (!(is_member(map, key)))
            {// this word does not exist in the map yet.
                if (is_val_member(map, word)) return false;
                add_to_map(map, key, word);
            }
            else
            {// word already exists in the map. We need to check if it's the same
                string map_str = get_val_from_key(map, key);
                if (map_str!=word)
                {
                    // they are different!
                    result = false;
                    return result;
                }
            }
        }

        if (fin+1<s.size()) return false;
        return result;
    }
private:

    struct HashNode
    {
        char key;
        string val;
    };


    struct HashMap
    {
        struct HashNode * arr[26];
    };

    // this function creates the hash node with input key and val pair.
    HashNode * init_node(char key, string &val)
    {
        HashNode* node = new HashNode;
        if (node==NULL) return NULL;
        node->key = key;
        node->val = val;
        return node;
    }
    HashMap * init_map()
    {
        HashMap * map = new HashMap;
        if (map==NULL) return NULL;
        for (int ii = 0; ii<26; ii++)
        {
            map->arr[ii] = NULL;
        }
        return map;
    }


    int hash_function(char key)
    {
        int result = (int)(key-'a');
        if (result<0 || result>26) result = -1;
        return result;
    }

    bool is_member(HashMap * map, char key)
    {
        char node_key;
        HashNode * node;
        int idx = hash_function(key);
        if (idx<0 || idx>25)
            return false;

        if (map->arr[idx]==NULL)
        {
            return false;
        }
        else
        {
            node = map->arr[idx];
            node_key = node->key;
        }
        return (node_key==key);
    }
    bool is_val_member(HashMap * map, string val)
    {
        for (int ii = 0; ii<26; ii++)
        {
            if (map->arr[ii]!=NULL)
            {
                if (val==((map->arr[ii])->val))
                    return true;
            }
        }
        return false;
    }

    string get_val_from_key(HashMap * map, char key)
    {
        string node_val;
        HashNode * node;
        if (!(is_member(map, key)))
        {// key does not exist
            return "";
        }
        else
        {
            int idx = hash_function(key);

            if (idx<0 || idx>25)
                return "";
            if (map->arr[idx]==NULL)
            {
                return "";
            }
            else
            {
                node = map->arr[idx];
                node_val = node->val;
            }
        }
        return node_val;
    }


    bool add_to_map(HashMap * map, char key, string val)
    {
        if (is_member(map, key))
        { // already exists
            return false;
        }
        else
        {
            int idx = hash_function(key);
            if (idx<0 || idx>25)
                return false;
            HashNode * node = init_node(key, val);
            if (node==NULL) return false;
            map->arr[idx] = node;
        }
        return true;
    }

    string find_word_idx(string& s, uint16_t curr_idx, uint16_t & start, uint16_t& fin)
    {
        int len = s.size();
        string result;
        if (curr_idx>len) return "";
        for (uint16_t ii = curr_idx; ii<=len; ii++)
        {
            if (s[ii]!= ' ')
            {
                start = ii;
                break;
            }
        }
        for (uint16_t ii = (start)+1; ii<=len; ii++)
        {
            if (s[ii]== ' ' || s[ii]== '\0')
            {
                fin = ii-1;
                break;
            }
        }
        return s.substr(start, fin-start+1);
    }
};
