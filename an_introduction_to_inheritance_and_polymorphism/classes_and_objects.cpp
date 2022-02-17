#include <iostream>

class Object {
 public:
  explicit Object(int i = 0) : i_{i} {}
  //    static void StaticFunc() {
  //        // Invalid use of member 'i_' in static member function
  //        std::cout << "i_: " << i_ << std::endl;
  //    }

  static void StaticFunc(const Object &co) {
    std::cout << "static function access private data member by reference: "
              << co.i_ << std::endl;
    std::cout << "static function access private member function by reference"
              << std::endl;
    co.PrivateFunc();
  }

 private:
  void PrivateFunc() const {
    std::cout << "private member function: i_: " << i_ << std::endl;
  }

  int i_;
};

int main() {
  Object o(1024);

  Object::StaticFunc(o);
  return 0;
}