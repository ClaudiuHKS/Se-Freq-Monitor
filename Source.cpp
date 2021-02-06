
#include "Requirements.hpp"
#include "Capabilities.hpp"
#include "Functions.hpp"

int main(int n, char** a) noexcept
{
    static unsigned long l[4096]{ }, s{ }, c{ };
    static void* p{ };
    static wchar_t w[4096]{ };
    static float q{ };
    static ::std::size_t i{ };
    static ::std::string b{ };

    ::std::setlocale(SE_TWO, XCS(".utf8")), ::SetPriorityClass(::GetCurrentProcess(), ::std::atoi(XCS("128"))), \
        ::SetProcessPriorityBoost(::GetCurrentProcess(), SE_ZERO);

    while (!::GetConsoleWindow())
        ::AllocConsole(), ::Sleep(SE_ONE);

    ::ShowWindow(::GetConsoleWindow(), SE_FIVE);

    for (c = ::GetCurrentProcessId(), i = SE_ZERO, ::K32EnumProcesses(l, ::std::atoi(XCS("16384")), &s); i < (s / SE_FOUR); i++)
    {
        if (l[i] != SE_ZERO && l[i] != c)
        {
            p = ::OpenProcess(::std::atoi(XCS("1040")), SE_ZERO, l[i]);

            if (p)
            {
                w[SE_ZERO] = SE_ZERO, ::K32GetModuleBaseNameW(p, nullptr, w, ::std::atoi(XCS("4095"))), ::CloseHandle(p), p = nullptr;

                if (::_wcsicmp(w, ::toUnicode(XCS("freqmonitor.exe")).c_str()) == SE_ZERO)
                {
                    ::std::exit(SE_ONE), ::std::quick_exit(SE_ONE), ::ExitProcess(SE_ONE), ::std::abort();

                    return SE_ONE;
                }
            }
        }
    }

    if (!a[SE_ONE] || ::std::atof(a[SE_ONE]) < ::std::atof(XCS("0.1")))
    {
        b.assign(XCS("No Arguments Or Parameters Provided?\n")), \
            b.append(XCS("\n")), \
            b.append(XCS("You Need To Create A Shortcut For This Exe File,\n")), \
            b.append(XCS("Edit The Properties Of The Shortcut You Created,\n")), \
            b.append(XCS("Adding An Argument Or A Parameter After The Exe File Name,\n")), \
            b.append(XCS("\n")), \
            b.append(XCS("For Example:\n")), \
            b.append(XCS("\n")), \
            b.append(XCS("FreqMonitor.Exe 3000.0\n")), \
            b.append(XCS("\n")), \
            b.append(XCS("So Freq Monitor Knows Which Is The Cpu Frequency,\n")), \
            b.append(XCS("To Trigger An Audio Alert,\n")), \
            b.append(XCS("For Cpu Frequencies Below This Cpu Frequency."));

        ::MessageBoxA
        (
            nullptr, \
            b.c_str(), \
            XCS
            (
                "No Arguments Or Parameters Provided"
            ), \
            ::std::atoi(XCS("16"))
        );

        ::std::exit(SE_ONE), ::std::quick_exit(SE_ONE), ::ExitProcess(SE_ONE), ::std::abort();

        return SE_ONE;
    }

    ::std::printf
    (
        XCS
        (
            "\n" \
            "FREQ MONITOR\n" \
            "\n" \
            "TESTING THE AUDIO ALERT\n"
        )
    );

    ::PlaySoundA(XCS("WARN.WAV"), nullptr, ::std::atoi(XCS("131073"))), ::Sleep(::std::atoi(XCS("1024")));

    ::std::printf
    (
        XCS
        (
            "\n" \
            "TESTED\n" \
            "\n" \
            "WILL TRIGGER AN AUDIO ALERT FOR CPU FREQUENCIES BELOW %.1f MHZ\n" \
            "\n"
        ), \
        ((float)(::std::atof(a[SE_ONE])))
    );

    while (SE_ONE)
    {
        ::Sleep(::std::atoi(XCS("1024")));

        if ((q = ((float)(::cpuSpeed()))) < ((float)(::std::atof(a[SE_ONE]))))
        {
            ::std::printf
            (
                XCS
                (
                    "BAD CPU FREQUENCY ENCOUNTERED %.1f MHZ\n"
                ), \
                q
            );

            ::PlaySoundA(XCS("WARN.WAV"), nullptr, ::std::atoi(XCS("131073")));
        }
    }

    ::std::exit(SE_ZERO), ::std::quick_exit(SE_ZERO), ::ExitProcess(SE_ZERO), ::std::abort();

    return SE_ZERO;
}
