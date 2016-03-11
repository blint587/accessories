#include <iostream>
#include "Error.h"

using namespace std;

int main() {

    Error err = Error();
    Error err2 = Error();
    Error err3 = Error();

    err.addError("foo", "bar");
    err.addError("foo", "bar");

    err2.addError("foo", "foo");
    err2.addError("Foo", "Bar");

    err.mergeAll(err2);

    cout << err.error_message() << endl;

    err.mergeAll(err3);

    cout << err.error_message() << endl;

    string s;

    cin >> s;

    return 0;
}