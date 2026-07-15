# 📘 Object-Oriented Programming (OOP) — Complete Study Notes

---

## 1. Introduction to Programming Paradigms

- **Programming paradigm** = a style/approach of writing code.
- Two major paradigms:
  - **Procedural Programming** — code is a sequence of instructions (functions). Data and functions are separate.
  - **Object-Oriented Programming (OOP)** — code is organized around **objects** that bundle data + behavior together.
- Procedural works fine for small programs, but as code grows it becomes hard to manage, debug, and reuse.
- OOP was introduced to solve these problems by modeling code like real-world entities.

> **Analogy:** Procedural programming is like cooking by following a long recipe step-by-step. OOP is like having a **kitchen team** — each chef (object) knows their own recipes (methods) and has their own ingredients (data).

```cpp
#include <iostream>
using namespace std;

// Procedural style
void greet() {
    cout << "Hello from a function!" << endl;
}

// OOP style — logic lives inside an object
class Greeter {
public:
    void greet() {
        cout << "Hello from an object!" << endl;
    }
};

int main() {
    greet();              // procedural call

    Greeter g;
    g.greet();            // OOP call
    return 0;
}
```

---

## 2. OOP — The Four Pillars

- OOP rests on **4 pillars**:
  1. **Encapsulation** — wrap data + methods together; hide internals.
  2. **Inheritance** — a new class can reuse/extend an existing class.
  3. **Polymorphism** — same function name, different behaviors.
  4. **Abstraction** — show only what's necessary, hide the complexity.
- **Why OOP?**
  - Code reusability
  - Easier maintenance
  - Real-world modeling
  - Data security (via access control)

> **Analogy:** Think of a **car**.  
> - *Encapsulation* — engine internals are hidden under the hood.  
> - *Inheritance* — an electric car inherits features of a generic car.  
> - *Polymorphism* — pressing the "start" button works differently in a diesel vs electric car.  
> - *Abstraction* — you use the steering wheel without knowing the rack-and-pinion mechanism.

---

## 3. Class & Object

- **Class** = a blueprint/template. It defines **what** data and functions an entity will have.
- **Object** = a real instance created from that blueprint.
- A class by itself takes **no memory**; memory is allocated when an object is created.
- Class contains:
  - **Data members** (variables)
  - **Member functions** (methods)

> **Analogy:** A class is like the **architectural plan** of a house. An object is the **actual house** built from that plan. You can build many houses from one plan.

```cpp
#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Student s1;           // s1 is an object of class Student
    s1.name = "Aman";
    s1.age = 20;
    s1.display();         // Name: Aman, Age: 20

    Student s2;           // another object from the same blueprint
    s2.name = "Riya";
    s2.age = 21;
    s2.display();         // Name: Riya, Age: 21

    return 0;
}
```

---

## 4. Access Specifiers

- Access specifiers control **who can access** the members of a class.
- Three types:

| Specifier | Inside Class | Derived Class | Outside Class |
|-----------|:---:|:---:|:---:|
| `public` | ✅ | ✅ | ✅ |
| `protected` | ✅ | ✅ | ❌ |
| `private` | ✅ | ❌ | ❌ |

- **`public`** — accessible everywhere.
- **`private`** — accessible only within the same class. (default in `class`)
- **`protected`** — accessible within the class and its child classes.

> **Analogy:**  
> - `public` = your **name** — anyone can know it.  
> - `protected` = your **family recipes** — only family (derived classes) can access.  
> - `private` = your **diary** — only you can read it.

```cpp
#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;        // only accessible inside this class

protected:
    string branch;         // accessible in this class + child classes

public:
    string ownerName;      // accessible everywhere

    void setBalance(double b) {
        if (b >= 0)
            balance = b;   // controlled access via public method
    }

    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount acc;
    acc.ownerName = "Aman";       // ✅ public
    // acc.balance = 1000;        // ❌ ERROR — private
    // acc.branch = "Delhi";      // ❌ ERROR — protected
    acc.setBalance(5000);         // ✅ access via public method
    cout << acc.getBalance() << endl;  // 5000
    return 0;
}
```

---

## 5. Encapsulation

- **Encapsulation** = wrapping data (variables) and methods (functions) into a single unit (class) **and** restricting direct access to the data.
- Achieved by making data members `private` and providing `public` getter/setter methods.
- **Data hiding** is the core benefit — outside code can't corrupt internal state.
- Provides **controlled access** — you decide what can be read/written and with what validations.

