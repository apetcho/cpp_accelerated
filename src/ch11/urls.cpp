#include<algorithm>
#include<cctype>
#include<string>

#include "Vec.hpp"
#include "urls.hpp"

static bool not_url_char(char);

static std::string::const_iterator
url_end(std::string::const_iterator, std::string::const_iterator);

static std::string::const_iterator
url_beg(std::string::const_iterator, std::string::const_iterator);

// ---
Vec<std::string> find_urls(const std::string& text){
    Vec<std::string> result;
    using iter_t = std::string::const_iterator;

    iter_t b = text.begin();
    iter_t e = text.end();

    // look through the entire input
    while(b != e){
        // look for one or more letters followed by `://'
        b = url_beg(b, e);
        // if we found it
        if(b != e){
            // get the rest of the \s-1URL\s0
            iter_t after = url_end(b, e);
            // remember the \s-1URL\s0
            result.push_back(std::string(b, after));
            // advance `b' and check for more \s-1URL\s0s on line
            b = after;
        }
    }

    return result;
}


static std::string::const_iterator
url_end(std::string::const_iterator b, std::string::const_iterator e){
    return std::find_if(b, e, not_url_char);
}

static bool not_url_char(char c){
    static const std::string url_ch = "~;/?:@=&$-$.+!*'(),";
    // see whether `c' can appear in a \s-1URL\s0 and return the negative
    return !(isalnum(c) ||
        std::find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

//
static std::string::const_iterator
url_beg(std::string::const_iterator b, std::string::const_iterator e){
    static const std::string sep = "://";
    using iter_t = std::string::const_iterator;

    // `i' marks where the separator was found
    iter_t i = b;
    while((i = std::search(i, e, sep.begin(), sep.end())) != e){
        // make sure the separator isn't at the beginning or end of the line
        if(i != b && i + sep.size() != e){
            // `beg' marks the beginning of the protocol-name
            iter_t beg = i;
            while(beg != b && isalpha(beg[-1])){ --beg; }

            // is there at least one appropriate character before and after
            // the separator?
            if(beg != i && !not_url_char(i[sep.size()])){ return beg; }
        }

        // the separator we found wasn't part of a \s-1URL\s0; advance
        // `i' past this separator
        i += sep.size();
    }

    return e;
}
