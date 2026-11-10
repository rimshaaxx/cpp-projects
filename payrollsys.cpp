//-----EMPLOYEE PAYROLL SYSTEM----

#include <iostream>
#include <string>
#include <windows.h>

class Employee {
    private:
        static int ID_generate;
        int ID;
        std::string name;
        std::string department;
        double base_salary;
        int allowances;
        double deductions;
        double net_salary;

    public:

        //-----DEFAULT CONSTRUCTOR-----
        Employee () {
            ID = ID_generate;
            ID_generate++;
            name = "NAME";
            department = "DEPARTMENT" ;
            base_salary = 0;
            allowances = 0;
            deductions = 0;
            net_salary = 0;
        }

        //-----PARAMETERIZED CONSTRUCTOR-----
        Employee (int emp_ID, std::string emp_name, std::string emp_department, double emp_basicSalary) {
            ID = emp_ID;
            name = emp_name;
            department = emp_department;
            base_salary = emp_basicSalary;
        }

        //------COPY CONSTRUCTOR-----
        Employee (const Employee& new_employee) {
                ID = new_employee.ID;
                name = new_employee.name;
                department = new_employee.department;
                base_salary = new_employee.base_salary;
                allowances = new_employee.allowances;
                deductions = new_employee.deductions;
                net_salary = new_employee.net_salary;
        }

        //----SETTER FUNCTIONS-----

        void set_ID(int empID) {
            ID = empID;
        }

        void set_name(std::string empName) {
            name = empName;
        }

        void set_department(std::string empDepartment) {
            department = empDepartment;
        }

        void set_base_salary(double empSalary) {
            base_salary = empSalary;
        }

        void set_allowances(int empAllowance) {
            allowances = empAllowance;
        }

        void set_deduction(double empDeductions) {
            deductions = empDeductions;
        }

        void set_net_salary(double empNetSalary) {
            net_salary = empNetSalary;
        }

        //-----GETTER FUNCTIONS-----

        int get_ID() {
            return ID;
        }

        std::string get_name() {
            return name;
        }

        std::string get_department() {
            return department;
        }

        int get_allowances() {
            return allowances;
        }

        double get_base_salary() {
            return base_salary;
        }

        double get_deduction() {
            return deductions;
        }

        double get_net_salary() {
            return net_salary;
        }

        //-----INPUT INFO FROM USER-----
        void inputEmployee () {
            SetConsoleOutputCP(CP_UTF8);

            std::cout << "────────୨ENTER EMPLOYEE DETAILSৎ────────\n" ;

            std::cout << "Enter ID: " ;
            std::cin >> ID ;
            std::cin.ignore();
            std::cout << "\nEnter name: " ;
            std::getline(std::cin, name);
            std::cout << "\nEnter department: " ;
            std::getline(std::cin, department) ;
            std::cout << "\nEnter basic salary: " ;
            std::cin >> base_salary ;
            while (base_salary <= 0) {
                std::cout << "\nSalary must be greater than zero. \nEnter again: " ;
                std::cin >> base_salary ;
            }

            std::cout << "─────────────────୨ৎ─────────────────\n\n" ;
        }

        //------CALCULATE SALARY FUNCTION------

        void calculate_salary() {
            //--ALLOWANCE IS 20% OF BASE SALARY--DEDUCTION IS 5%--
            allowances = base_salary * 20 / 100 ;
            deductions = base_salary * 5 / 100 ;
            if (deductions > base_salary) {
                deductions = base_salary ;
            }
            net_salary = ( base_salary + allowances ) - deductions ;
        }

        //------DISPLAY EMPLOYEE DETAILS-----
        void display_employee () {
            SetConsoleOutputCP(CP_UTF8);
            std::cout << "\n────────୨EMPLOYEE DETAILSৎ────────\n" ;

            std::cout << "ID = " << ID ;
            std::cout << "\nName: " << name ;
            std:: cout << "\nDepartment: " << department ;
            std::cout << "\nAllowance: " << allowances ;
            std::cout << "\nDeductions: " << deductions ;
            std::cout << "\nBasic Salary: " << base_salary ;
            std::cout << "\nNet Salary: " << net_salary ;

            std::cout << "\n\n────────୨ৎ────────" ;
        }

        //-----DESTRUCTOR FUNCTION-----
        ~Employee () {
            std::cout << "\nEmployee object is destroyed." << std::endl;
        }
};

int Employee::ID_generate = 1000;

int main () {
    //-----DEFAULT CONSTRUCTOR DISPLAY----
    Employee e1;
    e1.calculate_salary();
    e1.display_employee();

    //-----PARAMETERIZED CONNSTRUCTOR DISPLAY-----
    Employee e2(1002, "Sara Ahmed" , "HR" , 55000) ;
    e2.calculate_salary();
    e2.display_employee();

    //-----COPY CONSTRUCTOR DISPLAY-----
    Employee e3(e1);
    e3.calculate_salary();
    e3.display_employee();

    //-----SETTERS AND GETTERS-----
    Employee e4;
    e4.set_ID(1003);
    e4.get_ID();
    e4.set_name("Ayesha Noor");
    e4.get_name();
    e4.set_department("Marketing");
    e4.get_department();
    e4.set_base_salary(60000);
    e4.get_base_salary();
    e4.calculate_salary();
    e4.display_employee();

    //-----TAKE INPUT FROM USER----
    Employee e5;
    e5.inputEmployee();
    e5.calculate_salary();
    e5.display_employee();

    return 0;
}