#include <iostream>
#include <windows.h>
#include <string>
using namespace std;



void libraryName() {
	cout << "\t @@@@@@   @@@      @@@@@@@@  @@   @@         @@       @@@@@@   @@@@@@@   @@@@@@@    @@@@@@   @@@@@@@   @@    @@\n";
	cout << "\t@@    @@  @@       @@         @@ @@          @@         @@     @@    @@  @@    @@  @@    @@  @@    @@   @@  @@ \n";
	cout << "\t@@@@@@@@  @@       @@@@@@       @            @@         @@     @@@@@@@   @@@@@@@   @@@@@@@@  @@@@@@@     @@@@  \n";
	cout << "\t@@    @@  @@       @@         @@ @@          @@         @@     @@    @@  @@    @@  @@    @@  @@    @@     @@   \n";
	cout << "\t@@    @@  @@@@@@@  @@@@@@@@  @@   @@         @@@@@@@  @@@@@@   @@@@@@@   @@    @@  @@    @@  @@    @@     @@   \n";
}

void welcome() {
	system("Color 0e");
	cout << "\n\n\n\n\n\n";
	cout << "\t     @@       @@  @@@@@@@  @@      @@@@@@@  @@@@@@@@  @@@@    @@@@  @@@@@@@@        @@@@@@@   @@@@@@\n";
	cout << "\t     @@   @   @@  @@       @@      @@       @@    @@  @@  @  @  @@  @@                @@     @@    @@\n";
	cout << "\t     @@  @@@  @@  @@@@@@   @@      @@       @@    @@  @@   @@   @@  @@@@@@            @@     @@    @@\n";
	cout << "\t     @@ @@ @@ @@  @@       @@      @@       @@    @@  @@        @@  @@                @@     @@    @@\n";
	cout << "\t     @@@     @@@  @@@@@@@  @@@@@@  @@@@@@@  @@@@@@@@  @@        @@  @@@@@@@@          @@      @@@@@@\n\n";
	libraryName();
	Sleep(6000);
	system("cls");
	system("Color 0e");
}


//Main Components

//Pointers
//global scope

int* bookId = nullptr;
string* bookAuthor = nullptr;
string* bookTitle = nullptr;
double* bookPrice = nullptr;
bool* isAvailable = nullptr;
int currentIndex = 0;
int capacity = 0;
int nextID = 1;



//Function Template

template <typename Ty>
void infoInitialization(Ty*& arr, int size) {
	if (arr) {
		delete[] arr;
		arr = nullptr;
	}
	arr = new Ty[size];

}


void libraryInitialization(int size) {
	infoInitialization(bookId, size);
	infoInitialization(bookTitle, size);
	infoInitialization(bookAuthor, size);
	infoInitialization(bookPrice, size);
	infoInitialization(isAvailable, size);
}

template <typename Ty>
void claerInfo(Ty*& arr) {
	if (arr) {
		delete[] arr;
		arr = nullptr;

	}
}


void clearLibrarySystem() {
	claerInfo(bookId);
	claerInfo(bookAuthor);
	claerInfo(bookTitle);
	claerInfo(bookPrice);
	claerInfo(isAvailable);
}
//int arr[] == int* arr
template <typename Ty>
void infoExpand(Ty*& info) {

	Ty* temp = new Ty[capacity];
	for (int i = 0; i < currentIndex; i++)
	{
		temp[i] = info[i];
	}
	delete[] info;
	info = temp;

}


void expandAll() {
	capacity *= 2;
	infoExpand(bookId);
	infoExpand(bookAuthor);
	infoExpand(bookTitle);
	infoExpand(bookPrice);
	infoExpand(isAvailable);



}

void addBook(string _title, string _author, double _price) {
	bookId[currentIndex] = nextID++;
	bookTitle[currentIndex] = _title;
	bookAuthor[currentIndex] = _author;
	bookPrice[currentIndex] = _price;
	isAvailable[currentIndex++] = true;
	cout << "the book is added successfully!\n";

}

//search
int searchBook(int id) {
	for (int i = 0; i < currentIndex; i++)
	{
		if (id == bookId[i]) return i;
	}
	return -1;

}


//remove a book
void removeBook(int id) {
	int search = searchBook(id);

	if (search == -1) {
		cout << "the book is not found!\n";
		return;
	}

	for (int i = search; i < currentIndex - 1; i++)
	{
		bookId[i] = bookId[i + 1];
		bookPrice[i] = bookPrice[i + 1];
		bookAuthor[i] = bookAuthor[i + 1];
		bookTitle[i] = bookTitle[i + 1];
		isAvailable[i] = isAvailable[i + 1];
	}
	currentIndex--;
	cout << "the book is removed successfully!\n";

}




//update


void updateMenu() {
	cout << "what do you want to update?\n"
		<< "1-Book Author\n"
		<< "2-Book Title\n"
		<< "3-Book Price\n";
}

