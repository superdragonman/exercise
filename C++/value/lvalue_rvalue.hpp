/**
 * @file lvalue_rvalue.hpp
 * @author lzy
 * @brief 左值和右值的概念
 *
 *
 */
#include <utility>
void target(int &a);
void target(int &&a);

// 必须加forward，保证传来的是左值或者右值，传出去还是左值或者右值。不然进来了右值，传走了左值
// 当 T&& 中的 T 是由模板自动推导出来的时候，这个 T&& 不是普通的右值引用，而叫 转发引用 forwarding reference。
// 如果穿进来的是右值, 那么 T 就是 int，T&& 就是 int&&，传出去的就是右值引用。
// 如果传进来的参数是左值，C++ 会把 T 推导成 T&，那么 T&& 就变成了 T& &&，根据引用折叠规则，T& && 会折叠成 T&，所以传进来的左值就会被当作左值传出去。
// 引用折叠规则
// T& & => T&
// T&& & => T&
// T& && => T&
// T&& && => T&&
//
template <typename T>
void wrapper(T &&a)
{
  target(std::forward<T>(a));
}
