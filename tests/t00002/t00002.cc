#include <memory>

namespace clanguml {
namespace t00002 {

class A { };
 
class B { };
 
class C { };
 
class R {
public:
    std::unique_ptr<A> a;
    std::shared_ptr<B> b;
    std::weak_ptr<C> c;
};

int main()
{
	R r;
	return 0;
}

}
}