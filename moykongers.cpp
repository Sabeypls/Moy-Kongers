#include <iostream>
#include <vector>
using namespace std;

struct sOrder
{
    string item;
    double price;
    int amount;
};

class cRegister
{
private:
    double total = 0;
    int count = 0;
    vector<sOrder> order;
    float tax = 1.06;
    
public:
    void addOrder(string x, double y, int z)
    {
        order.push_back(sOrder());
        order[order.size()-1].item = x;
        order[order.size()-1].price = y;
        order[order.size()-1].amount = z;
        total += y * z;
        count += z;
    }

    void removeOrder(int i, double y, int z)
    {
        if(order[i].amount = 1)
        {
            order.erase(order.begin()+i);
            total -= y;
            count--;
        }
        else
        {
            order[i].amount = order[i].amount - z;
            total -= y * z;
            count -= z;
        }
    }

    inline void resetTotal(){total = count = 0;}
    inline double getTotal() {return total;}
    inline double getTotalTax() {return total * tax;}
    inline int getCount() {return count;}
    inline int getSize() {return order.size();}
    
    void printOrder()
    {
        cout << "Your Order: " << endl;
        for(int i = 0; i < order.size(); i++)
        {
            cout << "(" << i+1 << ") " << order[i].item << " - " << order[i].price << " x " << order[i].amount <<endl;
        }
    }

    void printSoupCup()
    {
        system("cls"); cout << "Would you like to add a cup of soup (+$0.95)?" << endl << "1) Egg Drop Soup" 
        << endl << "2) Wonton Soup" << endl << "3) Hot and Sour Soup" << endl << "4) No Thanks!"
        << endl << "Selection: ";
    }
};

