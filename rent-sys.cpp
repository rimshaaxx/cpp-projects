#include <iostream> 
#include <string>
#include <windows.h>

class vehicle {
    private: 
        std::string ID;
        std::string brand;
        std::string model;
        std::string regNo;
        int rentPerDay;
        int rentDays;
        double charges;

    public:
        //-----DEFAULT CONSTRUCTOR-----
        vehicle () {
            ID = "VH-101";
            brand = "Toyota";
            model = "corolla";
            regNo = "LEB-2021";
            rentPerDay = 5000;
            rentDays = 3;
            charges = 0;
        }
        
        //------PARAMETERIZED CONSTRUCTOR-----

        vehicle (std::string vh_ID, std::string vh_brand, std::string vh_model, std::string vh_regNo, int vh_rentPerDay, int vh_rentdays) {
            ID = vh_ID;
            brand = vh_brand;
            model = vh_model;
            regNo = vh_regNo;
            rentPerDay = vh_rentPerDay;
            rentDays = vh_rentdays;
        }

        //-----COPY CONSTRUCTOR-----
        vehicle(const vehicle& new_vehicle) {
            ID = new_vehicle.ID;
            brand = new_vehicle.brand;
            model = new_vehicle.model;
            regNo = new_vehicle.regNo;
            rentPerDay = new_vehicle.rentPerDay;
            rentDays = new_vehicle.rentDays;
            charges = new_vehicle.charges;
        }

        //----SETTER FUNCTIONS-----
        void set_ID(std::string vh_ID) {
            ID = vh_ID;
        }

        void set_brand(std::string vh_brand) {
            brand = vh_brand;
        }

        void set_model(std::string vh_model) {
            model = vh_model;
        }

        void set_regNo(std::string vh_regNo) {
            regNo = vh_regNo;
        }

        void set_rentPerDay(int vh_rentPerDay) {
            rentPerDay = vh_rentPerDay;
        }

        void set_rentDays(int vh_rentDays) {
            rentDays = vh_rentDays;
        }

        //-----GETTER FUNCTIONS-----
        std::string get_ID() {
            return ID;
        }

        std::string get_brand() {
            return brand;
        }

        std::string get_model() {
            return model;
        }

        std::string get_regNo() {
            return regNo;
        }

        int get_rentPerDay() {
            return rentPerDay;
        }

        int get_rentDays() {
            return rentDays;
        }

        //------INPUT FUNCTION-----
        void inputVehicle () {
            SetConsoleOutputCP(CP_UTF8);

            std::cout << "\n────────୨ENTER VEHICLE DETAILSৎ────────\n" ;

            std::cout << "Enter ID: " ;
            std::cin >> ID ;
            std::cin.ignore();
            std::cout << "\nEnter brand: " ;
            std::getline(std::cin, brand);
            std::cout << "\nEnter model: " ;
            std::getline(std::cin, model) ;
            std::cout << "\nEnter reistration number: " ;
            std::cin >> regNo;
            std::cout << "\nEnter price of rent per day: " ;
            std::cin >> rentPerDay ;
            while (rentPerDay <= 0) {
                std::cout << "\nrent can not be zero or negative.\nEnter again: ";
                std::cin >> rentPerDay;
            }
            std::cout << "\nEnter rent duration: ";
            std::cin >> rentDays;
            while (rentDays < 1) {
                std::cout << "\nRent days must be greater than zero.\nEnter rent duration again: ";
                std::cin >> rentDays;
            }

            std::cout << "─────────────────୨ৎ─────────────────\n\n" ;
        }

        //-----CALCULATE RENT FUNCTION-----
        void calculateRent() {
            charges = rentPerDay * rentDays ;
        }

        //-----DISPLAY VEHICLE INFO FUNCTION------
        void display_vehicle () {
            SetConsoleOutputCP(CP_UTF8);
            std::cout << "\n────────୨VEHICLE DETAILSৎ────────\n" ;

            std::cout << "ID = " << ID ;
            std::cout << "\nBrand: " << brand ;
            std:: cout << "\nModel: " << model ;
            std::cout << "\nRegistration Number: " << regNo ;
            std::cout << "\nRent per day charge: " << rentPerDay ;
            std::cout << "\nRent Duration(days): " << rentDays ;
            std::cout << "\nRent Charges: " << charges ;

            std::cout << "\n\n────────୨ৎ────────" ;
        }

        //-----DESTRUCTOR FUNCTION-----
        ~vehicle () {
            std::cout << "\nVehicle object is destroyed." << std::endl;
        }

};

int main () {
    //-----DEFAULT CONSTRUCTOR DISPLAY----
    vehicle v1;
    v1.calculateRent();
    v1.display_vehicle();

    //-----PARAMETERIZED CONNSTRUCTOR DISPLAY-----
    vehicle v2("VH-102", "Honda" , "Civic" , "LEA-3045" , 7000, 5) ;
    v2.calculateRent();
    v2.display_vehicle();

    //-----COPY CONSTRUCTOR DISPLAY-----
    vehicle v3(v1);
    v3.calculateRent();
    v3.display_vehicle();

    //-----SETTERS AND GETTERS-----
    vehicle v4;
    v4.set_ID("VH-103");
    v4.get_ID();
    v4.set_brand("Suzuki");
    v4.get_brand();
    v4.set_model("alto");
    v4.get_model();
    v4.set_regNo("LEC-1098");
    v4.get_regNo();
    v4.set_rentPerDay(3000);
    v4.get_rentPerDay();
    v4.set_rentDays(2);
    v4.get_rentDays();
    v4.calculateRent();
    v4.display_vehicle();

    //-----TAKE INPUT FROM USER----
    vehicle v5;
    v5.inputVehicle();
    v5.calculateRent();
    v5.display_vehicle();

    return 0;
}