> **Analogy:** A **medical capsule** wraps medicine inside a shell. You swallow the capsule (use the public interface); you don't touch the raw powder inside (private data).

```cpp
#include <iostream>
using namespace std;

class Employee {
private:
    int salary;   // hidden from outside

public:
    // setter — with validation
    void setSalary(int s) {
        if (s > 0)
            salary = s;
        else
            cout << "Invalid salary!" << endl;
    }

    // getter
    int getSalary() {
        return salary;
    }
};

int main() {
    Employee e;
    e.setSalary(50000);
    cout << "Salary: " << e.getSalary() << endl;  // 50000

    e.setSalary(-100);   // Invalid salary!
    return 0;
}
```

---

## 6. Constructor

- A **constructor** is a special member function that is **automatically called** when an object is created.
- Purpose: **initialize** the object's data members.
- Rules:
  - Same name as the class.
  - No return type (not even `void`).
  - Called only **once** per object, at the time of creation.
- Three types:
  1. **Default constructor** — takes no arguments.
  2. **Parameterized constructor** — takes arguments to initialize with custom values.
  3. **Copy constructor** — creates a new object as a copy of an existing object.

> **Analogy:** When a **baby is born**, it automatically gets a name, date of birth, etc. — that's the constructor setting up initial values at creation time.

```cpp
#include <iostream>
using namespace std;

class Car {
public:
    string brand;
    int year;

    // Default constructor
    Car() {
        brand = "Unknown";
        year = 0;
        cout << "Default constructor called" << endl;
    }

    // Parameterized constructor
    Car(string b, int y) {
        brand = b;
        year = y;
        cout << "Parameterized constructor called" << endl;
    }

    void display() {
        cout << brand << " (" << year << ")" << endl;
    }
};

int main() {
    Car c1;                 // Default constructor called
    c1.display();           // Unknown (0)

    Car c2("Toyota", 2024); // Parameterized constructor called
    c2.display();           // Toyota (2024)

    return 0;
}
```

---

## 7. `this` Pointer

- **`this`** is an implicit pointer available inside every non-static member function.
- It **points to the current object** that invoked the function.
- Used when:
  - Parameter names **shadow** (are the same as) data member names.
  - You want to **return the current object** from a method (for method chaining).
  - You need to **pass the current object** to another function.

> **Analogy:** In a classroom, if the teacher says "stand up," every student knows "stand up" means **themselves**. `this` is each student's way of referring to themselves.

```cpp
#include <iostream>
using namespace std;

class Box {
    int length;

public:
    // 'length' parameter shadows the data member
    // 'this->length' refers to the data member
    Box(int length) {
        this->length = length;
    }

    // method chaining: return *this
    Box& addLength(int val) {
        this->length += val;
        return *this;
    }

    void display() {
        cout << "Length: " << this->length << endl;
    }
};

int main() {
    Box b(10);
    b.addLength(5).addLength(3);   // method chaining
    b.display();                   // Length: 18
    return 0;
}
```

---

## 8. Copy Constructor

- A **copy constructor** creates a new object as an **exact copy** of an existing object.
- Syntax: `ClassName(const ClassName &obj)`
- The compiler provides a **default copy constructor** that does a member-by-member (shallow) copy.
- You write your own when you need a **deep copy** (see next topic).
- Invoked when:
  - `ClassName obj2 = obj1;`
  - `ClassName obj2(obj1);`
  - An object is passed **by value** to a function.
  - An object is **returned by value** from a function.

> **Analogy:** **Photocopying a document** — the copy constructor creates a duplicate. The original and the copy look the same, but they are separate sheets of paper.

```cpp
#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;

    // Parameterized constructor
    Student(string n, int a) : name(n), age(a) {}

    // Copy constructor
    Student(const Student &other) {
        name = other.name;
        age = other.age;
        cout << "Copy constructor called!" << endl;
    }

    void display() {
        cout << name << ", " << age << endl;
    }
};

int main() {
    Student s1("Aman", 20);
    Student s2 = s1;          // Copy constructor called!

    s2.name = "Riya";         // changing s2 does NOT affect s1
    s1.display();             // Aman, 20
    s2.display();             // Riya, 20
    return 0;
}
```

---

## 9. Shallow Copy vs Deep Copy

- **Shallow Copy** (default):
  - Copies all member values **as-is**, including pointers.
  - If a member is a pointer, both original and copy point to the **same memory**.
  - Changing data through one object **affects** the other.
  - Dangerous: double-free / dangling pointer bugs.

