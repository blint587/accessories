#include <iostream>
#include "Error/Error.h"

using namespace std;


class Some : public Error{
    public:
        void dosomething(string key, string value){
            this->error.add(key, value);
        }
};

int main() {

    Some err = Some();
    err.dosomething("foo", "bar");
    err.dosomething("foo", "Bar");
    Some err2 = Some();
    err2.dosomething("Bar", "FOO");


    if(err.isError()) {
        cout << err.toString();
    }
    err.mergeAll(err2);

    cout << err << endl;

    return 0;
}