void updateBook(int id) {
	int search = searchBook(id);

	if (search == -1) {
		cout << "the book is not found!\n";
		return;
	}
	string newInput;
	double newPrice;
	int choice;
	char answer = 'y';
	while (answer == 'y' || answer == 'Y') {
		updateMenu();
		cin >> choice;
		switch (choice) {
		case 1:
			system("cls");
			cout << "Enter a new book author\n";
			cin.ignore();
			getline(cin, newInput);
			bookAuthor[search] = newInput;
			cout << "the author is updated successfully!\n";

			break;

		case 2:
			system("cls");
			cout << "Enter a new book title\n";
			cin.ignore();
			getline(cin, newInput);
			bookTitle[search] = newInput;
			cout << "the title is updated successfully!\n";

			break;
		case 3:
			system("cls");
			cout << "Enter a new book price\n";
			cin >> newPrice;
			bookPrice[search] = newPrice;
			cout << "the price is updated successfully!\n";

			break;
		default:
			cout << "choose a number from 1 and 3\n";
			break;
		}
		cout << "Do you want to update anything else?(y/n)\n";

		cin >> answer;
	}



}


void borrowBook(int id) {
	int search = searchBook(id);

	if (search == -1) {
		cout << "the book is not found!\n";
		return;
	}


	if (isAvailable[search]) {

		isAvailable[search] = false;
		cout << "the book is borrowed sucessfully!\n";
		return;
	}
	cout << "the book is already borrowed!\n";

}


void returnBook(int id) {
	int search = searchBook(id);

	if (search == -1) {
		cout << "the book is not found!\n";
		return;
	}


	if (!isAvailable[search]) {

		isAvailable[search] = true;
		cout << "the book is returned sucessfully!\n";
		return;
	}
	cout << "the book is already returned!\n";

}


void displayInfo(int id) {
	int search = searchBook(id);

	if (search == -1) {
		cout << "the book is not found!\n";
		return;
	}

	cout << "=====================================\n"
		<< "Book ID     : " << bookId[search] << endl
		<< "Book Title  : " << bookTitle[search] << endl
		<< "Book Author : " << bookAuthor[search] << endl
		<< "Book Price  : " << bookPrice[search] << endl
		<< "Book Status : " << (isAvailable[search] ? "Available" : "not Available") << endl
		<< "=====================================\n";


}


void displayInfoByIndex(int id) {


	cout << "=====================================\n"
		<< "Book ID     : " << bookId[id] << endl
		<< "Book Title  : " << bookTitle[id] << endl
		<< "Book Author : " << bookAuthor[id] << endl
		<< "Book Price  : " << bookPrice[id] << endl
		<< "Book Status : " << (isAvailable[id] ? "Available" : "not Available") << endl
		<< "=====================================\n";


}

void booksList() {
	for (int i = 0; i < currentIndex; i++)
	{
		displayInfoByIndex(i);
	}


}


void mainMenu() {
	cout << "Choose an Option: \n"
		<< "1-Add a Book\n"
		<< "2-Remove a Book\n"
		<< "3-Update a Book\n"
		<< "4-Borrow a Book\n"
		<< "5-Return a Book\n"
		<< "6-Display a Book Info\n"
		<< "7-List all Books\n"
		<< "8-Exit a Book\n"
		<< "Your Option is: \n";
}

void run() {
	welcome();
	cout << "Enter the capacity of the library\n";
	cin >> capacity;
	libraryInitialization(capacity);
	bool flag = true;
	int option, id;
	string author, title;
	double price;
	while (flag) {
		system("cls");
		mainMenu();
		cin >> option;
		switch (option) {
		case 1:
			system("cls");
			if (currentIndex == capacity) {
				expandAll();

			}
			cout << "Enter the book title\n";
			cin.ignore();
			getline(cin, title);
			cout << "Enter the book author\n";
			getline(cin, author);
			cout << "Enter the book price\n";
			cin >> price;
			addBook(title, author, price);
			system("pause");
			break;
		case 2:
			system("cls");
			cout << "Enter the book ID:\n";
			cin >> id;
			removeBook(id);
			system("pause");
			break;
		case 3:
			system("cls");
			cout << "Enter the book ID:\n";
			cin >> id;
			updateBook(id);
			system("pause");
			break;
		case 4:
			system("cls");
			cout << "Enter the book ID:\n";
			cin >> id;
			borrowBook(id);
			system("pause");
			break;
		case 5:
			system("cls");
			cout << "Enter the book ID:\n";
			cin >> id;
			returnBook(id);
			system("pause");
			break;
		case 6:
			system("cls");
			cout << "Enter the book ID:\n";
			cin >> id;
			displayInfo(id);
			system("pause");
			break;
		case 7:
			system("cls");
			booksList();
			system("pause");
			break;
		case 8:
			flag = false;
			break;
		default:
			cout << "Choose a Number from 1 to 8\n";
			break;
		}

		system("cls");



	}

	cout << "Thank You for Your Visit.\n\n";

	clearLibrarySystem();
}



int main()
{

	run();

}



