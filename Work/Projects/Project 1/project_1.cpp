#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    string input;
    bool valid = false;

    // Valid rec name vector:
    char invalidRec[1024];
    char specialChar[1024] = "!@#$%^&*+-=/?_'{|.<>\""; // Allowed special chars

    
    // Beginning input

    while (input != "q") {

        cout << "Input email or q to quit: ";
        getline(cin, input);

        //Turn input into array
        char mychar[1024];

        bool valid = true;

        // Error message:
        string error_message = "";

        // Detect space:
        for (int i = 0; i < input.length(); i++) {
            if (isspace(input.at(i))) {
                valid = false;
                error_message.append("* Space in email is not valid\n");
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
                error_message.append("* Recipient name is too long\n");
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
                error_message.append("* Special characters cannot appear at first or last letter of email address\n");
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
                error_message.append("* Char in rec is not valid\n");
            }

        }

        else {
            valid = false;
            error_message.append("* @ symbol\n");
        }

        // Domain Name:
        string domain = input.substr((input.find("@") + 1), (input.length() - (input.find("@") + 1)));

        // Check domain length 
        if (domain.length() > 253) {
            valid = false;
            error_message.append("* domain is too long (max of 253 characters)\n");
        }

        // Check Valid Char
        for (int i = 0; i < domain.length(); i++) {

            if (!((isalpha(domain.at(i))) || (isdigit(domain.at(i))) || (domain.at(i) == '-') || (domain.at(i) == '.') || (domain.at(i) == '_'))) { // Not valid
                valid = false;
                error_message.append("* invalid char in domain\n");
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
            error_message.append("* missing top level domain \n");
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
            cout << error_message << endl;
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


