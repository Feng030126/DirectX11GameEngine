#include "FrameTimer.h"

void FrameTimer::init(int frameTarget) {
    // Query performance frequency (ticks per second)
    QueryPerformanceFrequency(&perfFreq);
    // Compute seconds per frame (fixed timestep)
    frameInterval = 1.0 / static_cast<double>(frameTarget);
    // Initialize counters
    QueryPerformanceCounter(&lastCount);
    accumulator = 0.0;
}

// Returns how many fixed-size update steps to run this frame
int FrameTimer::framesToUpdate() {
    // Get current time
    LARGE_INTEGER currentCount;
    QueryPerformanceCounter(&currentCount);
    // Compute delta time in seconds
    double deltaSeconds = static_cast<double>(currentCount.QuadPart - lastCount.QuadPart)
        / static_cast<double>(perfFreq.QuadPart);
    lastCount = currentCount;
    // Accumulate elapsed time
    accumulator += deltaSeconds;

    int updates = 0;
    // Process as many fixed-interval steps as needed
    while (accumulator >= frameInterval) {
        updates++;
        accumulator -= frameInterval;

        if (updates >= 1) {
            // Drop any excess accumulated time and break out
            accumulator = 0.0;
            break;
        }
    }
    return updates;
}
