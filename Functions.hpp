
#pragma once

static bool x64System(::std::string* a = nullptr, ::std::wstring* w = nullptr) noexcept
{
    static char da[4096]{ };
    static wchar_t dw[4096]{ };
    static bool r{ };

    r = false;

    if (::GetSystemWow64DirectoryA(da, ::std::atoi(XCS("4095"))))
    {
        if (a)
            a->assign(da);

        r = true;
    }

    if (::GetSystemWow64DirectoryW(dw, ::std::atoi(XCS("4095"))))
    {
        if (w)
            w->assign(dw);

        r = true;
    }

    return r;
}

static void toUpper(char* b) noexcept
{
    static ::std::size_t i{ };

    if (!b || *b == SE_ZERO)
        return;

    for (i = SE_ZERO; i < ::std::strlen(b); i++)
        b[i] = ::std::toupper(b[i]);
}

static void toUpper(wchar_t* b) noexcept
{
    static ::std::size_t i{ };

    if (!b || *b == SE_ZERO)
        return;

    for (i = SE_ZERO; i < ::std::wcslen(b); i++)
        b[i] = ::std::towupper(b[i]);
}

static ::std::string& toUpper(::std::string& b) noexcept
{
    if (b.empty())
        return b;

    ::std::transform(b.begin(), b.end(), b.begin(), ::toupper);

    return b;
}

static ::std::string toUpper(const char* b) noexcept
{
    static ::std::string u{ };

    if (!b || *b == SE_ZERO)
        return { };

    u.assign(b), ::std::transform(u.begin(), u.end(), u.begin(), ::toupper);

    return u;
}

static void toUpper(::std::string* b) noexcept
{
    if (!b || (*b).empty())
        return;

    ::std::transform((*b).begin(), (*b).end(), (*b).begin(), ::toupper);
}

static ::std::wstring& toUpper(::std::wstring& b) noexcept
{
    if (b.empty())
        return b;

    ::std::transform(b.begin(), b.end(), b.begin(), ::towupper);

    return b;
}

static ::std::wstring toUpper(const wchar_t* b) noexcept
{
    static ::std::wstring u{ };

    if (!b || *b == SE_ZERO)
        return { };

    u.assign(b), ::std::transform(u.begin(), u.end(), u.begin(), ::towupper);

    return u;
}

static void toUpper(::std::wstring* b) noexcept
{
    if (!b || (*b).empty())
        return;

    ::std::transform((*b).begin(), (*b).end(), (*b).begin(), ::towupper);
}

static void toLower(char* b) noexcept
{
    static ::std::size_t i{ };

    if (!b || *b == SE_ZERO)
        return;

    for (i = SE_ZERO; i < ::std::strlen(b); i++)
        b[i] = ::std::tolower(b[i]);
}

static void toLower(wchar_t* b) noexcept
{
    static ::std::size_t i{ };

    if (!b || *b == SE_ZERO)
        return;

    for (i = SE_ZERO; i < ::std::wcslen(b); i++)
        b[i] = ::std::towlower(b[i]);
}

static ::std::string& toLower(::std::string& b) noexcept
{
    if (b.empty())
        return b;

    ::std::transform(b.begin(), b.end(), b.begin(), ::tolower);

    return b;
}

static ::std::string toLower(const char* b) noexcept
{
    static ::std::string u{ };

    if (!b || *b == SE_ZERO)
        return { };

    u.assign(b), ::std::transform(u.begin(), u.end(), u.begin(), ::tolower);

    return u;
}

static void toLower(::std::string* b) noexcept
{
    if (!b || (*b).empty())
        return;

    ::std::transform((*b).begin(), (*b).end(), (*b).begin(), ::tolower);
}

static ::std::wstring& toLower(::std::wstring& b) noexcept
{
    if (b.empty())
        return b;

    ::std::transform(b.begin(), b.end(), b.begin(), ::towlower);

    return b;
}

static ::std::wstring toLower(const wchar_t* b) noexcept
{
    static ::std::wstring u{ };

    if (!b || *b == SE_ZERO)
        return { };

    u.assign(b), ::std::transform(u.begin(), u.end(), u.begin(), ::towlower);

    return u;
}

static void toLower(::std::wstring* b) noexcept
{
    if (!b || (*b).empty())
        return;

    ::std::transform((*b).begin(), (*b).end(), (*b).begin(), ::towlower);
}