- **Deep Copy**:
  - Allocates **new memory** for pointer members and copies the actual data.
  - Original and copy are **completely independent**.
  - Must be implemented manually in the copy constructor (and assignment operator).

> **Analogy:**  
> - *Shallow copy* = sharing a **Google Doc link**. Both people edit the same document.  
> - *Deep copy* = **downloading the doc as a PDF**. Each person has their own independent copy.

```cpp
#include <iostream>
using namespace std;

class Shallow {
public:
    int* data;

    Shallow(int val) {
        data = new int(val);
    }

    // Default copy = shallow (both point to same memory)
};

class Deep {
public:
    int* data;

    Deep(int val) {
        data = new int(val);
    }

    // Deep copy constructor — allocates NEW memory
    Deep(const Deep &other) {
        data = new int(*other.data);  // copy the value, not the pointer
    }

    ~Deep() {
        delete data;
    }
};

int main() {
    // --- Shallow copy problem ---
    Shallow a(10);
    Shallow b = a;           // both a.data and b.data point to SAME memory
    *b.data = 99;
    cout << "Shallow — a: " << *a.data << endl;  // 99 (unintended!)

    // --- Deep copy solution ---
    Deep x(10);
    Deep y = x;              // y gets its OWN copy of the data
    *y.data = 99;
    cout << "Deep    — x: " << *x.data << endl;  // 10 (safe!)

    return 0;
}
```

---

## 10. Destructor

- A **destructor** is a special function called **automatically** when an object goes out of scope or is deleted.
- Purpose: **clean up resources** (free heap memory, close files, release locks).
- Rules:
  - Same name as the class, prefixed with `~`.
  - No parameters, no return type.
  - Only **one** destructor per class (no overloading).
  - Called in **reverse order** of construction.

> **Analogy:** When you **check out of a hotel room**, housekeeping cleans the room, returns the key, and releases the reservation. That's the destructor — cleanup after you're done.

```cpp
#include <iostream>
using namespace std;

class File {
    string filename;

public:
    File(string name) : filename(name) {
        cout << "Opened file: " << filename << endl;
    }

    ~File() {
        cout << "Closed file: " << filename << endl;  // automatic cleanup
    }
};

int main() {
    File f1("data.txt");
    File f2("log.txt");

    cout << "--- End of main ---" << endl;
    // Destructors called automatically in reverse order:
    // Closed file: log.txt
    // Closed file: data.txt
    return 0;
}
```

---

## 11. Inheritance

- **Inheritance** = a mechanism where a **child class** (derived) acquires the properties and behaviors of a **parent class** (base).
- Promotes **code reuse** — don't rewrite what already exists.
- The derived class can **add new** members or **override** existing ones.
- Syntax: `class Child : access_specifier Parent { };`
- **Base class** = parent. **Derived class** = child.

> **Analogy:** A **child inherits traits** from their parents — eye color, height, etc. Similarly, a derived class inherits data and methods from the base class, and can also have its own unique traits.

```cpp
#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    string name;

    void eat() {
        cout << name << " is eating." << endl;
    }
};

// Derived class
class Dog : public Animal {
public:
    void bark() {
        cout << name << " says Woof!" << endl;
    }
};

int main() {
    Dog d;
    d.name = "Buddy";   // inherited from Animal
    d.eat();             // inherited from Animal — Buddy is eating.
    d.bark();            // own method — Buddy says Woof!
    return 0;
}
```

---

## 12. Mode of Inheritance

- The **access specifier** used while inheriting decides how base class members are treated in the derived class.

| Base Member | `public` Inheritance | `protected` Inheritance | `private` Inheritance |
|---|---|---|---|
| `public` | stays `public` | becomes `protected` | becomes `private` |
| `protected` | stays `protected` | stays `protected` | becomes `private` |
| `private` | ❌ not inherited | ❌ not inherited | ❌ not inherited |

- **`public` inheritance** — "is-a" relationship. Most common.
- **`protected` inheritance** — restricts base's public members to protected in child.
- **`private` inheritance** — everything from base becomes private in child. Most restrictive.
- `private` members of the base are **never directly accessible** in the derived class regardless of mode; use getters/setters.

> **Analogy:**  
> - *Public inheritance* = inheriting a **family business** openly — everyone knows you own it.  
> - *Protected inheritance* = the business is now for **family use only**.  
> - *Private inheritance* = the business is **your personal secret** — nobody outside knows.

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    int x = 1;
protected:
    int y = 2;
