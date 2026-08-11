/* Sarthak Yeole (SDY_25) */
#include <bits/stdc++.h>
using namespace std;

class Burger {
public:
    virtual void prepare() = 0;
    virtual ~Burger() {};           // virtual deconstructor
};

class BasicBurger : public Burger {
public:
    void prepare() override {
        cout << "Preapring Basic Burger" << endl;
    }
};

class StandardBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Standard Burger" << endl;
    }
};

class PremiumBurger : public Burger {
public:
    void prepare() override {
        cout << "Preapring Premium Burger" << endl;
    }
};

class BasicWheatBurger : public Burger {
public:
    void prepare() override {
        cout << "Preapring Basic Wheat Burger" << endl;
    }
};

class StandarWheatdBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Standard Wheat Burger" << endl;
    }
};

class PremiumWheatBurger : public Burger {
public:
    void prepare() override {
        cout << "Preapring Premium Wheat Burger" << endl;
    }
};

class BurgerFactory {
public:
    virtual Burger* createBurger(string& burgerType) = 0;
};

class SinghBurger : public BurgerFactory {
public:
    Burger* createBurger(string& burgerType) override {
        if(burgerType == "Basic") {
            return new BasicBurger();
        }
        else if(burgerType == "Standard") {
            return new StandardBurger();
        }
        else if(burgerType == "Premium") {
            return new PremiumBurger();
        }
        else {
            cout << "Invalid burger type" << endl;
            return NULL;
        }
    }
};

class KingBurger : public BurgerFactory {
public:
    Burger* createBurger(string& burgerType) override {
        if(burgerType == "Basic") {
            return new BasicWheatBurger();
        }
        else if(burgerType == "Standard") {
            return new StandarWheatdBurger();
        }
        else if(burgerType == "Premium") {
            return new PremiumWheatBurger();
        }
        else {
            cout << "Invalid burger type" << endl;
            return NULL;
        }
    }
};

int main(){
    string type = "Standard";
    
    BurgerFactory* myBurgerFactory = new KingBurger();

    Burger* myBurger = myBurgerFactory->createBurger(type);

    myBurger->prepare();
}
