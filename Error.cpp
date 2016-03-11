//
// Created by bmolnar on 2016.03.11..
//

#include <ostream>
#include "Error.h"
#include <sstream>


using namespace std;

void Error::_add(map<string, set<string>> & mp, const string & key, const string & value) {
    bool added = false;
    auto current = mp.begin();
    while(!added && current != mp.end()){
        if(key == current->first){
            current->second.insert(value);
            added = true;
        }
        current++;
    }
    if(!added) {
        mp.insert(pair<string, set<string>>(key, set<string> {value}));
    }
}

void Error::_merge(map<string, set<string>> & mp1, const map<string, set<string>> & mp2){
    for(auto p_to_map_element = mp1.begin(); p_to_map_element != mp1.end(); p_to_map_element++)
    {
        for(auto p_form_map_element = mp2.begin(); p_form_map_element != mp2.end(); p_form_map_element++)
        {
            if(p_to_map_element->first == p_form_map_element->first)
            {
                p_to_map_element->second.insert(p_form_map_element->second.begin(), p_form_map_element->second.end());
            }
            else
            {
                mp1.insert(* p_form_map_element);
            }
        }
    }

}

std::string Error::_tostring(const map<string, set<string>> &mp) {
    stringstream strm;

    for(auto pelemnt = mp.begin(); pelemnt != mp.end(); pelemnt++){
        strm << pelemnt->first << " : [";
        int i = 0;
        for(auto pmessage = pelemnt->second.begin(); pmessage != pelemnt->second.end(); pmessage++){
            if(0 == i){
                strm << * pmessage;
            }else{
                strm << ", " << * pmessage;
            }
            i++;
        }
        strm << "]" << std::endl;
    }
    return strm.str();
}

void Error::mergeAll(const Error &other) {
    this->mergeErrors(other.errors());
    this->mergeWarnings(other.warnings());
    this->mergeInfos(other.infos());
}

// Error related methods
bool Error::isError() {
    return this->_is_error;
}

void Error::addError(const string key, const string value) {
    Error::_add(this->_errors, key, value);
    this->_is_error = true;
}

std::map<std::string, std::set<std::string>> Error::errors() const {
    return this->_errors;
}

std::string Error::error_message() {
    return Error::_tostring(this->errors());
}

void Error::mergeErrors(const map<string, set<string>> &mp) {
    Error::_merge(this->_errors, mp);
}

// Warning related methods
bool Error::isWarning(){
    return this->_is_warning;
}

void Error::addWarning(const string key, const string value) {
    Error::_add(this->_warnings, key, value);
    this->_is_warning = true;
}

std::map<std::string, std::set<std::string>> Error::warnings() const{
    return this->_warnings;
}

std::string Error::warning_message(){
    return Error::_tostring(this->warnings());
}

void Error::mergeWarnings(const map<string, set<string>> &mp) {
    Error::_merge(this->_warnings, mp);

}

// Info related methods
bool Error::isInfo(){
    return this->_is_info;
}

void Error::addInfo(const string key, const string value) {
    Error::_add(this->_infos, key, value);
    this->_is_info = true;
}

std::map<std::string, std::set<std::string>> Error::infos() const {
    return this->_infos;
}

std::string Error::info_message(){
    return Error::_tostring(this->infos());
}

void Error::mergeInfos(const map<string, set<string>> &mp) {
    Error::_merge(this->_infos, mp);
}

