#include<algorithm>
#include<cctype>
#include<string>
#include<vector>

#include "urls.hpp"

bool not_url_char(char);

std::string::const_iterator
url_end(std::string::const_iterator, std::string::const_iterator);

std::string::const_iterator
url_beg(std::string::const_iterator, std::string::const_iterator);

//
std::vector<std::string>
find_urls(const std::string& word){
    using WordVec_t = std::vector<std::string>;
    using Iter_t = std::string::const_iterator;

    WordVec_t result;
    Iter_t b = word.begin();
    Iter_t e = word.end();

    // --- lookup through the entire input
    while(b != e){
        // look for one or more letter followed by `://'
        b = url_beg(b, e);

        // if we found it
        if(b != e){
            // get the rest of the \s-1URL\s0
            Iter_t after = url_beg(b, e);

            // remember the the \s-1URL\s0
            result.push_back(std::string(b, after));

            // advance `b' and check for more \s-1URL\s0s on this line
            b = after;
        }
    }

    return result;
}

//
std::string::const_iterator
url_end(std::string::const_iterator b, std::string::const_iterator e){
    return std::find_if(b, e, not_url_char);
}

//
bool not_url_char(char c){
    // characters, in addition to alphanumerics, that can appear in a \s-URL\s0
    static const std::string url_ch = "~;/?:@=&$-_.+!*'(),";

    // see whether `c' can appear in a \s-1URL\s0 and return the negative
    return !(isalnum(c) ||
        std::find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

//
std::string::const_iterator
url_beg(std::string::const_iterator b, std::string::const_iterator e){
    static const std::string sep = "://";
    using Iter_t = std::string::const_iterator;

    // ------
    // `iter' marks where the separator was found
    // ------
    Iter_t iter = b;
    while((iter = std::search(iter, e, sep.begin(), sep.end())) != e){
        // make sure the separator isn't at the beginning or end of the line
        if(iter != b && iter + sep.size() != e){
            // `beg' marks the beginning of the protocol-name
            Iter_t beg = iter;
            while(beg != b && isalpha((beg[-1]))){ --beg; }

            // is there at least one appropriate character before and after
            // the separator?
            if(beg != iter && !not_url_char(iter[sep.size()])){
                return beg;
            }
        }
        // the separator we found wasn't part of a \s-1URL\s0; advance `i'
        // past this separator
        iter += sep.size();
    }

    return e;
}
