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
    // �����������  
    Subscriber(const char* name, const char* hPhone, const char* wPhone, const char* mPhone, const char* info) {
        fullName = new char[strlen(name) + 1];
        strcpy(fullName, name);
        strncpy(homePhone, hPhone, sizeof(homePhone));
        strncpy(workPhone, wPhone, sizeof(workPhone));
        strncpy(mobilePhone, mPhone, sizeof(mobilePhone));
        strncpy(additionalInfo, info, sizeof(additionalInfo));
    }

    // ����������  
    ~Subscriber() {
        delete[] fullName;
    }

    // ������� ��� ����������� ���������� �� ��������  
    void display() const {
        cout << "���: " << fullName << "\n"
            << "�������� �������: " << homePhone << "\n"
            << "������� �������: " << workPhone << "\n"
            << "��������� �������: " << mobilePhone << "\n"
            << "�������������� ����������: " << additionalInfo << "\n";
    }

    // ��������� ���  
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

    // ������� ���������� ��������  
    void addSubscriber(const char* name, const char* hPhone, const char* wPhone, const char* mPhone, const char* info) {
        if (count < 100) {
            subscribers[count++] = new Subscriber(name, hPhone, wPhone, mPhone, info);
        }
        else {
            cout << "���������� ����� �����!\n";
        }
    }

    // ������� �������� ��������  
    void removeSubscriber(const char* name) {
        for (int i = 0; i < count; i++) {
            if (strcmp(subscribers[i]->getFullName(), name) == 0) {
                delete subscribers[i];
                for (int j = i; j < count - 1; j++) {
                    subscribers[j] = subscribers[j + 1];
                }
                count--;
                cout << "������� " << name << " ������.\n";
                return;
            }
        }
       cout << "������� �� ������.\n";
    }

    // ������� ������ ��������  
    void findSubscriber(const char* name) const {
        for (int i = 0; i < count; i++) {
            if (strcmp(subscribers[i]->getFullName(), name) == 0) {
                subscribers[i]->display();
                return;
            }
        }
        cout << "������� �� ������.\n";
    }

    // ������� ����������� ���� ���������  
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
    pb.addSubscriber("������ ���� ��������", "123456789", "987654321", "111222333", "���� �������");
    pb.addSubscriber("������ ���� ��������", "234567890", "876543210", "222333444", "�����");

   cout << "��� ��������:\n";
    pb.displayAll();

    pb.findSubscriber("������ ���� ��������");
    pb.removeSubscriber("������ ���� ��������");

    cout << "����� ��������:\n";
    pb.displayAll();

    return 0;
}