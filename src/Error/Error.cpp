#include "Error.h"
#include <sstream>


using namespace std;


void Container::add(const string &key, const string &value) {
    bool added = false;
    auto current = this->_container.begin();
    while(!added && current != this->_container.end()){
        if(key == current->first){
            current->second.insert(value);
            added = true;
        }
        current++;
    }
    if(!added) {
        this->_container.insert(pair<string, set<string>>(key, set<string> {value}));
    }
    this->_has = true;
}

void Container::merge(const Container & ctr) {
    for(auto p_to_map_element = this->_container.begin(); p_to_map_element != this->_container.end(); p_to_map_element++)
    {
        for(auto p_form_map_element = ctr._container.begin(); p_form_map_element != ctr._container.end(); p_form_map_element++)
        {
            if(p_to_map_element->first == p_form_map_element->first)
            {
                p_to_map_element->second.insert(p_form_map_element->second.begin(), p_form_map_element->second.end());
            }
            else
            {
                this->_container.insert(* p_form_map_element);
            }
        }
    }

}

std::string Container::toString(int tabing) const {
    stringstream strm;

    for(auto pelemnt = this->_container.begin(); pelemnt != this->_container.end(); pelemnt++){
        strm << string(tabing,'\t') << pelemnt->first  <<" : [";
        int i = 0;
        for(auto pmessage = pelemnt->second.begin(); pmessage != pelemnt->second.end(); pmessage++){
            if(0 == i){
                strm << * pmessage;
            }else{
                strm << ", " << * pmessage;
            }
            i++;
        }
        strm << "]" << endl;
    }
    return strm.str();
}

std::string Container::toString() const {
    return Container::toString(0);
}

void Error::mergeAll(const Error &other) {
    this->info.merge(other.info);
    this->warning.merge(other.warning);
    this->error.merge(other.error);
}

string Error::toString() const {
    stringstream s;
    s << "{" << endl;
    if(this->info.has()) {
        s << " Info:" << endl;
        s << this->info.toString(1);
    }
    if(this->warning.has()) {
        s << " Warning:" << endl;
        s << this->warning.toString(1);
    }
    if(this->error.has()){
        s << " Error:" << endl;
        s << this->error.toString(1);
    }
    s << "}" << endl;
    return s.str();
}

std::ostream & operator<<(std::ostream & strm, Error const & err){
    strm << err.toString();
    return strm;
}