int main()
{
    int iChoice, amount;
    string sChoice;
    bool c1=true, c2=true, c3=true;
    cRegister r;

    while(c1) { // while true loop this
        // Main
        system("cls"); cout << "Welcome to Moy Kong, what would you like to order!" << endl;
        cout << "Total: " << r.getTotal() << "| Number of Items: " << r.getCount() << endl << "1) Appetizers" << endl << "2) Chicken" << endl << "3) Beef" 
        << endl << "4) Pork" << endl << "5) Shrimp" << endl << "6) Fried Rice" << endl << "7) Chop Suey or Chow Mein" << endl << "8) Egg Foo Young" 
        << endl << "9) Lite-n-Little" << endl << "0) Complete" << endl << "Selection: "; cin >> iChoice;

        switch(iChoice) { // Subsections
            case(1): { // Appetizer Menu
                c2 = true;
                while(c2) { // Stay in Appetizer Menu
                    system("cls"); cout << "Total: " << r.getTotal() << "| Number of Items: " << r.getCount() << endl << "Appetizers" << endl << "1) Soups"  
                    << endl << "2) Crab Cheese (4pc) - $3.00" << endl << "3) Egg Roll (1pc) - $1.50" << endl << "4) Vegetable Egg Roll - $1.50"
                    << endl << "5) Stuff Fried Wonton (6pc) - $3.50" << endl << "0) Back" << endl << "Selection: "; cin >> iChoice;

                    switch(iChoice) { // Appetizer Selection
                        case(1): // Soup Menu
                            c3 = true;
                            while(c3) { // Stay in Soup Menu
                                system("cls"); cout << "Soups" << endl << "Comes with Soup Chips" << endl << "1) Egg Drop Soup" << endl << "2) Wonton Soup" 
                                << endl << "3) Hot and Sour Soup" << endl << "4) Sizzling Rice Soup" << endl << "Selection: "; cin >> iChoice;

                                switch(iChoice) { // Size Selection
                                    case(1): // ED Soup
                                        system("cls"); cout << "Egg Drop Soup" << endl << "Contains: Egg" << endl << "Size" 
                                        << endl << "1) Small - $1.85" << endl << "2) Large - $2.80" << endl << "0) Back" 
                                        << endl << "Selection: "; cin >> iChoice;

                                        switch(iChoice) { // Amount
                                            case(1): // Small
                                                system("cls"); cout << "Egg Drop Soup(S)" << endl << "Amount? - 0) Back" << endl << "Input: "; cin >> amount; // Clear; Print; Input;
                                                if(amount != 0) {
                                                    r.addOrder("Egg Drop Soup(S)", 1.85, amount); c3 = false; // Call Function; break while; break;
                                                }
                                                else { // 0 = Back
                                                    c3 = true;
                                                }
                                                break;
                                            case(2): // Large
                                                system("cls"); cout << "Egg Drop Soup(L)" << endl << "Amount? - 0) Back" << endl << "Input: "; cin >> amount; // Clear; Print; Input;
                                                if(amount != 0) {
                                                    r.addOrder("Egg Drop Soup(L)", 2.80, amount); c3 = false; break; // Call Function; break while; break;
                                                }
                                                else { // 0 = Back
                                                    c3 = true;
                                                }
                                                break;
                                            case(0): c3 = true; break; // Back
                                        }
                                    break; // Break out of ED

                                    case(2): // Wonton Soup
                                        system("cls"); cout << "Wonton Soup" << endl << "[Only in Large] Contains: Waterchest Nut, Mushroom, Bamboo Shoot, BBQ Pork Shred, and Napa"
                                        << endl << "Size" << endl << "1) Small - $1.95" << endl << "2) Large - $4.60" << endl << "0) Back" 
                                        << endl << "Selection: "; cin >> iChoice;

                                        switch(iChoice) { // Amount
                                            case(1):  // Small
                                                system("cls"); cout << "Wonton Soup(S)" << endl << "Amount? - 0) Back" << endl << "Input: "; cin >> amount; // Clear; Print; Input;
                                                if(amount != 0) {
                                                    r.addOrder("Wonton Soup(S)", 1.95, amount); c3 = false; break; // Call Function; break while; break;
                                                }
                                                else { // 0 = Back
                                                    c3 = true; break;
                                                }
                                            case(2):  // Large
                                                system("cls"); cout << "Wonton Soup(L)" << endl << "Amount? - 0) Back" << endl << "Input: "; cin >> amount; // Clear; Print; Input;
                                                if(amount != 0) {
                                                    r.addOrder("Wonton Soup(L)", 4.60, amount); c3 = false; break; // Call Function; break while; break;
                                                }
                                                else { // 0 = Back
                                                    c3 = true; break;
                                                }
                                            case(0):  c3 = true; break; // Back
                                        }
                                    break; // Break out of Wonton

                                    case(3): // HnS Soup
                                        system("cls"); cout << "Hot and Sour Soup" << endl << "Contains: Bamboo Shoot" << endl << "Size"
                                        << endl << "1) Small - $3.35" << endl << "2) Large - $5.40" << endl << "0) Back" 
                                        << endl << "Selection: "; cin >> iChoice;

                                        switch(iChoice) { // Amount
                                            case(1): // Small
                                                system("cls"); cout << "Hot and Sour Soup(S)" << endl << "Amount? - 0) Back" << endl << "Input: "; cin >> amount; // Clear; Print; Input;
                                                if(amount != 0) {
                                                    r.addOrder("Hot and Sour Soup(S)", 3.35, amount); c3 = false; break; // Call Function; break while; break;
                                                }
                                                else { // 0 = Back
                                                    c3 = true; break;
                                                }
                                            case(2):  // Large
                                                system("cls"); cout << "Hot and Sour Soup(L)" << endl << "Amount? - 0) Back" << endl << "Input: "; cin >> amount; // Clear; Print; Input;
                                                if(amount != 0) {
                                                    r.addOrder("Hot and Sour Soup(L)", 5.40, amount); c3 = false; break; // Call Function; break while; break;
                                                }
                                                else { // 0 = Back
                                                    c3 = true; break;
                                                }
                                            case(0):  c3 = true; break; // Back
                                        }
                                    break; // Break out of HnS

                                    case(4): // Sizzling Rice Soup
                                        system("cls"); cout << "Sizzling Rice Soup" << endl << "Contains: Chicken, Pork, Shrimp, Water Chestnut, Mushroom, and Bamboo Shoot" 
                                        << endl << "Comes with Crispy Rice instead of Soup Chips" << endl << "Size" << endl << "1) Small - $4.35" 
                                        << endl << "2) Large - $5.60" << endl << "0) Back" << endl << "Selection: "; cin >> iChoice;

                                        switch(iChoice) { // Amount
                                            case(1):  // Small
                                                system("cls"); cout << "Amount? - 0) Back" << endl << "Input: "; cin >> amount; // Clear; Print; Input;
                                                if(amount != 0) {
                                                    r.addOrder("Sizzling Rice Soup(S)", 4.35, amount); c3 = false; break; // Call Function; break while; break;
                                                }
                                                else { // 0 = Back
                                                    c3 = true; break;
                                                }
                                            case(2):  // Large
                                                system("cls"); cout << "Amount? - 0) Back" << endl << "Input: "; cin >> amount; // Clear; Print; Input;
                                                if(amount != 0) {
                                                    r.addOrder("Sizzling Rice Soup(L)", 5.60, amount); c3 = false; break; // Call Function; break while; break;
                                                }
                                                else { // 0 = Back
                                                    c3 = true; break;
                                                }
                                            case(0): c3 = true; break; // Back
                                        }
                                    break; // Break out of Sizzling

                                    case(0): c3 = false; break; // Back Menu
                                }
                        break; // Break out of Soup Selection

                        case(2):  // CC
                            system("cls"); cout << "Crab Cheese" << endl << "Contains: Immitation Crab, Cream Cheese, and Green Onion" << endl << "Amount? - 0) Back" 
                            << endl << "Input: "; cin >> amount; // Clear; Print; Input;
                            if(amount != 0) {
                                r.addOrder("Crab Cheese", 3.00, amount); c2 = false; break; // Call Function; break while; break;
                            }
                            else { // 0 = Back
                                c2 = true; break;
                            }
                        case(3):  // ER
                            system("cls"); cout << "Contains: Chicken, Bean Sprout, and Cabbage" << endl << "Amount? - 0) Back" 
                            << endl << "Input: "; cin >> amount; // Clear; Print; Input;
                            if(amount != 0) {
                                r.addOrder("Egg Roll", 1.50, amount); c2 = false; break; // Call Function; break while; break;
                            }
                            else { // 0 = Back
                                c2 = true; break;
                            }
                        case(4): // VG ER
                            system("cls"); cout << "Contains: Bean Sprout, Celery, and Cabbage" << endl << "Amount? - 0) Back"
                            << endl << "Input: "; cin >> amount; // Clear; Print; Input;
                            if(amount != 0) {
                                r.addOrder("Vegetable Egg Roll", 1.50, amount); c2 = false; break; // Call Function; break while; break;
                            }
                            else { // 0 = Back
                                c2 = true; break;
                            }
                        case(5): // SFW
                            system("cls"); cout << "Contains: Pork and Green Onion" << endl << "Amount? - 0) Back" 
                            << endl << "Input: "; cin >> amount; // Clear; Print; Input;
                            if(amount != 0) {
                                r.addOrder("Stuff Fried Wonton", 1.50, amount); c2 = false; break; // Call Function; break while; break;
                            }
                            else { // 0 = Back
                                c2 = true; break;
                            }
                        case(0): c2 = false; break; // Back
                        }
                    }
                }
                break; // Break out of Appetizer Menu
            }

            case(2): { // Chicken Menu
                c2 = true;
                while(c2) { // Stay in Chicken Menu
                    system("cls"); cout << "Chicken" << endl << "1) Sweet and Sour Chicken" << endl << "2) Almond Boneless Chicken" << endl << "3) Chicken Almond Ding"
                    << endl << "4) Cashew Chicken" << endl << "5) Curry Chicken [Spicy]" << endl << "6) Chicken and Broccoli" << endl << "7) Gong Bo Gai [Spicy]"
                    << endl <<  "8) Gai Kow" << endl << "9) Garlic Chicken" << endl << "10) General's Chicken [Spicy]"  << endl << "11) Sesame Chicken"
                    << endl << "12) Orange Chicken [Spicy]" << endl; cin >> iChoice;

                    switch(iChoice) { // Chicken Selection
                        case(1): // SS Chicken
                            system("cls"); cout << "Sweet and Sour Chicken" << endl << "Small and Large comes with just White Rice." 
                            << endl << "Combination is a Small serving with Chicken Fried Rice and a Chicken Egg Roll along with an optional Soup Cup (+$0.95)" 
                            << endl << "Contains: Carrot and Cucumber" << endl << "Size" << endl << "1) Small - $5.95" << endl << "2) Large - $8.45" 
                            << endl << "3) Combination - $7.25" << endl << "0) Back" << endl << "Selection: "; cin >> iChoice;

                            switch(iChoice) { // Size Selection
                                case(1): // Small
                                    system("cls"); cout << "Sweet and Sour Chicken(S)" << endl << "Amount? - 0) Back" 
                                    << endl << "Input: "; cin >> amount; // Clear; Print; Input;
                                    if(amount != 0) {
                                        r.addOrder("Sweet and Sour Chicken(S)", 5.95, amount); c2 = false; break; // Call Function; break while; break;
                                    }
                                    else { // 0 = Back
                                        c2 = true; break;
                                    }
                                case(2): // Large
                                    system("cls"); cout << "Sweet and Sour Chicken(L)" << endl << "Amount? - 0) Back" 
                                    << endl << "Input: "; cin >> amount; // Clear; Print; Input;
                                    if(amount != 0) {
                                        r.addOrder("Sweet and Sour Chicken(L)", 8.45, amount); c2 = false; break; // Call Function; break while; break;
                                    }
                                    else { // 0 = Back
                                        c2 = true; break;
                                    }
                                case(3): // Combo
                                    system("cls"); cout << "Sweet and Sour Chicken(C)" << endl << "Amount? - 0) Back" 
                                    << endl << "Input: "; cin >> amount; // Clear; Print; Input;
                                    if(amount != 0) {
                                        r.printSoupCup();
                                        cin >> iChoice;
                                        switch(iChoice) { // Call Function; break while; break;
                                            case(1): r.addOrder("Sweet and Sour Chicken(C) /w Egg Drop Soup", 8.20, amount); c2 = false; break;
                                            case(2): r.addOrder("Sweet and Sour Chicken(C) /w Wonton Soup", 8.20, amount); c2 = false; break;
                                            case(3): r.addOrder("Sweet and Sour Chicken(C) /w Hot and Sour Soup", 8.20, amount); c2 = false; break;
                                            case(4): r.addOrder("Sweet and Sour Chicken(C)", 7.25, amount); c2 = false; break;
                                        }
                                        break;
                                    }
                                    else { // 0 = Back
                                        c2 = true; break;
                                    }
                                case(0): c2 = true; break; // Back
                            }
                        break; // Break out of SS Chicken

                        case(2): // ABC
                            system("cls"); cout << "Almond Boneless Chicken" << endl << "Small and Large comes with just White Rice." 
                            << endl << "Combination is a Small serving with Chicken Fried Rice and a Chicken Egg Roll along with an optional Soup Cup (+$0.95)" 
                            << endl << "Contains: Green Onion, Almond Powder, and Brown Gravy" << endl << "Size" << endl << "1) Small - $5.95" << endl << "2) Large - $8.45" 
                            << endl << "3) Combination - $7.25" << endl << "0) Back" << endl << "Selection: "; cin >> iChoice;

                            switch(iChoice) { // Size Selection
                                case(1): // Small
                                    system("cls"); cout << "Almond Bonless Chicken(S)" << endl << "Amount? - 0) Back" 
                                    << endl << "Input: "; cin >> amount; // Clear; Print; Input;
                                    if(amount != 0) {
                                        r.addOrder("Almond Boneless Chicken(S)", 5.95, amount); c2 = false; break; // Call Function; break while; break;
                                    }
                                    else { // 0 = Back
                                        c2 = true; break;
                                    }
                                case(2): // Large
                                    system("cls"); cout << "Almond Boneless Chicken(L)" << endl << "Amount? - 0) Back" 
                                    << endl << "Input: "; cin >> amount; // Clear; Print; Input;
                                    if(amount != 0) {
                                        r.addOrder("Almond Boneless Chicken(L)", 8.45, amount); c2 = false; break; // Call Function; break while; break;
                                    }
                                    else { // 0 = Back
                                        c2 = true; break;
                                    }
                                case(3): // Combo
                                    system("cls"); cout << "Almond Boneless Chicken(C)" << endl << "Amount? - 0) Back" 
                                    << endl << "Input: "; cin >> amount; // Clear; Print; Input;
                                    if(amount != 0) {
                                        r.printSoupCup();
                                        cin >> iChoice;
                                        switch(iChoice) { // Call Function; break while; break;
                                            case(1): r.addOrder("Almond Boneless Chicken(C) /w Egg Drop Soup", 8.20, amount); c2 = false; break;
                                            case(2): r.addOrder("Almond Boneless Chicken(C) /w Wonton Soup", 8.20, amount); c2 = false; break;
                                            case(3): r.addOrder("Almond Boneless Chicken(C) /w Hot and Sour Soup", 8.20, amount); c2 = false; break;
                                            case(4): r.addOrder("Almond Boneless Chicken(C)", 7.25, amount); c2 = false; break;
                                        }
                                        break;
                                    }
                                    else { // 0 = Back
                                        c2 = true; break;
                                    }
                                case(0): c2 = true; break; // Back
                            }
                        break; // Break out of ABC

                        case(3): // Almond Ding
                            system("cls"); cout << "Chicken Almond Ding" << endl << "Small and Large comes with just White Rice." 
                            << endl << "Combination is a Small serving with Chicken Fried Rice and a Chicken Egg Roll along with an optional Soup Cup (+$0.95)" 
                            << endl << "Contains: Almond Nut, Water Chestnut, Mushroom, Bamboo Shoot, Bok Choy, Carrot" << endl << "Size" << endl << "1) Small - $6.45" 
                            << endl << "2) Large - $9.20" << endl << "3) Combination - $8.75" << endl << "0) Back" << endl << "Selection: "; cin >> iChoice;

                            switch(iChoice) { // Size Selection
                                case(1): // Small
                                    system("cls"); cout << "Chicken Almond Ding(S)" << endl << "Amount? - 0) Back" 
                                    << endl << "Input: "; cin >> amount; // Clear; Print; Input;
                                    if(amount != 0) {
                                        r.addOrder("Chicken Almond Ding(S)", 6.45, amount); c2 = false; break; // Call Function; break while; break;
                                    }
                                    else { // 0 = Back
                                        c2 = true; break;
                                    }
                                case(2): // Large
                                    system("cls"); cout << "Chicken Almond Ding(L)" << endl << "Amount? - 0) Back" 
                                    << endl << "Input: "; cin >> amount; // Clear; Print; Input;
                                    if(amount != 0) {
                                        r.addOrder("Chicken Almond Ding(L)", 9.20, amount); c2 = false; break; // Call Function; break while; break;
                                    }
                                    else { // 0 = Back
                                        c2 = true; break;
                                    }
                                case(3): // Combo
                                    system("cls"); cout << "Chicken Almond Ding(C)" << endl << "Amount? - 0) Back" 
                                    << endl << "Input: "; cin >> amount; // Clear; Print; Input;
                                    if(amount != 0) {
                                        r.printSoupCup();
                                        cin >> iChoice;
                                        switch(iChoice) { // Call Function; break while; break;
                                            case(1): r.addOrder("Chicken Almond Ding(C) /w Egg Drop Soup", 9.70, amount); c2 = false; break;
                                            case(2): r.addOrder("Chicken Almond Ding(C) /w Wonton Soup", 9.70, amount); c2 = false; break;
                                            case(3): r.addOrder("Chicken Almond Ding(C) /w Hot and Sour Soup", 9.70, amount); c2 = false; break;
                                            case(4): r.addOrder("Chicken Almond Ding(C)", 8.75, amount); c2 = false; break;
                                        }
                                        break;
                                    }
                                    else { // 0 = Back
                                        c2 = true; break;
                                    }
                                case(0): c2 = true; break; // Back
                            }
                        break; // Break out of Almond Ding

                        case(4): // Cashew Chicken
                            system("cls"); cout << "Cashew Chicken" << endl << "Small and Large comes with just White Rice." 
                            << endl << "Combination is a Small serving with Chicken Fried Rice and a Chicken Egg Roll along with an optional Soup Cup (+$0.95)"
                            << endl << "Size" << endl << "1) Small - $6.45" << endl << "2) Large - $9.20" << endl << "3) Combination - $7.95" 
                            << endl << "0) Back" << endl << "Selection: "; cin >> iChoice;

                            switch(iChoice) { // Size Selection
                                case(1): // Small
                                    system("cls"); cout << "Cashew Chicken(S)" << endl << "Amount? - 0) Back"
                                    << endl << "Input: "; cin >> amount; // Clear; Print; Input;
                                    if(amount != 0) {
                                        r.addOrder("Cashew Chicken(S)", 6.45, amount); c2 = false; break; // Call Function; break while; break;
                                    }
                                    else { // 0 = Back
                                        c2 = true; break;
                                    }
                                case(2): // Large
                                    system("cls"); cout << "Cashew Chicken(L)" << endl << "Amount? - 0) Back "
                                    << endl << "Input: "; cin >> amount; // Clear; Print; Input;
                                    if(amount != 0) {
                                        r.addOrder("Cashew Chicken(L)", 9.20, amount); c2 = false; break; // Call Function; break while; break;
                                    }
                                    else { // 0 = Back
                                        c2 = true; break;
                                    }
                                case(3): // Combo
                                    system("cls"); cout << "Cashew Chicken(C)" << endl << "Amount? - 0) Back"
                                    << endl << "Input: "; cin >> amount; // Clear; Print; Input;
                                    if(amount != 0) {
                                        r.printSoupCup();
                                        cin >> iChoice;
                                        switch(iChoice) { // Call Function; break while; break;
                                            case(1): r.addOrder("Cashew Chicken(C) /w Egg Drop Soup", 8.90, amount); c2 = false; break;
                                            case(2): r.addOrder("Cashew Chicken(C) /w Wonton Soup", 8.90, amount); c2 = false; break;
                                            case(3): r.addOrder("Cashew Chicken(C) /w Hot and Sour Soup", 8.90, amount); c2 = false; break;
                                            case(4): r.addOrder("Cashew Chicken(C)", 7.95, amount); c2 = false; break;
                                        }
                                        break;
                                    }
                                    else { // 0 = Back
                                        c2 = true; break;
                                    }
                                case(0): c2 = true; break; // Back
                            }
                        break; // Break out of Cashew Chicken

                        case(5): // Curry Chicken
                            system("cls"); cout << "Curry Chicken" << endl << "Small and Large comes with just White Rice." 
                            << endl << "Combination is a Small serving with Chicken Fried Rice and a Chicken Egg Roll along with an optional Soup Cup (+$0.95)" 
                            << endl << "Contains: Green Bell Pepper and White Onion" << endl << "Size" << endl << "1) Small - $6.45" 
                            << endl << "2) Large - $9.20" << endl << "3) Combination - $8.75" << endl << "0) Back" << endl << "Selection: "; cin >> iChoice;

                            switch(iChoice) { // Size Selection
                                case(1): // Small
                                    system("cls"); cout << "Curry Chicken(S)" << endl << "Amount? - 0) Back" 
                                    << endl << "Input: "; cin >> amount; // Clear; Print; Input;
                                    if(amount != 0) {
                                        r.addOrder("Curry Chicken(S)", 6.45, amount); c2 = false; break; // Call Function; break while; break;
                                    }
                                    else { // 0 = Back
                                        c2 = true; break;
                                    }
                                case(2): // Large
                                    system("cls"); cout << "Curry Chicken(L)" << endl << "Amount? - 0) Back" 
                                    << endl << "Input: "; cin >> amount; // Clear; Print; Input;
                                    if(amount != 0) {
                                        r.addOrder("Curry Chicken(L)", 9.20, amount); c2 = false; break; // Call Function; break while; break;
                                    }
                                    else { // 0 = Back
                                        c2 = true; break;
                                    }
                                case(3): // Combo
                                    system("cls"); cout << "Curry Chicken(C)" << endl << "Amount? - 0) Back" 
                                    << endl << "Input: "; cin >> amount; // Clear; Print; Input;
                                    if(amount != 0) {
                                        r.printSoupCup();
                                        cin >> iChoice;
                                        switch(iChoice) { // Call Function; break while; break;
                                            case(1): r.addOrder("Curry Chicken(C) /w Egg Drop Soup", 9.70, amount); c2 = false; break;
                                            case(2): r.addOrder("Curry Chicken(C) /w Wonton Soup", 9.70, amount); c2 = false; break;
                                            case(3): r.addOrder("Curry Chicken(C) /w Hot and Sour Soup", 9.70, amount); c2 = false; break;
                                            case(4): r.addOrder("Curry Chicken(C)", 8.75, amount); c2 = false; break;
                                        }
                                        break;
                                    }
                                    else { // 0 = Back
                                        c2 = true; break;
                                    }
                                case(0): c2 = true; break; // Back
                            }
                        break; // Break out of Curry Chicken

                        case(6): // CnB
                            system("cls"); cout << "Chicken and Broccoli" << endl << "Small and Large comes with just White Rice."
                            << endl << "Combination is a Small serving with Chicken Fried Rice and a Chicken Egg Roll along with an optional Soup Cup (+$0.95)"
                            << endl << "Size" << endl << "1) Small - $6.45" << endl << "2) Large - $9.20" << endl << "3) Combination - $7.85" 
                            << endl << "0) Back" << endl << "Selection: "; cin >> iChoice;

                            switch(iChoice) { // Size Selection
                                case(1): // Small
                                    system("cls"); cout << "Chicken and Broccoli(S)" << endl << "Amount? - 0) Back"
                                    << endl << "Input: "; cin >> amount; // Clear; Print; Input;
                                    if(amount != 0) {
                                        r.addOrder("Chicken and Broccoli(S)", 6.45, amount); c2 = false; break; // Call Function; break while; break;
                                    }
                                    else { // 0 = Back
                                        c2 = true; break;
                                    }
                                case(2): // Large
                                    system("cls"); cout << "Chicken and Broccoli(L)" << endl << "Amount? - 0) Back"
                                    << endl << "Input: "; cin >> amount; // Clear; Print; Input;
                                    if(amount != 0) {
                                        r.addOrder("Chicken and Broccoli(L)", 9.20, amount); c2 = false; break; // Call Function; break while; break;
                                    }
                                    else { // 0 = Back
                                        c2 = true; break;
                                    }
                                case(3): // Combo
                                    system("cls"); cout << "Chicken and Broccoli(C)" << endl << "Amount? - 0) Back"
                                    << endl << "Input: "; cin >> amount; // Clear; Print; Input;
                                    if(amount != 0) {
                                        r.printSoupCup();
                                        cin >> iChoice;
                                        switch(iChoice) { // Call Function; break while; break;
                                            case(1): r.addOrder("Chicken and Broccoli(C) /w Egg Drop Soup", 8.80, amount); c2 = false; break;
                                            case(2): r.addOrder("Chicken and Broccoli(C) /w Wonton Soup", 8.80, amount); c2 = false; break;
                                            case(3): r.addOrder("Chicken and Broccoli(C) /w Hot and Sour Soup", 8.80, amount); c2 = false; break;
                                            case(4): r.addOrder("Chicken and Broccoli(C)", 7.85, amount); c2 = false; break;
                                        }
                                        break;
                                    }
                                    else { // 0 = Back
                                        c2 = true; break;
                                    }
                                case(0): c2 = true; break; // Back
                            }
                        break; // Break out of CnB

                    }
                }
                break; // Break out of Chicken Menu
            }

            case(0): {
                system("cls");
                r.printOrder();
                cout << "Total: " << r.getTotal() << endl << "Total(+Taxes): " << r.getTotalTax() << endl << "Thank You!" << endl;
                system("pause"); // For Now...
                c1 = false; break; // Proceed to Exit
            }
        }
    }
    return(0);
}