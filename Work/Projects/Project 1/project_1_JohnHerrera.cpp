#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    string input;
    bool valid = false;

    // Valid rec name vector:
    char invalidRec[1024];
    char specialChar[1024] = "!@#$%^&*+-=/?_'{|.<>\""; // Allowed special chars ... wait this is usless because of "ispunct()" ...
    
    // Beginning input

    while (input != "q") {

        // error message:
        bool error1 = false;
        bool error2 = false;
        bool error3 = false;
        bool error4 = false;
        bool error5 = false;
        bool error6 = false;
        bool error7 = false;
        bool error8 = false;
        bool error9 = false;

        cout << "Input email or q to quit: ";
        getline(cin, input);

        //Turn input into array
        char mychar[1024];

        bool valid = true;

        // Detect space:
        for (int i = 0; i < input.length(); i++) {
            if (isspace(input.at(i))) {
                valid = false;
                error1 = true;
            }
        }

        // Turn everything to lowercase: 
        for (int i = 0; i < input.length(); i++) {
            if (isalpha(input.at(i))) {
                input[i] = tolower(input.at(i));
            }
        }

        // Checking recipient

        int length = input.length(); // Total length
        string rec = input.substr(0,(input.find("@"))); // recipient

        if (input.find("@") < 99999999) {

            if (rec.length() > 64) { // check rec length
                valid = false;
                error2 = true;
            } 

            // Check first and last character
            bool temp = true;
            for (int i = 0; i < rec.length(); i = i + rec.length() - 1) {
                for (int j = 0; j < 22; j++) {
                    if (rec.at(i) == specialChar[j]) {
                        temp = false; // detected specialchar
                    }
                }
            }

            if (temp == false) { // detected specialchar
                valid = false;
                error3 = true;
            }

            // Check consecutive characters rec:
            bool dum = false; //dw worry about the bool name :D 

            for (int i = 0; i < rec.length(); i++) {
                if (ispunct(rec.at(i)) != 0) { // detect punctuation is true
                    if (dum == true) { // check temp var
                        valid = false; // invalid if previous char is also punct
                        error9 = true;
                    }
                    else if (dum == false) { // set temp to true
                        dum = true;
                    }
                }
                if (ispunct(rec.at(i)) == 0) { // it is not punct
                    dum = false;
                }
            }

            // Check Valid characters
            bool temp2 = false; // assumed wrong char until proven right
            for (int i = 0; i < rec.length(); i++) {
                for (int j = 0; j < 22; j++) {
                    if (((isdigit(rec.at(i))) || (isalpha(rec.at(i)))) || (rec.at(i) == specialChar[j])) {
                        temp2 = true; //detected true char
                    }
                }
            }

            if (temp2 == false) {
                valid = false;
                error4 = true;
            }

        }

        else {
            valid = false;
            error5 = true;
        }

        // Domain Name:
        string domain = input.substr((input.find("@") + 1), (input.length() - (input.find("@") + 1)));

        // Check domain length 
        if (domain.length() > 253) {
            valid = false;
            error6 = true;
        }

        // Check Valid Char
        for (int i = 0; i < domain.length(); i++) {

            if (!((isalpha(domain.at(i))) || (isdigit(domain.at(i))) || (domain.at(i) == '-') || (domain.at(i) == '.') || (domain.at(i) == '_'))) { // Not valid
                valid = false;
                error7 = true;
            }

        }

        // Detect top level domain and/or sub-domain
        int lastPer = -1;

        for (int i = 0; i < domain.length(); i++) { // detecting last .
            if (domain.at(i) == '.') {
                lastPer = i;
            }
        }

        // detect top level domain
        if (lastPer <= -1) {
            valid = false;
            error8 = true;
        }
        
        else { 
            string topDomain = domain.substr(lastPer, (domain.length() - lastPer));
        }

        // Final Output
        if (input == "q") {
            cout << "Exited" << endl;
        }

        else if (valid == true) {
            cout << "The email " << input << " is valid" << endl << endl;
        }

        else if (valid == false) {
            cout << "The email " << input << " is invalid" << endl;

            // Output error message: 
            if (error1 == true) {
                cout << "* Space in email is not valid" << endl; 
            }
            if (error2 == true) {
                cout << "* Recipient name is too long" << endl; 
            }
            if (error3 == true) {
                cout << "* Special characters cannot appear at first or last letter of email address" << endl; 
            }
            if (error4 == true) {
                cout << "* Char in rec is not valid" << endl; 
            }
            if (error5 == true) {
                cout << "* @ symbol" << endl; 
            }
            if (error6 == true) {
                cout << "* Domain is too long (max of 253 characters)" << endl; 
            }
            if (error7 == true) {
                cout << "* Invalid char in domain" << endl; 
            }
            if (error8 == true) {
                cout << "* Missing top level domain" << endl; 
            }
            if (error9 == true) {
                cout << "* Consecutive special characters are invalid" << endl;
            }
        }

        // debug 2

        // cout << "Top level domain is: " << topDomain << endl;

        /* debug:
        cout << endl << endl;
        cout << "* DEBUG *" << endl << endl;
        cout << length << endl;
        cout << rec << endl;
        cout << valid << endl;
        cout << domain << endl;

        //old domain code: input.substr((input.find("@") + 1), ((input.find(".") - (input.find("@") + 1))));
        */

    }
    return 0;
}