private:
    int z = 3;
};

// Public inheritance
class PubChild : public Base {
public:
    void show() {
        cout << "x = " << x << endl;   // ✅ still public
        cout << "y = " << y << endl;   // ✅ still protected
        // cout << z;                  // ❌ private — never inherited
    }
};

// Private inheritance
class PriChild : private Base {
public:
    void show() {
        cout << "x = " << x << endl;   // ✅ but now private in PriChild
        cout << "y = " << y << endl;   // ✅ but now private in PriChild
    }
};

int main() {
    PubChild pc;
    pc.x = 10;        // ✅ public member — accessible
    // pc.y = 20;     // ❌ protected — not accessible outside

    PriChild pr;
    // pr.x = 10;     // ❌ x is now private in PriChild
    pr.show();         // ✅ accessible through public method
    return 0;
}
```

---

## 13. Types of Inheritance

- **5 types** of inheritance in C++:

| Type | Structure | Description |
|---|---|---|
| **Single** | A → B | One parent, one child |
| **Multilevel** | A → B → C | Chain: grandparent → parent → child |
| **Multiple** | A, B → C | One child inherits from multiple parents |
| **Hierarchical** | A → B, C, D | One parent, multiple children |
| **Hybrid** | Mix of above | Combination (may cause diamond problem) |

- **Diamond Problem** (in multiple/hybrid): If two parents inherit from the same grandparent, the grandchild gets **two copies** of the grandparent. Fix: use **`virtual` inheritance**.

> **Analogy:**  
> - *Single* = child learns from **one teacher**.  
> - *Multiple* = child learns from **two teachers** at once.  
> - *Multilevel* = knowledge passed from **grandparent → parent → child**.  
> - *Hierarchical* = **one teacher** teaches many students.

```cpp
#include <iostream>
using namespace std;

// --- Single Inheritance ---
class A { public: void showA() { cout << "Class A" << endl; } };
class B : public A { public: void showB() { cout << "Class B" << endl; } };

// --- Multilevel Inheritance ---
class C : public B { public: void showC() { cout << "Class C" << endl; } };

// --- Multiple Inheritance ---
class X { public: void showX() { cout << "Class X" << endl; } };
class Y { public: void showY() { cout << "Class Y" << endl; } };
class Z : public X, public Y {
public:
    void showZ() { cout << "Class Z (from X and Y)" << endl; }
};

// --- Diamond Problem Fix with Virtual Inheritance ---
class Base { public: int val = 42; };
class D1 : virtual public Base {};
class D2 : virtual public Base {};
class Diamond : public D1, public D2 {
public:
    void show() { cout << "val = " << val << endl; } // only ONE copy of val
};

int main() {
    C obj;
    obj.showA(); obj.showB(); obj.showC();  // multilevel chain

    Z zObj;
    zObj.showX(); zObj.showY(); zObj.showZ(); // multiple

    Diamond d;
    d.show();  // val = 42 — no ambiguity thanks to virtual
    return 0;
}
```

---

## 14. Polymorphism

- **Polymorphism** = "many forms" — same name, different behavior.
- Two types:
  1. **Compile-time (Static) Polymorphism**:
     - Resolved at **compile time**.
     - Achieved via **function overloading** and **operator overloading**.
  2. **Run-time (Dynamic) Polymorphism**:
     - Resolved at **run time**.
     - Achieved via **function overriding** + **virtual functions**.
- Polymorphism allows writing flexible, extensible code.

> **Analogy:** The word **"open"** is polymorphic in real life.  
> - "Open the door" — push/pull.  
> - "Open the book" — flip the cover.  
> - "Open the app" — tap the icon.  
> Same word, different actions depending on context.

```cpp
#include <iostream>
using namespace std;

// Compile-time: function overloading
class Math {
public:
    int add(int a, int b)          { return a + b; }
    double add(double a, double b) { return a + b; }
};

// Run-time: function overriding
class Shape {
public:
    virtual void draw() {
        cout << "Drawing a shape" << endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a circle" << endl;
    }
};

