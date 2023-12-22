#include <iostream>
// list 헤더 include 필요.
#include <list>
using namespace std;

int main(void)
{
    list<int> L = {1, 2};              // 1 2
                                       // list 타입의 iterator 선언 -> auto t로 변경 가능.
    list<int>::iterator t = L.begin(); // t는 1을 가리키는 중
    L.push_front(10);                  // 10 1 2
    cout << *t << '\n';                // t가 가리키는 값 = 1을 출력
    L.push_back(5);                    // 10 1 2 5
    L.insert(t, 6);                    // t가 가리키는 곳 앞에 6을 삽입, 10 6 1 2 5
    t++;                               // t를 1칸 앞으로 전진, 현재 t가 가리키는 값은 2
    L.erase(t);                        // t가 가리키는 값을 제거, 그 다음 원소인 5의 위치를 반환
                                       // 10 6 1 5, t가 가리키는 값은 5
    cout << *t << '\n';                // 5

    t = L.end();

    cout << *(--t) << '\n'; // 5

    for (auto i : L)
        cout << i << ' ';
    cout << '\n';
    for (list<int>::iterator it = L.begin(); it != L.end(); it++)
        cout << *it << ' ';
}