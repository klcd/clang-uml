#include <vector>
#include <algorithm>
#include <numeric>

namespace clanguml {
namespace t00001 {

class A {
public:
    int add(int x, int y) { return x + y; }

    int add3(int x, int y, int z)
    {
        std::vector<int> v;
        v.push_back(x);
        v.push_back(y);
        v.push_back(z);
        auto res = add(v[0], v[1]) + v[2];
        log_result(res);
        return res;
    }

    void log_result(int r) {}
};

class B {
public:
    B(A &a)
        : m_a{a}
    {
    }

    int wrap_add(int x, int y)
    {
        auto res = m_a.add(x, y);
        m_a.log_result(res);
        return res;
    }

    int wrap_add3(int x, int y, int z)
    {
        auto res = m_a.add3(x, y, z);
        m_a.log_result(res);
        return res;
    }

private:
    A &m_a;
};

int tmain()
{
    A a;
    B b(a);

    return b.wrap_add3(1, 2, 3);
}
}
}