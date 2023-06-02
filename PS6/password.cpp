#include "password.h"

namespace {
    string password;
    bool isValid() {
        if (password.length() < 8) {
            return false;
        }
        bool nonLetter = false;
        for (char c : password) {
            if (!isalpha(c)) {
                nonLetter = true;
            }
        }
        return nonLetter;
    }
}

namespace Authenticate
{
    void inputPassword()
    {
        do
        {
        cout << "Enter your password (at least 8 characters " <<
                "and at least one non-letter)" << endl;
        cin >> password ;
        } while (!isValid());
    }
    string getPassword()
    {
        return password;
    }
}