static ::std::wstring toUnicode(::std::string i) noexcept
{
    static wchar_t w[4096]{ };

    ::MultiByteToWideChar
    (
        ((unsigned int)(::std::atoi(XCS("65001")))), \
        SE_ZERO, \
        i.c_str(), \
        ::std::atoi(XCS("-1")), \
        w, \
        ::std::atoi(XCS("4095"))
    );

    return ((::std::wstring)(w));
}

static ::std::string fromUnicode(::std::wstring i) noexcept
{
    static char b[4096]{ };

    ::WideCharToMultiByte
    (
        ((unsigned int)(::std::atoi(XCS("65001")))), \
        SE_ZERO, \
        i.c_str(), \
        ::std::atoi(XCS("-1")), \
        b, \
        ::std::atoi(XCS("4095")), \
        nullptr, \
        nullptr
    );

    return ((::std::string)(b));
}

static ::std::string& replaceAll(::std::string& i, ::std::string f, ::std::string t) noexcept
{
    static ::std::size_t w{ }, fl{ }, tl{ };

    if (i.empty() || f.empty())
        return i;

    w = SE_ZERO, fl = f.length(), tl = t.length();

    while ((w = i.find(f, w)) != ::std::string::npos)
        i.replace(w, fl, t), w += tl;

    return i;
}

static ::std::wstring& replaceAll(::std::wstring& i, ::std::wstring f, ::std::wstring t) noexcept
{
    static ::std::size_t w{ }, fl{ }, tl{ };

    if (i.empty() || f.empty())
        return i;

    w = SE_ZERO, fl = f.length(), tl = t.length();

    while ((w = i.find(f, w)) != ::std::string::npos)
        i.replace(w, fl, t), w += tl;

    return i;
}

static ::std::string& replaceOnce(::std::string& i, ::std::string f, ::std::string t) noexcept
{
    static ::std::size_t w{ };

    if (i.empty() || f.empty())
        return i;

    if ((w = i.find(f)) != ::std::string::npos)
        i.replace(w, f.length(), t);

    return i;
}

static ::std::wstring& replaceOnce(::std::wstring& i, ::std::wstring f, ::std::wstring t) noexcept
{
    static ::std::size_t w{ };

    if (i.empty() || f.empty())
        return i;

    if ((w = i.find(f)) != ::std::string::npos)
        i.replace(w, f.length(), t);

    return i;
}

static ::std::string& eraseAll(::std::string& i, ::std::string f) noexcept
{
    static const ::std::string e{ };

    static ::std::size_t w{ }, fl{ };

    if (i.empty() || f.empty())
        return i;

    w = SE_ZERO, fl = f.length();

    while ((w = i.find(f, w)) != ::std::string::npos)
        i.replace(w, fl, e);

    return i;
}

static ::std::wstring& eraseAll(::std::wstring& i, ::std::wstring f) noexcept
{
    static const ::std::wstring e{ };

    static ::std::size_t w{ }, fl{ };

    if (i.empty() || f.empty())
        return i;

    w = SE_ZERO, fl = f.length();

    while ((w = i.find(f, w)) != ::std::string::npos)
        i.replace(w, fl, e);

    return i;
}

static ::std::string& eraseOnce(::std::string& i, ::std::string f) noexcept
{
    static const ::std::string e{ };

    static ::std::size_t w{ };

    if (i.empty() || f.empty())
        return i;

    if ((w = i.find(f)) != ::std::string::npos)
        i.replace(w, f.length(), e);

    return i;
}

static ::std::wstring& eraseOnce(::std::wstring& i, ::std::wstring f) noexcept
{
    static const ::std::wstring e{ };

    static ::std::size_t w{ };

    if (i.empty() || f.empty())
        return i;

    if ((w = i.find(f)) != ::std::string::npos)
        i.replace(w, f.length(), e);

    return i;
}

static ::std::string& truncateFullPathToAddFileName(::std::string& p) noexcept
{
    static const ::std::string q{ XCS("\\/") };

    static ::std::size_t w{ };

    if (p.empty() || p.ends_with(q.at(SE_ZERO)) || p.ends_with(q.at(SE_ONE)))
        return p;

    w = p.find_last_of(q.at(SE_ZERO));

    if (w != ::std::string::npos)
        p.erase(w + ::std::size_t(SE_ONE));

    w = p.find_last_of(q.at(SE_ONE));

    if (w != ::std::string::npos)
        p.erase(w + ::std::size_t(SE_ONE));

    return p;
}

