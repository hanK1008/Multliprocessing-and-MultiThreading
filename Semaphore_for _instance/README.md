# Win32 Semaphore Instance Limiter

A simple Win32 API project demonstrating how to limit the number of simultaneously running application instances using a named semaphore.

## Concepts Used
- Win32 API
- Semaphore
- Kernel Objects
- Cross-Process Synchronization
- `CreateSemaphore`
- `WaitForSingleObject`
- `ReleaseSemaphore`

## Behavior
- Maximum 3 instances allowed
- 4th instance exits automatically