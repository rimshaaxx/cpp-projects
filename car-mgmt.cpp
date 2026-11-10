#include <iostream> 
#include <string>
#include <windows.h>

class Car {
    private: 
        std::string ID;
        std::string brand;
        std::string model;
        std::string regNo;
        int mfg;
        std::string fuel_type;
        double price;
        int mileage;
        int car_age;

    public:
        //-----DEFAULT CONSTRUCTOR-----
        Car () {
            ID = "C-101";
            brand = "Toyota";
            model = "corolla";
            regNo = "LEA-1234";
            mfg = 2021;
            fuel_type = "Petrol";
            price = 55000000;
            mileage = 35000;
        }
        
        //------PARAMETERIZED CONSTRUCTOR-----

        Car (std::string car_id, std::string car_brand, std::string car_model, std::string car_regNo, int car_mfg, std::string car_fuel_type, double car_price, int car_mileage) {
            ID = car_id;
            brand = car_brand;
            model = car_model;
            regNo = car_regNo;
            mfg = car_mfg;
            fuel_type = car_fuel_type;
            price = car_price;
            mileage = car_mileage;
        }

        //-----COPY CONSTRUCTOR-----
        Car(const Car& new_Car) {
            ID = new_Car.ID;
            brand = new_Car.brand;
            model = new_Car.model;
            regNo = new_Car.regNo;
            mfg = new_Car.mfg;
            fuel_type = new_Car.fuel_type;
            price = new_Car.price;
            mileage = new_Car.mileage;
        }

        //----SETTER FUNCTIONS-----
        void set_ID(std::string car_id) {
            ID = car_id;
        }

        void set_brand(std::string car_brand) {
            brand = car_brand;
        }

        void set_model(std::string car_model) {
            model = car_model;
        }

        void set_regNo(std::string car_regNo) {
            regNo = car_regNo;
        }

        void set_mfg(int car_mfg) {
            mfg = car_mfg;
        }

        void set_fuel_type(std::string car_fuel_type) {
            fuel_type = car_fuel_type;
        }

        void set_price(double car_price) {
            price = car_price;
        }

        void set_mileage(int car_mileage) {
            mileage = car_mileage;
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

        int get_mfg() {
            return mfg;
        }

        std::string get_fuel_type() {
            return fuel_type;
        }

        double get_price() {
            return price;
        }

        int get_mileage() {
            return mileage;
        }

        //------INPUT FUNCTION-----
        void inputCar () {
            SetConsoleOutputCP(CP_UTF8);

            std::cout << "\n────────୨ENTER Car DETAILSৎ────────\n" ;

            std::cout << "Enter ID: " ;
            std::cin >> ID ;
            std::cin.ignore();
            std::cout << "\nEnter brand: " ;
            std::getline(std::cin, brand);
            std::cout << "\nEnter model: " ;
            std::getline(std::cin, model) ;
            std::cout << "\nEnter reistration number: " ;
            std::cin >> regNo;
            std::cout << "\nEnter manufacture year: " ;
            std::cin >> mfg ;
            while (mfg <= 1880) {
                std::cout << "\nInvalid year.\nEnter again: ";
                std::cin >> mfg;
            }
            std::cout << "\nEnter fuel type \n(only Petrol/Diesel/Hybrid/Electric): ";
            std::cin >> fuel_type;
            while (fuel_type != "Petrol" || fuel_type != "Diesel" || fuel_type != "Hybrid" || fuel_type != "Electric") {
                std::cout << "\nInvalid. Only enter (Petrol/Diesel/Hybrid/Electric): ";
                std::cin >> fuel_type;
            }
            std::cout << "\nEnter price: ";
            std::cin >> price ;
            std::cout << "\nEnter mileage: ";
            std::cin >> mileage;

            std::cout << "─────────────────୨ৎ─────────────────\n\n" ;
        }

        //-----CALCULATE CAR AGE FUNCTION-----
        void calculateAge() {
            int current_year = 2026;
            car_age = current_year - mfg;
        }

        //-----DISPLAY Car INFO FUNCTION------
        void display_Car () {
            SetConsoleOutputCP(CP_UTF8);
            std::cout << "\n────────୨Car DETAILSৎ────────\n" ;

            std::cout << "ID = " << ID ;
            std::cout << "\nBrand: " << brand ;
            std:: cout << "\nModel: " << model ;
            std::cout << "\nRegistration Number: " << regNo ;
            std::cout << "\nManufacture year: " << mfg ;
            std::cout << "\nFuel type: " << fuel_type ;
            std::cout << "\nPrice: " << price ;
            std::cout << "\nMileage: " << mileage;
            std::cout << "\ncar age: " << car_age;

            std::cout << "\n\n────────୨ৎ────────" ;
        }

        void comparePrice() {
            
        }

        //-----DESTRUCTOR FUNCTION-----
        ~Car () {
            std::cout << "\nCar object is destroyed." << std::endl;
        }

};

int main () {
    //-----DEFAULT CONSTRUCTOR DISPLAY----
    Car v1;
    v1.calculateRent();
    v1.display_Car();

    //-----PARAMETERIZED CONNSTRUCTOR DISPLAY-----
    Car v2("VH-102", "Honda" , "Civic" , "LEA-3045" , 7000, 5) ;
    v2.calculateRent();
    v2.display_Car();

    //-----COPY CONSTRUCTOR DISPLAY-----
    Car v3(v1);
    v3.calculateRent();
    v3.display_Car();

    //-----SETTERS AND GETTERS-----
    Car v4;
    v4.set_ID("VH-103");
    v4.get_ID();
    v4.set_brand("Suzuki");
    v4.get_brand();
    v4.set_model("alto");
    v4.get_model();
    v4.set_regNo("LEC-1098");
    v4.get_regNo();
    v4.set_mfg(3000);
    v4.get_mfg();
    v4.set_fuel_type(2);
    v4.get_fuel_type();
    v4.calculateRent();
    v4.display_Car();

    //-----TAKE INPUT FROM USER----
    Car v5;
    v5.inputCar();
    v5.calculateRent();
    v5.display_Car();

    return 0;
}