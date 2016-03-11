//
// Created by bmolnar on 2016.03.11..
//

#ifndef DESIGN_PROCESS_ERROR_H
#define DESIGN_PROCESS_ERROR_H

#include <map>
#include <set>
#include <string>


class Error {

    private:
        bool _is_info = false;
        bool _is_warning = false;
        bool _is_error = false;
        bool _is_exception = false;

        std::map<std::string, std::set<std::string>> _infos;
        std::map<std::string, std::set<std::string>> _warnings;
        std::map<std::string, std::set<std::string>> _errors;
        std::string _exception;

        void _add(std::map<std::string, std::set<std::string>>&, const std::string&, const std::string&);
        void _merge(std::map<std::string, std::set<std::string>>&, const std::map<std::string, std::set<std::string>>&);
        std::string _tostring(const std::map<std::string, std::set<std::string>>&);

    public:
        // Error related properties
        bool isError(); // has any errors
        std::map<std::string, std::set<std::string>> errors() const; // gives back the error container, use for merging
        void addError(const std::string, const std::string); // adding errors
        std::string error_message(); // converts to string
        void mergeErrors(const std::map<std::string, std::set<std::string>>&); // merge other error containers into this

        // Warning related properties
        bool isWarning();
        std::map<std::string, std::set<std::string>> warnings() const; // gives back the warning container, use for merging
        void addWarning(const std::string, const std::string); // adding warnings
        std::string warning_message(); // converts to string
        void mergeWarnings(const std::map<std::string, std::set<std::string>>&); // merge other warning containers into this

        // Warning related properties
        bool isInfo();
        std::map<std::string, std::set<std::string>> infos() const; // gives back the warning container, use for merging
        void addInfo(const std::string, const std::string); // adding warnings
        std::string info_message(); // converts to string
        void mergeInfos(const std::map<std::string, std::set<std::string>>&); // merge other warning containers into this

        void mergeAll(const Error &);

};


#endif //DESIGN_PROCESS_ERROR_H
