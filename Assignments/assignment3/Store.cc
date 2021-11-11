
#include "Store.h"


using namespace std;

Store::Store(const string& storeName) {
  this->storeName = storeName;
  products = new List;


}

Store::~Store() {
  delete products;
}

void Store::findAvailableSLoc(StoreLocation** sloc) {

  for (int i = 0; i < SLOCS; ++i) {

    if (slocs[i].isAvailable()) {
      *sloc = slocs + i;
      return;
    }
  }

  *sloc = nullptr; // no available stores :(
}

void Store::findAvailableWHLoc(WHLocation** whloc) {
  for (int i = 0; i < WHLOCS; ++i) {
    if (whlocs[i].isAvailable()) {
      *whloc = whlocs + i;
      return;
    }
  }

  *whloc = nullptr; // no available warehouses
}

void Store::findProduct(const std::string& productName, Product** prod) {
  products->findProduct(productName, prod);
}


// various printing functions
void Store::printStoreStock() const {
  cout << "The locations in the store that have a product assigned to them:" << endl;
  for (int i = 0; i < SLOCS; ++i) {
    slocs[i].print();
    cout << endl;
  }

  cout << endl;
}

void Store::printWareHouseStock() const {
  cout << "A list of (non-empty) warehouses and the product they hold:" << endl;
  for (int i = 0; i < WHLOCS; ++i) {
    whlocs[i].print();
    cout << endl;
  }

  cout << endl;
}

void Store::printProducts() const {
  cout << "A list of all products:" << endl;
  products->print();
  cout << endl << endl;
}

void Store::print() const {
  cout << "Store name: " << storeName << endl << endl;
  printStoreStock();
  printWareHouseStock();
  printProducts();

}


// this was provided by the instructor
void Store::receiveProduct(const string& pname, int quantity){
    Product* prod = nullptr;
    cout<<"Receiving..."<<endl;
    products->findProduct(pname, &prod);
    if (prod==nullptr){
        cout<<"Making new product"<<endl;
        StoreLocation* sloc;
        findAvailableSLoc(&sloc);
        prod = new Product(pname, sloc);
        products->add(prod);

    }


    WHLocation* bloc;
    while(quantity > 0){
        findAvailableWHLoc(&bloc);
        if (quantity > bloc->getCapacity()){
            bloc->add(pname, bloc->getCapacity()); // use of unitilized variable
            prod->addWHLocation(bloc);
            quantity -= bloc->getCapacity();
        }else{
            bloc->add(pname, quantity);
            prod->addWHLocation(bloc);
            quantity = 0;
        }
    }

    cout<<"stocking store location..."<<endl;
    prod->stockStoreLocation();

}

void Store::fillOrder(const string& product, int& quantity){
    Product* prod;
    findProduct(product, &prod);
    if (prod == nullptr){
        return;
    }
    prod->fillOrder(quantity);
}
