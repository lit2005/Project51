#include <iostream>  
#include <cstring>  
using namespace std;

class Subscriber {
private:
    char* fullName;
    char homePhone[15];
    char workPhone[15];
    char mobilePhone[15];
    char additionalInfo[50];

public:
    // Конструктор  
    Subscriber(const char* name, const char* hPhone, const char* wPhone, const char* mPhone, const char* info) {
        fullName = new char[strlen(name) + 1];
        strcpy(fullName, name);
        strncpy(homePhone, hPhone, sizeof(homePhone));
        strncpy(workPhone, wPhone, sizeof(workPhone));
        strncpy(mobilePhone, mPhone, sizeof(mobilePhone));
        strncpy(additionalInfo, info, sizeof(additionalInfo));
    }

    // Деструктор  
    ~Subscriber() {
        delete[] fullName;
    }

    // Функция для отображения информации об абоненте  
    void display() const {
        cout << "ФИО: " << fullName << "\n"
            << "Домашний телефон: " << homePhone << "\n"
            << "Рабочий телефон: " << workPhone << "\n"
            << "Мобильный телефон: " << mobilePhone << "\n"
            << "Дополнительная информация: " << additionalInfo << "\n";
    }

    // Получение ФИО  
    const char* getFullName() const {
        return fullName;
    }
};

class PhoneBook {
private:
    Subscriber* subscribers[100];
    int count;

public:
    PhoneBook() : count(0) {}

    // Функция добавления абонента  
    void addSubscriber(const char* name, const char* hPhone, const char* wPhone, const char* mPhone, const char* info) {
        if (count < 100) {
            subscribers[count++] = new Subscriber(name, hPhone, wPhone, mPhone, info);
        }
        else {
            cout << "Телефонная книга полна!\n";
        }
    }

    // Функция удаления абонента  
    void removeSubscriber(const char* name) {
        for (int i = 0; i < count; i++) {
            if (strcmp(subscribers[i]->getFullName(), name) == 0) {
                delete subscribers[i];
                for (int j = i; j < count - 1; j++) {
                    subscribers[j] = subscribers[j + 1];
                }
                count--;
                cout << "Абонент " << name << " удален.\n";
                return;
            }
        }
       cout << "Абонент не найден.\n";
    }

    // Функция поиска абонента  
    void findSubscriber(const char* name) const {
        for (int i = 0; i < count; i++) {
            if (strcmp(subscribers[i]->getFullName(), name) == 0) {
                subscribers[i]->display();
                return;
            }
        }
        cout << "Абонент не найден.\n";
    }

    // Функция отображения всех абонентов  
    void displayAll() const {
        for (int i = 0; i < count; i++) {
            subscribers[i]->display();
            cout << "-----------------------\n";
        }
    }

    ~PhoneBook() {
        for (int i = 0; i < count; i++) {
            delete subscribers[i];
        }
    }
};

int main() {
    PhoneBook pb;
    pb.addSubscriber("Иванов Иван Иванович", "123456789", "987654321", "111222333", "Друг детства");
    pb.addSubscriber("Петров Петр Петрович", "234567890", "876543210", "222333444", "Сосед");

   cout << "Все абоненты:\n";
    pb.displayAll();

    pb.findSubscriber("Иванов Иван Иванович");
    pb.removeSubscriber("Петров Петр Петрович");

    cout << "После удаления:\n";
    pb.displayAll();

    return 0;
}