int main() {
    Math m;
    cout << m.add(2, 3) << endl;       // 5  (int version)
    cout << m.add(2.5, 3.1) << endl;   // 5.6 (double version)

    Shape* s = new Circle();
    s->draw();   // "Drawing a circle" — decided at runtime
    delete s;
    return 0;
}
```

---

## 15. Function Overloading

- **Function overloading** = multiple functions with the **same name** but **different parameter lists** (number, type, or order of parameters).
- Resolved at **compile time** (static polymorphism).
- Return type alone is **NOT** sufficient to overload — parameters must differ.
- Makes code more readable — one logical name for similar operations.

> **Analogy:** A **washing machine** has one "wash" button but behaves differently based on what you put in — delicates get a gentle cycle, jeans get a heavy cycle. Same name, different behavior based on input.

```cpp
#include <iostream>
using namespace std;

class Printer {
public:
    void print(int i) {
        cout << "Integer: " << i << endl;
    }

    void print(string s) {
        cout << "String: " << s << endl;
    }

    void print(int a, int b) {
        cout << "Two ints: " << a << ", " << b << endl;
    }
};

int main() {
    Printer p;
    p.print(42);            // Integer: 42
    p.print("Hello");       // String: Hello
    p.print(3, 7);          // Two ints: 3, 7
    return 0;
}
```

---

## 16. Function Overriding

- **Function overriding** = a derived class provides its **own implementation** of a function that is already defined in the base class.
- Requirements:
  - Same function name, same parameters, same return type.
  - Must have an **inheritance** relationship.
  - The base class function should be declared `virtual` for proper runtime behavior with pointers/references.
- Without `virtual`, the function called depends on the **pointer type** (static binding), not the actual object.

> **Analogy:** Your parents taught you a **recipe**. You **override** it with your own twist — same dish name, but your version.

```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() {
        cout << "Some generic animal sound" << endl;
    }
};

class Cat : public Animal {
public:
    void sound() override {     // overrides base class version
        cout << "Meow!" << endl;
    }
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Woof!" << endl;
    }
};

int main() {
    Animal* a;

    Cat c;
    Dog d;

    a = &c;
    a->sound();   // Meow! — runtime decision

    a = &d;
    a->sound();   // Woof! — runtime decision

    return 0;
}
```

---

## 17. Virtual Function

- A **virtual function** is a member function declared with the `virtual` keyword in the base class.
- Tells the compiler: "don't bind this at compile time; decide at **runtime** which version to call."
- Enables **dynamic dispatch** via a **vtable** (virtual table).
- How it works internally:
  - Each class with virtual functions has a **vtable** — a table of function pointers.
  - Each object has a hidden **vptr** (virtual pointer) pointing to its class's vtable.
  - At runtime, the correct function is looked up through the vptr.
- **Pure virtual function** — has no body: `virtual void func() = 0;` — makes the class abstract.

> **Analogy:** A **TV remote's power button** is virtual — it says "turn on," but **which TV** turns on depends on which TV the remote is paired with. The decision happens at runtime.

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() {          // virtual function
        cout << "Base class" << endl;
    }

    void greet() {                 // non-virtual
        cout << "Hello from Base" << endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        cout << "Derived class" << endl;
    }

    void greet() {
        cout << "Hello from Derived" << endl;
    }
};

int main() {
    Base* ptr = new Derived();

    ptr->show();    // "Derived class" — virtual → runtime binding ✅
    ptr->greet();   // "Hello from Base" — non-virtual → compile-time binding ⚠️

    delete ptr;
    return 0;
}
```

---

## 18. Abstraction

- **Abstraction** = showing only the **essential features** and hiding the implementation details.
- The user interacts with a simple interface; the complex logic is hidden.
- Achieved in C++ through:
  - **Abstract classes** (classes with pure virtual functions).
  - **Header files** — you use `cout` without knowing how it's implemented.
- Abstraction ≠ Encapsulation:
  - *Abstraction* = **what** to show (design level).
  - *Encapsulation* = **how** to hide (implementation level).

> **Analogy:** An **ATM machine** — you insert your card, enter a PIN, and get cash. You don't know the internal banking protocols, network calls, or vault mechanics. That's abstraction.

```cpp
#include <iostream>
using namespace std;

// Abstract interface — user sees only this
class RemoteControl {
public:
    virtual void powerOn() = 0;     // what to do — not how
    virtual void powerOff() = 0;
};

// Implementation hidden inside
class TV : public RemoteControl {
public:
    void powerOn() override {
        cout << "TV is ON (initializing display, tuner, speakers...)" << endl;
    }

    void powerOff() override {
        cout << "TV is OFF" << endl;
    }
};

int main() {
    RemoteControl* device = new TV();
    device->powerOn();     // user doesn't care about internal steps
    device->powerOff();
    delete device;
    return 0;
}
```

