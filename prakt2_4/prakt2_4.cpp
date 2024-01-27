#include <iostream>
#include <string>

class Client {
private:
    std::string name;
    double balance;

public:
    Client(const std::string& n, double b) : name(n), balance(b) {}

    std::string getName() const {
        return name;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }
};

class Bank {
private:
    static const int MAX_CLIENTS = 100;
    Client* clients[MAX_CLIENTS];
    int numClients;

public:
    Bank() : numClients(0) {
        for (int i = 0; i < MAX_CLIENTS; ++i) {
            clients[i] = nullptr;
        }
    }

    void openAccount(const std::string& name, double initialDeposit) {

            clients[numClients++] = new Client(name, initialDeposit);
            std::cout << "Аккаунт открыт - " << name << " Депозит - " << initialDeposit << std::endl;
        
        
    }

    void deposit(const std::string& clientName, double amount) {
        for (int i = 0; i < numClients; ++i) {
            if (clients[i]->getName() == clientName) {
                clients[i]->deposit(amount);
                std::cout << " Депозит - " << amount << " Аккаунта - " << clientName << " Успешен." << std::endl;
                return;
            }
        }
        std::cout << "Клиент не найден" << std::endl;
    }

    void withdraw(const std::string& clientName, double amount) {
        for (int i = 0; i < numClients; ++i) {
            if (clients[i]->getName() == clientName) {
                if (clients[i]->withdraw(amount)) {
                    std::cout << "Снятие " << amount << " Аккаунта -  " << clientName << " Успешно." << std::endl;
                }
                else {
                    std::cout << "Недостаточно средств для вывода на счет " << clientName << std::endl;
                }
                return;
            }
        }
        std::cout << "Клиент не найден" << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    Bank bank;

    bank.openAccount("Alice", 1000);
    bank.openAccount("Bob", 500);


    bank.deposit("Alice", 200);
    bank.withdraw("Bob", 1000);
    bank.withdraw("Alice", 1500);

    return 0;
}