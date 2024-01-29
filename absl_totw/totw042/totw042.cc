// https://abseil.io/tips/42
#include <iostream>

/* This program demonstrates that virtual function despatch is disabled in constructors. Objects are constructed base-first, so at the time of calling base-class
 constructors, the subclass virtual function may be undefined.
 */
class Parent
{
public:
  Parent()
  {
    Foo();
  }

  virtual void Foo()
  {
    data = 5;
  };

  int data = 0;
};

class Child : public Parent
{
  virtual void Foo()
  {
    // Constructor in Parent does NOT call this virtual functions.
    data = 10;
  }
};

int main()
{
  Parent parent;
  std::cout << "Parent.data = " << parent.data << std::endl;
  Child child;
  std::cout << "Child.data = " << child.data << std::endl;
  return 0;
}