---

## 19. Abstract Class

- An **abstract class** has at least one **pure virtual function** (`= 0`).
- **Cannot be instantiated** — you can't create objects of it.
- Acts as a **contract/interface** — derived classes **must** override all pure virtual functions, otherwise they also become abstract.
- Can have:
  - Pure virtual functions (no body).
  - Regular functions (with body).
  - Data members.
- Used to define a **common interface** for a family of classes.

> **Analogy:** A **job application form** is abstract — it defines fields like "Name," "Experience," "Skills" that every applicant **must fill in**. The form itself isn't a complete application; each person fills it differently.

```cpp
#include <iostream>
using namespace std;

// Abstract class — cannot be instantiated
class Shape {
public:
    virtual double area() = 0;       // pure virtual — MUST be overridden

    void describe() {                // regular method — shared behavior
        cout << "I am a shape. My area is: " << area() << endl;
    }
};

class Rectangle : public Shape {
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() override {
        return length * width;
    }
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}

    double area() override {
        return 3.14159 * radius * radius;
    }
};

int main() {
    // Shape s;              // ❌ ERROR — can't instantiate abstract class

    Shape* s1 = new Rectangle(5, 3);
    Shape* s2 = new Circle(4);

    s1->describe();   // I am a shape. My area is: 15
    s2->describe();   // I am a shape. My area is: 50.2655

    delete s1;
    delete s2;
    return 0;
}
```

---

## 20. Static Keyword

- The `static` keyword changes the **lifetime and scope** of a variable or function.
- **Static data member**:
  - Belongs to the **class**, not to any specific object.
  - Shared by **all objects** of that class.
  - Only **one copy** exists in memory.
  - Must be **defined outside** the class.
- **Static member function**:
  - Can be called **without creating an object** (`ClassName::func()`).
  - Can only access **static members** (no `this` pointer).
- **Static local variable** (inside a function):
  - Initialized **only once**; retains its value between function calls.

> **Analogy:** A **classroom whiteboard** is static — it belongs to the room, not to any one student. All students share it and can see the same content.

```cpp
#include <iostream>
using namespace std;

class Counter {
    static int count;     // shared across all objects

public:
    Counter() {
        count++;
    }

    static int getCount() {     // static function — no 'this' pointer
        return count;
    }
};

// Must define static member outside the class
int Counter::count = 0;

// Static local variable example
void tracker() {
    static int calls = 0;   // initialized only once
    calls++;
    cout << "Called " << calls << " time(s)" << endl;
}

int main() {
    Counter c1, c2, c3;
    cout << "Objects created: " << Counter::getCount() << endl;  // 3

    tracker();   // Called 1 time(s)
    tracker();   // Called 2 time(s)
    tracker();   // Called 3 time(s)
    return 0;
}
```

---

## 🧠 Quick Revision Cheat Sheet

| # | Concept | One-Liner |
|---|---------|-----------|
| 1 | OOP | Programming using objects that bundle data + behavior |
| 2 | Class | Blueprint/template for objects |
| 3 | Object | Real instance created from a class |
| 4 | Access Specifiers | `public`, `protected`, `private` — control visibility |
| 5 | Encapsulation | Wrap data + methods, hide internals via private + getters/setters |
| 6 | Constructor | Auto-called on object creation to initialize values |
| 7 | `this` Pointer | Points to the current object inside a member function |
| 8 | Copy Constructor | Creates a new object as a copy of an existing one |
| 9 | Shallow Copy | Copies pointers (shared memory) — risky |
| 10 | Deep Copy | Copies actual data (new memory) — safe |
| 11 | Destructor | Auto-called on object destruction to clean up resources |
| 12 | Inheritance | Child class reuses/extends parent class |
| 13 | Mode of Inheritance | How base members' access changes: public/protected/private |
| 14 | Types of Inheritance | Single, Multilevel, Multiple, Hierarchical, Hybrid |
| 15 | Polymorphism | Same name, different behavior (compile-time or runtime) |
| 16 | Function Overloading | Same function name, different parameters (compile-time) |
| 17 | Function Overriding | Child redefines parent's function (runtime with virtual) |
| 18 | Virtual Function | Enables runtime binding via vtable mechanism |
| 19 | Abstraction | Show essential features, hide complexity |
| 20 | Abstract Class | Has pure virtual function(s), can't be instantiated |
| 21 | Static Keyword | Belongs to the class, not to any object; shared by all |

---

> *All the best for your exams! 🚀*
