#include <map>
#include <string>
#include <vector>

namespace clanguml {
namespace t00062 {
template <typename T> struct A;

template <typename U> struct A<U &> {
    U &u;
};

template <typename U> struct A<std::map<std::string, U> &> {
    U &u;
};

template <>
struct A<std::map<std::string, std::map<std::string, std::string>> &> { };

template <typename U> struct A<U ***> {
    U ***u;
};

template <typename U> struct A<U &&> {
    U &&u;
};

template <typename U> struct A<U const &> {
    U const &u;
};

template <typename M, typename C> struct A<M C::*> {
    C &c;
    M C::*m;
};

template <typename M, typename C> struct A<M C::*&&> {
    C &&c;
    M C::*m;
};

template <typename M, typename C, typename Arg> struct A<M (C::*)(Arg)> {
    C &c;
    M C::*m;
};

template <typename C> struct A<int (C::*)(bool)> {
    C &c;
};

template <typename M, typename C, typename Arg> struct A<M (C::*)(Arg) &&> {
    C &&c;
    M C::*m;
};

template <typename C> struct A<float (C::*)(int) &&> {
    C &&c;
    float C::*mf;
};

template <typename M, typename C, typename Arg1, typename Arg2, typename Arg3>
struct A<M (C::*)(Arg1, Arg2, Arg3)> {
    C &c;
    M C::*m;
};

template <int N> struct A<char[N]> {
    char n[N];
};

template <> struct A<char[1000]> {
    std::vector<char> n;
};

}
}