#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

class Client {
private:
    string name;
    string email;
    vector<double> purchasehist;
    static int totalclients;

public:

    Client(const string& name, const string& email)
        : name(name), email(email) {
        ++totalclients;
    }

    
    ~Client() {
        --totalclients;
    }

    string getn() const { return name; }
    string getem() const { return email; }
    vector<double> getPurchaseHistory() const { return purchasehist; }


    void setn(const string& newName) { name = newName; }
    void setem(const string& newEmail) { email = newEmail; }

    void addpurchase(double amount) {
        purchasehist.push_back(amount);
    }

    int bonus(int index = -1) const {
        if (purchasehist.empty()) return 0;

        if (index == -1) {
            index = purchasehist.size() - 1; 
        }
        if (index < 0) return 0; 

        return static_cast<int>(purchasehist[index] * 0.1) + bonus(index - 1);
    }
    static int totalc() { return totalclients; }
};

int Client::totalclients = 0;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Client client1("Максим Олександрович", "maxim@examp.com");
    client1.addpurchase(200.0);
    client1.addpurchase(300.0);

    cout << "Клієнт: " << client1.getn() << "\n";
    cout << "Email: " << client1.getem() << "\n";
    cout << "Всі клієнти: " << Client::totalc() << "\n";
    cout << "Бонус бали: " << client1.bonus() << "\n";

    return 0;
}
