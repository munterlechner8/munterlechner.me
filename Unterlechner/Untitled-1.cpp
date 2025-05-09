#include <iostream>
using namespace std;

class TicketInventory {
    int total, available, sold;
public:
    TicketInventory(int total) : total(total), available(total), sold(0) {}
    void sell(int qty) { 
        if (qty <= available) { available -= qty; sold += qty; cout << qty << " sold.\n"; }
        else cout << "Not enough tickets.\n"; 
    }
    void restock(int qty) { available += qty; total += qty; cout << qty << " restocked.\n"; }
    void status() { cout << "Total: " << total << ", Available: " << available << ", Sold: " << sold << "\n"; }
};

int main() {
    TicketInventory inv(100);
    int choice, qty;
    while (true) {
        cout << "\n1. Sell\n2. Restock\n3. Status\n4. Exit\nChoice: ";
        cin >> choice;
        if (choice == 1) { cout << "Sell qty: "; cin >> qty; inv.sell(qty); }
        else if (choice == 2) { cout << "Restock qty: "; cin >> qty; inv.restock(qty); }
        else if (choice == 3) inv.status();
        else if (choice == 4) break;
        else cout << "Invalid.\n";
    }
    return 0;
}