static ::std::wstring& truncateFullPathToAddFileName(::std::wstring& p) noexcept
{
    static const ::std::wstring q{ ::toUnicode(XCS("\\/")).c_str() };

    static ::std::size_t w{ };

    if (p.empty() || p.ends_with(q.at(SE_ZERO)) || p.ends_with(q.at(SE_ONE)))
        return p;

    w = p.find_last_of(q.at(SE_ZERO));

    if (w != ::std::string::npos)
        p.erase(w + ::std::size_t(SE_ONE));

    w = p.find_last_of(q.at(SE_ONE));

    if (w != ::std::string::npos)
        p.erase(w + ::std::size_t(SE_ONE));

    return p;
}

static ::std::string& replaceOneChar(::std::string& i, ::std::string f, ::std::string t) noexcept
{
    static ::std::size_t x{ };

    if (i.empty())
        return i;

    for (x = (::std::size_t)SE_ZERO; x < i.length(); x++)
    {
        if (i[x] == f[SE_ZERO])
            i[x] = t[SE_ZERO];
    }

    return i;
}

static ::std::wstring& replaceOneChar(::std::wstring& i, ::std::wstring f, ::std::wstring t) noexcept
{
    static ::std::size_t x{ };

    if (i.empty())
        return i;

    for (x = (::std::size_t)SE_ZERO; x < i.length(); x++)
    {
        if (i[x] == f[SE_ZERO])
            i[x] = t[SE_ZERO];
    }

    return i;
}

static ::std::string& trimBeg(::std::string& i, ::std::string w = XCS(" \f\n\r\t\v")) noexcept
{
    static ::std::size_t p{ };

    if (i.empty() || w.empty())
        return i;

    if ((p = i.find_first_not_of(w)) != ::std::string::npos)
        i.erase(SE_ZERO, p);

    else
        i.clear();

    return i;
}

static ::std::wstring& trimBeg(::std::wstring& i, ::std::wstring w = ::toUnicode(XCS(" \f\n\r\t\v")).c_str()) noexcept
{
    static ::std::size_t p{ };

    if (i.empty() || w.empty())
        return i;

    if ((p = i.find_first_not_of(w)) != ::std::wstring::npos)
        i.erase(SE_ZERO, p);

    else
        i.clear();

    return i;
}

static ::std::string& trimEnd(::std::string& i, ::std::string w = XCS(" \f\n\r\t\v")) noexcept
{
    static ::std::size_t p{ };

    if (i.empty() || w.empty())
        return i;

    if ((p = i.find_last_not_of(w)) != ::std::string::npos)
        i.erase(p + SE_ONE);

    else
        i.clear();

    return i;
}

static ::std::wstring& trimEnd(::std::wstring& i, ::std::wstring w = ::toUnicode(XCS(" \f\n\r\t\v")).c_str()) noexcept
{
    static ::std::size_t p{ };

    if (i.empty() || w.empty())
        return i;

    if ((p = i.find_last_not_of(w)) != ::std::wstring::npos)
        i.erase(p + SE_ONE);

    else
        i.clear();

    return i;
}

static ::std::string& trimAll(::std::string& i, ::std::string w = XCS(" \f\n\r\t\v")) noexcept
{
    if (i.empty() || w.empty())
        return i;

    return trimBeg(trimEnd(i, w), w);
}

static ::std::wstring& trimAll(::std::wstring& i, ::std::wstring w = ::toUnicode(XCS(" \f\n\r\t\v")).c_str()) noexcept
{
    if (i.empty() || w.empty())
        return i;

    return trimBeg(trimEnd(i, w), w);
}

static ::std::string& removeQuotes(::std::string& i, ::std::string q = XCS("\"'")) noexcept
{
    if (i.empty() || q.empty())
        return i;

    return trimBeg(trimEnd(i, q), q);
}

static ::std::wstring& removeQuotes(::std::wstring& i, ::std::wstring q = ::toUnicode(XCS("\"'")).c_str()) noexcept
{
    if (i.empty() || q.empty())
        return i;

    return trimBeg(trimEnd(i, q), q);
}

static ::std::string& removeSlashes(::std::string& i, ::std::string q = XCS("\\/")) noexcept
{
    if (i.empty() || q.empty())
        return i;

    return trimBeg(trimEnd(i, q), q);
}

