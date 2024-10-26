#include <iostream>
#include <vector>
#include <string>

// Я нічого не зробив так що я не знаю що ти будеш писати в ревю I didn't do anything so I don't know what you will write in the review

using namespace std;

int vibor;

class student {

    string name;
    string surname;
    string phone;
    string email;
    string password;
    string login;
    int rating_group;
    int rating_class;

public:

    student(string na, string su, string ph, string em, string pa, string lo, int r_g, int r_c)
        : name(na), surname(su), phone(ph), email(em), password(pa), login(lo), rating_group(r_g), rating_class(r_c) {}


    string get_name() const { return name; }
    string get_surname() const { return surname; }
    string get_login() const { return login; }
    string get_password() const { return password; }
    string get_phone() const { return phone; }
    string get_email() const { return email; }
    int get_rating_group() const { return rating_group; }
    int get_rating_class() const { return rating_class; }
};

class mystut {

    vector<student> stud;


    string name_temp;
    string surname_temp;
    string phone_temp;
    string email_temp;
    string password_temp;
    string login_temp;
    int rating_group_temp;
    int rating_class_temp;

public:

    mystut() {}

    void open() {
        string enter_password;
        string enter_login;

        cout << "Enter password: ";
        cin >> enter_password;
        cout << "Enter login: ";
        cin >> enter_login;

        bool found = false;  

        // Я призераю while
        for(;;){

            for (const student& i : stud) {
                if (i.get_password() == enter_password && i.get_login() == enter_login) {
                    name_temp = i.get_name();
                    surname_temp = i.get_surname();
                    phone_temp = i.get_phone();
                    email_temp = i.get_email();
                    password_temp = i.get_password();
                    login_temp = i.get_login();
                    rating_group_temp = i.get_rating_group();
                    rating_class_temp = i.get_rating_class();

                    cout << "Login successful! Welcum, " << endl;
                    found = true;
                    break;
                }
            }


            if (!found) {
                cout << "eror =(" << endl;
            }

        }

    }


    void profile() {
        cout << "Personal information: " << endl;
        cout << "Name: " << name_temp << endl;
        cout << "Surname: " << surname_temp << endl;
        cout << "Phone: " << phone_temp << endl;
        cout << "Email: " << email_temp << endl;
        cout << "Login: " << login_temp << endl;
        cout << "Rating Group: " << rating_group_temp << endl;
        cout << "Rating Class: " << rating_class_temp << endl;

        cout << "1 exit" << endl;
        cout << "2 change password" << endl;
        cout << "2 change login" << endl;
        for (;;) {
            if (vibor == 1) {
                break;
            }
            else if (vibor == 2) {
                string enter_password;
                cout << "Enter old password: ";
                cin >> enter_password;

                bool found = false;
                for (student& i : stud) {
                    if (i.get_password() == enter_password) {
                        student new_stud(i.get_name(), i.get_surname(), i.get_phone(), i.get_email(), enter_password, i.get_login(), i.get_rating_group(), i.get_rating_class()); 
                        stud = stud.erase(); // тут помилка сарян I apologize for the error here
                    }
                }
                if (!found) {
                    cout << "eror =(" << endl;
                }
            }

        }

    }

    void shop() {
        cout << "eror =(" << endl;
    }

    void add_student(const student& bim) {
        stud.push_back(bim);
    }


};

int main() {
    mystut db;


    db.add_student(student("Ivan", "Kovalenko", "380123456789", "ivan@gmail.com", "pass123", "ivan123", 1, 5));
    db.add_student(student("Olena", "Shevchenko", "380987654321", "olena@gmail.com", "qwerty", "olena456", 2, 4));


    db.open();


   // db.display_temp_data();

    return 0;
}
