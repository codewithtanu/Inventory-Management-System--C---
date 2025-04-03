#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Product
{
    private:
        int id;
        string name;
        double price;
        int quantity;
    
    public:
        Product(int id, string name, double price, int quantity)
        {
            this->id=id;
            this->name=name;
            this->price=price;
            this->quantity=quantity;
        }

        int getId() const{
            return id;
        }

        void setId(int id){
            this->id=id;
        }

        string getName() const{
            return name;
        }

        void setName(string name){
            this->name=name;
        }


        double getPrice() const{
            return price;
        }

        void setPrice(double price){
            this->price=price;
        }

        int getQuantity() const{
            return quantity;
        }

        void setQuantity(int quantity){
            this->quantity=quantity;
        }
};

class Inventory
{
    private:
        vector<Product> products;
    
    public:
        void addProduct(Product product)
        {
            bool found = false;
            for (auto& p : products)
            {
                if (p.getId() == product.getId())
                {
                    cout << "Id already Exist."<< endl;
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                products.push_back(product);
                cout << "Product added successfully." << endl;
                cout << "-------------------------------------------" <<endl;
            }
        }            

        void removeProduct(int id)
        {
            bool found = false;
            for (auto i = products.begin(); i != products.end(); i++)
            {
                if (i->getId() == id)
                {
                    products.erase(i);
                    found = true;
                    cout << "Product removed successfully." << endl;        
                    cout << "---------------------------------------" <<endl;
                    break;
                }
            }
            if (!found)
            {
                cout << "Id does not exist" << endl;
            }
        }

        Product* findProduct(int id)
        {
            for(auto i=products.begin();i!=products.end();i++)
            {
                if(i->getId()==id)
                {
                    return &(*i);
                }
            }
            return nullptr;
        }

        void updateProduct(int id, string name, double price, int quantity)
        {
            bool found = false;
            for (auto i = products.begin(); i != products.end(); i++)
            {
                if (i->getId() == id)
                {
                    i->setName(name);
                    i->setPrice(price);
                    i->setQuantity(quantity);
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "ID does not exist." << endl;
            }
        }        

        void printProduct() const{
            for(auto i=products.begin();i!=products.end();i++)
            {
                cout<<"ID : "<<i->getId()<<endl;
                cout<<"Name : "<<i->getName()<<endl;
                cout<<"Price : $"<<i->getPrice()<<endl;
                cout<<"Quantity : "<<i->getQuantity()<<endl<<endl;
            }
        }
};

int main() {
    Inventory inventory;
    cout << "-------------------------------------------------------" <<endl;
    cout << "-------------Inventory Management System --------------" <<endl;   
    cout << "-------------------------------------------------------" <<endl;
    cout << "----------------------- Welcome! ----------------------" <<endl;
    cout << "-------------------------------------------------------" <<endl;
    char choice;
    do {
        cout << "Please choose an option:" << endl;
        cout << "1. Add a product" << endl;
        cout << "2. Remove a product" << endl;
        cout << "3. Find a product" << endl;
        cout << "4. Update a product" << endl;
        cout << "5. View all products" << endl;
        cout << "Q. Quit" << endl;
        cin >> choice;

        switch (choice) {
        case '1': {
            int id;
            string name;
            double price;
            int quantity;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter product name: ";
            cin >> name;
            cout << "Enter product price: $ ";
            cin >> price;
            cout << "Enter product quantity: ";
            cin >> quantity;
            Product product(id, name, price, quantity);
            inventory.addProduct(product);
            break;
        }

        case '2': {
            int id;
            cout << "Enter product id: ";
            cin >> id;
            inventory.removeProduct(id);
            break;
        }

        case '3': {
            int id;
            cout << "Enter product id: ";
            cin >> id;
            Product* product = inventory.findProduct(id);
            if (product) {
                cout << "Name: " << product->getName() << endl;
                cout << "Price:  " << product->getPrice() << endl;
                cout << "Quantity: " << product->getQuantity() << endl;
                cout << "------------------------------------------" <<endl;
            }
            else {
                cout << "Product not found." << endl;
                cout << "------------------------------------------" <<endl;
            }
            break;
        }

        case '4': {
            int id;
            string name;
            double price;
            int quantity;
            cout << "Enter the product id: ";
            cin >> id;
            cout << "Enter new product name: ";
            cin >> name;
            cout << "Enter new product price: $ ";
            cin >> price;
            cout << "Enter new product quantity: ";
            cin >> quantity;
            inventory.updateProduct(id, name, price, quantity);
            cout << "Product updated successfully." << endl;
            cout << "--------------------------------------------" <<endl;
            break;
        }

        case '5': {
            inventory.printProduct();
            break;
        }
       
        case 'q':
        case 'Q':
            cout << "Goodbye!" << endl;
            cout << "----------------------------------------" <<endl;
            return 0;
        
        default:
            cout << "Invalid Choice. Please Try again" << endl;
            cout << "---------------------------------------" <<endl;
            break;
        }
    } while (true);

    return 0;
}