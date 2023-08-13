#include <climits>
#include <string>
#include <vector>
#include <memory>
#include <iostream>

class Trie {
public:
    Trie() { }
    
    void insert(const std::string & word) {
      node.insert(word, 0);
    }
    
    bool search(const std::string & word) {
      return node.search(word, 0);
    }
    
    bool startsWith(const std::string & prefix) {
      return node.startsWith(prefix, 0);
    }
  
private:
  	struct Node {
      Node() : isEnd(false) {
        next.resize(26);
      }
      
      auto & get_node(char c) {
        return next[c - 'a'];
      }
      
      void insert(const std::string & word, int start) {
        if (start >= word.size()) return;

        auto & next_node = get_node(word[start]);
        if (!next_node) {
          next_node = std::make_shared<Node>();
        }
        next_node->insert(word, start+1);

        if (start + 1 == word.size())
            next_node->isEnd = true;
      }
      
      bool search(const std::string & word, int start) {
        if (start == word.size()) {
          return isEnd;
        }

        // std::cerr << word.substr(start) << std::endl;
        
        auto & next_node = get_node(word[start]);
        if (next_node) {
          return next_node->search(word, start + 1);
        } else {
          return false;
        }
      }

      bool startsWith(const std::string & word, int start) {
        if (start == word.size()) {
          return true;
        }
        
        auto & next_node = get_node(word[start]);
        // std::cerr << word.substr(start) << ((void *) next_node.get()) << std::endl;
        if (next_node) {
          return next_node->startsWith(word, start + 1);
        } else {
          return false;
        }
      }

      std::vector<std::shared_ptr<Node>> next;
      bool isEnd;
    };
  
  	Node node;
};

int main() {
  Trie t;
  t.insert("abc");
  std::cerr << t.search("abc") << std::endl;
  std::cerr << t.search("ab") << std::endl;
  std::cerr << t.search("abb") << std::endl;
  std::cerr << t.search("abcd") << std::endl;
  std::cerr << t.startsWith("ab") << std::endl;
  std::cerr << t.startsWith("abb") << std::endl;
  return 0;
}