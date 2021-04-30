#include "Order.h"
#include "OrderSP.h"
#include "OrderUP.h"

bool Process(Order order) // takes `order` by value (i.e., creates a copy of the `Order` object)
{
  // ...
  return true;
} // `order` goes out of scope here and destroys 

bool Process(OrderSP orderSP) // adds a new temporary shared pointer when called
{
  // ...
  return true;
} // new shared pointer is destroyed up exit

bool Process(OrderUP& orderUP) // pass by reference -- cannot copy `std::unique_ptr` member (i.e., `OrderUP::discount`)
{
  // ...
  return true;
}


int main()
{
  // original approach -- has subtle bug
  Order o;
  o.SetDiscount(10);
  o.SetDiscount(10);
  Process(o); // `o` is copied to parameter `order`
  // `o.discount->amount` now contains garbage since `order`'s destructor deleted `o.discount`


  // better approach using `std::shared_ptr`
  OrderSP osp;
  osp.SetDiscount(10);
  osp.SetDiscount(10);
  Process(osp); // this is still problematic for this particular case -- what if `Process()` must change `osp` (i.e., rather than a copy of it), what if `osp` is a large/expensive-to-copy object, etc.


  // best approach using `std::unique_ptr`, which renders member variable `oup.discount` non-copyable
  OrderUP oup;
  oup.SetDiscount(10);
  oup.SetDiscount(10);
  Process(oup);

  return 0;
}
