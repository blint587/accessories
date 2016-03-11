//
// Created by bmolnar on 2016.03.11..
//

#ifndef DESIGN_PROCESS_ERROR_H
#define DESIGN_PROCESS_ERROR_H

#include <map>
#include <set>
#include <string>

class Container{

    private:
        bool _has = false;
        std::map<std::string, std::set<std::string>> _container;
    public:
        void add(const std::string&, const std::string&);
        void merge(const Container&);
        std::string toString() const;
        bool has() const{
            return this->_has;
        };

};


class Error {

    protected:
        Container info;
        Container warning;
        Container error;
    public:
        bool isError() const{
            return this->error.has();
        }
        bool isWarning() const{
            return this->warning.has();
        }
        bool isInfo() const{
            return this->info.has();
        }
        std::string error_message() const{
            return this->error.toString();
        }
        std::string warning_message() const{
            return this->warning.toString();
        }
        std::string info_message() const{
            return this->info.toString();
        }

        void mergeAll(const Error &);

};


#endif //DESIGN_PROCESS_ERROR_H
