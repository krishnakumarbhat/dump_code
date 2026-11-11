#ifndef PROFILE_TIMING_H
#define PROFILE_TIMING_H

#include <array>
#include <chrono>
#include <limits>
#include <string>
#include <vector>

#define TIMER_START(module) Get_Profile().startTimer(module)
#define TIMER_STOP(module)  Get_Profile().stopTimer(module)
#define TIMER_RESET(...)    Get_Profile().resetTimer()

/* Enum to identify different modules */
enum TimingModule
{
   /* Create enums in order of function execution */
   POPULATE_IPC_DATA = 0,
   RSP_RUN,
   TRACKER,
   FEATURE_FUNCTION,
   TRANSMIT_UDP,
   TRANSMIT_CAN,
   POPULATE_RADAR_OUTPUT_SYMBOL,
   EXECUTE,
};

/* Timing elements of a module */
struct TimingElements
{
   long long duration  = 0;
   long long max_delta = std::numeric_limits<long long>::min();
   long long min_delta = std::numeric_limits<long long>::max();
};

class Profile
{
 public:
   static constexpr size_t kTimingModuleCount = static_cast<size_t>(EXECUTE) + 1U;

   /* public methods */
   void startTimer(TimingModule module);
   void stopTimer(TimingModule module);
   void resetTimer();

   /* Get functions */
   long long Get_Timing_Duration(TimingModule mod) const;
   const char *Get_TimingModule_Name(TimingModule mod) const;

 private:
   /* Stores start times of each modules */
   std::array<std::chrono::high_resolution_clock::time_point, kTimingModuleCount> startTimes{};

   /* Tracks which modules currently have active start time */
   std::array<bool, kTimingModuleCount> activeTimers{};

   /* Stores timing data of all modules */
   std::array<TimingElements, kTimingModuleCount> timingData{};

   friend Profile &Get_Profile();

   static bool IsValidModule(TimingModule module)
   {
      const size_t idx = static_cast<size_t>(module);
      return idx < kTimingModuleCount;
   }

   static size_t ToIndex(TimingModule module)
   {
      return static_cast<size_t>(module);
   }
};

Profile &Get_Profile();

#endif