static ::std::wstring& removeSlashes(::std::wstring& i, ::std::wstring q = ::toUnicode(XCS("\\/")).c_str()) noexcept
{
    if (i.empty() || q.empty())
        return i;

    return trimBeg(trimEnd(i, q), q);
}

static bool procRunning(::std::string n) noexcept
{
    static unsigned long l[4096]{ }, c{ }, s{ };
    static char on[4096]{ };
    static void* p{ };
    static ::std::size_t i{ };

    if (n.empty() || SE_ZERO == ::K32EnumProcesses(l, ::std::atoi(XCS("16384")), &c))
        return { };

    for (i = SE_ZERO, s = ::GetCurrentProcessId(); i < (c / SE_FOUR); i++)
    {
        if (l[i] != SE_ZERO && l[i] != s)
        {
            p = ::OpenProcess(::std::atoi(XCS("1040")), SE_ZERO, l[i]);

            if (p)
            {
                ::K32GetModuleBaseNameA(p, nullptr, on, ::std::atoi(XCS("4095"))), ::CloseHandle(p), p = nullptr;

                if (::lstrcmpiA(on, n.c_str()) == SE_ZERO)
                    return true;
            }
        }
    }

    return { };
}

static bool procRunning(::std::wstring n) noexcept
{
    static unsigned long l[4096]{ }, c{ }, s{ };
    static wchar_t on[4096]{ };
    static void* p{ };
    static ::std::size_t i{ };

    if (n.empty() || SE_ZERO == ::K32EnumProcesses(l, ::std::atoi(XCS("16384")), &c))
        return { };

    for (i = SE_ZERO, s = ::GetCurrentProcessId(); i < (c / SE_FOUR); i++)
    {
        if (l[i] != SE_ZERO && l[i] != s)
        {
            p = ::OpenProcess(::std::atoi(XCS("1040")), SE_ZERO, l[i]);

            if (p)
            {
                ::K32GetModuleBaseNameW(p, nullptr, on, ::std::atoi(XCS("4095"))), ::CloseHandle(p), p = nullptr;

                if (::lstrcmpiW(on, n.c_str()) == SE_ZERO)
                    return true;
            }
        }
    }

    return { };
}

static ::std::vector < ::std::pair < ::std::string, ::std::string > > enumApps(void) noexcept
{
    static const ::std::string f{ XCS("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall") };

    static ::HKEY__* t{ }, * a{ };
    static ::std::vector < ::std::pair < ::std::string, ::std::string > > l{ };
    static ::std::pair < ::std::string, ::std::string > p{ };
    static ::std::size_t i{ };
    static ::std::string e{ };
    static char b[4096]{ };
    static long r{ };
    static unsigned long s{ };

    if (::RegOpenKeyExA(HKEY_LOCAL_MACHINE, f.c_str(), SE_ZERO, SE_EIGHT, &t) != SE_ZERO)
        return { };

    for (i = SE_ZERO, l.clear(); i < ((::std::numeric_limits < ::std::size_t > ::max) ()); i++)
    {
        ::std::memset(b, SE_ZERO, ::std::atoi(XCS("4096"))), s = ::std::atoi(XCS("4095")), \
            r = ::RegEnumKeyExA(t, (unsigned long)i, b, &s, nullptr, nullptr, nullptr, nullptr);

        if (r == SE_ZERO)
        {
            e.assign(f.c_str()), e.append(XCS("\\")), e.append(b);

            if (::RegOpenKeyExA(HKEY_LOCAL_MACHINE, e.c_str(), SE_ZERO, SE_ONE, &a) != SE_ZERO)
            {
                if (a)
                    ::RegCloseKey(a), a = nullptr;

                continue;
            }

            ::std::memset(b, SE_ZERO, ::std::atoi(XCS("4096"))), s = ::std::atoi(XCS("4095"));

            if (::RegQueryValueExA(a, XCS("DisplayName"), nullptr, nullptr, ((unsigned char*)(b)), &s) == SE_ZERO)
                p.first.assign(b);

            else
                p.first.clear();

            ::std::memset(b, SE_ZERO, ::std::atoi(XCS("4096"))), s = ::std::atoi(XCS("4095"));

            if (::RegQueryValueExA(a, XCS("DisplayVersion"), nullptr, nullptr, ((unsigned char*)(b)), &s) == SE_ZERO)
                p.second.assign(b);

            else
                p.second.clear();

            if (a)
                ::RegCloseKey(a), a = nullptr;

            if (!p.first.empty() && !p.second.empty())
                l.emplace_back(p);
        }

        else if (r == ::std::atol(XCS("259")))
            break;
    }

    if (t)
        ::RegCloseKey(t), t = nullptr;

    return l;
}

