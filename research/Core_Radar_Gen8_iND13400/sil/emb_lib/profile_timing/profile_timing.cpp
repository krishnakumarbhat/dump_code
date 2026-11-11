#include "profile_timing.h"

namespace
{
volatile int g_profile_lock = 0;

struct ProfileLockGuard
{
   bool acquired;

   ProfileLockGuard() : acquired(false)
   {
      for (uint32_t attempt = 0U; attempt < 50000U; ++attempt)
      {
         if (__sync_lock_test_and_set(&g_profile_lock, 1) == 0)
         {
            acquired = true;
            break;
         }
      }
   }

   ~ProfileLockGuard()
   {
      if (acquired)
      {
         __sync_lock_release(&g_profile_lock);
      }
   }

   bool IsAcquired() const
   {
      return acquired;
   }
};
} // namespace

/* Object of class Profile */
static Profile profile;

/* Getter function for Profile class */
Profile &Get_Profile()
{
   return profile;
}

/* Gets timing elements for a module */
long long Profile::Get_Timing_Duration(TimingModule mod) const
{
   ProfileLockGuard lock;
   if (!lock.IsAcquired())
   {
      return 0;
   }

   if (!IsValidModule(mod))
   {
      return 0;
   }

   const size_t idx = ToIndex(mod);
   return timingData[idx].duration;
}

/* Gets timing module name */
const char *Profile::Get_TimingModule_Name(TimingModule mod) const
{
   switch (mod)
   {
      case POPULATE_IPC_DATA:
         return "populate_ipc_data()";
      case RSP_RUN:
         return "rsp_run()";
      case TRACKER:
         return "tracker_run()";
      case FEATURE_FUNCTION:
         return "feature_run()";
      case TRANSMIT_UDP:
         return "transmit_udp_data()";
      case TRANSMIT_CAN:
         return "transmit_can_data()";
      case POPULATE_RADAR_OUTPUT_SYMBOL:
         return "populate_radar_output_symbol()";
      case EXECUTE:
         return "SRR7_SiL_Execute()";
      default:
         return "";
   }
}

/* Starts the timer */
void Profile::startTimer(TimingModule module /**< [in] timing module */)
{
   ProfileLockGuard lock;
   if (!lock.IsAcquired())
   {
      return;
   }

   if (!IsValidModule(module))
   {
      return;
   }

   const size_t idx = ToIndex(module);

   /* Stores start time of the module */
   startTimes[idx]   = std::chrono::high_resolution_clock::now();
   activeTimers[idx] = true;
}

/* Stops the timer and update min, max and calculate duration*/
void Profile::stopTimer(TimingModule module /**< [in] timing module */)
{
   ProfileLockGuard lock;
   if (!lock.IsAcquired())
   {
      return;
   }

   if (!IsValidModule(module))
   {
      return;
   }

   const size_t idx = ToIndex(module);

   /* Stores end time of the module */
   auto end = std::chrono::high_resolution_clock::now();

   if (activeTimers[idx])
   {
      const auto start = startTimes[idx];

      /* Duration calculation */
      long long duration_micro = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

      /* push back duration to durations vector */
      TimingElements &data = timingData[idx];
      data.duration        = duration_micro;

      /* Calculate min and max delta */
      data.max_delta = std::max(data.max_delta, duration_micro);
      data.min_delta = std::min(data.min_delta, duration_micro);

      activeTimers[idx] = false;
   }
}

/* Resets the timer */
void Profile::resetTimer()
{
   ProfileLockGuard lock;
   if (!lock.IsAcquired())
   {
      return;
   }

   for (size_t idx = 0U; idx < kTimingModuleCount; ++idx)
   {
      activeTimers[idx] = false;
      timingData[idx]   = TimingElements{};
   }
}
