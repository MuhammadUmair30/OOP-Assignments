#include <iostream>
using namespace std;

class Product {

private:

	char* name;
	float price;
	int quantity;

public:

	Product() {
		name = nullptr;
		price = 0.0;
		quantity = 0;
	}

	Product(const char* n, float p, int q) {

		int size = strlen(n);
		name = new char[size + 1];
		for (int i = 0;i < size;i++) {
			name[i] = n[i];
		}
		name[size] = '\0';

		price = p;
		quantity = q;
	}

	~Product() {
		delete[] name;
	}

	void setName(const char* n) {
		int size = strlen(n);
		name = new char[size + 1];
		for (int i = 0;i < size;i++) {
			name[i] = n[i];
		}
		name[size] = '\0';
	}
	const char* getName() {
		return name;
	}

	void setprice(float p) {
		price = p;
	}
	float getprice() {
		return price;
	}

	void setquantity(int q) {
		quantity = q;
	}
	int getquantity() {
		return quantity;
	}

	void restock(int amount) {
		if (amount > 0) {
			quantity += amount;
		}
		else {
			cout << "Invalid amount enter." << endl;
		}
	}

	float sell(int amount) {
		if (amount <= 0) {
			cout << "Invalid quantity." << endl;
			return 0.0;
		}
		if (amount > quantity) {
			cout << "Not enough stock available!" << endl;
		}

		quantity -= amount;
		return price * amount;
	}

	int lowStock() {
		int threshold = 5;
		return quantity < threshold;
	}

	void display() {

		cout << "Prodect: " << name << "\n" << "Price: " << price << "\n" << "Quantity: " << quantity << endl;
	}

};

Product& findHighestPrice(Product& p1, Product& p2, Product& p3) {
	Product& highest = p1;
	if (p2.getprice() > highest.getprice()){
       highest = p2;
	} 
	if (p3.getprice() > highest.getprice()){
       highest = p3;
	} 
	return highest;
}


int main() {

	Product laptop("Laptop", 999.99, 10);
	Product smartphone("Smartphone", 799.50, 15);
	Product headphones("Headphones", 120, 25);

	float totalRevenue = 0.0;
	int choice = 0;

	while (choice != 7) {
		cout << endl << "===== GadgetWorld Inventory Management =====" << endl;;
		cout << "1. Display all products" << endl;
		cout << "2. Restock a product" << endl;
		cout << "3. Sell a product" << endl;
		cout << "4. Check low-stock products" << endl;
		cout << "5. Show most expensive product" << endl;
		cout << "6. Show total revenue" << endl;
		cout << "7. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		if (choice == 1) {
			cout << endl << "-----Product list-----" << endl;
			laptop.display();
			smartphone.display();
			headphones.display();
		}
		else if (choice == 2) {
			int productChoice, amount;
			cout << "Select product to restock: " << endl;
			cout << "1. Laptop\n2. Smartphone\n3. Headphones " <<endl;
			cin >> productChoice;
			cout << "Enter quantity to restock: ";
			cin >> amount;

			if (productChoice == 1)
				laptop.restock(amount);
			else if (productChoice == 2)
				smartphone.restock(amount);
			else if (productChoice == 3)
				headphones.restock(amount);
			else
				cout << "Invalid product! " << endl;
		}

		else if (choice == 3) {
			int productChoice, amount;
			cout << "Select product to sell: " << endl;
			cout << "1. Laptop\n2. Smartphone\n3. Headphones\n";
			cin >> productChoice;
			cout << "Enter quantity to sell: ";
			cin >> amount;

			float revenue = 0.0;
			if (productChoice == 1)
				revenue = laptop.sell(amount);
			else if (productChoice == 2)
				revenue = smartphone.sell(amount);
			else if (productChoice == 3)
				revenue = headphones.sell(amount);
			else
				cout << "Invalid product! " << endl;

			totalRevenue += revenue;
			if (revenue > 0)
				cout << "Sale successful! Revenue: $" << revenue << endl;
		}

		else if (choice == 4) {
			cout << "--- Low Stock Products (less than 5 units) ---" << endl;
			bool anyLow = false;
			if (laptop.lowStock()) {
				laptop.display();
				anyLow = true;
			}
			if (smartphone.lowStock()) {
				smartphone.display();
				anyLow = true;
			}
			if (headphones.lowStock()) {
				headphones.display();
				anyLow = true;
			}
			if (!anyLow)
				cout << "No low stock items!" << endl;
		}
		else if (choice == 5) {
			Product& mostExp = findHighestPrice(laptop, smartphone, headphones);
			cout << "Most Expensive Product:\n";
			mostExp.display();
		}

		else if (choice == 6) {
			cout << "Total Revenue So Far: $" << totalRevenue << endl;
		}

		else if (choice == 7) {
			cout << "Exiting program. Goodbye!" << endl;
		}

		else {
			cout << "Invalid choice! Try again." << endl;
		}


	}

	return 0;
		
}