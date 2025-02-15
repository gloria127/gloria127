#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
public:
    string title;

    Book(const string& title) : title(title) {}
};

class Writer {
public:
    string name;
    vector<Book> books;

    Writer(const string& name) : name(name) {}

    void addBook(const Book& book) {
        books.push_back(book);
    }

    void displayBooks() const {
        cout << "����� " << name << ":\n";
        for (size_t i = 0; i < books.size(); ++i) {
            cout << i + 1 << " � " << books[i].title << endl;
        }
    }
};

void mainMenu() {
    cout << "������� ����:\n";
    cout << "1 � ������� ��������\n";
    cout << "0 � ��������� ������\n";
}

void pushkinMenu(const Writer& pushkin) {
    cout << "������ ������� ���� (������):\n";
    pushkin.displayBooks();
    cout << "0 � ����� � ���������� ����\n";
}

int main() {
    Writer pushkin("��������� ������");
    pushkin.addBook(Book("����������"));
    pushkin.addBook(Book("������� ������"));
    pushkin.addBook(Book("������ �����"));
    int mainChoice;
    do {
        mainMenu();
        cin >> mainChoice;

        if (mainChoice == 1) {
            int secondChoice;
            do {
                secondLevelMenu();
                cin >> secondChoice;

                if (secondChoice == 1) {
                    int thirdChoice;
                    do {
                        pushkinMenu(pushkin);
                        cin >> thirdChoice;

                        if (thirdChoice > 0 && thirdChoice <= pushkin.books.size()) {
                            cout << "�� �������: " << pushkin.books[thirdChoice - 1].title << endl;
                        }
                        else if (thirdChoice != 0) {
                            cout << "�������� �����. ���������� �����.\n";
                        }
                    } while (thirdChoice != 0);
                }
                else if (secondChoice == 2) {
                    cout << "������ ���������� ���� �� �����������.\n";
                }
                else if (secondChoice == 3) {
                    cout << "������ ������� ���� �� �����������.\n";
                }
                else if (secondChoice != 0) {
                    cout << "�������� �����. ���������� �����.\n";
                }
            } while (secondChoice != 0);
        }
        else if (mainChoice != 0) {
            cout << "�������� �����. ���������� �����.\n";
        }
    } while (mainChoice != 0);

    cout << "���������� ������ ���������.\n";
    return 0;
}