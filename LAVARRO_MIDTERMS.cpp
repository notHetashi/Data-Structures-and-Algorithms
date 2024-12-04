//Gawa ni Lavarro para makapasa ng midterms (Wala muna GUI may System Integ pa po T_T)
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Product {
    string product;
    float price;
};

struct CartItem {
    Product product;
    int quantity;
};

void add_cart(vector<CartItem> &cart, const Product &prod, int quan) {
    cart.push_back({prod, quan});
}

float cal_total(const vector<CartItem> &cart) {
    float total = 0;
    for (const auto &item : cart) {
        total += item.product.price * item.quantity;
    }
    return total;
}

void menu(const vector<Product> &prod, const string &type_prod) {
    cout << "\n==== " << type_prod << " ====\n";
    for (size_t i = 0; i < prod.size(); ++i) {
        cout << i + 1 << ". " << prod[i].product << " - PHP " << prod[i].price << "\n";
    }
}

void choice_type_prod(const vector<Product> &type, const string &type_prod, vector<CartItem> &cart) {
    while (true) {
        menu(type, type_prod);
        int choice;
        cout << "\nEnter the number of the product you want to buy: ";
        cin >> choice;

        if (choice == 0) {
            break;
        } else if (choice > 0 && choice <= static_cast<int>(type.size())) {
            const Product &product = type[choice - 1];
            int quantity;
            cout << "\nHow many " << product.product << "'s would you like: ";
            cin >> quantity;
            add_cart(cart, product, quantity);
            cout << quantity << " " << product.product << " added to the cart.\n";
        } else {
            cout << "\nNumber inputted is not valid. Please try again.\n";
        }
    }
}

void view_cart(vector<CartItem> &cart) {
    if (cart.empty()) {
        cout << "\nCart is empty.\n";
    } else {
        cout << "\n=== Cart ===\n";
        for (size_t i = 0; i < cart.size(); ++i) {
            cout << i + 1 << ". " << cart[i].product.product
                 << " - Quantity: " << cart[i].quantity
                 << " - Total: PHP " << cart[i].product.price * cart[i].quantity << "\n";
        }

        string choice;
        cout << "\nDo you want to remove items from the cart? (yes/no): ";
        cin >> choice;

        if (choice == "yes") {
            while (true) {
                int rc;
                cout << "\nEnter the number of the item you want to remove (enter 0 to go back): ";
                cin >> rc;

                if (rc > 0 && rc <= static_cast<int>(cart.size())) {
                    CartItem removedItem = cart[rc - 1];
                    cart.erase(cart.begin() + rc - 1);
                    cout << "\n" << removedItem.quantity << " " << removedItem.product.product << " has been removed from the cart.\n";
                } else if (rc == 0) {
                    break;
                } else {
                    cout << "\nNumber inputted is not valid. Please try again.\n";
                }
            }
        }
    }
}

void receipt(const vector<CartItem> &cart){
    cout << "\n========== Your Reciept ==========\n";
    for (const auto &item : cart){
        cout << item.quantity << " x " << item.product.product << " - PHP " << item.product.price * item.quantity << "\n";
    }
    cout << "Total: PHP " << cal_total(cart) << "\n";
    cout << "\nThank you for shopping, come again!\n";
}

int main() {
    vector<Product> kor_imp = {
        {"Jin Ramen", 45}, {"Beef Bulgogi", 60}, {"Shin Ramen", 60},
        {"Samyang Cheese", 68}, {"Samyang Carbonara", 68}, {"Chacharoni", 65},
        {"Kimnori Seaweed", 115}, {"Bibigo Seaweed", 160}
    };

    vector<Product> meat = {
        {"Pork Jowls", 200}, {"Pork Belly", 250}, {"Pork Bulgogi", 250},
        {"Beef Plain", 250}, {"Beef Bulgogi", 260}, {"Fish Cake 1kg", 310},
        {"Shabu Mix 100g", 135}
    };

    vector<Product> drinks = {
        {"Binggrea Milk", 60}, {"Yonsai Milk", 60}, {"BTS Coffee", 45},
        {"Lets be Coffee", 45}, {"Milkis 1.5L", 120}, {"Mandarin 1.5L", 150},
        {"Aloe Drink", 150}
    };

    vector<CartItem> scart;

    while (true) {
        cout << "==== Annyeong Korean Mini Mart Candelaria ====\n";
        cout << "\nAvailable Products:\n";
        cout << "\nKorean Imported Snacks\n";
        for (size_t i = 0; i < kor_imp.size(); ++i) {
            cout << i + 1 << ". " << kor_imp[i].product << " - PHP " << kor_imp[i].price << "\n";
        }
        cout << "\nSamgyupsal Meats\n";
        for (size_t i = 0; i < meat.size(); ++i) {
            cout << i + 1 << ". " << meat[i].product << " - PHP " << meat[i].price << "\n";
        }
        cout << "\nKorean Imported Drinks\n";
        for (size_t i = 0; i < drinks.size(); ++i) {
            cout << i + 1 << ". " << drinks[i].product << " - PHP " << drinks[i].price << "\n";
        }

        int cath_choice;
        cout << "\n1. Korean Imported Snacks \n2. Samgyupsal Meat \n3. Drinks \n4. View Cart \n0. Main Menu or Checkout \nEnter the type of product you want to check: ";
        cin >> cath_choice;

        if (cath_choice == 0) {
            cout << "=== Checkout ===\n";
            for (const auto &item : scart) {
                cout << item.quantity << " " << item.product.product << " - PHP " << item.product.price * item.quantity << "\n";
            }
            cout << "Total: PHP " << cal_total(scart) << "\n";
            receipt(scart);
            break;
        } else if (cath_choice == 1) {
            choice_type_prod(kor_imp, "Korean Imported Snacks", scart);
        } else if (cath_choice == 2) {
            choice_type_prod(meat, "Samgyupsal Meats", scart);
        } else if (cath_choice == 3) {
            choice_type_prod(drinks, "Korean Imported Drinks", scart);
        } else if (cath_choice == 4) {
            view_cart(scart);
        } else {
            cout << "Number inputted is not valid. Please try again.\n";
        }
    }

    return 0;
}