static ::std::vector < ::std::pair < ::std::wstring, ::std::wstring > > enumAppsUnicode(void) noexcept
{
    static const ::std::wstring f{ ::toUnicode(XCS("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall")).c_str() };

    static ::HKEY__* t{ }, * a{ };
    static ::std::vector < ::std::pair < ::std::wstring, ::std::wstring > > l{ };
    static ::std::pair < ::std::wstring, ::std::wstring > p{ };
    static ::std::size_t i{ };
    static ::std::wstring e{ };
    static wchar_t b[4096]{ };
    static long r{ };
    static unsigned long s{ };

    if (::RegOpenKeyExW(HKEY_LOCAL_MACHINE, f.c_str(), SE_ZERO, SE_EIGHT, &t) != SE_ZERO)
        return { };

    for (i = SE_ZERO, l.clear(); i < ((::std::numeric_limits < ::std::size_t > ::max) ()); i++)
    {
        ::std::memset(b, SE_ZERO, ::std::atoi(XCS("8192"))), s = ::std::atoi(XCS("4095")), \
            r = ::RegEnumKeyExW(t, (unsigned long)i, b, &s, nullptr, nullptr, nullptr, nullptr);

        if (r == SE_ZERO)
        {
            e.assign(f.c_str()), e.append(::toUnicode(XCS("\\")).c_str()), e.append(b);

            if (::RegOpenKeyExW(HKEY_LOCAL_MACHINE, e.c_str(), SE_ZERO, SE_ONE, &a) != SE_ZERO)
            {
                if (a)
                    ::RegCloseKey(a), a = nullptr;

                continue;
            }

            ::std::memset(b, SE_ZERO, ::std::atoi(XCS("8192"))), s = ::std::atoi(XCS("4095"));

            if (::RegQueryValueExW(a, ::toUnicode(XCS("DisplayName")).c_str(), nullptr, nullptr, ((unsigned char*)(b)), &s) == SE_ZERO)
                p.first.assign(b);

            else
                p.first.clear();

            ::std::memset(b, SE_ZERO, ::std::atoi(XCS("8192"))), s = ::std::atoi(XCS("4095"));

            if (::RegQueryValueExW(a, ::toUnicode(XCS("DisplayVersion")).c_str(), nullptr, nullptr, ((unsigned char*)(b)), &s) == SE_ZERO)
                p.second.assign(b);

            else
                p.second.clear();

            if (a)
                ::RegCloseKey(a), a = nullptr;

            if (!p.first.empty() && !p.second.empty())
                l.emplace_back(p);
        }

        else if (r == ::std::atol(XCS("259")))
            break;
    }

    if (t)
        ::RegCloseKey(t), t = nullptr;

    return l;
}

static ::std::size_t countAppsByPartOfName(::std::string p, ::std::vector < ::std::pair < ::std::string, ::std::string > > l) noexcept
{
    static ::std::size_t i{ }, c{ };

    if (p.empty() || l.empty())
        return { };

    for (c = SE_ZERO, i = SE_ZERO; i < l.size(); i++)
    {
        if (::std::strstr(l[i].first.c_str(), p.c_str()))
            c++;
    }

    return c;
}

static ::std::size_t countAppsByPartOfName(::std::wstring p, ::std::vector < ::std::pair < ::std::wstring, ::std::wstring > > l) noexcept
{
    static ::std::size_t i{ }, c{ };

    if (p.empty() || l.empty())
        return { };

    for (c = SE_ZERO, i = SE_ZERO; i < l.size(); i++)
    {
        if (::std::wcsstr(l[i].first.c_str(), p.c_str()))
            c++;
    }

    return c;
}

static ::std::string retrieveAppVersionByPartOfName(::std::string p, ::std::vector < ::std::pair < ::std::string, ::std::string > > l) noexcept
{
    static ::std::size_t i{ };

    if (p.empty() || l.empty())
        return { };

    for (i = SE_ZERO; i < l.size(); i++)
    {
        if (::std::strstr(l[i].first.c_str(), p.c_str()))
            return l[i].second;
    }

    return { };
}

