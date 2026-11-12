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
        long price;
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
            price = 550000;
            mileage = 35000;
        }
        
        //------PARAMETERIZED CONSTRUCTOR-----

        Car (std::string car_id, std::string car_brand, std::string car_model, std::string car_regNo, int car_mfg, std::string car_fuel_type, long car_price, int car_mileage) {
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
            while ( price <= 0 ) {
                std::cout << "\nInvalid price. Enter price again: ";
                std::cin >> price ;
            }
            std::cout << "\nEnter mileage: ";
            std::cin >> mileage;
            while ( mileage < 0 ) {
                std::cout << "\nMileage cannot be negative. Enter again: ";
                std::cin >> mileage ;
            }

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
            std::cout << "\ncar age: " << car_age << " years.";

            std::cout << "\n\n────────୨ৎ────────" ;
        }

        //-----COMPARE TWO OBJECTS-------
        void comparePrice(const Car& another_car) {
            SetConsoleOutputCP(CP_UTF8);
            std::cout << "\n────────୨PRICE COMPARISONৎ────────";

            if (price > another_car.price) {
                std::cout << "\n" << brand << " " << model << " is more expensive than " << another_car.brand << " " << another_car.model ;

            }
            else if (price < another_car.price) {
                std::cout << "\n" << another_car.brand << " " << another_car.model << " is more expensive than " << brand << " " << model ;

            }
        }

        //-----DESTRUCTOR FUNCTION-----
        ~Car () {
            std::cout << "\nCar object is destroyed." << std::endl;
        }

};

int main () {
    //-----DEFAULT CONSTRUCTOR DISPLAY----
    std::cout << "\nDefault Constructor: \n";
    Car c1;
    c1.calculateAge();
    c1.display_Car();

    //-------PARAMETERIZED CONSTRUCTOR DISPLAY------
    std::cout << "\nParamaterized Constructor: \n";
    Car c2("C-102" , "Suzuki" , "Alto VXR" , "LEA-20-9012" , 2000 , "Petrol" , 2450550 , 5200) ;
    c2.calculateAge();
    c2.display_Car();

    //------COPY CONSTRUCTOR-------
    std::cout << "\nCopy constructor with modified price. \n";
    Car c4(c2);
    //(modeified price of copied object)
    c4.set_price(34676776);
    c4.get_price();
    c4.calculateAge();
    c4.display_Car();

    //-----COMPARE PRICES OF TWO OBJECTS-----
    std::cout << "Prices comparison of two objects.\n";
    c4.comparePrice(c1);

    //------SETTERS AND GETTERS-------
    std::cout << "\n\nAll setters and getters functions. \n";
    Car c3;
    c3.set_ID("C-104");
    c3.get_ID();
    c3.set_brand("Toyota");
    c3.get_brand();
    c3.set_model("Prius S");
    c3.get_model();
    c3.set_mfg(1906);
    c3.get_mfg();
    c3.set_price(34567834567);
    c3.get_price();
    c3.set_regNo("C-SS-456");
    c3.get_regNo();
    c3.set_fuel_type("Diesel");
    c3.get_fuel_type();
    c3.set_mileage(9878);
    c3.get_mileage();
    c3.calculateAge();
    c3.display_Car();

    return 0;
}