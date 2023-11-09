#include <iostream>
#include <optional>
#include <chrono>

enum class Mode
{
    Rx,
    Tx
};

struct TimingSpec
{
    Mode mode;
    std::optional<std::chrono::milliseconds> time_period_millisecs;
};


int main()
{
    // Valid C++ format - Very useful if a forward declaration to be avoided.
    struct TimingSpec timing_spec{};

    TimingSpec timing_spec_1;

    if (timing_spec.time_period_millisecs)
    {
       auto ms = timing_spec.time_period_millisecs.value();
       (void)ms;
    } 
    
    if (timing_spec_1.time_period_millisecs)
    {
        auto ms_1 = timing_spec_1.time_period_millisecs.value();
        (void)ms_1;
    }

    return 0;
}