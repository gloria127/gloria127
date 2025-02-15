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
        cout << "Книги " << name << ":\n";
        for (size_t i = 0; i < books.size(); ++i) {
            cout << i + 1 << " — " << books[i].title << endl;
        }
    }
};

void mainMenu() {
    cout << "Главное меню:\n";
    cout << "1 — Русские писатели\n";
    cout << "0 — Завершить чтение\n";
}

void pushkinMenu(const Writer& pushkin) {
    cout << "Третий уровень меню (Пушкин):\n";
    pushkin.displayBooks();
    cout << "0 — Выйти в предыдущее меню\n";
}

int main() {
    Writer pushkin("Александр Пушкин");
    pushkin.addBook(Book("Дубровский"));
    pushkin.addBook(Book("Евгений Онегин"));
    pushkin.addBook(Book("Зимний вечер"));
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
                            cout << "Вы выбрали: " << pushkin.books[thirdChoice - 1].title << endl;
                        }
                        else if (thirdChoice != 0) {
                            cout << "Неверный выбор. Попробуйте снова.\n";
                        }
                    } while (thirdChoice != 0);
                }
                else if (secondChoice == 2) {
                    cout << "Чтение Лермонтова пока не реализовано.\n";
                }
                else if (secondChoice == 3) {
                    cout << "Чтение Крылова пока не реализовано.\n";
                }
                else if (secondChoice != 0) {
                    cout << "Неверный выбор. Попробуйте снова.\n";
                }
            } while (secondChoice != 0);
        }
        else if (mainChoice != 0) {
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (mainChoice != 0);

    cout << "Завершение работы программы.\n";
    return 0;
}