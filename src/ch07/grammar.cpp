#include<algorithm>
#include<stdexcept>
#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>
#include<map>
#include<ctime>

#include "../ch05/split.hpp"

using Rule = std::vector<std::string>;
using RuleCollection = std::vector<Rule>;
using Grammar = std::map<std::string, RuleCollection>;

/** read a grammar from a given input stream */
static Grammar read_grammar(std::istream& stream){
    Grammar result;
    std::string line;

    using Entry = std::vector<std::string>;

    /* read the input */
    while(std::getline(stream, line)){
        /** `split' the input into words */
        Entry entry = split(line);
        if(!entry.empty()){
            result[entry[0]].push_back(Rule(entry.begin()+1, entry.end()));
        }
    }

    return result;
}

//
static void gen_aux(
    const Grammar&, const std::string&, std::vector<std::string>&);

static int nrand(int);

//
static std::vector<std::string>
gen_sentence(const Grammar& grammar){
    std::vector<std::string> result;
    gen_aux(grammar, "<sentence>", result);
    return result;
}

//
static bool bracketed(const std::string& text){
    return text.size() > 1 && text[0] == '<' && text[text.size()-1] == '>';
}

//
static void
gen_aux(
    const Grammar& grammar,
    const std::string& word, std::vector<std::string>& retval
){
    if(!bracketed(word)){
        retval.push_back(word);
    }else{
        // locate the rule that correspont to `word'
        Grammar::const_iterator iter = grammar.find(word);
        if(iter == grammar.end()){
            throw std::logic_error("empty rule");
        }

        // fetch the set of possible rules
        const RuleCollection& collection = iter->second;

        // from which we select one at random
        const Rule& rule = collection[nrand(collection.size())];

        // recursively expand the selected rule
        for(Rule::const_iterator riter = rule.begin();
            riter != rule.end(); riter++)
        {
            gen_aux(grammar, *riter, retval);
        }
    }
}

// --- MAIN DRIVER ---
int main(){
    // generate the sentence
    std::vector<std::string> sentence = gen_sentence(read_grammar(std::cin));

    // write the first word, if any
    std::vector<std::string>::const_iterator iter = sentence.begin();

    if(!sentence.empty()){
        std::cout << *iter;
        ++iter;
    }

    // write the rest of the words, each preceded by a space
    while(iter != sentence.end()){
        std::cout << " " << *iter++;
    }

    std::cout << std::endl;

    return EXIT_SUCCESS;
}


// return a random integer in the range `[0, n]'
static int nrand(int n){
    if(n <= 0 || n > RAND_MAX){
        throw std::domain_error("Argument to nrand() is out of range");
    }

    const int bucket_size = RAND_MAX / n;
    int r;
    do{
        r = rand()/bucket_size;
    }while(r >= n);

    return r;
}