static ::std::wstring retrieveAppVersionByPartOfName(::std::wstring p, ::std::vector < ::std::pair < ::std::wstring, ::std::wstring > > l) noexcept
{
    static ::std::size_t i{ };

    if (p.empty() || l.empty())
        return { };

    for (i = SE_ZERO; i < l.size(); i++)
    {
        if (::std::wcsstr(l[i].first.c_str(), p.c_str()))
            return l[i].second;
    }

    return { };
}

static ::std::string retrieveSteamUsersFilePath(void) noexcept
{
    static ::HKEY__* k{ };
    static char p[4096]{ };
    static unsigned long s{ };
    static ::std::string f{ };

    ::RegOpenKeyExA(HKEY_CURRENT_USER, XCS("SOFTWARE\\Valve\\Steam"), SE_ZERO, SE_ONE, &k);

    if (k)
    {
        ::std::memset(p, SE_ZERO, ::std::atoi(XCS("4096"))), s = ::std::atoi(XCS("4095")), \
            ::RegQueryValueExA(k, XCS("SteamPath"), nullptr, nullptr, ((unsigned char*)(p)), &s), \
            ::RegCloseKey(k), k = nullptr;

        if (::std::strlen(p) > (::std::size_t)SE_ZERO)
        {
            f.assign(p), ::trimAll(f), ::removeQuotes(f), ::trimAll(f), \
                ::replaceAll(f, XCS("/"), XCS("\\")), \
                f.append(XCS("\\config\\loginusers.vdf"));

            return f;
        }
    }

    return { };
}

static ::std::wstring retrieveSteamUsersFilePathUnicode(void) noexcept
{
    static ::HKEY__* k{ };
    static wchar_t p[4096]{ };
    static unsigned long s{ };
    static ::std::wstring f{ };

    ::RegOpenKeyExW(HKEY_CURRENT_USER, ::toUnicode(XCS("SOFTWARE\\Valve\\Steam")).c_str(), SE_ZERO, SE_ONE, &k);

    if (k)
    {
        ::std::memset(p, SE_ZERO, ::std::atoi(XCS("8192"))), s = ::std::atoi(XCS("4095")), \
            ::RegQueryValueExW(k, ::toUnicode(XCS("SteamPath")).c_str(), nullptr, nullptr, ((unsigned char*)(p)), &s), \
            ::RegCloseKey(k), k = nullptr;

        if (::std::wcslen(p) > (::std::size_t)SE_ZERO)
        {
            f.assign(p), ::trimAll(f), ::removeQuotes(f), ::trimAll(f), \
                ::replaceAll(f, ::toUnicode(XCS("/")).c_str(), ::toUnicode(XCS("\\")).c_str()), \
                f.append(::toUnicode(XCS("\\config\\loginusers.vdf")).c_str());

            return f;
        }
    }

    return { };
}

static double cpuSpeed(void) noexcept
{
    static ::_LARGE_INTEGER W{ }, S{ }, C{ };
    static unsigned long long X{ };

    ::QueryPerformanceCounter(&S), ::QueryPerformanceFrequency(&W), W.QuadPart >>= SE_FIVE, X = ::__rdtsc();

    do ::QueryPerformanceCounter(&C);

    while (C.QuadPart - S.QuadPart < W.QuadPart);

    return ((::__rdtsc() - X) << SE_FIVE) / ((double)(::std::strtod(XCS("1000000.0"), nullptr)));
}

