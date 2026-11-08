// LIBRARY BOOK MANAGEMENT SYSTEM //

#include <iostream>
#include <string> // or <cstring>
#include <windows.h>

class Book {
    private:
        std::string ID;
        std::string Title;  // or use char Title[30];
        std::string Author;
        double price;
        int copies;

    public:

        // DEFAULT CONSTRUCTOR //

        Book () {
            ID = "BK-2020-001";  // or strcpy ( ID, "BK-2020-001")
            Title = "Harry Potter";
            Author = "J.K. Rowling";
            price = 1500.50;
            copies = 7;
        }

        // PARAMETERIZED CONSTRUCTOR //

        // in paramters use const char array or if using string use 
        // std::string& bk_id  -- to save memory and more speed (also its always const std::string& if we use "&")---

        Book (std::string bk_id, std::string bk_title, std::string bk_author, double bk_price, int bk_copies) { 
            ID = bk_id;
            Title = bk_title;
            Author = bk_author; // or strcpy (Author, bk_author)
            price = bk_price;
            copies = bk_copies;
        }

        // COPY CONSTRUCTOR //

        Book (const Book& new_book) {
            ID = new_book.ID;
            Title = new_book.Title;
            Author = new_book.Author;
            price = new_book.price;
            copies = new_book.copies;
        }

        // SETTER FUNCTIONS // 

        void set_ID (std::string bk_id) { //learned tht if we use std::string& bk_id then tht new variable is actually not created. saves memory ig...?
            ID = bk_id;
        }

        void set_Title(std::string bk_title) {
            Title = bk_title;
        }

        void set_Author(std::string bk_author) {
            Author = bk_author;
        }

        void set_price(double bk_price) {
            price = bk_price;
        }

        void set_copies(int bk_copies) {
            copies = bk_copies;
        }

        // GETTER FUNCTIONS //

        std::string get_ID() { //for cstring way it's const char* get_ID () {} whaever
            return ID;
        }

        std::string get_Title() {
            return Title;
        }

        std::string get_Author() {
            return Author;
        }

        double get_price() {
            return price;
        }

        int get_copies() {
            return copies;
        }

        void input_book() {
            SetConsoleOutputCP(CP_UTF8);
            std::cout << "────────୨ৎ────────\n";

            std::cout << "Enter Book ID: " ;
            std::cin >> ID;
            std::cin.ignore();
            std::cout << "\nEnter book title: ";
            std::getline(std::cin, Title); //or std::cin.getline(Title, 30) for char arrays
            std::cout << "\nEnter book author: ";
            std::getline(std::cin, Author);
            std::cout << "\nEnter book price: ";
            std::cin >> price;

            while (price < 0) {
                std::cout <<"Price cannot be negative.\nEnter price again: ";
                std::cin >> price;
            }

            std::cout << "\nEnter number of copies available: ";
            std::cin >> copies;

            while (copies < 0) {
                std::cout <<"Copies cannot be negative.\nEnter number of copies available: ";
                std::cin >> copies;
            }

            std::cout << "────────୨ৎ────────" << std::endl;
        }

        void display_book() {
            SetConsoleOutputCP(CP_UTF8);
            std::cout << "────────୨BOOK DETAILSৎ────────";

            std::cout << "\nID: " << ID ;
            std::cout << "\nTitle: " << Title ;
            std::cout << "\nAuthor: " << Author ;
            std::cout << "\nPrice: " << price ;
            std::cout << "\nNumber of copies available: " << copies ;

            std::cout << "\n────────୨ৎ────────" << std::endl ;
        }

        void menu(int choice) {
            SetConsoleOutputCP(CP_UTF8);
            std::cout << "────────୨Choose an optionৎ────────" ;
            std::cout << "\n1. Enter book details." ;
            std::cout << "\n2. Display book details." ;
            std::cout << "\n3. Borrow book." ;
            std::cout << "\n4. Return book." ;
            std::cout << "\n5. Exit program." ;
            std::cin >> choice ;

            while (choice < 0 || choice > 5) {
                std::cout << "\nInvalid choice. Enter again: ";
                std::cin >> choice ;
            }
        }

        void borrow_book() {
            if (copies == 0) {
                std::cout << "No copies available." << std::endl;
            }
            else { copies--; }
        }

        void return_book() {
            copies++;
        }

        ~Book () {
            std::cout << "Book is destroyed." << std::endl;
        }
};

int main() {
    // -----DEFAULT CONSTRUCTOR CALLED.-----
    Book b1, b2, b3;

    // -----PARAMETERIZED COSTRUCTOR CALL.-----
    Book b4( "2018-002" , "The Outsider" , "Stephen King" , 1200.00 , 5);
    Book b5( "2023-003" , "One of us is back" , "Karen M. McManus." , 700.00 , 0);

    // -----COPY CONSTRUCTOR~CREATE COPY-----
    Book b6(b1);

    // -----SHOW COPY CONSTRUCTOR WORKED-----
    b6.display_book();

    // -----WHY NOT SEE OTHER BOOKS TOO-----
    b4.display_book();
    b5.display_book();

    int choice = 0;
    b2.menu(choice);
    
    if (choice == 1) {
        b2.input_book();
    }
    else if (choice == 2) {
        b2.display_book();
    }
    else if (choice == 3) {
        b2.borrow_book();
    }
    else if (choice == 4) {
        b2.return_book();
    }
    else if (choice == 5) {
        std::cout << "Exiting."<<std::endl;
    }
}
