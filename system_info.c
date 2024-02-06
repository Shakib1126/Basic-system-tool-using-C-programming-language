#include <windows.h>
#include <stdio.h>
#include <time.h>

void displaySystemInfo() {
    SYSTEM_INFO systemInfo;
    GetSystemInfo(&systemInfo);

    OSVERSIONINFO osVersionInfo;
    ZeroMemory(&osVersionInfo, sizeof(OSVERSIONINFO));
    osVersionInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    GetVersionEx(&osVersionInfo);

    printf("System Information:\n");
    printf("  OS Version: %d.%d\n", osVersionInfo.dwMajorVersion, osVersionInfo.dwMinorVersion);
    printf("  Architecture: ");
    switch (systemInfo.wProcessorArchitecture) {
        case PROCESSOR_ARCHITECTURE_AMD64:
            printf("64-bit\n");
            break;
        case PROCESSOR_ARCHITECTURE_INTEL:
            printf("32-bit\n");
            break;
        default:
            printf("Unknown\n");
    }
}

void displayMemoryInfo() {
    MEMORYSTATUSEX memoryStatus;
    memoryStatus.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memoryStatus);

    printf("\nMemory Information:\n");
    printf("  Total Physical Memory: %llu MB\n", memoryStatus.ullTotalPhys / (1024 * 1024));
    printf("  Available Physical Memory: %llu MB\n", memoryStatus.ullAvailPhys / (1024 * 1024));
    printf("  Total Virtual Memory: %llu MB\n", memoryStatus.ullTotalVirtual / (1024 * 1024));
    printf("  Available Virtual Memory: %llu MB\n", memoryStatus.ullAvailVirtual / (1024 * 1024));
}

void displayProcessorInfo() {
    SYSTEM_INFO systemInfo;
    GetSystemInfo(&systemInfo);

    printf("\nProcessor Information:\n");
    printf("  Number of Processor Cores: %u\n", systemInfo.dwNumberOfProcessors);
}

void displayDateTime() {
    time_t t;
    struct tm* tm_info;

    time(&t);
    tm_info = localtime(&t);

    printf("\nCurrent Date and Time:\n");
    printf("  %s", asctime(tm_info));
}

int main() {
    displaySystemInfo();
    displayMemoryInfo();
    displayProcessorInfo();
    displayDateTime();

    return 0;
}