static void resolveLicenses(::std::string f, ::std::string t, ::std::vector < ::std::string > l, \
    ::std::string k = XCS("HWIDS"), ::std::string fn = XCS("XS")) noexcept
{
    static ::_iobuf* ff{ }, * tf{ };
    static char b[4096]{ };
    static ::std::string c{ }, r{ };
    static ::std::size_t s{ }, i{ };
    static bool d{ };

    ::fopen_s(&ff, f.c_str(), XCS("r"));

    if (!ff)
        return;

    ::fopen_s(&tf, t.c_str(), XCS("w"));

    if (!tf)
    {
        if (ff)
            ::std::fclose(ff), ff = nullptr;

        return;
    }

    s = l.size(), d = { };

    while (SE_ZERO == ::std::feof(ff))
    {
        b[SE_ZERO] = SE_ZERO, ::std::fgets(b, ::std::atoi(XCS("4095")), ff), c.assign(b);

        if (c.find(k.c_str()) != ::std::string::npos && !d)
        {
            for (i = SE_ZERO, r.clear(); i < s; i++)
            {
                if (i != (s - SE_ONE))
                {
                    if (i == SE_ZERO)
                        r.append(fn.c_str()), r.append(XCS("(\"")), r.append(l[i]), r.append(XCS("\"), \\\n"));

                    else
                        r.append(XCS("\t")), r.append(fn.c_str()), r.append(XCS("(\"")), r.append(l[i]), r.append(XCS("\"), \\\n"));
                }

                else
                    r.append(XCS("\t")), r.append(fn.c_str()), r.append(XCS("(\"")), r.append(l[i]), r.append(XCS("\"),"));
            }

            ::replaceOnce(c, k.c_str(), r), d = true;
        }

        ::std::fprintf(tf, c.c_str());
    }

    ::std::fclose(ff), ff = nullptr, ::std::fclose(tf), tf = nullptr;
}

static void resolveLicenses(::std::wstring f, ::std::wstring t, ::std::vector < ::std::string > l, \
    ::std::string k = XCS("HWIDS"), ::std::string fn = XCS("XS")) noexcept
{
    static ::_iobuf* ff{ }, * tf{ };
    static char b[4096]{ };
    static ::std::string c{ }, r{ };
    static ::std::size_t s{ }, i{ };
    static bool d{ };

    ::_wfopen_s(&ff, f.c_str(), ::toUnicode(XCS("r")).c_str());

    if (!ff)
        return;

    ::_wfopen_s(&tf, t.c_str(), ::toUnicode(XCS("w")).c_str());

    if (!tf)
    {
        if (ff)
            ::std::fclose(ff), ff = nullptr;

        return;
    }

    s = l.size(), d = { };

    while (SE_ZERO == ::std::feof(ff))
    {
        b[SE_ZERO] = SE_ZERO, ::std::fgets(b, ::std::atoi(XCS("4095")), ff), c.assign(b);

        if (c.find(k.c_str()) != ::std::string::npos && !d)
        {
            for (i = SE_ZERO, r.clear(); i < s; i++)
            {
                if (i != (s - SE_ONE))
                {
                    if (i == SE_ZERO)
                        r.append(fn.c_str()), r.append(XCS("(\"")), r.append(l[i]), r.append(XCS("\"), \\\n"));

                    else
                        r.append(XCS("\t")), r.append(fn.c_str()), r.append(XCS("(\"")), r.append(l[i]), r.append(XCS("\"), \\\n"));
                }

                else
                    r.append(XCS("\t")), r.append(fn.c_str()), r.append(XCS("(\"")), r.append(l[i]), r.append(XCS("\"),"));
            }

            ::replaceOnce(c, k.c_str(), r), d = true;
        }

        ::std::fprintf(tf, c.c_str());
    }

    ::std::fclose(ff), ff = nullptr, ::std::fclose(tf), tf = nullptr;
}

static float elapsedSince(::std::clock_t s) noexcept
{
    static ::std::clock_t r{ };

    r = ::std::clock() - s;

    return ((float)(r)) / ((::std::clock_t)(::std::atoi(XCS("1000"))));
}

static void freezeForCacheCleared(unsigned long f = (unsigned long) ::std::atoi(XCS("128")), \
    unsigned long d = (unsigned long) ::std::atoi(XCS("4096"))) noexcept
{
    static wchar_t* p{ };
    static ::std::wstring b{ };
    static ::std::size_t c{ };

    p = nullptr, ::SHGetKnownFolderPath(::FOLDERID_InternetCache, SE_ZERO, nullptr, &p);

    if (p)
    {
        b.assign(p);

        if (b.ends_with(::toUnicode(XCS("\\")).c_str()))
            b.append(::toUnicode(XCS("IE")).c_str());

        else
            b.append(::toUnicode(XCS("\\IE")).c_str());

        ::_wmkdir(b.c_str()), ::Sleep(::std::atoi(XCS("128")));

        while (SE_ONE)
        {
            c = SE_ZERO;

            for (const ::std::filesystem::directory_entry& e : ::std::filesystem::directory_iterator(b.c_str()))
            {
                if (e.is_directory())
                    c++;
            }

            if (c < (::std::size_t)SE_ONE)
                return;

            ::Sleep(f);
        }
    }

    else
        ::Sleep(d);
}
