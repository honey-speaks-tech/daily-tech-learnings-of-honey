// Nested try .. catch example

#include <exception>
#include <iostream>

void fancy_handler() {
    try {
        throw; // assumes that fancy_handler() is called from catch-clause
    } catch (std::runtime_error const& rt) {
        std::cout << "runtime-error: " << rt.what() << "\n";
    } catch (std::exception const& ex) {
        std::cout << "excption: " << ex.what() << "\n";
    } catch (...) {
        std::cout << "unknown exception\n";
    }
}

int do_foo()
{
    return 0;
}

int do_bar()
{
    return 0;
}

void foo() { try { do_foo(); } catch (...) { fancy_handler(); } }
void bar() { try { do_bar(); } catch (...) { fancy_handler(); } }

int main()
{
    foo();
    bar();

    return 0;
}
